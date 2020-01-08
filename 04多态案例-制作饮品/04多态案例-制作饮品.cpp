#include <iostream>
using namespace std;

//咖啡：1.煮水；2.冲泡咖啡；3.倒入水中；4.加糖和牛奶
//茶：1.煮水；2.冲泡茶叶；3.倒入杯中；4.加柠檬

class AbstractDrinking
{
public:
    //煮水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅料
    virtual void PutSomething() = 0;
    //制作饮品
    void MakeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};
//咖啡
class Coffee : public AbstractDrinking
{
public:
    //煮水
    virtual void Boil()
    {
        cout << "煮农夫山泉" << endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    //倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入咖啡杯" << endl;
    }
    //加入辅料
    virtual void PutSomething()
    {
        cout << "加糖和牛奶" << endl;
    }
};
//茶
class Tea : public AbstractDrinking
{
public:
    //煮水
    virtual void Boil()
    {
        cout << "煮怡宝" << endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout << "冲泡茶" << endl;
    }
    //倒入杯中
    virtual void PourInCup()
    {
        cout << "倒入茶杯" << endl;
    }
    //加入辅料
    virtual void PutSomething()
    {
        cout << "加柠檬" << endl;
    }
};

//制作函数
void DoWork(AbstractDrinking* p)
{
    p->MakeDrink();
    delete p;//释放
}

void test01()
{
    //制作咖啡
    AbstractDrinking* MakeCoffee(new Coffee);
    DoWork(MakeCoffee);
    cout << "----------------------------------" << endl;
    //制作茶
    AbstractDrinking* MakeTea(new Tea);
    DoWork(MakeTea);
}

int main()
{
    test01();
    return 0;
}