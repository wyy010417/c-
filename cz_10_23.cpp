#include<iostream>
using namespace std;
//浅拷贝和深拷贝
//class String
//{
//public:
//	String(const char* string = "")
//	{
//		//先给字符串开辟一段空间
//		m_data = (char*)malloc(strlen(string) + 1);
//		strcpy(m_data, string);
//	}
//
//	//拷贝构造方法（浅拷贝）
//	//String(const String &s)
//	//{
//	//此时为指针成员赋值，说明赋值结束二者指向同一个内存空间
//	//只拷贝了指针的指向，没有拷贝出新的内存空间，称为浅拷贝
//	//	m_data = s.m_data;
//	//}
//
//	//深拷贝
//	String(const String& s)
//	{
//		//先开辟内存空间，再进行值拷贝
//		m_data = (char*)malloc(strlen(s.m_data) + 1);
//		strcpy(m_data, s.m_data);
//	}
//	void show()const
//	{
//		cout << m_data << endl;
//	}
//	~String()
//	{
//		//此时先析构对象s1，释放了s1所指向的内存空间
//		//也就表明S指向的内存空间被释放了
//		free(m_data);
//		m_data = nullptr;
//	}
//	//等号的重载
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			//若s2本来有所指向的内存空间，重新开辟指向空间
//			//会导致原空间无处安放，导致内存泄露,因此要提前释放
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
//	String s1 = s;//系统会调用默认的拷贝构造方法（按成员拷贝）
//	String s2;
//	s2 = s1;//系统会调用默认的赋值方法（按成员赋值）
//}




//运算符的重载
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
//	//算术运算符重载
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
//	//逻辑运算符的重载
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
//	//自增自减运算符
//	MyInt& operator++()//前置 ++
//	{
//		m_i++;
//		return *this;
//	}
//	MyInt operator++(int)//后置++（传参的目的就是与前++方法构成重载）
//	{
//		MyInt tmp = *this;
//		m_i++;
//		return tmp;
//	}
//	MyInt& operator--()//前置--
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




//友元函数（类外部函数通过此方法可以直接访问类内部的私有对象）
//class Test
//{
//	friend void func(const Test& t);//只需要在类中声明这个方法即可
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
//	int data = t.m_data;//由于m_data是类中私有成员,因此我们需要将此方法变为友元方法
//}

class Complex//复数类
{
	friend ostream& operator<<(ostream& out, const Complex& x);
	friend Complex operator+(int value, const Complex& x);
public:
	Complex(int real=0, int iamg=0) :m_real(real), m_iamg(iamg)//参数列表的初始化方式
	{}
	~Complex()
	{}
public:
	Complex operator+(const Complex &x)
	{
		return Complex(m_real + x.m_real, m_iamg + x.m_iamg);
	}
private:
	int m_real;//实部
	int m_iamg;//虚部
};
//输出运算符重载
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
	//若构造函数中有默认值，10会被编译器改写为一个临时对象
	//此时的10相当于Complex(10,0)
	Complex y = c1 + 10;//如果需要加整数，我们可以自己通过方法进行重载
	Complex z = 10+ c1;//c1+前面是对象，可以调动运算符重载函数,若为整数，无法调动
	//operator<<(cout,z);
	cout << z<< endl;
}