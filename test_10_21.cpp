#include<iostream>
using namespace std;
//C++中class默认为private，struct默认为public
//类的大小和数据成员相关，并且要考虑内存对齐，空类占一个字节



//构造函数(申请资源）:
//class Test {
//public:
//	//构造函数特点（作用：对象初始化）
//	//没有返回值，名字与类名相同 
//	//如果没有自定义构造函数，系统会默认产生构造函数(产生随机值）
//	//Test(){
//	//默认构造函数只能有一个默认值，避免二义性
//	//	cout << "Create Test object" << this << endl;
//	//	data = 1;
//	//}
//	//Test(int d) {
//	//	//构造函数允许重载
//	//	data = d;
//	//}
//	Test(int d = 0) {
//		data = d;
//	}
//	//析构函数(不允许重载)（释放资源）
//	//若没有自定义，系统会自己生成析构函数
//	//对象生命周期结束后，系统会自己调用析构函数
//	~Test() {
//		cout << "Free Test object:" << this << endl;
//	}
//private:
//	int data;
//};
//int main() {
//	//注意：实例化对象时要么括号内赋值，要么不带括号用默认值
//	Test t;//实例化对象（每产生一个对象，调动一次构造函数）
//	Test t1(10);//也可以使用Test t1=10;
//	Test t2();// 此时并不能完成实例化对象，表示的是一个函数的声明
//	Test t2;//构造函数按照t1到t3的顺序依次构造，析构时按照相反的顺序析构
//	Test t3;//当构造函数中含有全局变量和静态变量时，析构时局部，静态，全局的顺序
//    return 0;
//}


//拷贝构造函数(属于构造函数的一种）
//class Test 
//{
//public:
//	Test(int data = 0) 
//	{   
//		cout << "Create Test objest:" << this << endl;
//		m_data = data;
//	}
//	//拷贝构造函数
//	Test(const Test &t) //采用引用取别名，不用重新开辟空间让实参给形参赋值
//		                //采用传值方式会引发无穷递归调用
//	{
//		//加const采用常引用防止内部改变参数对象的值
//		cout << "Copy create Test objest:" << this << endl;
//		m_data = t.m_data;
//	}
//public:
//	int getData()const 
//	{
//		return m_data;
//	}
//private:
//	int m_data;
//};
//Test func(Test obj) 
//{
//	int value = obj.getData();
//	Test tmp(value);
//	return tmp;//返回tmp时也需要调动拷贝构造函数
//	//tmp是这个函数内的临时对象，函数结束后需要将这个对象拷贝
//	//到一个临时对象的空间内保存,对象初始化给对象调动拷贝构造函数
//}
//int main() 
//{
//	Test t1(20);
//	Test t2 = t1;//当用对象初始化对象时，系统会自动调用拷贝构造函数
//	//如果不写，系统也会产生默认的拷贝构造函数，并且最终结果与上面定义的相同
//	func(t1);//此时也会调动拷贝构造函数（函数的实参为实例化对象时）
//	return 0;
//}


//运算符的重载
class Test 
{
public:
	Test(int data = 0)
	{
		cout << "Create Test objest:" << this << endl;
		m_data = data;
	}
	Test(const Test& t) 
	{
		cout << "Copy create Test objest:" << this << endl;
		m_data = t.m_data;
	}
	~Test() 
	{
		cout << "Free Test object:" << this << endl;
	}
	//赋值语句    等号的重载
	//运算符重载真实意义：我们在进行对某种类型变量在进行运算时，我们希望可以直接的表达
	//而不是通过函数的调用完成运算，运算符的重载相当于给这个运算符赋予一个其他的含义
	void operator=(Test &t)
	//Test& operator=(const Test &t)
	{
		cout << "Assign" << this << " : " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		//return *this;
	}
private:
	int m_data;
};
int main()
{   
	Test t1(20);
	Test t2;
	t2 = t1;// t2.operater=(t1);注意：此时为赋值语句，不调动拷贝构造函数
	return 0;
}


