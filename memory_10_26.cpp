#include<iostream>
using namespace std;
//��Ԫ��
//class ListNode
//{
//	friend class List;//List����ListNode����Ԫ�࣬��Ϊ��ֱ�ӷ���ListNode�ķǹ��г�Ա
//    //��Ԫ��ϵ����˫��ģ�ListNode���ܷ���List�ڲ��ǹ��г�Ա
//public:
//	ListNode():m_data(0),m_next(nullptr)
//	{}
//	~ListNode()
//	{}
//private:
//	int m_data;
//	ListNode* m_next;
//};
//class List
//{
//public:
//	List():m_head(nullptr)//��ͷ�ڵ㵥����
//	{}
//	~List()
//	{}
//private:
//	ListNode* m_head;
//public:
//	void push_front(int v)
//	{
//		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
//		s->m_data = v;
//		s->m_next = nullptr;
//		s->m_next = m_head;
//		m_head = s;
//	}
//	void show()const
//	{
//		ListNode* p = m_head;
//		while (p != nullptr)
//		{
//			cout << p->m_data << "-->";
//			p = p->m_next;
//		}
//		cout << "over!" << endl;
//	}
//};
//void main()
//{
//	List mylist;
//	for (int i = 1; i <= 10; i++)
//	{
//		mylist.push_front(i);
//	}
//	mylist.show();
//}



//�ڲ���
class Test
{
	//��һ�����ڲ���public,private,protected���ɣ��ٶ���һ����
public:
	//�ڲ������ⲿ�����Ԫ���ⲿ�಻���ڲ������Ԫ
	class iterator
	{
	public:
		void show()const
		{
			cout << "Test::iterator::show" << endl;
			Test t;
			t.m_a = 10;//�ڲ������ʵ�����ⲿ����󣬲�������˽�г�Ա
		}
	private:
		int m_c=0;
	};
private:
	int m_a=0;
	int m_b = 0;
};
void main()
{
	Test::iterator it;
	it.show();
	cout << sizeof(Test) << endl;
}