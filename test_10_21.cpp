#include<iostream>
using namespace std;
//C++��classĬ��Ϊprivate��structĬ��Ϊpublic
//��Ĵ�С�����ݳ�Ա��أ�����Ҫ�����ڴ���룬����ռһ���ֽ�



//���캯��(������Դ��:
//class Test {
//public:
//	//���캯���ص㣨���ã������ʼ����
//	//û�з���ֵ��������������ͬ 
//	//���û���Զ��幹�캯����ϵͳ��Ĭ�ϲ������캯��(�������ֵ��
//	//Test(){
//	//Ĭ�Ϲ��캯��ֻ����һ��Ĭ��ֵ�����������
//	//	cout << "Create Test object" << this << endl;
//	//	data = 1;
//	//}
//	//Test(int d) {
//	//	//���캯����������
//	//	data = d;
//	//}
//	Test(int d = 0) {
//		data = d;
//	}
//	//��������(����������)���ͷ���Դ��
//	//��û���Զ��壬ϵͳ���Լ�������������
//	//�����������ڽ�����ϵͳ���Լ�������������
//	~Test() {
//		cout << "Free Test object:" << this << endl;
//	}
//private:
//	int data;
//};
//int main() {
//	//ע�⣺ʵ��������ʱҪô�����ڸ�ֵ��Ҫô����������Ĭ��ֵ
//	Test t;//ʵ��������ÿ����һ�����󣬵���һ�ι��캯����
//	Test t1(10);//Ҳ����ʹ��Test t1=10;
//	Test t2();// ��ʱ���������ʵ�������󣬱�ʾ����һ������������
//	Test t2;//���캯������t1��t3��˳�����ι��죬����ʱ�����෴��˳������
//	Test t3;//�����캯���к���ȫ�ֱ����;�̬����ʱ������ʱ�ֲ�����̬��ȫ�ֵ�˳��
//    return 0;
//}


//�������캯��(���ڹ��캯����һ�֣�
//class Test 
//{
//public:
//	Test(int data = 0) 
//	{   
//		cout << "Create Test objest:" << this << endl;
//		m_data = data;
//	}
//	//�������캯��
//	Test(const Test &t) //��������ȡ�������������¿��ٿռ���ʵ�θ��βθ�ֵ
//		                //���ô�ֵ��ʽ����������ݹ����
//	{
//		//��const���ó����÷�ֹ�ڲ��ı���������ֵ
//		cout << "Copy create Test objest:" << this << endl;
//		m_data = t.m_data;
//	}
//public:
//	int getData()const 
//	{
//		return m_data;
//	}
//private:
//	int m_data;
//};
//Test func(Test obj) 
//{
//	int value = obj.getData();
//	Test tmp(value);
//	return tmp;//����tmpʱҲ��Ҫ�����������캯��
//	//tmp����������ڵ���ʱ���󣬺�����������Ҫ��������󿽱�
//	//��һ����ʱ����Ŀռ��ڱ���,�����ʼ������������������캯��
//}
//int main() 
//{
//	Test t1(20);
//	Test t2 = t1;//���ö����ʼ������ʱ��ϵͳ���Զ����ÿ������캯��
//	//�����д��ϵͳҲ�����Ĭ�ϵĿ������캯�����������ս�������涨�����ͬ
//	func(t1);//��ʱҲ������������캯����������ʵ��Ϊʵ��������ʱ��
//	return 0;
//}


//�����������
class Test 
{
public:
	Test(int data = 0)
	{
		cout << "Create Test objest:" << this << endl;
		m_data = data;
	}
	Test(const Test& t) 
	{
		cout << "Copy create Test objest:" << this << endl;
		m_data = t.m_data;
	}
	~Test() 
	{
		cout << "Free Test object:" << this << endl;
	}
	//��ֵ���    �Ⱥŵ�����
	//�����������ʵ���壺�����ڽ��ж�ĳ�����ͱ����ڽ�������ʱ������ϣ������ֱ�ӵı��
	//������ͨ�������ĵ���������㣬������������൱�ڸ�������������һ�������ĺ���
	void operator=(Test &t)
	//Test& operator=(const Test &t)
	{
		cout << "Assign" << this << " : " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		//return *this;
	}
private:
	int m_data;
};
int main()
{   
	Test t1(20);
	Test t2;
	t2 = t1;// t2.operater=(t1);ע�⣺��ʱΪ��ֵ��䣬�������������캯��
	return 0;
}


