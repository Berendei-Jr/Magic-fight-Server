#ifndef OBJECT_H
#define OBJECT_H
class hexagon;

class object
{
    public:
        object();
        virtual void move(int direction);


    protected:
        hexagon* position;

    private:

};
#endif // OBJECT_H
