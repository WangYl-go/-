#include <iostream>
using namespace std;

class Base
{
public:
    //纯虚函数
    //只要有一个纯虚函数，这个类就成为抽象类
    //抽象类的特点：
    //1.无法实例化对象
    //2.抽象类的子类 必须要重写父类中的纯虚函数，负责也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
public:
    void func()
    {
        cout << "func函数调用" << endl;
    }
};

void test01()
{
    //Base b; //抽象类是无法实例化对象
    //new Base; //抽象类是无法实例化对象
    //Son s; //子类必须重写父类中的纯虚函数，否则无法实例化对象
    Base* base = new Son;
    base->func();
}

int main()
{
    test01();
    return 0;
} 