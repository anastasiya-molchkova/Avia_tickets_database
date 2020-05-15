// Заголовочный файл класса "Пассажир"

#ifndef PASSENGER
#define PASSENGER

#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin;

void enter_passenger(string& name, string& surname);

// структура "Пассажир" для хранения и вывода имени и фамилии пассажира
struct Passenger
{
private:
	string name;
	string surname;
public:
	Passenger() {}  // конструктор по умолчанию нужен для использования этого класса в другом классе

	// конструктор с передаваемыми именем и фамилией
	Passenger(const string initial_name, const string initial_surname) : name(initial_name), surname(initial_surname)
	{}

	// дружественная функция печати полного имени
	friend std::ostream& operator<<(std::ostream& out, const Passenger& passenger)
	{
		out << passenger.name << " " << passenger.surname;
		return out;
	}

	// статическая (общая для всех объектов) функция создания объекта класса "Пассажир"
	static Passenger create_passenger()
	{
		string name; string surname;
		enter_passenger(name, surname);
		return Passenger(name, surname);
	}
};

// функция запроса имени и фамилии пассажира у пользователя
void enter_passenger(string& name, string& surname)
{
	cout << "Введите имя пассажира в формате ИМЯ ФАМИЛИЯ: ";
	cin >> name;
	cin >> surname;
}

#endif