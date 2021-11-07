#include<iostream>
using namespace std;
template<typename Type>
class SeqList
{
public:
	SeqList(size_t sz)
	{
		capacity = sz;
		base = new Type[capacity];
		size = 0;
	}
	~SeqList()
	{
		delete []base;
		base = nullptr;
		size = capacity = 0;
	}
public:
	void pushBack(Type x)
	{
		base[size++] = x;
	}
	void show()const
	{
		for (int i = 0; i < size; ++i)
			cout << base[i] <<" ";
		cout << endl;
	}
private:
	Type* base;
	size_t capacity;
	size_t size;
};
void main()
{
	SeqList<int> list(10);
	for (int i = 1; i <= 10; i++)
	{
		list.pushBack(i);
	}
	list.show();
	SeqList<char>list1(10);
	for (int i = 0; i < 10; i++)
	{
		list1.pushBack('a' + i);
	}
	list1.show();
}