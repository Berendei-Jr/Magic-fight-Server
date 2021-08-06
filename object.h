#ifndef OBJECT_H
#define OBJECT_H
class hexagon;

class object
{
    public:
        char* type;
        char icon;

        object(hexagon* position);
        virtual void destroy()=0;

    protected:
        hexagon* position;

    private:

};

class hero:public object
{
    public:
        hero(hexagon* position);
        int health;
        void move(int direction);
        void destroy();
        ~hero();
    private:

};

class projectile: public object
{
    public:
        projectile(hexagon* position, int damage, int SpeedTime, int Creator);
        int damage;
        int SpeedTime;
        int Creator;
};
#endif // OBJECT_H
