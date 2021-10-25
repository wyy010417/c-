#include<iostream>
using namespace std;
class Test
{
	friend ostream& operator<<(ostream& out, const Test& d);
public:
	//构造函数三个作用：
	//构造对象   初始化对象   类型转换
	//explicit关键字的意思为显示，表明此构造函数无法进行隐式类型转换
	Test(int data = 0):m_data(data)
	{
		//m_data = data;
	}//初始化列表的效率比赋初值的略高
	~Test()
	{}
public:
	operator int()//类型强制转换的重载
	{
		return m_data;
	}
private:
	int m_data;
	//int& m_a;//引用的成员只能通过列表的初始化
};
ostream& operator<<(ostream& out, const Test& d)
{
	out << d.m_data ;
	return out;
}
void main()
{
	Test dt;
	//dt = 100;//先将100通过构造函数变为一个临时对象，然后对象给对象赋值
	dt = (Test)100;//显示转换100
	cout << "dt=" << dt<<endl;
	int value = (int)dt;
	cout << "value=" << value << endl; 
}