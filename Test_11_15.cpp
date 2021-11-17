#include<iostream>
#include<string>
using namespace std;
//string��ӿ�
void TestString1()
{
	string s1("abcdefg");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
/////////////////////////////////////////
     //��s1����Ч�ַ����ӵ�10�������λ����"a"���
	s1.resize(10, 'a');
	//��s1�е���Ч�ַ����ӵ�15��,���λ����'\0'���
	s1.resize(15);
	s1.resize(5);
	cout << s1 << endl;
/////////////////////////////////////////
	//����reserve��߲������ݵ�Ч��,�������ݴ����Ŀ���
	s1.reserve(50);
	cout << s1.capacity() << endl;
	//��reserve����С��string�ײ�ռ��Сʱ���ռ䲻���ٴ���С
	s1.reserve(25);
	cout << s1.capacity() << endl;
	s1.reserve(1000);
	cout << s1.capacity() << endl;
	//clear�����Ч�ַ������ı�ײ�ռ�Ĵ�С
	s1.clear();
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}
//reserve
void TestPushBack()
{
	//reserve��ĵײ�ռ������������Դ�һ�㣬����������ײ�ռ��Сʱ��ϵͳ���Զ���������
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
//string ��ķ��ʼ���������
void TestString2()
{
	string s1("Hello world");
	//const���Ͷ������޸�
	const string s2("Hello world");
///////////////////////////////////////////////////
	//3�ֱ�����ʽ
	//1.for+operator[](c��ʽ)
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cout << endl;
	//2.������
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	//3.����ָ��auto
	for (auto& s : s1)
		cout << s ;
	cout << endl;
////////////////////////////////////////////////
//���ص�����ָ���ֵ��Ҫ������back
	s1.begin();
	s1.end();
	cout << s1.back() << endl;
	cout << s1.front()<< endl;
	//rbegin ��rendֻ����reverse_iterator����ʹ��,��ֻ���������
	for (string::reverse_iterator rit = s1.rbegin(); rit < s1.rend();++rit)
		cout << *rit ;
	cout << endl;
}
//string�������޸Ĳ���
void TestString3()
{
	string s;
	s.push_back('!');//���ַ���s�����һ����
	s.append("lalala");//��s�ַ�����׷��һ���ַ���
	s += "w";//��s�ַ�����׷��һ���ַ�
	s += 'ac';//��s�ַ�������׷�ӣ�������Ч�ַ�ֻ�����һ���ַ�
	cout << s << endl;
	cout << s.c_str() << endl;//��C���Է�ʽ��ӡ�ַ���
////////////////////////////////////////////////////////////////
	//��ȡfile�ĺ�׺
	string file1("string.cpp");
	//�����ַ�'.'��ĵ�һ���ַ�
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;
}
int main()
{
	//String�����ĳ�������
	string s1;//����յ�string�����s1
	string s2("Hello world");//��C��string���������
	string s3(s2);//��������
	string s4(5, 'a');//s4�д��5��a
	string s5(s2, 6, 5);//��s2�н�ȡ���±�6��ʼ��5���ַ�
	string s6("Hello world", 5);//��ȡ�ַ����е�ǰ5���ַ�
	string s7 = "Hello world";
	cout << s7 << endl;
	////////////////////////////////////////////////////////////////
	//TestString1();
	//TestPushBack();
	//TestString2();
	//TestString3();
	return 0;
}