#include "XOR_LL.h"
int main()
{
	XOR_LL l;
	char c = 'a';
	do
	{
		cout << "Select a function\n";
		cout << "1. Insert At Head" << endl;
		cout << "2. Insert At Tail" << endl;
		cout << "3. Insert After" << endl;
		cout << "4. Remove At Head" << endl;
		cout << "5. Remove At Tail" << endl;
		cout << "6. Delete Before" << endl;
		cout << "7. Print List" << endl;
		int choice;
		cin >> choice;
		while (!(choice>=1 && choice<=7))
		{
			cout << "Select between 1 and 7...";
			cin >> choice;
		}
		system("cls");
		if (choice == 1)
		{
			cout << "Currently your list is" << endl;
			l.printList();
			int a;
			cout << "Enter the value you want to insert: ";
			cin >> a;
			l.insertAtHead(a);
			cout << "Your List is" << endl;
			l.printList();
		}
		else if (choice == 2)
		{
			cout << "Currently your list is" << endl;
			l.printList();
			int a;
			cout << "Enter the value you want to insert: ";
			cin >> a;
			l.insertAtTail(a);
			cout << "Your List is" << endl;
			l.printList();
		}
		else if (choice == 3)
		{
			if (l.isEmpty())
			{
				l.printList();
				cout << "To test this function, there must be one or more nodes present in the list" << endl;
			}
			else
			{
				cout << "Currently your list is" << endl;
				l.printList();
				int a, b;
				cout << "Enter the node to which you want to insert after: ";
				cin >> a;
				cout << "Enter the value you want to insert: ";
				cin >> b;
				l.insertAfter(a, b);
				cout << "Your List is" << endl;
				l.printList();
			}
		}
		else if (choice == 4)
		{
			if (l.isEmpty())
			{
				l.printList();
				cout << "First insert some nodes in the list, then try this function" << endl;
			}
			else
			{
				cout << "Currently your list is" << endl;
				l.printList();
				l.removeAtHead();
				cout << "After removing the head, your list is" << endl;
				l.printList();
			}
		}
		else if (choice == 5)
		{
			if (l.isEmpty())
			{
				l.printList();
				cout << "First insert some nodes in the list, then try this function" << endl;
			}
			else
			{
				cout << "Currently your list is" << endl;
				l.printList();
				l.removeAtTail();
				cout << "After removing the tail, your list is" << endl;
				l.printList();
			}
		}
		else if (choice == 6)
		{
			if (l.isEmpty())
			{
				l.printList();
				cout << "First insert some nodes in the list, then try this function" << endl;
			}
			else
			{
				cout << "Currently your list is" << endl;
				l.printList();
				int a;
				cout << "Enter the node before which you want to delete: ";
				cin >> a;
				l.deletetBefore(a);
				cout << "Your list after calling delete function is" << endl;
				l.printList();
			}
		}
		else if (choice == 7)
		{
			l.printList();
		}
		cout << "Do you want to run again?(Y/N)";
		cin >> c;
		system("cls");
	} while (c=='Y'||c=='y');
	return 0;
}