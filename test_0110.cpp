#include<iostream>
using namespace std;
//��Ԫ��ϵ���ܱ��̳�
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
////B��̳�A����������Ժͷ�����������Ԫ��ϵ���ܼ̳�
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

//�̳��뾲̬��Ա
//class Base
//{
//public:
//	static int m_base;//c++11�﷨
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
//	//���ඨ���˾�̬��Ա���������̳���ϵ��ֻ��һ�������ĳ�Ա
//	A a;
//	B b;
//	cout << a.m_base << endl;
//	cout << b.m_base << endl;
//	b.m_base = 10;
//	cout << a.m_base << endl;
//	cout << b.m_base << endl;
//}

//���μ̳�
////�����
//class A
//{
//public:
//	int m_a=1;
//};
////��̳�
//class B:virtual public A
//{
//public:
//	int m_b = 2;
//};
////��̳�
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
//	//���μ̳е���������(D�̳�������A�����ݣ������ݱ������˲����ڴ�ռ��ϣ�
//	// ����ʵ�ʿ�����ֻ��Ҫһ��)
//	//���μ̳еĶ�����(D��������A���е�m_a��B���е�m_a��
//	//������ֱ�ӵ���d�е�m_a���������Ǵ��ڵ��ڴ�ռ䲻ͬ��
//	//
//	//����ֱ�ӵ���D�е�m_a����ֶ����ԣ�
//	cout << &d.B::m_a << " : " << d.B::m_a << endl;
//	cout << &d.C::m_a << " : " << d.C::m_a << endl;
//
//	//ʹ����̳к�
//	cout << d.m_a << endl;
//}

//�̳к����
//�̳� is-a ��һ�ֹ�ϵ
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
