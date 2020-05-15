// MAIN
/* Напишите программу, которая содержит текущую информацию о заявках на авиабилеты. Каждая заявка должна иметь:
	пункт назначения;
	номер рейса;
	ФИО пассажира;
	желаемую дату вылета.
Программа должна обеспечивать :
	хранение всех заявок в виде списка;
	добавление и удаление заявок;
	вывод всех заявок.                   */

#include <Windows.h> // для ввода-вывода на кириллице
#include "Tickets_list.h"

// перечисление возможностей пользователя
enum users_options
{
	add_ticket = 1, delete_ticket, print_tickets, add_test_tickets, options_number
};

// функция получает ответ от пользователя, что он хочет делать с заявками на билеты
users_options what_user_wants()
{
	cout << endl;
	cout << "Что Вы хотите сделать? " << endl;
	cout << users_options::add_ticket << " - добавить заявку " <<
            users_options::delete_ticket << " - удалить заявку " <<
	        users_options::print_tickets << " - посмотреть все заявки " << 
		    users_options::add_test_tickets << " - добавить тестовые заявки " << endl;

	cout << endl << "Ваш выбор: ";
	int choice;
	cin >> choice;

	// проверяем, чтобы ответ пользователя был в списке доступных опций
	while (cin.fail() || (choice < 1) || (choice >= (users_options::options_number)))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ваш выбор не очевиден, пожалуйста, вовторите ввод, введя одно из значений  списка: ";
		cin >> choice;
	}

	return static_cast<users_options>(choice);
}

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251); // для ввода-вывода на кириллице

	cout << "Программа работает со списком заявок на авиабилеты." << endl;
	Request_list the_list;  // создаём объект класса Список заявок, вся дальнейшая работа происхдит с этим списком

	while (true)
	{
		switch (what_user_wants())
		{
		case users_options::add_ticket:
			the_list.add_ticket();
			break;
		case users_options::delete_ticket:
			cout << "Введите номер заявки для удаления: ";
			unsigned short number_for_deletion;
			cin >> number_for_deletion;
			the_list.delete_ticket(number_for_deletion);
			break;
		case users_options::print_tickets:
			the_list.print_list();
			break;
		case users_options::add_test_tickets:
			the_list.add_test_data();
			break;
		}
	}
	
	return 0;
}