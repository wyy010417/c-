#include<iostream>
using namespace std;
class Test
{
	friend ostream& operator<<(ostream& out, const Test& d);
public:
	//���캯���������ã�
	//�������   ��ʼ������   ����ת��
	//explicit�ؼ��ֵ���˼Ϊ��ʾ�������˹��캯���޷�������ʽ����ת��
	Test(int data = 0):m_data(data)
	{
		//m_data = data;
	}//��ʼ���б��Ч�ʱȸ���ֵ���Ը�
	~Test()
	{}
public:
	operator int()//����ǿ��ת��������
	{
		return m_data;
	}
private:
	int m_data;
	//int& m_a;//���õĳ�Աֻ��ͨ���б�ĳ�ʼ��
};
ostream& operator<<(ostream& out, const Test& d)
{
	out << d.m_data ;
	return out;
}
void main()
{
	Test dt;
	//dt = 100;//�Ƚ�100ͨ�����캯����Ϊһ����ʱ����Ȼ����������ֵ
	dt = (Test)100;//��ʾת��100
	cout << "dt=" << dt<<endl;
	int value = (int)dt;
	cout << "value=" << value << endl; 
}