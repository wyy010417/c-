#include<iostream>
using namespace std;
//日期类
class Date
{
	friend ostream& operator<<(ostream &out, const Date& d);
public:
	Date(int year = 2001, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	Date(const Date& d)
	{
		m_year = d.m_year;
		m_month = d.m_month;
		m_day = d.m_day;
	}
	~Date()
	{}
//运算符的重载
public:
	bool operator>(const Date& d)
	{
		if (m_year > d.m_year 
			|| (m_year == d.m_year && m_month > d.m_month)
			|| (m_year == d.m_year && m_month == d.m_month && m_day > d.m_day))
			return true;
		return false;
	}
	bool operator<=(const Date& d)
	{
		return !(this > &d);
	}
	bool operator<(const Date& d)
	{
		if (m_year < d.m_year
			|| (m_year == d.m_year && m_month < d.m_month)
			|| (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day))
			return true;
		return false;
	}
	bool operator>=(const Date& d)
	{
		return !(this < &d);
	}
	bool operator==(const Date& d)
	{
		if (m_year == d.m_year && m_month == d.m_month && m_day == d.m_day)
			return true;
		return false;
	}
	bool operator!=(const Date &d)
	{
		return !(*this == d);
	}
public:
	Date operator+(int n)//日期+n天
	{
		int year = m_year;
		int month = m_month;
		int day = m_day;
		int days = GetDaysByYearMonth(year, month);
		while (day + n > days)
		{
			month++;
			if (month > 12)
			{
				year++;
				month = 1;
			}
			n -= days;
			days = GetDaysByYearMonth(year, month);
		}
		day += n;
		return Date(year, month, day);
	}
	Date& operator+=(int n)
	{
		int days = GetDaysByYearMonth(m_year, m_month);
		while (m_day + n > days)
		{
			m_month++;
			if (m_month > 12)
			{
				m_year++;
				m_month = 1;
			}
			n -= days;
			days = GetDaysByYearMonth(m_year, m_month);
		}
		m_day += n;
		return *this;
	}
	Date operator-(int n)//日期-n天
	{
		int year = m_year;
		int month = m_month;
		int day = m_day;
		int days = GetDaysByYearMonth(year, month);
		while ( n > days)
		{
			month--;
			if (month == 1)
			{
				year--;
				month = 12;
			}
			n -= days;
			days = GetDaysByYearMonth(year, month);
		}
	}
	int operator-(const Date& dt)
	{
		if (*this < dt)
		{
			return;
		}
		int count = 0;
		int year = m_year;
		int month = m_month;
		int day = m_day;
		if (day >= dt.m_day)
		{
			count = day - m_day;
		}
		else
		{
			int days = GetDaysByYearMonth(year, month);
			count = days + day - m_day;
			if (month == 1)
			{
				month = 12;
				year--;
			}
			month--;
		}
		if (month >= dt.m_month)
		{
			while (month >= dt.m_month)
			{
				int days = GetDaysByYearMonth(year, month);
				count += days;
				month--;
			}
		else
		{
			month = 12;
			year--;
		}
		}
		
		if (year > dt.m_year)
		{
			tmp.m_year = year - dt.m_year;
		}
	}
public:
	//获取某一年某一月的天数
	bool IsLeap(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0)||year % 400 == 0)
			return true;
		return false;
	}
	/*int GetDayByYearMonth(int year, int month)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12)
			return 31;
		else if (month == 2)
		{
			if (IsLeap(year))
				return 29;
			return 28;
		}
		return 30;
	}*/
	int GetDaysByYearMonth(int year, int month)
	{
		int days[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2)
		{
			if (IsLeap(year))
				month = 0;
		}
		return days[month];
	}
private:
	int m_year;
	int m_month;
	int m_day;
};
ostream& operator<<(ostream &out, const Date& d)
{
	out << d.m_year << "年" << d.m_month << "月" << d.m_day << "日" << endl;
	return out;
}
/////////////////////////////////////////////////////
void main()
{
	Date dt(2021,10,24);
	cout << "dt = " << dt;
	//Date dt1 = dt;
	//cout << "dt1 = " << dt1 << endl;
	Date dt2 = dt - 100;
	cout << "dt2 = " << dt2 << endl;
	//dt1 += 100;
	//cout << "dt = " << dt << endl;
}