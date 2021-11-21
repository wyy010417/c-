#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
//1.把字符串转化为整数
//int StrToInt(string str)
//{
//	if (str.size() == 0)
//	{
//		return 0;
//	}
//	int i = 0;
//	int sign = 1;//正数为1，负数为-1
//	if (str[0] == '+' || str[0] == '-')
//	{
//		if (str[0] == '-')
//		{
//			sign = -1;
//		}
//		i++;
//	}
//	int num = 0;
//	while (i < str.size())
//	{
//		if (str[i] < '0' || str[i]>'9')
//		{
//			return 0;
//		}
//		num = num * 10 + str[i]-'0';
//		i++;
//	}
//	return num;
//}
//int main()
//{
//	string str = "123456";
//	cout << StrToInt(str) << endl;
//}

//字符串相加
//int addNum(int a, int b, int& sign)
//{
//	int sum = a + b + sign;
//	if (sum >= 10)
//	{
//		sign = 1;
//		sum -= 10;
//	}
//	else
//		sign = 0;
//	return sum;
//}
//string addStrings(string s1, string s2)
//{
//	reverse(s1.begin(), s1.end());
//	reverse(s2.begin(), s2.end());
//	int i, j;
//	i = j = 0;
//	int sign = 0;
//	int sum = 0;
//	string result;
//	while (i < s1.size() && j < s2.size())
//	{
//		sum = addNum(s1[i]-'0', s2[j]-'0', sign);
//		result.push_back(sum + '0');
//		i++;
//		j++;
//	}
//	while (i < s1.size())
//	{
//		sum = addNum(s1[i]-'0', 0, sign);
//		result.push_back(sum + '0');
//		i++;
//	}
//	while (j < s2.size())
//	{
//		sum = addNum(0, s2[j]-'0', sign);
//		result.push_back(sum + '0');
//		j++;
//	}
//	reverse(result.begin(), result.end());
//	return result;
//}
//int main()
//{
//	string s1 = "2340";
//	string s2 = "1111";
//	cout << addStrings(s1, s2) << endl;
//}


//字符串中的第一个唯一字符
//（1）暴力求解
//int firstUniqChar(string str)
//{
//	int j;
//	for (int i = 0; i < str.size(); i++) 
//	{
//		for (j = 0; j < str.size(); j++)
//		{
//			if (i ==j)
//				continue;
//			if (str[i] == str[j])
//				break;
//		}
//		if (j >= str.size())
//			return i;
//	}
//	return -1;
//}

//（2）哈希法(统计每个字符出现的次数)
//int firstUniqChar(string str)
//{
//	//代表下标0--255
//	int hash[256] = { 0 };
//	for (int i = 0; i < str.size(); i++)
//	{
//		hash[str[i]]++;
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		
//		if (hash[str[i]] == 1)
//		{
//			return i;
//		}
//	}
//	return -1;
//}

//（3）反向查找法
//int firstUniqChar(string str)
//{
//	for (int i = 0; i < str.size(); i++)
//	{
//		int index = str.find(str[i]);
//		int r_index = str.rfind(str[i]);
//		if (index == r_index)
//			return i;
//	}
//	return -1;
//}
//int main()
//{
//	string str = "erferk";
//	cout << firstUniqChar(str) << endl;
//}


//字符串里面最后一个单词的长度
//int GetLengthLastWord(string str)
//{
//	int pos = str.rfind(' ');
//	if (pos == string::npos)
//		return str.size();
//	int length = str.size() - pos - 1;
//	return length;    
//}
//int main()
//{
//	string str;
//	getline(cin, str);
//	cout << GetLengthLastWord(str) << endl;
//}


//验证一个字符串是否为回文
bool IsLetterOrDig(char ch)
{
	return((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}
bool IsPalindrome(string str)
{
	if (str.size() <= 1)
		return true;
	int left = 0;
	int right = str.size() - 1;
	transform(str.begin(), str.end(), str.begin(), toupper);
	while (left < right)
	{
		while (!IsLetterOrDig(str[left]))
			left++;
		while (!IsLetterOrDig(str[right]))
			right++;
		if (str[left] != str[right])
			return false;
		left++;
		right--;
	}
	return true;
}
int main()
{
	string str = "ac,sdl mdSCA";
	cout << IsPalindrome(str) << endl;
}