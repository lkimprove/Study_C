#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class Date{
	//<< >> ������
	friend ostream& operator<<(ostream& _cout, const Date &d);
	friend istream& operator>>(istream& _cin, Date &d);
private:
	int _year;
	int _month;
	int _day;
public:
	//��ȡÿ���µ�����
	int GetMonthDay(int year, int month);

	//���캯��
	Date(int year = 1900, int month = 1, int day = 1){
		if ((year >= 1900) && (month > 0) && (month < 13) && (day > 0) && (day < GetMonthDay(year, month))){
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "������������" << endl;
		}
	}

	//��������
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//��ֵ��������غ���
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
	//ǰ��++  ++i
	Date& operator++();
	//����++  i++
	Date operator++(int);
	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);
	//- �����������
	int operator-(const Date& d) const;

	//��ӡ
	void Print(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//����
	~Date(){
		//cout << "������������" << endl;
	}
};