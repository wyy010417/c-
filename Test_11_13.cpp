#include<iostream>
using namespace std;
//模拟实现list
namespace Giggle_List
{
	//List的节点类
	template<typename _Ty>
	class list
	{
	public:
		//类型萃取
		typedef size_t      size_type;
		typedef _Ty         value_type;
		typedef _Ty*        pointer_type;
		typedef _Ty&        reference_type;
		typedef const _Ty*  const_pointer_type;
		typedef const _Ty&  const_refernce_type;
	public:
		struct _Node;
		typedef struct _Node* _Nodeptr;
		struct _Node
		{
			_Nodeptr _Next;
			_Nodeptr _Prev;
			_Ty      _Value;
		};
		struct _Acc
		{
			typedef _Nodeptr& _Nodepref;
			typedef _Ty&       _Vref;
			//将此方法定义为static类型即可不用实例化对象直接通过类名调用方法
			static _Nodepref _Next(_Nodeptr _P)
			{return _P->_Next;}
			static _Nodepref _Prev(_Nodeptr _P)
			{return _P->_Prev;}
			static _Vref _Value(_Nodeptr _P)
			{return _P->_Value;}
		};
	public:
		//构造函数
		list() :_Head(_Buynode()), _Size(0)
		{}
		//尾插
		void push_back(const _Ty& _X)
		{
			_Nodeptr _S=_Buynode(_Head,_Acc::_Prev(_Head));
			_Acc::_Value(_S)= _X;
			_Acc::_Next(_Acc::_Prev(_S)) = _S;
			_Acc::_Prev(_Acc::_Next(_S)) =_S;
			_Size++;
		}
	protected:
		_Nodeptr _Buynode(_Nodeptr _Narg=0,_Nodeptr _Parg=0)
		{
			//增加的Narg和Parg参数默认为空
			//申请节点方法既可以申请头节点，也可以在此后申请完节点后直接插入链表中
			_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
			_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
			_Acc::_Prev(_S)= _Parg != 0 ? _Parg : _S;
			return _S;
		}
	private:
		//数据成员
		_Nodeptr _Head;   //_Node* _Head;
		size_type _Size;  //size_t _Size;
	};
}
int main()
{
	Giggle_List::list<int>l1;
	for (int i = 1; i <= 10; i++)
	{
		l1.push_back(i);
	}
	return 0;
}