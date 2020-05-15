// ������������ ���� ������ ����

#ifndef DATE
#define DATE

#include <iostream>
using std::cout; using std::cin; using std::endl;

void enter_date(unsigned short& year, unsigned short& month, unsigned short& day);

// ����� "����"
class Date
{
public:
	enum Months { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
private:
	unsigned short year;
	Months month;
	unsigned short day;

public:
	Date() {} // ����������� �� ��������� ����� ��� ������������� ����� ������ � ������ ������

	// ����������� � ����������� ���, ������ � ����
	Date(const unsigned short d, const Months m, const unsigned short y) : day(d), month(m), year(y)
	{}

	// ����������� ������������� ������� ������ ���� � ������� ��.��.����
	friend std::ostream& operator<<(std::ostream& out, const Date& date)
	{
		if (date.day < 10)
			out << "0" << date.day << ".";
		else out << date.day << ".";

		if (date.month < 10)
			out << "0" << date.month << ".";
		else out << date.month << ".";

		out << date.year;

		return out;
	}

	// ����������� (����� ��� ���� ��������) ������� �������� ������� ���� � ���������������� �����������
	static Date create_date()
	{
		unsigned short year{ 2019 };
		unsigned short month{ 01 };
		unsigned short day{ 01 };

		enter_date(day, month, year);
		return Date(day, static_cast<Months>(month), year);
	}
};

// ������� ������� � ������������ ����, ���������� �����, �����, ��� �� ������
void enter_date(unsigned short& day, unsigned short& month, unsigned short& year)
{
	cout << "������� �������� ���� ������ � ������� �� �� ����: ";
	// ������� ����� ������, ��� ��� ���������� ������ ������� ��.��.���� � ����, �����, ��� ��������� ������

	cin >> day;
	cin >> month;
	cin >> year;
	// !!! ����� �� �� �������� ������ �� ���������� ��������� ���������, ���� ��������� ����� �������
	// ����� - �� 1 �� 31, ����� - �� 1 �� 12, ��� - �� 2019
	while ((cin.fail()) || (year < 2019) || (month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "�� ����� ������������ ���� ��� ���� � �������� �������!" << endl;
		cout << "���������� ������ ���� � ������� �� �� ���� ��� ���:" << endl;
		cin >> day;
		cin >> month;
		cin >> year;
	};
}

#endif