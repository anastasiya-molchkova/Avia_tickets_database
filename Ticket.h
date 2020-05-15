// ������������ ���� ������ "������ �� �����"

#ifndef TICKET
#define TICKET

#include "Passenger.h"
#include "Date.h"

// ����� "������ �� ���������"
class Ticket_request
{
private:
	string point_of_destination;
	string flight_number;
	Date date_of_departure;
	Passenger passenger;
public:
	static unsigned tickets_numeration; // ����������� ���������� ������, ����� ��� ������������ ����� ���������
	unsigned number;                    // �������������� ����� ������ ������, ������ ��� ���������, ����� �� ��������� ������

	// ����������� ������ �� ���������:
	Ticket_request()
	{}

	// ����������� ������ � �����������:
	Ticket_request(const Passenger& passenger_fullname, const Date& date, const string& fl_number, const string& airport) :
		point_of_destination(airport), flight_number(fl_number), date_of_departure(date), passenger(passenger_fullname), number(tickets_numeration++)
	{}

	// ����������� (����� ��� ���� �������� ������) ������� �������� ������ �� �����
	static Ticket_request create_request()
	{
		cout << "������� ����� ����������: ";
		string point_of_destination;
		cin >> point_of_destination;

		cout << "������� ����� �����: ";
		string flight_number;
		cin >> flight_number;

		Date date_of_departure = Date::create_date();
		Passenger passenger = Passenger::create_passenger();

		return Ticket_request(passenger, date_of_departure, flight_number, point_of_destination);
	}

	// ������������� ������� ������ ������ �� �����:
	friend std::ostream& operator<<(std::ostream& out, const Ticket_request& request)
	{
		out << "������ �" << request.number << ", �������� " << request.passenger <<
		       ", ���� � " << request.flight_number << ", ����� " << request.date_of_departure << " � " << request.point_of_destination << endl;
		return out;
	}
};

// ����������� ���������� ������ ��� ��������� ������ �� ������ ���������������� ��� ������:
unsigned Ticket_request::tickets_numeration = 1;

#endif