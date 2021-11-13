#include<iostream>
using namespace std;
//ģ��ʵ��list
namespace Giggle_List
{
	//List�Ľڵ���
	template<typename _Ty>
	class list
	{
	public:
		//������ȡ
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
			//���˷�������Ϊstatic���ͼ��ɲ���ʵ��������ֱ��ͨ���������÷���
			static _Nodepref _Next(_Nodeptr _P)
			{return _P->_Next;}
			static _Nodepref _Prev(_Nodeptr _P)
			{return _P->_Prev;}
			static _Vref _Value(_Nodeptr _P)
			{return _P->_Value;}
		};
	public:
		//���캯��
		list() :_Head(_Buynode()), _Size(0)
		{}
		//β��
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
			//���ӵ�Narg��Parg����Ĭ��Ϊ��
			//����ڵ㷽���ȿ�������ͷ�ڵ㣬Ҳ�����ڴ˺�������ڵ��ֱ�Ӳ���������
			_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
			_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
			_Acc::_Prev(_S)= _Parg != 0 ? _Parg : _S;
			return _S;
		}
	private:
		//���ݳ�Ա
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