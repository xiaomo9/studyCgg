# include<iostream>
using namespace std;

// ��Ҫ��װ��������Ӳ�� CPU��GPU���ڴ�

// ����CPU������
class AbstractCPU
{
public:
    virtual void calculator() = 0;
};

// ����GPU������
class AbstractGPU
{
public:
    virtual void vediodisplay() = 0;
};

// �����ڴ������
class AbstraMemory
{
public:
    virtual void storage() = 0;
};



//---------����Ӳ�����Բ�ͬ�Ĺ�Ӧ��---------------

// ���ض�CPU����
class IntelCPU :public AbstractCPU
{
public:
    void calculator()
    {
        cout << "Ŀǰʹ�õ���Intel��CPU" << endl;
    }
};

// Ӣΰ��GPU����
class NvidiaGPU :public AbstractGPU
{
public:
    void vediodisplay()
    {
        cout << "�����Կ�Ʒ����NVIDIA��4090�׻���" << endl;
    }
};

//  ��ٴ��ڴ洴��
class JinBaiDaMemory :public AbstraMemory
{
public:
    void storage()
    {
        cout << "�������ݴ洢�ڽ�ٴ��ڴ�32*2" << endl;
    }
};

// --------���Ե���װ-------
class Computer
{
public:
    AbstractCPU *cpu;
    AbstractGPU *gpu;
    AbstraMemory *memory;

public:
    Computer(AbstractCPU *cpu1, AbstractGPU *gpu1, AbstraMemory *memory1)// �����Ӳ��ָ��
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
