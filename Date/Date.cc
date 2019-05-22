#include "Date.h"

//ÿ���µ�����
int Date::GetMonthDay(int year, int month){
	//��һ����̬�������齫ÿ���µ�������������
	static int month_day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//�ж϶����Ƿ�Ϊ 29 ��
	if (month == 2){
		//�ж��Ƿ�Ϊ����
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
			return 29;
		}
	}
	return month_day[month];
}

//>
bool Date::operator>(const Date& d) const{
	if (_year > d._year){
		return true;
	}
	else if (_year == d._year){
		if (_month > d._month){
			return true;
		}
		else if (_day > d._day){
			return true;
		}
	}

	return false;
}

//==
bool Date::operator==(const Date& d) const{
	if ((_year == d._year) && (_month == d._month) && (_day == d._day)){
		return true;
	}
	return false;
}

//<
bool Date::operator<(const Date& d) const{
	return !((*this == d) || (*this > d));
}


//>=
bool Date::operator>=(const Date& d) const{
	return !(*this < d);
}

//<=
bool Date::operator<=(const Date& d)const{
	return !(*this > d);
}

//!=
bool Date::operator!=(const Date& d)const {
	return !(*this == d);
}

//+=
Date& Date::operator+=(int days) {
	//��� days Ϊ����
	if (days < 0){
		*this -= (-days);
		return *this;
	}
	//���������� _day ��
	_day += days;
	//�ж����Ƿ���Ҫ��λ
	while (_day > GetMonthDay(_year, _month)){
		_day -= GetMonthDay(_year, _month);
		//�ж����Ƿ���Ҫ��λ
		if (_month == 12){
			_month = 1;
			_year++;
		}
		else{
			_month++;
		}
	}
	return *this;
}

//-=
Date& Date::operator-=(int days){
	//��� days Ϊ����
	if (days < 0){
		*this += (-days);
		return *this;
	}
	//���������� _day ��
	_day -= days;
	//�ж����Ƿ���Ҫ��λ
	while (_day <= 0){
		//�ж����Ƿ���Ҫ��λ
		if (_month == 1){
			_month = 12;
			_year--;
		}
		else{
			_month--;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

//+
Date Date::operator+(int days) const{
	Date ret(*this);
	ret += days;

	return ret;
}

//-
Date Date::operator-(int days) const{
	Date ret(*this);
	ret -= days;

	return ret;
}

//ǰ��++
Date& Date::operator++(){
	*this += 1;

	return *this;
}

//����++
Date Date::operator++(int){
	Date ret(*this);
	*this += 1;

	return ret;
}

//ǰ��--
Date& Date::operator--(){
	*this -= 1;

	return *this;
}

//����--
Date Date::operator--(int){
	Date ret(*this);
	*this -= 1;

	return ret;
}

//- (���ڼ�������)
int Date::operator-(const Date& d) const{
	//ȷ����������С����
	Date max_date(*this);
	Date min_date(d);
	int flag = 1;
	if (*this < d){
		max_date = d;
		min_date = *this;
		flag = -1;
	}
	int days = 0;
	while (max_date > min_date){
		days++;
		min_date++;
	}
	return days * flag;
}


ostream& operator<<(ostream& _cout, const Date& d){
	_cout << d._year << "-";
	_cout << d._month << "-";
	_cout << d._day;
	_cout << endl;

	return _cout;
}

istream& operator>>(istream& _cin, Date& d){
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;

	return _cin;
}

