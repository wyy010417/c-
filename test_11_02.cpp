#include<iostream>
using namespace std;
void* operator new(size_t sz)
{
	void* ptr = malloc(sz);
	return ptr;
}
void operator delete(void* ptr)
{
	free(ptr);
}
void* operator new[](size_t sz)
{
	void* ptr = malloc(sz);
	return ptr;
}
void operator delete[](void* ptr)
{
	free(ptr);
}
class Test
{
public:
	Test(int data=0):m_data(data)
	{
		cout << "Test::Test()" << endl;
	}
	~Test()
	{
		cout << "Test::~Test()" << endl;
	}
private:
	int m_data;
};
//RAII ��Դ�Ļ�ȡ����ʼ��
//ʵ�����������Զ����ù��캯�����г�ʼ��������ռ����Զ��ĵ�����������
void main()
{
	Test t;//��̬������ջ�����
	Test* pt = new Test;//����new���������ط�����̬����ռ䣬�ٽ��й��캯��
	delete pt;
	Test* pt1 = new Test[10];

}