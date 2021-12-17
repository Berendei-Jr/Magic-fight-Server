//
// Created by hellcat on 17.12.2021.
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
    s.name = j.at("name");
    s.hash_pass = j.at("hash");
}

class Database : public std::enable_shared_from_this<Database>
{
public:
    explicit Database(const std::string& path)
    {
        std::fstream fin(path);
        if (!fin.is_open())
        {
            throw std::runtime_error("Unable to load database\n");
        }

        fin >> _db;

        for (auto const& item : _db.at("users")) {
            auto student = item.get<user_t>();
            _data.push_back(student);
        }

        for (auto& it : _data)
        {
            std::cout << it;
        }
    }

private:
    nlohmann::json _db;
    std::vector<user_t> _data;
    std::mutex _mtx;
};

#endif //SERVER_APP_NETDATABASE_HPP
