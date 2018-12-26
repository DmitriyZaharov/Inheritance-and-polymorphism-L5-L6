#include <iostream>
#include <string>
#include <vector>

using namespace std;

//v0==============================================================
//class Chicken
//{
//public:
//    Chicken(string name) :
//            age(0),
//            name(name),
//            roadsCrossed(0)
//    {
//        cout << "Chicken ctor" << endl;
//    }
//
//    string getName() const
//    {
//        return name;
//    }
//
//    int getAge() const
//    {
//        return age;
//    }
//
//    void crossRoad()
//    {
//        roadsCrossed++;
//    }
//
//    void talk() const
//    {
//        cout << "bawwk";
//
//    }
//
//private:
//    int age;
//    string name;
//    int roadsCrossed;
//};
//
//class Duck
//{
//public:
//    Duck(string name):
//    age(0),
//    name(name),
//    numDucklings(0)
//    {
//        cout << "Duck ctor" << endl;
//    }
//private:
//    int age;
//    string name;
//    int numDucklings;
//
//};
//end v0==========================================================

//v1==============================================================

//class Bird
//{
//public:
//    Bird(string name):
//    age(0),
//    name(name)
//    {
//        cout << "Bird ctor" << endl;
//    }
//    virtual ~Bird()  {}
//
//    string getName() const
//    {
//        return name;
//    }
//
//    int getAge() const
//    {
//        return age;
//    }
//
//    void talk() const
//    {
//        cout << "Tweet" << endl;
//    }
//
//
//
//private:
//    int age;
//    string name;
//};
//
//class Chicken : public Bird
//{
//public:
//    Chicken(string name):
//    Bird(name),
//    roadsCrossed(0)
//    {
//        cout << "Chicken ctor" << endl;
//    }
//    ~Chicken(){}
//    void crossRoad()
//    {
//        roadsCrossed++;
//    }
//
//    void talk() const
//    {
//        cout << "bawwk" << endl;
//
//    }
//
//
//private:
//    int roadsCrossed;
//};
//
//class Duck : public Bird {
//
//
//public:
//    Duck(string name_in)
//    : Bird(name_in), numDucklings(0)
//    {
//        cout << "Duck ctor" << endl;
//    }
//    ~Duck(){}
//
//    void babyDucklings()
//    {
//        numDucklings += 7;
//    }
//
//    void talk() const
//    {
//        cout << "quack" << endl;
//    }
//
//private:
//    int numDucklings;
//};


//end v1=========================================================


//v2==============================================================

class Bird
{
public:
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


//end v2==========================================================


//
void allTalk(vector<Bird *> birds)
{
    for (auto br : birds)
    {
        br->talk();
    }
}

//void allTalk(vector<Bird*> birds)
//{
//    for (Bird *br : birds)
//    {
//        Chicken *ch = dynamic_cast<Chicken*>(br);
//        if (ch)
//        {
//            ch->talk();
//        }
//        Duck *dc = dynamic_cast<Duck*>(br);
//        if (dc)
//        {
//            dc->talk();
//        }
//
//    }
//}



int main()
{
    Chicken c("ch");
    Duck d("du");
    Bird b("bi");
    vector<Bird *> birds;
    birds.push_back(&c);
    birds.push_back(&d);
    birds.push_back(&b);
    allTalk(birds);

    return 0;
}