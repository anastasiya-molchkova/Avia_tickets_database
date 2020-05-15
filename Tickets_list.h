// Заголовочный файл класса-контейнера для заявок на билеты

#ifndef TICKETS_LIST
#define TICKETS_LIST

#include <vector>
#include <algorithm> // для std::swap
#include "Ticket.h"

using std::vector;

// импровизированный класс-контейнер, для хранения и обработки заявок на билеты в векторе
class Request_list
{
private:
	// хранить заявки будем в векторе, тогда не надо думать о количестве заявок, выделении и освобождении памяти
	vector <Ticket_request> tickets_list{}; 
public:
	// конструктор по умолчанию:
	Request_list() {}

	// метод для добавления новой заявки в конец списка
	void add_ticket()
	{
		Ticket_request one_more_ticket(Ticket_request::create_request());
		tickets_list.push_back(one_more_ticket);
		cout << "Созданная заявка №" << one_more_ticket.number << " добавлена в конец списка заявок." << endl;
	}

	// метод для добавления в список тестовых данных
	void add_test_data()
	{
		tickets_list.push_back(Ticket_request(Passenger("Винни", "Пух"), Date(14, static_cast<Date::Months>(02), 2020), "S7328", "Астрахань"));
		tickets_list.push_back(Ticket_request(Passenger("Антонио", "Бандерас"), Date(29, static_cast<Date::Months>(06), 2020), "782", "Нью-Йорк"));
		tickets_list.push_back(Ticket_request(Passenger("Гарри", "Поттер"), Date(23, static_cast<Date::Months>(11), 2020), "3762", "Пермь"));
		tickets_list.push_back(Ticket_request(Passenger("Дайнерис", "Таргариен"), Date(22, static_cast<Date::Months>(12), 2019), "37623", "Вестеросс"));
		tickets_list.push_back(Ticket_request(Passenger("Ксения", "Собчак"), Date(03, static_cast<Date::Months>(8), 2021), "0931", "Санкт-Петербург"));
		cout << "Добавлены тестовые данные по заявкам. " << endl;
	}

	// метод для удаления заявки из списка по номеру заявки
	void delete_ticket(const unsigned short number_for_deletion)
	{
		bool deleted = false;
		for (auto& request : tickets_list)
		{
			if (request.number == number_for_deletion)
				// нашли заявку с указанным номером
			{
				std::swap(request, tickets_list[tickets_list.size() - 1]);
				// меняем местами нужную заявку с последней в списке
				tickets_list.pop_back(); // удаляем последнюю заявку из списка
				cout << "Заявка с указанным номером удалена!" << endl;
				deleted = true;
			}
			if (deleted == true) break;
		}
		if (deleted == false)
			cout << "Не удалось найти заявку с указанным номером!" << endl;
	}

	// метод печати списка заявок
	void print_list()
	{
		cout << endl;
		if (tickets_list.size() == 0) cout << "Список заявок на авиабилеты пуст!";
		else 
			for (const auto& ticket : tickets_list) cout << ticket;
		cout << endl;
	}
};

#endif