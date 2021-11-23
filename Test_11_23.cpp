//日期累加（注意学习OJ题的格式化输入输出方式）
//#include<iostream>
//using namespace std;
//class Date
//{
//    friend ostream& operator<<(ostream& out, const Date& dt);
//public:
//Date(int year = 2001, int month = 4, int day = 17) :m_year(year), m_month(month), m_day(day)
//{}
//~Date()
//{}
//public:
//    Date operator+(int n)
//    {
//        int year = m_year;
//        int month = m_month;
//        int day = m_day;
//        int days = GetDayByMonthYear(year, month);
//        while (day + n > days)
//        {
//            month++;
//            if (month > 12)
//            {
//                month = 1;
//                year++;
//            }
//            n -= days;
//            days = GetDayByMonthYear(year, month);
//        }
//        day += n;
//        return Date(year, month, day);
//    }
    /*int GetDayByMonthYear(int year, int month)
    {
        int days[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2)
        {
            if (IsLeap(year))
                month = 0;
        }
        return days[month];
    }*/
    //bool IsLeap(int year)
    //{
    //    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    //    {
    //        return true;
    //    }
    //    return false;
    //}
//private:
//    int m_year;
//    int m_month;
//    int m_day;
//};
//ostream& operator<<(ostream& out, const Date& dt)
//{
//    if (dt.m_month < 10 && dt.m_day < 10)
//    {
//        out << dt.m_year << '-' << 0 << dt.m_month << '-' << 0 << dt.m_day;
//    }
//    else if (dt.m_month >= 10 && dt.m_day < 10)
//    {
//        out << dt.m_year << '-' << dt.m_month << '-' << 0 << dt.m_day;
//    }
//    else if (dt.m_month < 10 && dt.m_day >= 10)
//    {
//        out << dt.m_year << '-' << 0 << dt.m_month << '-' << dt.m_day;
//    }
//    else
//        out << dt.m_year << '-' << dt.m_month << '-' << dt.m_day;
//    return out;
//}
//int main()
//{
//    int count = 0;
//    int year, month, day;
//    year = month = day = 0;
//    int n = 0;
//    cin >> count;
//    for (int i = 0; i < count; i++)
//    {
//        cin >> year >> month >> day >> n;
//        Date dt(year, month, day);
//        Date result = dt + n;
//        cout << result << endl;
//    }
//    return 0;
//}


//给出年分m和一年中的第n天，算出第n天是几月几号
//#include<iostream>
//using namespace std;
//class Date
//{
//    friend ostream& operator<<(ostream& out, const Date& dt);
//public:
//    Date(int year = 2001, int month = 4, int day = 17) :m_year(year), m_month(month), m_day(day)
//    {}
//    ~Date()
//    {}
//public:
//    Date GetDate(int year, int n)
//    {
//        int month = 1;
//        int day = 0;
//        int days = GetDayByMonth(year, month);
//        while (n > days)
//        {
//            ++month;
//            n -= days;
//            days = GetDayByMonth(year, month);
//        }
//        day = n;
//        return Date(year, month, day);
//    }
//    int GetDayByMonth(int year, int month)
//    {
//        int days[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if (month == 2)
//        {
//            if (IsLeap(year))
//                month = 0;
//        }
//        return days[month];
//    }
//    bool IsLeap(int year)
//    {
//        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//private:
//    int m_year;
//    int m_month;
//    int m_day;
//};
//ostream& operator<<(ostream& out, const Date& dt)
//{
//    if (dt.m_month < 10 && dt.m_day < 10)
//    {
//        out << dt.m_year << '-' << 0 << dt.m_month << '-' << 0 << dt.m_day;
//    }
//    else if (dt.m_month >= 10 && dt.m_day < 10)
//    {
//        out << dt.m_year << '-' << dt.m_month << '-' << 0 << dt.m_day;
//    }
//    else if (dt.m_month < 10 && dt.m_day >= 10)
//    {
//        out << dt.m_year << '-' << 0 << dt.m_month << '-' << dt.m_day;
//    }
//    else
//        out << dt.m_year << '-' << dt.m_month << '-' << dt.m_day;
//    return out;
//}
//int main()
//{
//    int year, days;
//    year = days = 0;
//    while (cin >> year >> days)
//    {
//        Date dt;
//        Date result;
//        result = dt.GetDate(year, days);
//        cout << result << endl;
//    }
//    return 0;
//}

//