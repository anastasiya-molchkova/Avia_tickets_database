// ������������ ���� ������-���������� ��� ������ �� ������

#ifndef TICKETS_LIST
#define TICKETS_LIST

#include <vector>
#include <algorithm> // ��� std::swap
#include "Ticket.h"

using std::vector;

// ����������������� �����-���������, ��� �������� � ��������� ������ �� ������ � �������
class Request_list
{
private:
	// ������� ������ ����� � �������, ����� �� ���� ������ � ���������� ������, ��������� � ������������ ������
	vector <Ticket_request> tickets_list{}; 
public:
	// ����������� �� ���������:
	Request_list() {}

	// ����� ��� ���������� ����� ������ � ����� ������
	void add_ticket()
	{
		Ticket_request one_more_ticket(Ticket_request::create_request());
		tickets_list.push_back(one_more_ticket);
		cout << "��������� ������ �" << one_more_ticket.number << " ��������� � ����� ������ ������." << endl;
	}

	// ����� ��� ���������� � ������ �������� ������
	void add_test_data()
	{
		tickets_list.push_back(Ticket_request(Passenger("�����", "���"), Date(14, static_cast<Date::Months>(02), 2020), "S7328", "���������"));
		tickets_list.push_back(Ticket_request(Passenger("�������", "��������"), Date(29, static_cast<Date::Months>(06), 2020), "782", "���-����"));
		tickets_list.push_back(Ticket_request(Passenger("�����", "������"), Date(23, static_cast<Date::Months>(11), 2020), "3762", "�����"));
		tickets_list.push_back(Ticket_request(Passenger("��������", "���������"), Date(22, static_cast<Date::Months>(12), 2019), "37623", "���������"));
		tickets_list.push_back(Ticket_request(Passenger("������", "������"), Date(03, static_cast<Date::Months>(8), 2021), "0931", "�����-���������"));
		cout << "��������� �������� ������ �� �������. " << endl;
	}

	// ����� ��� �������� ������ �� ������ �� ������ ������
	void delete_ticket(const unsigned short number_for_deletion)
	{
		bool deleted = false;
		for (auto& request : tickets_list)
		{
			if (request.number == number_for_deletion)
				// ����� ������ � ��������� �������
			{
				std::swap(request, tickets_list[tickets_list.size() - 1]);
				// ������ ������� ������ ������ � ��������� � ������
				tickets_list.pop_back(); // ������� ��������� ������ �� ������
				cout << "������ � ��������� ������� �������!" << endl;
				deleted = true;
			}
			if (deleted == true) break;
		}
		if (deleted == false)
			cout << "�� ������� ����� ������ � ��������� �������!" << endl;
	}

	// ����� ������ ������ ������
	void print_list()
	{
		cout << endl;
		if (tickets_list.size() == 0) cout << "������ ������ �� ���������� ����!";
		else 
			for (const auto& ticket : tickets_list) cout << ticket;
		cout << endl;
	}
};

#endif