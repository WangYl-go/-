#include <iostream>
using namespace std;

//抽象出每个零件的类 CPU，VideoCard, Memory

//抽象CPU类
class CPU
{
public:
    //抽象的计算函数
    virtual void Calculate() = 0;
};

//抽象显卡类
class VideoCard
{
public:
    //抽象的显示函数
    virtual void Display() = 0;
};

//抽象内存条类
class Memory
{
public:
    //抽象的显示函数
    virtual void Storage() = 0;
};

class Computer
{
public:
    Computer(CPU* cpu, VideoCard* vc, Memory* mem)
    {
        this->m_cpu = cpu;
        this->m_vc = vc;
        this->m_mem = mem;
    }
    //提供析构函数 释放3个电脑零件
    ~Computer()
    {
        if (m_cpu)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (!m_vc)
        {
            delete m_vc;
            m_vc = NULL;
        }
        if (!m_mem)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

    //提供工作的函数
    void Work()
    {
        //让零件工作起来，调用接口
        m_cpu->Calculate();
        m_vc->Display();
        m_mem->Storage();
    }
private:
    CPU* m_cpu; //CPU的零件指针
    VideoCard* m_vc; //显卡零件指针
    Memory* m_mem; //内存条零件指针
};

//具体厂商
//Inter厂商
class InterCPU : public CPU
{
public:
    virtual void Calculate()
    {
        cout << "Inter的CPU开始计算了" << endl;
    }
};
class InterVideoCard : public VideoCard
{
public:
    virtual void Display()
    {
        cout << "Inter的显卡开始显示了" << endl;
    }
};
class InterMemory : public Memory
{
public:
    virtual void Storage()
    {
        cout << "Inter的内存条开始储存了" << endl;
    }
};

//Lenovo厂商
class LenovoCPU : public CPU
{
public:
    virtual void Calculate()
    {
        cout << "Lenovo的CPU开始计算了" << endl;
    }
};
class LenovoVideoCard : public VideoCard
{
public:
    virtual void Display()
    {
        cout << "Lenovo的显卡开始显示了" << endl;
    }
};
class LenovoMemory : public Memory
{
public:
    virtual void Storage()
    {
        cout << "Lenovo的内存条开始储存了" << endl;
    }
};

void test01()
{
    //第一台电脑的零件
    CPU* interCpu = new InterCPU;
    VideoCard* interVC = new InterVideoCard;
    Memory* interMem = new InterMemory;

    //创建第一台电脑
    Computer* FirstComputer = new Computer(interCpu, interVC, interMem);
    FirstComputer->Work();
    delete FirstComputer;

    cout << "-----------分割线-------------" << endl;
    //第二台电脑的零件
    CPU* lenovoCpu = new LenovoCPU;
    VideoCard* lenovoVC = new LenovoVideoCard;
    Memory* lenovoMem = new LenovoMemory;

    //创建第二台电脑
    Computer* SecondComputer = new Computer(lenovoCpu, lenovoVC, lenovoMem);
    SecondComputer->Work();
    delete SecondComputer;

    cout << "-----------分割线-------------" << endl;

    //第三台电脑的零件
    CPU* ThirdCpu = new InterCPU;
    VideoCard* ThirdVC = new LenovoVideoCard;
    Memory* ThirdMem = new InterMemory;

    //创建第三台电脑
    Computer* ThirdComputer = new Computer(ThirdCpu, ThirdVC, ThirdMem);
    ThirdComputer->Work();
    delete ThirdComputer;
}

int main()
{
    test01();
    return 0;
}