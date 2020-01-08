// 多态.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
    //虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

//猫类
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

//狗类
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

//执行说话的函数
//地址早绑定  在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void doSpeak(Animal& animal) //Animal & animal = cat
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02()
{
    cout << "Size of Animal = " << sizeof(Animal) << endl;
}

int main()
{
    //test01();
    test02();
}

//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数 函数返回值类型 函数名 参数列表 完全相同


//动态多态使用
//父类的指针或者引用 指向子类对象