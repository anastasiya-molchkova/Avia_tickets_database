// Заголовочный файл класса Дата

#ifndef DATE
#define DATE

#include <iostream>
using std::cout; using std::cin; using std::endl;

void enter_date(unsigned short& year, unsigned short& month, unsigned short& day);

// класс "Дата"
class Date
{
public:
	enum Months { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
private:
	unsigned short year;
	Months month;
	unsigned short day;

public:
	Date() {} // конструктор по умолчанию нужен для использования этого класса в другом классе

	// конструктор с параметрами дня, месяца и года
	Date(const unsigned short d, const Months m, const unsigned short y) : day(d), month(m), year(y)
	{}

	// определение дружественной функции печати даты в формате ДД.ММ.ГГГГ
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

	// статическая (общая для всех объектов) функция создания объекта Дата с соответствующими параметрами
	static Date create_date()
	{
		unsigned short year{ 2019 };
		unsigned short month{ 01 };
		unsigned short day{ 01 };

		enter_date(day, month, year);
		return Date(day, static_cast<Months>(month), year);
	}
};

// функция запроса у пользователя даты, возвращает число, месяц, год по ссылке
void enter_date(unsigned short& day, unsigned short& month, unsigned short& year)
{
	cout << "Введите желаемую дату вылета в формате ДД ММ ГГГГ: ";
	// сделала через пробел, так как превращать строку формата ДД.ММ.ГГГГ в день, месяц, год посчитала долгим

	cin >> day;
	cin >> month;
	cin >> year;
	// !!! Здесь бы не помешала сверка со встроенным настоящим календарём, пока проверяем очень топорно
	// число - от 1 до 31, месяц - от 1 до 12, год - от 2019
	while ((cin.fail()) || (year < 2019) || (month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели некорректную дату или дату в неверном формате!" << endl;
		cout << "Попробуйте ввести дату в формате ДД ММ ГГГГ ещё раз:" << endl;
		cin >> day;
		cin >> month;
		cin >> year;
	};
}

#endif