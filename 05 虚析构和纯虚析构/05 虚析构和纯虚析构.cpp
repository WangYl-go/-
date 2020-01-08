#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }
    //利用虚析构可以解决 父类指针释放子类对象时不干净的问题
    //virtual ~Animal()
    //{
    //    cout << "Animal函数调用" << endl;
    //}

    //纯虚析构 既需要声明，也需要实现
    //有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;

    //纯虚函数
    virtual void Speak() = 0;
};

//纯虚析构的实现
Animal::~Animal()
{
    cout << "Animal函数调用" << endl;
}

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造函数调用" << endl;
        this->m_Name = new string(name);
    }
    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    virtual void Speak()
    {
        cout << *m_Name << "在说话" << endl;
    }

    string *m_Name;
};

void doSpeak(Animal* animal)
{
    animal->Speak();
}

void test01()
{
    Animal* animal = new Cat("Tom");
    doSpeak(animal);
    //父类指针在析构时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete animal;
}

int main()
{
    test01();
}
