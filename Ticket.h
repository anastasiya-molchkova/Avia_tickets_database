// Заголовочный файл класса "Заявка на билет"

#ifndef TICKET
#define TICKET

#include "Passenger.h"
#include "Date.h"

// Класс "Заявка на авиабилет"
class Ticket_request
{
private:
	string point_of_destination;
	string flight_number;
	Date date_of_departure;
	Passenger passenger;
public:
	static unsigned tickets_numeration; // статическая переменная класса, нужна для отслеживания общей нумерации
	unsigned number;                    // индивидуальный номер каждой заявки, делаем его публичным, чтобы не создавать геттер

	// конструктор класса по умолчанию:
	Ticket_request()
	{}

	// конструктор класса с параметрами:
	Ticket_request(const Passenger& passenger_fullname, const Date& date, const string& fl_number, const string& airport) :
		point_of_destination(airport), flight_number(fl_number), date_of_departure(date), passenger(passenger_fullname), number(tickets_numeration++)
	{}

	// статическая (общая для всех объектов класса) функция создания заявки на билет
	static Ticket_request create_request()
	{
		cout << "Введите пункт назначения: ";
		string point_of_destination;
		cin >> point_of_destination;

		cout << "Введите номер рейса: ";
		string flight_number;
		cin >> flight_number;

		Date date_of_departure = Date::create_date();
		Passenger passenger = Passenger::create_passenger();

		return Ticket_request(passenger, date_of_departure, flight_number, point_of_destination);
	}

	// дружественная функция печати заявки на билет:
	friend std::ostream& operator<<(std::ostream& out, const Ticket_request& request)
	{
		out << "Заявка №" << request.number << ", пассажир " << request.passenger <<
		       ", рейс № " << request.flight_number << ", летит " << request.date_of_departure << " в " << request.point_of_destination << endl;
		return out;
	}
};

// статическая переменная класса для нумерации заявок на билеты инициализируется вне класса:
unsigned Ticket_request::tickets_numeration = 1;

#endif