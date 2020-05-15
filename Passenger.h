// ������������ ���� ������ "��������"

#ifndef PASSENGER
#define PASSENGER

#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin;

void enter_passenger(string& name, string& surname);

// ��������� "��������" ��� �������� � ������ ����� � ������� ���������
struct Passenger
{
private:
	string name;
	string surname;
public:
	Passenger() {}  // ����������� �� ��������� ����� ��� ������������� ����� ������ � ������ ������

	// ����������� � ������������� ������ � ��������
	Passenger(const string initial_name, const string initial_surname) : name(initial_name), surname(initial_surname)
	{}

	// ������������� ������� ������ ������� �����
	friend std::ostream& operator<<(std::ostream& out, const Passenger& passenger)
	{
		out << passenger.name << " " << passenger.surname;
		return out;
	}

	// ����������� (����� ��� ���� ��������) ������� �������� ������� ������ "��������"
	static Passenger create_passenger()
	{
		string name; string surname;
		enter_passenger(name, surname);
		return Passenger(name, surname);
	}
};

// ������� ������� ����� � ������� ��������� � ������������
void enter_passenger(string& name, string& surname)
{
	cout << "������� ��� ��������� � ������� ��� �������: ";
	cin >> name;
	cin >> surname;
}

#endif