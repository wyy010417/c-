#include<iostream>
#include<list>
#include<vector>
using namespace std;
//int main()
//{
//	list<int>l1;//����յ�l1
//	list<int>l2(4, 100);//l2�д��4��ֵΪ100��Ԫ��
//	list<int>l3(l2.begin(), l2.end());//��l2��begin(),end()����ҿ������乹��l3
//	list<int>l4(l3);//��l3��������l4
//	//������Ϊ���������乹��l5
//	int array[] = { 16,2,77,29 };
//	list<int>l5(array, array + sizeof(array) / sizeof(int));
//	//�õ�������ʽ��ӡl5�е�Ԫ��
//	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//c11��Χfor�ķ�ʽ����
//	for (auto& e : l5)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//list iterator ��ʹ��
//void print_list(const list<int> & l)
//{
//	//ע����õ�list��begin����const������list��const����iterator����
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
//	//ʹ���������������list��Ԫ��
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//ʹ�÷�������������ӡList��Ԫ��
//	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	print_list(l);
//	return 0;
//}

//list��Ľӿ�
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
//	//��list��β������4��ͷ������0
//	L.push_back(4);
//	L.push_front(0);
//	PrintList(L);
//	//ɾ��listβ���ڵ��ͷ���ڵ�
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
//	//��ȡ�����еڶ����ڵ�
//	auto pos = ++L.begin();
//	cout << *pos << endl;
//	//��posǰ����ֵΪ4��Ԫ��
//	L.insert(pos, 4);
//	PrintList(L);
//	//��posǰ����5��ֵΪ5��Ԫ��
//	L.insert(pos, 5, 5);
//	PrintList(L);
//	//��posǰ����[v.begin(),v.end()]�����Ԫ��
//	vector<int>v{ 7,8,9 };
//	L.insert(pos, v.begin(), v.end());
//	PrintList(L);
//	//ɾ��posλ�õ�Ԫ��
//	L.erase(pos);
//	PrintList(L);
//	//ɾ��list��[beign,end]�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
//	L.erase(L.begin(), L.end());
//	PrintList(L);
//} 
/////////////////////////////////////////////////////////////////
//
////resize/swap/clear
//void TestList3()
//{
//	//������������list
//	int array1[] = { 1,2,3 };
//	list<int>l1(array1, array1 + sizeof(array1) / sizeof(int));
//	int array2[] = { 4,5,6 };
//	list<int>l2(array2, array2 + sizeof(array2) / sizeof(int));
//	PrintList(l1);
//	PrintList(l2);
//	//����l1��l2�е�Ԫ��
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//	//��l2�е�Ԫ�����
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

//list�ĵ�����ʧЧ
//void TestListIterator1()
//{
//	int array[] = { 0,1,2,3,4,5,6,7,8,9 };
//	list<int>l(array, array + sizeof(array) / sizeof(int));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		//earse����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��it�������ȸ��丳ֵ
//		l.erase(it);
//		++it;
//	}
//}
////����
//void TestListIterator()
//{
//	int array[] = { 0,1,2,3,4,5,6,7,8,9 };
//	list<int>l(array, array + sizeof(array) / sizeof(int));
//	auto it = l.begin();
//	//ɾ��list�е�����Ԫ��
//	while (it != l.end())
//	{
//		//erase�ӿ��ڲ�ʵ�ַ��ص���ɾ�������һ���ڵ�
//		l.erase(it++);//it=l.erase(it);
//	}
//}
//int main()
//{
//	TestListIterator();
//	return 0;
//}

///////////////////////////////////////////////////////////

