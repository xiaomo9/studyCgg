# include<iostream>
using namespace std;

// 主要组装电脑三大硬件 CPU、GPU、内存

// 创建CPU抽象类
class AbstractCPU
{
public:
    virtual void calculator() = 0;
};

// 创建GPU抽象类
class AbstractGPU
{
public:
    virtual void vediodisplay() = 0;
};

// 创建内存抽象类
class AbstraMemory
{
public:
    virtual void storage() = 0;
};



//---------各个硬件来自不同的供应商---------------

// 因特尔CPU创建
class IntelCPU :public AbstractCPU
{
public:
    void calculator()
    {
        cout << "目前使用的是Intel的CPU" << endl;
    }
};

// 英伟达GPU创建
class NvidiaGPU :public AbstractGPU
{
public:
    void vediodisplay()
    {
        cout << "您的显卡品牌是NVIDIA的4090白火神" << endl;
    }
};

//  金百达内存创建
class JinBaiDaMemory :public AbstraMemory
{
public:
    void storage()
    {
        cout << "您的数据存储在金百达内存32*2" << endl;
    }
};

// --------电脑的组装-------
class Computer
{
public:
    AbstractCPU *cpu;
    AbstractGPU *gpu;
    AbstraMemory *memory;

public:
    Computer(AbstractCPU *cpu1, AbstractGPU *gpu1, AbstraMemory *memory1)// 引入各硬件指针
    {
        cpu = cpu1;
        gpu = gpu1;
        memory = memory1;
    }

    void domake()
    {
        cpu->calculator();
        gpu->vediodisplay();
        memory->storage();
    }
};

void test01()
{
    IntelCPU cpu1;
    NvidiaGPU gpu1;
    JinBaiDaMemory memory;

    Computer cmp(new IntelCPU, new NvidiaGPU, new JinBaiDaMemory);

    cmp.domake();
}

int main()
{
    test01(); 
    system("pause");
    return 0;
}
