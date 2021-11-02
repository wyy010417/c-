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
//RAII 资源的获取即初始化
//实例化对象后会自动调用构造函数进行初始化，脱离空间后会自动的调动析构函数
void main()
{
	Test t;//静态变量在栈区存活
	Test* pt = new Test;//调动new操作符重载方法动态申请空间，再进行构造函数
	delete pt;
	Test* pt1 = new Test[10];

}