#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> iv;
	vector<int> iv1(10,2);
	for (const auto& e : iv)
		cout << e << " ";
	cout << endl;
	vector<int>::iterator it = iv1.begin();
	while (it != iv1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	auto it1 = iv1.begin();
	while (it1 != iv1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	for (int i = 0; i < iv1.size(); i++)
		cout << iv1[i] << " ";
	cout << endl;
	//at会对越界进行检查，[]不会
	for (int i = 0; i < iv1.size(); i++)
		cout << iv1.at(i) << " ";
	cout << endl;
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> iv2(arr, arr + n);
	for (int i = 0; i < iv2.size(); i++)
		cout << iv2.at(i) << " ";
	cout << endl;
	cout << iv2.size() << endl;
	cout << iv2.capacity() << endl;
	//当空间不足时，push_back可以自动扩充空间容量(vs中自动增加到1.5倍，g++中增加到2倍)
	//尾插
	iv2.push_back(10);
	iv2.push_back(11);
	iv2.push_back(12);
	cout << iv2.capacity() << endl;
	iv2.reserve(100);
	cout << iv2.capacity() << endl;
	//使用反向迭代器进行遍历打印
	vector<int>::reverse_iterator rit = iv2.rbegin();
	while (rit != iv2.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	//尾删
	iv2.pop_back();
	iv2.pop_back();
	for (int i = 0; i < iv2.size(); i++)
		cout << iv2.at(i) << " ";
	cout << endl;
	//find/erase/insert
	vector<int>::iterator pos = find(iv2.begin(), iv2.end(), 3);
	cout << *pos << endl;
	//在3的前面插入一个40
	iv2.insert(pos, 40);
	for (int i = 0; i < iv2.size(); i++)
		cout << iv2.at(i) << " ";
	cout << endl;
	vector<int>::iterator pos1 = find(iv2.begin(), iv2.end(), 40);
	iv2.erase(pos1);
	for (int i = 0; i < iv2.size(); i++)
		cout << iv2.at(i) << " ";
	cout << endl;
	int a[] = { 1,1,2,3 };
	vector<int> iv3(a, a + sizeof(a) / sizeof(a[0]));
	//通过[]来读写第0个位置
	iv3[0] = 0;
	cout << iv3[0] << endl;
	//swap交换数据
	vector<int> swapiv3;
	swapiv3.swap(iv3);
	cout << "iv3.data:";
	for (int i = 0; i < iv3.size(); i++)
		cout << iv3.at(i) << " ";
	cout << endl;
	cout << "swapiv3.data:";
	for (int i = 0; i < swapiv3.size(); i++)
		cout << swapiv3.at(i) << " ";
	cout << endl;
	return 0;
}