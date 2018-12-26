#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;



class Bird
{
public:
    using Sptr = std::shared_ptr<Bird>;

    Bird(string name):
            age(0),
            name(name)
    {
        cout << "Bird ctor" << endl;
    }
    virtual ~Bird()  {}

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    virtual void talk() const
    {
        cout << "Tweet" << endl;
    }



private:
    int age;
    string name;
};

class Chicken : public Bird
{
public:
    Chicken(string name):
            Bird(name),
            roadsCrossed(0)
    {
        cout << "Chicken ctor" << endl;
    }
    ~Chicken(){}

    void crossRoad()
    {
        roadsCrossed++;
    }

    void talk() const override
    {
        cout << "bawwk" << endl;

    }


private:
    int roadsCrossed;
};

class Duck : public Bird {


public:
    Duck(string name_in)
            : Bird(name_in), numDucklings(0)
    {
        cout << "Duck ctor" << endl;
    }
    ~Duck(){}

    void babyDucklings()
    {
        numDucklings += 7;
    }

    void talk() const override
    {
        cout << "quack" << endl;
    }

private:
    int numDucklings;
};



void allTalk(vector<Bird::Sptr> birds)
{
    for (auto br : birds)
    {
        br->talk();
    }
}


int main()
{

    vector<Bird::Sptr> birds;
    birds.push_back(make_shared<Chicken>("ch"));
    birds.push_back(make_shared<Duck>("du"));
    birds.push_back(make_shared<Bird>("bi"));
    
    allTalk(birds);

    return 0;
}


//part2

//class Base
//{
//public:
//    using Ptr = std::shared_ptr<Base>;
//
//    virtual ~Base() { cout << "~Base()"; }
//
//    int ibase = 1;
//};
//
//class Derived : public Base
//{
//public:
////    Derived( const Derived& rhs ) : Base(rhs)
//    ~Derived() { cout << "~Derived()"; }
//    std::string sder;
//};
//
//
//static void foo( Base b )
//{
//    cout << b.ibase;
//};
//
////static void close_fd(int*fd_ptr)
////{
////    int real_fd = *(int*)fd_ptr;
////    vdeb << "Let close " << real_fd;
////    ::close(real_fd);
////}
//
////int fd = ::open( "/dev/urandom", O_RDONLY );
////std::shared_ptr<int> rd_wdog( &fd, close_fd );
//
//
//int main(int argc, char**argv)
//{
//
//    Base::Ptr p1( std::make_shared<Derived>() );
//    std::weak_ptr<Base> w1 = p1;
//
//    p1->ibase;
//
//
////    std::weak_ptr<Base> w1;
////
////    {
////        Base::Ptr p1(std::make_shared<Derived>());
////        w1 = p1;
////
////        p1->ibase;
////    }
//
//    if ( auto ptr = w1.lock() )
//    {
//        cout << ptr->ibase << endl;
//    }
//
//    return 0;
//}