// lab 12.8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

struct Info
{
	string surname;
	string typdoc;
	int mark;
};

struct DoubleList
{
	Info info;
	DoubleList* next;
	DoubleList* prev;
};


void AddList(DoubleList* &head, Info value)
{
	DoubleList* node = new DoubleList;
	node->info = value;
	if (head == NULL)
	{
		node->next = node;
		node->prev = node;
		head = node;
	}
	else
	{
		DoubleList* p = head;
		p = p->next;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	cout << "\nItem added...\n\n";
}

void DeleteList(DoubleList* head, int position)
{
	if (head == NULL)
	{
		cout << "\nThe list is empty\n\n";
	}
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		DoubleList* a = head;
		for (int i = position; i > 1; i--)
			a = a->next;
		if (a == head)
			head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	cout << "\nItem deleted ...\n\n";
}

void PrintList(DoubleList* head)
{
	if (head == NULL)
		cout << "\nThe list is empty\n\n";
	else
	{
		DoubleList* a = head;
		cout << "\nList items: ";
		do
		{
			cout << a->info.surname << ' ' << a->info.typdoc << ' ' << a->info.mark << " | ";
			a = a->next;
		} while (a != head);
		cout << "\n\n";
	}
}


void CreateNewList(DoubleList*& first, DoubleList*& last, Info value)
{
	DoubleList* tmp = new DoubleList;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

void GetValue(DoubleList* head, DoubleList*& first, DoubleList*& last, int userMark)
{
	if (head == NULL)
		cout << "\nThe list is empty\n\n";
	else
	{
		DoubleList* a = head;
		do
		{
			if (a->info.mark >= userMark)
			{
				CreateNewList(first, last, a->info);
			}
			a = a->next;
		} while (a != head);
		cout << "\n\n";
	}
}

void Print(DoubleList* L)
{
	while (L != NULL)
	{
		cout << L->info.surname << ' ' << L->info.typdoc << ' ' << L->info.mark << " | ";
		L = L->next;
	}
	cout << endl;
}

int main()
{
	Info S;
	DoubleList* head = NULL;
    DoubleList* first = NULL,
    * last = NULL;



	int value, position, x;
	do
	{
		cout << "1. Add an item" << endl;
		cout << "2. Delete the item" << endl;
		cout << "3. Display a list" << endl;
		cout << "4. Display a modified list" << endl;
		cout << "0. Exit" << endl;
		cout << "\ntransaction number > ";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "document type: "; cin >> S.typdoc;
			cout << "Mark: "; cin >> S.mark;
			cout << "Surname: "; cin >> S.surname;
			AddList(head, S);
			break;
		case 2:
			cout << "Position > ";
			cin >> position;
			DeleteList(head, position);
			break;
		case 3:
			PrintList(head);
			break;
		case 4:
			int mark;
			cout << "Enter the number of valid points: "; cin >> mark;
			GetValue(head, first, last, mark);
			Print(first);
			break;
		}
	} while (x != 0);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
