#include<iostream>
#include<assert.h>
using namespace std;
//new操作符的重载
void* operator new(size_t sz)
{// 返回值类型必须是void*
 //参数必须是无符号整型
	void* pt = malloc(sz);
	return pt;
}
void operator delete(void* pt)
{
	free(pt);
}
//定位new的重载
void* operator new(size_t sz, int* ptr, int pos)
{
	//利用new定位到生成的变量内存空间中的具体位置
	return &ptr[pos];
}
class Test
{
public:
	Test(int data = 0)
	{}
	~Test()
	{}
private:
	int m_data;
};
void main()
{
	//operator new只负责申请空间，并不会调动构造方法
	Test* pt = new Test;//new operator(new 操作符）
	//如果类内部也重载了new操作符，则优先类内部的重载方法
	delete pt;
	Test* pt1 = (Test*)operator new(sizeof(Test));
	/*int* ptr = (int*)malloc(sizeof(int) * 10);
	assert(ptr != NULL);*/
	int ptr[10];
	//此时new并不会开辟空间，而是在已有空间中把一个对象给构造进去
	new(ptr,2)int(1);//定位new
	new(ptr)int(0);//参数省略位置默认为第一个空间
}