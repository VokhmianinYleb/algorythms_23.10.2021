//#include <iostream>
//using namespace std;
//
//struct list {
//	int data;
//	list* next;
//	list* prev;
//};
//
//void Search(list* Head, int SearchEl) {
//	list* ptr = Head;
//	while (ptr) {
//		if (ptr->data == SearchEl)
//			cout << ptr->data << "\tAdress: " << ptr << endl;
//		ptr = ptr->next;
//	}
//}
//
////функция удаления заданной позиции
//list* Delete(list* head, int number)
//{
//	list* ptr;
//	list* current = head;
//	for (int i = 1;i < number && current != NULL; i++)
//		current = current->next;
//	if (current != NULL)
//	{
//		if (current->prev == NULL) //Проверка, если удаляется 1-ый эл-т
//		{
//			head = head->next;
//			delete(current);
//			head->prev = NULL;
//			current = head;
//		}
//		else
//		{
//			if (current->next == NULL) //Проверка на удаление последнего эл-та
//			{
//				current->prev->next = NULL;
//				delete(current);
//				current = head;
//			}
//			else //Другие случаи
//			{
//				ptr = current->next;
//				current->prev->next = current->next;
//				current->next->prev = current->prev;
//				delete(current);
//				current = ptr;
//			}
//		}
//	}
//	return head;
//}
//
//int main() {
//	setlocale(LC_ALL, "");
//
//	list* Head = new list;
//	int n, a;
//	cout << "Введите кол-во эл-тов списка: "; cin >> n;
//	list* ptr = new list;
//	cout << "Введите эл-т: "; cin >> a;
//	ptr->data = a;
//	ptr->next = NULL;
//	ptr->prev = NULL;
//	Head = ptr;
//
//	for (int i = 1; i < n; i++) {
//		ptr->next = new list;
//		cout << "Введите эл-т: "; cin >> a;
//		ptr->next->data = a;
//		ptr->next->next = NULL;
//		ptr->next->prev = ptr;
//		ptr = ptr->next;
//	}
//	list* last = ptr;
//
//	ptr = Head;
//	while (ptr) {
//		cout << ptr->data << "\tAdress: " << ptr << "\tAdress next: " << ptr->next << "\tAdress prev: " << ptr->prev << endl;
//		ptr = ptr->next;
//	}
//	cout << endl;
//
//	list* ptr_last = last;
//	while (ptr_last) {
//		cout << ptr_last->data << "\tAdress: " << ptr_last << "\tAdress next: " << ptr_last->next << "\tAdress prev: " << ptr_last->prev << endl;
//		ptr_last = ptr_last->prev;
//	}
//	cout << endl;
//
//	int SearchEl;
//	cout << "Введите элемент, который хотите найти: "; cin >> SearchEl;
//	Search(Head, SearchEl);
//
//	int DeleteNum;
//	cout << "Введите позицию, которую хотите удалить: "; cin >> DeleteNum;
//	Head = Delete(Head, DeleteNum);
//
//	ptr = Head;
//	while (ptr) {
//		cout << ptr->data << "\tAdress: " << ptr << "\tAdress next: " << ptr->next << "\tAdress prev: " << ptr->prev << endl;
//		ptr = ptr->next;
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
//Двусвязные списки






//Циклический односвязный список
#include <iostream>
using namespace std;

struct list {
	int data;
	list* next;
};

void Output(list* Head) {
	list* ptr = Head;
	do {
		cout << ptr->data << "\tAdress: " << ptr << "\tAdress next: " << ptr->next << endl;
		ptr = ptr->next;
	} while (ptr != Head);
}

list* Insert(list* Head, int Number, int value) {
	list* ptr = Head;
	list* el = new list;
	el->data = value;
	if (Head == NULL) {// Если списка нет
		el->next = el;
		Head = el;
	}
	else {//Если есть хотя бы 1 эл-т
		for (int i = 1; i < Number; i++)
			ptr = ptr->next;
		el->next = ptr->next;
		ptr->next = Head;
	}
	return Head;
}

list* Insert2(list* Head, int Number, int DataItem)
{
	list* Current = Head;
	list* NewItem = new(list);
	NewItem->data = DataItem;
	if (Head == NULL) {// список пуст
		NewItem->next = NewItem;
		Head = NewItem;
	}
	else {//список  непуст
		for (int i = 1; i < Number; i++)
			Current = Current->next;
		NewItem->next = Current->next;
		Current->next = NewItem;
	}
	return Head;
}

list* Delete(list* Head, int Number)
{
	if (Head != NULL) {//Если список существует
		list* Current = Head;
		if (Head->next != Head) {//Если элемент не 1 в списке
			for (int i = 1; i < Number; i++) //Поиск позиции для удаления
				Current = Current->next;
			list* ptr = Head;
			while (ptr->next != Current) //Пока следующий не равен тому, что нужно удалить
				ptr = ptr->next;
			//непосредственное удаление элемента
			ptr->next = Current->next;
			if (Head = Current)
				Head = Current->next;
			delete(Current);
		}
		else {
			Head = NULL;
			delete(Current);
		}
	}
	return Head;
}

int main() {
	setlocale(LC_ALL, "");
	list* Head = new list;
	int n, a;
	cout << "Введите кол-во эл-тов списка: "; cin >> n;
	list* ptr = new list;
	cout << "Введите эл-т: "; cin >> a;
	ptr->data = a;
	ptr->next = ptr; //Зацикливаем первый на самого себя
	Head = ptr;
	
	for (int i = 1; i < n; i++) {
		ptr->next = new list;
		cout << "Введите эл-т: "; cin >> a;
		ptr->next->data = a;
		ptr->next->next = Head; //Зацикливаем последний добавленный на первый
		ptr = ptr->next;
	}

	Output(Head);

	int num, value;
	cout << "После какой позиции вставить элемент? "; cin >> num;
	cout << "Какое значение вставить? "; cin >> value;
	Head = Insert2(Head, num, value);
	Output(Head);
	cout << endl << endl;

	cout << "Какой по счёту элемент удалить? "; cin >> num;
	Head = Delete(Head, num);
	Output(Head);

	system("pause");
	return 0;
}
