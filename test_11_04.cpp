#include<iostream>
using namespace std;
//模板是泛型编程的基础
//模板就是将类型参数化的一个过程
//template<typename Type>
////template<class Type>
//void Swap(Type& a, Type& b)
//{
//	cout << typeid(Type).name() << endl;
//	Type tmp = a;
//	a = b;
//	b = tmp;
//}
//void main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	double d1 = 1.2;
//	double d2 = 2.3;
//	Swap(d1, d2);
//	char c1 = 'a';
//	char c2 = 'd';
//	Swap(c1, c2);
//}
template<typename Type>
Type Sum(Type a, Type b)
{
	cout << typeid(Type).name() << endl;
	return a + b;
}
void main()
{
	cout << Sum(1, 2) << endl;
	cout << Sum('A', 'B') << endl;
	cout << Sum(2, 2.4) << endl;
}