#include<iostream>
#include<list>
#include<vector>
using namespace std;
//int main()
//{
//	list<int>l1;//构造空的l1
//	list<int>l2(4, 100);//l2中存放4个值为100的元素
//	list<int>l3(l2.begin(), l2.end());//用l2的begin(),end()左闭右开的区间构造l3
//	list<int>l4(l3);//用l3拷贝构造l4
//	//以数组为迭代器区间构造l5
//	int array[] = { 16,2,77,29 };
//	list<int>l5(array, array + sizeof(array) / sizeof(int));
//	//用迭代器方式打印l5中的元素
//	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//c11范围for的方式遍历
//	for (auto& e : l5)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//list iterator 的使用
//void print_list(const list<int> & l)
//{
//	//注意调用的list的begin（）const，返回list的const——iterator对象
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	int array[] = { 0,1,2,3,4,5,6,7,8,9};
//	list<int>l(array, array + sizeof(array) / sizeof(int));
//	//使用正向迭代器正向list的元素
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//使用反向迭代器逆向打印List的元素
//	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	print_list(l);
//	return 0;
//}

//list类的接口
//void PrintList(list<int>& l)
//{
//	for (auto& e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
///////////////////////////////////////////////////////////////
//
////push_back/push_front/pop_back/pop_front
//void TestList1()
//{
//	int array[] = { 1,2,3 };
//	list<int>L(array, array + sizeof(array) / sizeof(int));
//	//在list的尾部插入4，头部插入0
//	L.push_back(4);
//	L.push_front(0);
//	PrintList(L);
//	//删除list尾部节点和头部节点
//	L.pop_back();
//	L.pop_front();
//	PrintList(L);
//}
///////////////////////////////////////////////////////////////////////////////
//
////insert/erase
//void TestList2()
//{
//	int array1[] = { 1,2,3 };
//	list<int>L(array1, array1 + sizeof(array1) / sizeof(int));
//	//获取链表中第二个节点
//	auto pos = ++L.begin();
//	cout << *pos << endl;
//	//在pos前插入值为4的元素
//	L.insert(pos, 4);
//	PrintList(L);
//	//在pos前插入5个值为5的元素
//	L.insert(pos, 5, 5);
//	PrintList(L);
//	//在pos前插入[v.begin(),v.end()]区间的元素
//	vector<int>v{ 7,8,9 };
//	L.insert(pos, v.begin(), v.end());
//	PrintList(L);
//	//删除pos位置的元素
//	L.erase(pos);
//	PrintList(L);
//	//删除list中[beign,end]区间中的元素，即删除list中的所有元素
//	L.erase(L.begin(), L.end());
//	PrintList(L);
//} 
/////////////////////////////////////////////////////////////////
//
////resize/swap/clear
//void TestList3()
//{
//	//用数组来构造list
//	int array1[] = { 1,2,3 };
//	list<int>l1(array1, array1 + sizeof(array1) / sizeof(int));
//	int array2[] = { 4,5,6 };
//	list<int>l2(array2, array2 + sizeof(array2) / sizeof(int));
//	PrintList(l1);
//	PrintList(l2);
//	//交换l1和l2中的元素
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//	//将l2中的元素清空
//	l2.clear();
//	cout <<"size= "<<l2.size() << endl;
//}
//
//
//int main()
//{
//	TestList1();
//	TestList2();
//	TestList3();
//	return 0;
//}

//////////////////////////////////////////////////////////////////

//list的迭代器失效
//void TestListIterator1()
//{
//	int array[] = { 0,1,2,3,4,5,6,7,8,9 };
//	list<int>l(array, array + sizeof(array) / sizeof(int));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		//earse函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it，必须先给其赋值
//		l.erase(it);
//		++it;
//	}
//}
////改正
//void TestListIterator()
//{
//	int array[] = { 0,1,2,3,4,5,6,7,8,9 };
//	list<int>l(array, array + sizeof(array) / sizeof(int));
//	auto it = l.begin();
//	//删除list中的所有元素
//	while (it != l.end())
//	{
//		//erase接口内部实现返回的是删除后的下一个节点
//		l.erase(it++);//it=l.erase(it);
//	}
//}
//int main()
//{
//	TestListIterator();
//	return 0;
//}

///////////////////////////////////////////////////////////

