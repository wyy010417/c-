#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
void main()
{
	vector<int> iv = { 1,3,5,2,7,4,8 };
	for (const auto& e : iv)
		cout << e << " ";
	cout<< endl;
	//make_heap() �����ѽṹ
	//push_heap()�����ѽṹ
	make_heap(iv.begin(), iv.end());
	for (const auto& e : iv)
		cout << e << " ";
	cout << endl;
	iv.push_back(10);
	push_heap(iv.begin(), iv.end());
	for (const auto& e : iv)
		cout << e << " ";
	cout << endl;
	/*auto it = iv.end();
	for (int i = 0; i < iv.size(); i++)
	{
		pop_heap(iv.begin(), it--);
	}
	for (const auto& e : iv)
		cout << e << " ";
	cout << endl;*/
	sort_heap(iv.begin(), iv.end());
	for (const auto& e : iv)
		cout << e << " ";
	cout << endl;
}
//void main()
//{
//	/*stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.size() << endl;
//	cout << "top=" << st.top() << endl;*/
//	//ͨ��grearer�����ΪС��
//	priority_queue<int,vector<int>,greater<int>> pq;
//	pq.push(1);
//	pq.push(3);
//	pq.push(5);
//	pq.push(7);
//	pq.push(2);
//	pq.push(4);
//	//���ȼ�Ĭ�������Ϊ���
//	while (!pq.empty())
//	{
//		cout << pq.top() <<" ";
//		pq.pop();
//	}
//	cout << endl;
//}