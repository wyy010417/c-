#include<iostream>
#include<string>
using namespace std;
//string类接口
void TestString1()
{
	string s1("abcdefg");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
/////////////////////////////////////////
     //将s1中有效字符增加到10个，多出位置用"a"填充
	s1.resize(10, 'a');
	//将s1中的有效字符增加到15个,多出位置用'\0'填充
	s1.resize(15);
	s1.resize(5);
	cout << s1 << endl;
/////////////////////////////////////////
	//利用reserve提高插入数据的效率,避免增容带来的开销
	s1.reserve(50);
	cout << s1.capacity() << endl;
	//当reserve参数小于string底层空间大小时，空间不会再次缩小
	s1.reserve(25);
	cout << s1.capacity() << endl;
	s1.reserve(1000);
	cout << s1.capacity() << endl;
	//clear清空有效字符，不改变底层空间的大小
	s1.clear();
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}
//reserve
void TestPushBack()
{
	//reserve后的底层空间会比所给参数略大一点，当超过这个底层空间大小时，系统会自动进行扩容
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << s.capacity() << endl;
	cout << "making s grow\n";
	for (int i = 0; i <=100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed" << sz << endl;
		}
	}
	cout << s << endl;
}
//string 类的访问及遍历操作
void TestString2()
{
	string s1("Hello world");
	//const类型对象不能修改
	const string s2("Hello world");
///////////////////////////////////////////////////
	//3种遍历方式
	//1.for+operator[](c方式)
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cout << endl;
	//2.迭代器
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	//3.智能指针auto
	for (auto& s : s1)
		cout << s ;
	cout << endl;
////////////////////////////////////////////////
//返回迭代器指针的值，要区别于back
	s1.begin();
	s1.end();
	cout << s1.back() << endl;
	cout << s1.front()<< endl;
	//rbegin 和rend只能与reverse_iterator搭配使用,且只能逆向进行
	for (string::reverse_iterator rit = s1.rbegin(); rit < s1.rend();++rit)
		cout << *rit ;
	cout << endl;
}
//string类对象的修改操作
void TestString3()
{
	string s;
	s.push_back('!');//在字符串s后插入一个！
	s.append("lalala");//在s字符串后追加一个字符串
	s += "w";//在s字符串后追加一个字符
	s += 'ac';//在s字符串这样追加，最终有效字符只有最后一个字符
	cout << s << endl;
	cout << s.c_str() << endl;//以C语言方式打印字符串
////////////////////////////////////////////////////////////////
	//获取file的后缀
	string file1("string.cpp");
	//返回字符'.'后的第一个字符
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;
}
int main()
{
	//String类对象的常见构造
	string s1;//构造空的string类对象s1
	string s2("Hello world");//用C的string来构造对象
	string s3(s2);//拷贝构造
	string s4(5, 'a');//s4中存放5个a
	string s5(s2, 6, 5);//从s2中截取从下标6开始的5个字符
	string s6("Hello world", 5);//截取字符串中的前5个字符
	string s7 = "Hello world";
	cout << s7 << endl;
	////////////////////////////////////////////////////////////////
	//TestString1();
	//TestPushBack();
	//TestString2();
	//TestString3();
	return 0;
}