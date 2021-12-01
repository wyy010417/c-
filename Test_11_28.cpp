#include<iostream>
#include<assert.h>
using namespace std;
namespace giggle 
{
	template<typename _Ty>
	class vector
	{
	public:
		typedef _Ty*         iterator;
		typedef const _Ty*   const_iterator;
		typedef size_t size_type;
	public:
		//构造函数
		vector():_start(nullptr),_finish(nullptr),_end_of_storage(nullptr)
		{}
		//构造n个相同的值
		vector(int n, const _Ty& value = _Ty())
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		//区间构造
		vector(const_iterator _first, const_iterator _last)
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			reserve(_last - _first);
			while (_first != _last)
			{
				push_back(*_first++);
			} 
		}
		//拷贝构造
		_Ty& operator[](size_t pos)
		{
			return _start[pos];
		}
		vector( vector<_Ty>& v)
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (int i = 0; i < v.size(); ++i)
				_start[i] = v[i];
			_finish = _start + v.size();
		}
		//赋值语句
		vector<_Ty>& operator=(vector<_Ty>& v)
		{
			if (this != &v)
			{
				vector<_Ty> tmp = v;
				swap(tmp);
			}
			return *this;
		}
		//析构函数
		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
	
	public:
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		bool empty()
		{
			return size() == 0;
		}
	public:
		iterator begin()const
		{
			return _start;
		}
		iterator end()const
		{
			return _finish;
		}
	public:
		iterator insert(iterator pos, const _Ty& x)
		{
			//先判断是否需要扩容
			if (_finish == _end_of_storage)
			{
				size_t old_n = pos - _start;
				size_t new_sz = capacity() == 0 ? 1 : 2 * capacity();
				reserve(new_sz);
				//重点：扩容后迭代器会失效，一定要重新设置
				pos = _start +old_n;
			}
			//移动要插入的位置后面的数据
			iterator cur = end();
			while (cur != pos)
			{
				*cur = *(cur - 1);
				cur--;
			}
			//此时的位置就是要插入数据的位置
			*cur = x;
			_finish++;
			return cur;
		}
		void push_back(const _Ty& x)
		{
			insert(end(), x);
		}
		void pop_back()
		{
			erase(end() - 1);
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator cur = pos;
			while (pos < _finish)
			{
				*pos = *(pos + 1);
				pos++;
			}
			_finish--;
			return cur;
		}
		void swap(vector& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish,v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		void resize(size_t n, const _Ty& value = _Ty())
		{
			//缩容情况
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			//若扩容大小比容量大，先扩容，再填充值
			if (n > capacity())
			{
				reserve(n);
			}
			size_t offset = n - size();
			while (offset--)
			{
				*_finish++ = value;
			}
		}
		void reserve(size_type n)
		{
			if (n > capacity())
			{
				size_t old_sz = size();
				_Ty* new_start = new _Ty[n];//开辟空间并进行初始化
				memcpy(new_start, _start,sizeof(_Ty)*old_sz);
				delete[]_start;
				_start = new_start;
				_finish = _start + old_sz;
				_end_of_storage = _start + n;
			}
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

}
int main()
{
	//giggle::vector<int> iv(10,3); 
	int arr[] = { 1,2,3,4,5 };
	giggle::vector<int> iv(arr, arr + 5);
	cout << iv.size() << endl;
	cout << iv.capacity() << endl;
	giggle::vector<int> iv1;
	iv1 = iv;
	iv1.resize(10,2);
	//iv.insert(iv.begin(), 1);
	/*iv.push_back(3);
	iv.push_back(2);
	iv.push_back(1);*/
	//iv.erase(iv.begin());
	//iv.pop_back();
	giggle::vector<int>::iterator it = iv1.begin();
	
	while (it != iv1.end())
	{
		cout << *it <<" ";
		it++;
	}
	cout << endl;
}