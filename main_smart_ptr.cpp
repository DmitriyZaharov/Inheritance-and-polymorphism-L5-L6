//#include <iostream>
//#include <memory>
//
//using namespace std;
//
//class Element
//{
//public:
//    Element()
//    {
//        cout << "Element ctor" << endl;
//    }
//    ~Element()
//    {
//        cout << "Element dtor" << endl;
//    }
//
//    void someFunction()
//    {
//        cout << "Hello" << endl;
//    }
//
//};
//
//int main()
//{
//    {
//        //первый способ
//        unique_ptr<Element> element1(new Element());
//        //второй способ exception safe предпочтительней
//        unique_ptr<Element> element2 = make_unique<Element>();
//        element1->someFunction();
//        element2->someFunction();
//    }
//
//    {
//        shared_ptr<Element> sh_el0;
//        {
//
//            shared_ptr<Element> sh_el1 = make_shared<Element>();
//            weak_ptr<Element> weak_el = sh_el1;
//            sh_el0 = sh_el1;
//        }
//
//    }
//    return 0;
//}