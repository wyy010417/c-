#include<iostream>
using namespace std;
////����
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
////�̳е��﷨
////���ࣨ�����ࣩ
//class D:public Base1,public Base//��̳У�����̳�����˳��һ�£�
//{
//public:
//	D():Base(2,3),  f(5, 6),Base1(2),c(4)//����˳�����ʼ�������б��˳���޹�
//	{
//		cout << "D::D()" << endl;
//	}
//	~D()
//	{
//		cout << "D::~D()" << endl;
//	}
//	//����ĽǶ�ȥ�����Ƿ���Է��ʸ���ĸ���Ա(���кͱ�����
//	void list()
//	{
//		cout << "D::list()" << endl;
//		//����ı�����Ա�������п��Է��ʣ���˽�г�Ա������
//		show();
//	}
//private:
//	int m_b;
//	C c;
//	F f;
//};
//void main()
//{
//	//����ĽǶ�ȥ�����Ƿ���Է��ʸ���ĸ���Ա(���У�
//	//�����ʱ���ȵ��ø��๹�췽�����ڵ�������ģ��ڵ���˽�����Ե����͹��췽��������ʱ���෴˳��
//	D d;
//	//d.func();
//	//d.show();
//}

//���������ĸ�ֵת��
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
////��ֵ���ݹ���
//	D d;
//	Base b;
//	//���������Ը��������ֵ
//	b = d;
//	//�������ĵ�ַ���Ը�����ָ�븳ֵ
//	Base* pb = &d;
//	//���������Գ�ʼ�����������
//	Base& rb = d;
//}

//ͬ������
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
	//�������еĺ����͸����к�����һ����ͬʱ���̳еĸ���ͬ��������������
	void fun()
	{
		cout << "D::fun()" << endl;
	}
};
void main()
{
	D d;
	d.fun();
	//ͬ�����ز�����û�м̳У�Ҳ����ͨ����������ø���ͬ������
	d.Base::fun();
	d.Base::fun1(1);
}
