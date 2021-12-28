//

#ifndef SERVER_APP_NETDATABASE_HPP
#define SERVER_APP_NETDATABASE_HPP

#include <mutex>
#include <vector>
#include <fstream>
#include <NetCommon.hpp>
#include <nlohmann/json.hpp>
#include <third-party/PicoSHA2/picosha2.h>

struct user_t
{
    std::string name;
    std::string hash_pass;
};

std::ostream& operator<<(std::ostream& out, const user_t& t)
{
    out << "Name: " << t.name << "\nHash: " << t.hash_pass << std::endl;
    return out;
}

void from_json(const nlohmann::json& j, user_t& s)
{
    s.name = j[0].at("name");
    s.hash_pass = j[0].at("hash");
}
void to_json(nlohmann::json& j, const user_t& u) {
    j.push_back({ {"name", u.name}, {"hash", u.hash_pass} });
}

class Database
{
public:
    explicit Database(const std::string& path)
    {
        std::ifstream fin(path);
        if (!fin.is_open())
        {
            throw std::runtime_error("Unable to load database\n");
        }

        fin >> _db;

        for (auto const& item: _db) {
            auto student = item.get<user_t>();
            _data.push_back(student);
        }

        for (auto& it : _data)
        {
            std::cout << it;
        }
        _thr_db_update = std::thread([&]() { Update(path); });
    }

    bool Register(const std::string& name, const std::string& pass)
    {
        std::scoped_lock<std::mutex> lock(_mtx);
        if (name.empty() || pass.empty())
            return false;
        for (auto& it : _data)
        {
            if (it.name == name)
                return false;
        }

        std::string hash_pass;
        picosha2::hash256_hex_string(pass, hash_pass);
        _data.emplace_back(user_t{name, hash_pass});
        _cv.notify_one();
        return true;
    }

    bool Login(const std::string& name, const std::string& pass)
    {
        std::scoped_lock<std::mutex> lock(_mtx);
        for (auto& it : _data)
        {
            if (it.name == name)
            {
                std::string hash_pass;
                picosha2::hash256_hex_string(pass, hash_pass);
                if (it.hash_pass == hash_pass)
                {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }

    ~Database() { Stop(); };

private:
    void Stop()
    {
        _stop = true;
        _cv.notify_one();
        if (_thr_db_update.joinable())
            _thr_db_update.join();
    }

    void Update(const std::string& path)
    {
        while (!_stop) {
            std::unique_lock<std::mutex> ul(_cv_mtx);
            _cv.wait(ul);

            std::scoped_lock<std::mutex> lock(_mtx);

            std::ofstream fout(path);
            std::cout << "PATH: " << path << "\n";
            if (!fout.is_open()) {
                throw std::runtime_error("Unable to load database\n");
            }

            _db.clear();
            _db = nlohmann::json(_data);
            fout << _db;
            fout.close();
        }
    }

    bool _stop = false;
    std::thread _thr_db_update;
    nlohmann::json _db;
    std::vector<user_t> _data;
    std::mutex _mtx;

    std::condition_variable _cv;
    std::mutex _cv_mtx;
};

#endif //SERVER_APP_NETDATABASE_HPP
