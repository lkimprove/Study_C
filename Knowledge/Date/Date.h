#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class Date{
	//<< >> 的重载
	friend ostream& operator<<(ostream& _cout, const Date &d);
	friend istream& operator>>(istream& _cin, Date &d);
private:
	int _year;
	int _month;
	int _day;
public:
	//获取每个月的天数
	int GetMonthDay(int year, int month);

	//构造函数
	Date(int year = 1900, int month = 1, int day = 1){
		if ((year >= 1900) && (month > 0) && (month < 13) && (day > 0) && (day < GetMonthDay(year, month))){
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "输入的年份有误" << endl;
		}
	}

	//拷贝构造
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//赋值运算符重载函数
	Date& operator=(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
		
		return *this;
	}

	//<
	bool operator<(const Date& d) const;
	//>
	bool operator>(const Date& d)const;
	//==
	bool operator==(const Date& d)const;
	//!= 
	bool operator!=(const Date& d)const;
	//>=
	bool operator>=(const Date& d)const;
	//<=
	bool operator<=(const Date& d)const;


	//+=
	Date& operator+=(int days);
	//-=
	Date& operator-=(int days);
	//+
	Date operator+(int days) const;
	//-
	Date operator-(int days) const;
	//前置++  ++i
	Date& operator++();
	//后置++  i++
	Date operator++(int);
	//前置--
	Date& operator--();
	//后置--
	Date operator--(int);
	//- （日期相减）
	int operator-(const Date& d) const;

	//打印
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//析构
	~Date(){
		//cout << "调用析构函数" << endl;
	}
};
