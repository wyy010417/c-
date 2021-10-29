#include<iostream>
using namespace std;
//友元类
//class ListNode
//{
//	friend class List;//List类是ListNode的友元类，是为了直接访问ListNode的非公有成员
//    //友元关系不是双向的，ListNode不能访问List内部非公有成员
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
//	List():m_head(nullptr)//无头节点单链表
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



//内部类
class Test
{
	//在一个内内部（public,private,protected均可）再定义一个类
public:
	//内部类是外部类的友元，外部类不是内部类的友元
	class iterator
	{
	public:
		void show()const
		{
			cout << "Test::iterator::show" << endl;
			Test t;
			t.m_a = 10;//内部类可以实例化外部类对象，并操作其私有成员
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