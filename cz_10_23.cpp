#include<iostream>
using namespace std;
//ǳ���������
//class String
//{
//public:
//	String(const char* string = "")
//	{
//		//�ȸ��ַ�������һ�οռ�
//		m_data = (char*)malloc(strlen(string) + 1);
//		strcpy(m_data, string);
//	}
//
//	//�������췽����ǳ������
//	//String(const String &s)
//	//{
//	//��ʱΪָ���Ա��ֵ��˵����ֵ��������ָ��ͬһ���ڴ�ռ�
//	//ֻ������ָ���ָ��û�п������µ��ڴ�ռ䣬��Ϊǳ����
//	//	m_data = s.m_data;
//	//}
//
//	//���
//	String(const String& s)
//	{
//		//�ȿ����ڴ�ռ䣬�ٽ���ֵ����
//		m_data = (char*)malloc(strlen(s.m_data) + 1);
//		strcpy(m_data, s.m_data);
//	}
//	void show()const
//	{
//		cout << m_data << endl;
//	}
//	~String()
//	{
//		//��ʱ����������s1���ͷ���s1��ָ����ڴ�ռ�
//		//Ҳ�ͱ���Sָ����ڴ�ռ䱻�ͷ���
//		free(m_data);
//		m_data = nullptr;
//	}
//	//�Ⱥŵ�����
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			//��s2��������ָ����ڴ�ռ䣬���¿���ָ��ռ�
//			//�ᵼ��ԭ�ռ��޴����ţ������ڴ�й¶,���Ҫ��ǰ�ͷ�
//			free(m_data);
//			m_data = (char*)malloc(strlen(s.m_data) + 1);
//			strcpy(m_data, s.m_data);
//		}
//		return *this;
//	}
//private:
//	char* m_data;
//};
//void main()
//{
//	String s("abcxyz");
//	s.show();
//	String s1 = s;//ϵͳ�����Ĭ�ϵĿ������췽��������Ա������
//	String s2;
//	s2 = s1;//ϵͳ�����Ĭ�ϵĸ�ֵ����������Ա��ֵ��
//}




//�����������
//class MyInt;
//ostream& operator<<(ostream& out, const MyInt &t);
//class MyInt  
//{
//	friend ostream& operator<<(ostream& out, const MyInt& t);
//public:
//	MyInt(int i = 0)
//	{
//		m_i = i;
//	}
//public:
//	//�������������
//	MyInt operator+(const MyInt& x)
//	{
//		return (m_i + x.m_i);
//	}
//	MyInt operator-(const MyInt& x)
//	{
//		return (m_i - x.m_i);
//	}
//	MyInt operator*(const MyInt& x)
//	{
//		return (m_i * x.m_i );
//	}
//	MyInt operator/(const MyInt& x)
//	{
//		return (m_i / x.m_i);
//	}
//public:
//	MyInt& operator+=(const MyInt& x)
//	{
//		m_i += x.m_i;
//		return *this;
//	}
//	MyInt& operator-=(const MyInt& x)
//	{
//		m_i -= x.m_i;
//		return *this;
//	}
//	MyInt operator%=(const MyInt& x)
//	{
//		m_i %= x.m_i;
//		return *this;
//	}
//public:
//	//�߼������������
//	bool operator>(const MyInt& x)
//	{
//		return m_i > x.m_i;
//	}
//	bool operator<=(const MyInt& x)
//	{
//		return !(*this > x);
//	}
//	bool operator<(const MyInt& x)
//	{
//		return m_i < x.m_i;
//	}
//	bool operator>=(const MyInt& x)
//	{
//		return !(*this < x);
//	}
//	bool operator==(const MyInt& x)
//	{
//		return m_i == x.m_i;
//	}
//	bool operator!=(const MyInt& x)
//	{
//		return m_i != x.m_i;
//	}
//public:
//	//�����Լ������
//	MyInt& operator++()//ǰ�� ++
//	{
//		m_i++;
//		return *this;
//	}
//	MyInt operator++(int)//����++�����ε�Ŀ�ľ�����ǰ++�����������أ�
//	{
//		MyInt tmp = *this;
//		m_i++;
//		return tmp;
//	}
//	MyInt& operator--()//ǰ��--
//	{
//		m_i--;
//		return *this;
//	}
//	MyInt operator--(int)
//	{
//		MyInt tmp = *this;
//		m_i--;
//		return *this;
//	}
//private:
//	int m_i;
//};
//ostream& operator<<(ostream &out, const MyInt& t)
//{
//	out << t.m_i;
//	return out;
//}
//void main()
//{
//	MyInt a = 10;
//	cout << "a= " << a << endl;
//	MyInt b = 20;
//	MyInt c;
//	c = a + b;
//	cout << "c= " << c << endl;
//	a += b;
//	cout << "a=" << a << endl;
//	if (a <= b)
//	{
//		cout << "a<=b" << endl;
//	}
//	else {
//		cout << "a>b" << endl;
//	}
//	MyInt x = ++a;
//	cout << "x= " << x << endl;
//	MyInt y = a++;
//	cout << "y= " << y << endl;
//}




//��Ԫ���������ⲿ����ͨ���˷�������ֱ�ӷ������ڲ���˽�ж���
//class Test
//{
//	friend void func(const Test& t);//ֻ��Ҫ���������������������
//public:
//	Test(int data = 0)
//	{
//		m_data = data;
//	}
//public:
//	int GetData()
//	{
//		return m_data;
//	}
//private:
//	int m_data;
//};
//void func(const Test &t)
//{
//	int data = t.m_data;//����m_data������˽�г�Ա,���������Ҫ���˷�����Ϊ��Ԫ����
//}

class Complex//������
{
	friend ostream& operator<<(ostream& out, const Complex& x);
	friend Complex operator+(int value, const Complex& x);
public:
	Complex(int real=0, int iamg=0) :m_real(real), m_iamg(iamg)//�����б�ĳ�ʼ����ʽ
	{}
	~Complex()
	{}
public:
	Complex operator+(const Complex &x)
	{
		return Complex(m_real + x.m_real, m_iamg + x.m_iamg);
	}
private:
	int m_real;//ʵ��
	int m_iamg;//�鲿
};
//������������
ostream& operator<<(ostream& out, const Complex& x)
{
	out << "(" << x.m_real << "," << x.m_iamg << ")";
	return out;
}
Complex operator+(int value, const Complex &x) 
{   
	
	return Complex(value + x.m_real,x.m_iamg);
}
void main()
{
	//Test t(10);
	//func(t);
	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex x = c1 + c2;
	//�����캯������Ĭ��ֵ��10�ᱻ��������дΪһ����ʱ����
	//��ʱ��10�൱��Complex(10,0)
	Complex y = c1 + 10;//�����Ҫ�����������ǿ����Լ�ͨ��������������
	Complex z = 10+ c1;//c1+ǰ���Ƕ��󣬿��Ե�����������غ���,��Ϊ�������޷�����
	//operator<<(cout,z);
	cout << z<< endl;
}