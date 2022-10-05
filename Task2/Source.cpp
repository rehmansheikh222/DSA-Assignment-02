#include "AVL_Tree.cpp"
int main()
{
	AVL_Tree<int> avl;
	char c = 'a';
	do
	{
		int choice;
		cout << "Select a function" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Print Tree" << endl;
		cin >> choice;
		while (!(choice >= 1 && choice <= 4))
		{
			cout << "Select between 1 to 4...";
			cin >> choice;
		}
		system("cls");
		if (choice == 1)
		{
			cout << "Currently your tree is" << endl;
			avl.printNodes(avl.getRoot());
			cout << "Enter the node you want to insert: ";
			int val;
			cin >> val;
			avl.insert(val);
			cout << "Your Tree after insertion is" << endl;
			avl.printNodes(avl.getRoot());
		}
		else if (choice == 2)
		{
			if (avl.isEmpty())
			{
				cout << "The tree has no nodes" << endl;
				cout << "First insert some nodes in the tree, then try this function" << endl;
			}
			else
			{
				cout << "Currently your tree is" << endl;
				avl.printNodes(avl.getRoot());
				cout << "Enter the node you want to search: ";
				int s;
				cin >> s;
				AVLNode<int>* f = avl.search(s);
				if (!f)
				{
					cout << "The node " << s << " is not found" << endl;
				}
				else
				{
					cout << "The node " << s << " is found successfully" << endl;
				}
			}
		}
		else if (choice == 3)
		{
			if (avl.isEmpty())
			{
				cout << "The tree has no nodes" << endl;
				cout << "First insert some nodes in the tree, then try this function" << endl;
			}
			else
			{
				cout << "Currently your tree is" << endl;
				avl.printNodes(avl.getRoot());
				cout << "Enter the node you want to delete: ";
				int dl;
				cin >> dl;
				AVLNode<int>* f = avl.search(dl);
				if (!f)
				{
					cout << "The node " << dl << " is not present in the tree" << endl;
				}
				else
				{
					avl.deleteNode(f);
					cout << "Your tree after calling the delete function is" << endl;
					avl.printNodes(avl.getRoot());
				}
			}
		}
		else if (choice == 4)
		{
			avl.printTree();
		}
		cout << "Do you want to run again?(Y/N)";
		cin >> c;
		system("cls");
	} while (c == 'Y' || c == 'y');
	return 0;
}
