#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class String;
//引用计数器类
class String_rep
{
	friend class String;
	friend ostream& operator<<(ostream& out, const String& s);
	//此类的作用是管理数据空间和管理引用计数的变化
public:
	String_rep(const char* str = "") :use_count(0)
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String_rep(const String_rep& rep) :use_count(0)
	{
		m_data = new char[strlen(rep.m_data) + 1];
		strcpy(m_data, rep.m_data);
	}
	String_rep& operator=(const String_rep& rep);
	~String_rep()
	{
		delete[]m_data;
		m_data = nullptr;
	}
public:
	void increment()
	{//增加引用计数
		++use_count;
	}
	void decrement()
	{//减少引用计数
		if(--use_count==0)
			delete this;//自杀
	}
private:
	char* m_data;
	size_t use_count;
};
///////////////////////////////////////////////////////// 
class String
{
	friend ostream& operator<<(ostream& out, const String& s);
public:
	String(const char* str = "") :m_rep(new String_rep(str))//浅拷贝其引用计数器指针
	{
		m_rep->increment();
	}
	String(const String& s) :m_rep(s.m_rep)
	{
		m_rep->increment();
	}
	String& operator=(const String& s)
	{   //释放对象
		if (this != &s)
		{
			m_rep->decrement();
			m_rep = s.m_rep;
			m_rep->increment();
		}
		return *this;
	}
	~String()
	{//减少引用计数
		m_rep->decrement();
	}
public:
	void to_upper()
	{
		String_rep* new_rep = new String_rep(*m_rep);
		m_rep->decrement();
		m_rep = new_rep;
		char* pch = new_rep->m_data;
		while (*pch != '\0')
		{
			if (*pch >= 'a' && *pch <= 'z')
			{
				*pch -= 32;
			}
			pch++;
		}
		m_rep->increment();
	}
private:
	char* m_data;
	String_rep* m_rep;//指针指向引用计数器的类
};
ostream& operator<<(ostream& out,const String& s)
{
	out << s.m_rep->m_data;
	return out;
}
void main()
{
	String s1("abc");
	String s2 = s1;
	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
	s1.to_upper();
	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
}