#include<iostream>
#include<assert.h>
using namespace std;
//new������������
void* operator new(size_t sz)
{// ����ֵ���ͱ�����void*
 //�����������޷�������
	void* pt = malloc(sz);
	return pt;
}
void operator delete(void* pt)
{
	free(pt);
}
//��λnew������
void* operator new(size_t sz, int* ptr, int pos)
{
	//����new��λ�����ɵı����ڴ�ռ��еľ���λ��
	return &ptr[pos];
}
class Test
{
public:
	Test(int data = 0)
	{}
	~Test()
	{}
private:
	int m_data;
};
void main()
{
	//operator newֻ��������ռ䣬������������췽��
	Test* pt = new Test;//new operator(new ��������
	//������ڲ�Ҳ������new�����������������ڲ������ط���
	delete pt;
	Test* pt1 = (Test*)operator new(sizeof(Test));
	/*int* ptr = (int*)malloc(sizeof(int) * 10);
	assert(ptr != NULL);*/
	int ptr[10];
	//��ʱnew�����Ὺ�ٿռ䣬���������пռ��а�һ������������ȥ
	new(ptr,2)int(1);//��λnew
	new(ptr)int(0);//����ʡ��λ��Ĭ��Ϊ��һ���ռ�
}