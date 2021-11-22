#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
//#include<string>
using namespace std;
//string类的构造方法，赋值等的深浅拷贝问题
//class string
//{
//public:
//	string(const char* str="")
//	{
//		m_data = new char(strlen(str) + 1);
//		strcpy(m_data,str); 
//	}
//	~string()
//	{
//		if (m_data)
//		{
//			delete[]m_data;
//			m_data = nullptr;
//		}
//	}
//	/*string(const string& s)
//	{
//		m_data = new char(strlen(s.m_data) + 1);
//		strcpy(m_data, s.m_data);
//	}*/
//	string(const string& s):m_data(nullptr)
//	{
//		//上面的m_data必须赋空，否则在交换后释放这个临时对象时就会出现错误
//		string Tmp(s.m_data);//调动构造函数构造一个临时对象
//		std::swap(m_data, Tmp.m_data);
//	}
//	string operator=(const string& s)
//	{
//		//判断自己有没有给自己赋值
//		if (this!=&s)
//		{
//			string Tmp(s);
//			std::swap(m_data, Tmp.m_data);
//			//char* new_data = new char(strlen(s.m_data) + 1);
//			//strcpy(new_data, s.m_data);
//			//delete[]m_data;
//			////若此处的申请空间失败，但是还依然释放了以前的数据，就会发生异常
//			//m_data = new_data;
//		}
//		return *this;
//	}
//private:
//	char* m_data;
//};


//string类的模拟实现
namespace giggle
{
	class string
	{
		friend ostream& operator<<(ostream& out, const string& s);
	public:
		string(const char* str = "")
			:m_str(nullptr), m_capacity(0), m_size(0)
		{
			m_capacity = strlen(str) * 2;
			m_size = strlen(str);
			m_str = new char[m_capacity + 1];
			strcpy(m_str, str);
		}
		string(const string& s):m_str(nullptr),m_capacity(0),m_size(0)
		{
			string tmp(s.m_str);
			swap(tmp);
		}
		string operator=(string s)
		{
			if (this != &s)
				swap(s);
			return *this;
		}
		~string()
		{
			if (m_str)
			{
				delete []m_str;
				m_str = nullptr;
				m_capacity = m_size = 0;
			}
		}
	public:
		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		string& operator+=(const char* str)
		{
			int len = strlen(str);
			if (m_size + len> m_capacity)
			{
				reserve((m_size + len) * 2);
			}
			strcat(m_str, str);
			m_size += len;
			return *this;
		}
		const char& operator[](int pos)const
		{
			assert(pos >= 0 && pos < m_size);
			return m_str[pos];
		}
	public:
		size_t capacity()const
		{
			return m_capacity;
		}
		size_t size()const
		{
			return m_size;
		}
		bool empty()const
		{
			return  size() == 0;
		}
		void push_back(char c)
		{
			if (m_size > m_capacity)
			{
				reserve(m_capacity == 0 ? 1: 2 * m_capacity);
			}
			m_str[m_size] = c;
			m_size++;
			m_str[m_size] = '\0';
		}
		const char* c_str()const
		{
			return m_str;
		}
		void append(const char* str)
		{
			int len = strlen(str);
			if (m_size + len > m_capacity)
			{
				reserve((m_size + len) * 2);
			}
			strcat(m_str, str);
			m_size += len;
		}
		void clear()
		{
			*m_str = '\0';
			m_size = 0;
		}
		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > m_size)
			{
				if (newSize > m_capacity)
				{
					reserve(newSize);
				}
				memset(m_str + m_size, c, newSize - m_size);
			}
			m_str[newSize] = '\0';
			m_size = newSize;
		}
		void reserve(size_t new_capacity)
		{
			//预留空间时不一定里面的值比原有空间的值大
			if (new_capacity > m_capacity)
			{
				//扩容
				char* new_str = new char[new_capacity + 1];
				//不需要将原有空间全部拷贝过来，只需拷贝有效存储区域
				memcpy(new_str, m_str, m_size + 1);
				delete[]m_str;
				m_str = new_str;
				m_capacity = new_capacity;
			}
		}
		void swap(string& s)
		{
			std::swap(m_str, s.m_str);
			std::swap(m_capacity, s.m_capacity);
			std::swap(m_size, s.m_size);
		}
	public:
		typedef char* iterator;
		iterator begin()
		{
			return m_str;
		}
		iterator end()
		{
			return m_str + m_size;
		}
	private:
		char* m_str;
		size_t m_capacity;
		size_t m_size;
	};
	 ostream& operator<<(ostream& out, const string& s)
	{
		for (int i = 0; i < s.size(); i++)
			out << s[i];
		return out;
	}
}
int main()
{
	giggle::string s("abc");
	s.push_back('x');
	s.push_back('y');
	s.push_back('z');
	cout << s << endl;
	const char* pstr = s.c_str();
	cout << pstr << endl;
	/*s += "Linux";
	cout << s << endl;*/
	for (auto& e : s)
		cout << e << " ";
	return 0;
}