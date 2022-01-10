#include<iostream>
using namespace std;
//友元关系不能被继承
//class B;
//class Base
//{
//	friend class A;
//public:
//	Base(int a = 0) :m_base(a)
//	{}
//private:
//	int m_base;
//};
//class A 
//{
//public:
//	A(int a = 0) :m_a(a)
//	{
//	}
//	void List(Base& b)const
//	{
//		cout << b.m_base << endl;
//	}
//private:
//	int m_a;
//};
////B类继承A类的所有属性和方法，但是友元关系不能继承
//class B:public A
//{
//public:
//	B(int b = 0) :m_b(b)
//	{}
//	void Show(Base &a)const
//	{
//		cout << a.m_base<< endl;
//	}
//private:
//	int m_b;
//};
//void main()
//{
//	A a(10);
//	B b(1);
//	Base(base);
//	a.List(base);
//	b.Show(base);
//}

//继承与静态成员
//class Base
//{
//public:
//	static int m_base;//c++11语法
//};
//int Base::m_base = 0;
//class A :public Base
//{
//private:
//	int m_a = 1;
//};
//class B :public Base
//{
//private:
//	int m_b = 2;
//};
//void main()
//{
//	//父类定义了静态成员，则整个继承体系中只有一个这样的成员
//	A a;
//	B b;
//	cout << a.m_base << endl;
//	cout << b.m_base << endl;
//	b.m_base = 10;
//	cout << a.m_base << endl;
//	cout << b.m_base << endl;
//}

//菱形继承
////虚基类
//class A
//{
//public:
//	int m_a=1;
//};
////虚继承
//class B:virtual public A
//{
//public:
//	int m_b = 2;
//};
////虚继承
//class C :virtual public A
//{
//public:
//	int m_c = 3;
//};
//class D :public B, public C
//{
//public:
//	int m_d = 4;
//};
//void main()
//{
//	D d;
//	cout << d.m_d << endl;
//	cout << d.m_b << endl;
//	cout << d.m_c << endl;
//	//菱形继承的数据冗余(D继承了两份A的数据，这两份被放在了不能内存空间上，
//	// 我们实际可能呢只需要一份)
//	//菱形继承的二义性(D中有来自A类中的m_a和B类中的m_a，
//	//若我们直接调用d中的m_a，由于他们存在的内存空间不同，
//	//
//	//所以直接调用D中的m_a会出现二义性）
//	cout << &d.B::m_a << " : " << d.B::m_a << endl;
//	cout << &d.C::m_a << " : " << d.C::m_a << endl;
//
//	//使用虚继承后
//	cout << d.m_a << endl;
//}

//继承和组合
//继承 is-a 是一种关系
class animal
{
public:
	void eat()
	{
		cout << "animal::eat()" << endl;
	}
	void foot()
	{
		cout << "animal::foot()" << endl;
	}
};
class person:public animal
{
public:
	void eat()
	{
		cout << "person::eat()" << endl;
	}
	void foot()
	{
		cout << "person::foot()" << endl;
	}
};
