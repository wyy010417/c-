#include<iostream>
using namespace std;
////父类
//class Base 
//{
//public:
//	Base(int a,int b)
//	{
//		cout << "Base::Base()" << endl;
//	}
//	~Base()
//	{
//		cout << "Base::~Base()" << endl;
//	}
//public:
//	void func()
//	{
//		cout << "Base::func()" << endl;
//	}
//protected:
//	void show()
//	{
//		cout << "Base::show()" << endl;
//	}
//private:
//	void print()
//	{
//		cout << "Base::print()" << endl;
//	}
//private:
//	int m_a;
//};
//class Base1
//{
//public:
//	Base1(int a)
//	{
//		cout << "Base1::Base1()" << endl;
//	}
//	~Base1()
//	{
//		cout << "Base1::~Base1()" << endl;
//	}
//private:
//	int m_a1;
//};
//class C
//{
//public:
//	C(int a)
//	{
//		cout << "C::C()" << endl;
//	}
//	~C()
//	{
//		cout << "C::~C()" << endl;
//	}
//};
//class F
//{
//public:
//	F(int a,int b)
//	{
//		cout << "F::F()" << endl;
//	}
//	~F()
//	{
//		cout << "F::~F()" << endl;
//	}
//};
////继承的语法
////子类（派生类）
//class D:public Base1,public Base//多继承（与其继承声明顺序一致）
//{
//public:
//	D():Base(2,3),  f(5, 6),Base1(2),c(4)//构造顺序与初始化参数列表的顺序无关
//	{
//		cout << "D::D()" << endl;
//	}
//	~D()
//	{
//		cout << "D::~D()" << endl;
//	}
//	//子类的角度去看待是否可以访问父类的各成员(公有和保护）
//	void list()
//	{
//		cout << "D::list()" << endl;
//		//父类的保护成员在子类中可以访问，而私有成员不可以
//		show();
//	}
//private:
//	int m_b;
//	C c;
//	F f;
//};
//void main()
//{
//	//对象的角度去看待是否可以访问父类的各成员(公有）
//	//构造的时候先调用父类构造方法，在调用子类的，在调用私有属性的类型构造方法，析构时按相反顺序
//	D d;
//	//d.func();
//	//d.show();
//}

//父类和子类的赋值转换
//class Base
//{
//public:
//	void fun()
//	{
//		cout << "Base::fun()" << endl;
//	}
//};
//class D:public Base
//{
//	void fun1()
//	{
//		cout << "D::fun1()" << endl;
//	}
//};
//void main()
//{
////赋值兼容规则
//	D d;
//	Base b;
//	//子类对象可以给父类对象赋值
//	b = d;
//	//子类对象的地址可以给父类指针赋值
//	Base* pb = &d;
//	//子类对象可以初始化父类的引用
//	Base& rb = d;
//}

//同名隐藏
class Base
{
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
	void fun1(int a)
	{
		cout << "Base::fun(int)" << endl;
	}
};
class D :public Base
{
public:
	//当子类中的函数和父类中函数名一旦相同时，继承的父类同名函数均被隐藏
	void fun()
	{
		cout << "D::fun()" << endl;
	}
};
void main()
{
	D d;
	d.fun();
	//同名隐藏不代表没有继承，也可以通过作用域调用父类同名函数
	d.Base::fun();
	d.Base::fun1(1);
}
