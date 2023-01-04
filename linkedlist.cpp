#include <iostream>
using namespace std;

//to use a generic initilization in function
template <class m>
//class to book sum blaces in memory without order called unorderd linkedlist
class Node
{
	m value;
	Node* next;
	Node* header;
	//constractor to but intial value to class variables = NULL
public:Node()
{
	value = NULL;
	next = NULL;
	header = NULL;
}
	  //constractor to add item to linkedlist class
	  void add(m item)
	  {
		  Node* current = new Node;
		  current->value = item;
		  current->next = header;
		  header = current;
	  }
	  //constractor to check if linkedlist is impty or not
	  bool isempty()
	  {
		  if (header == NULL)
		  {
			  return true;
		  }
		  else
		  {
			  return false;
		  }
	  }
	  //constractor to delet some item from the top of linkedlist
	  void drop()
	  {
		  if (isempty())
		  {
			  cout << "the node is empty";
		  }
		  else
		  {
			  Node* newheader = new Node;
			  newheader = header;
			  header = header->next;
			  newheader->next = NULL;
			  delete newheader;
		  }
	  }
	  //constractor to delet some item from the top of linkedlist and save value of top in linkedlist
	  void drop(m& element)
	  {
		  if (isempty())
		  {
			  cout << "the node is empty";
		  }
		  else
		  {
			  element = header;
			  Node* newheader = new Node;
			  newheader = header;
			  header->next = NULL;
			  delete newheader;
		  }
	  }
	  //constractor to return value of top in linkedlist
	  void gettop(m& element)
	  {
		  if (isempty())
		  {
			  cout << "the node is empty";
		  }
		  else
		  {
			  element = header->value;
		  }
	  }
	  //constractor to print all values in linkedlist if it not empty  
	  void print()
	  {
		  cout << "the value of linked list = ";
		  cout << "[";
		  while (header != NULL)
		  {
			  cout << header->value << " ";
			  header = header->next;
		  }
		  cout << "]";
	  }
	  void delet(int element)
	  {
		  Node* p = header;
		  if (p->value == element)
		  {
			  header = header->next;
			  delete p;
		  }
		  else
		  {
			  Node* t;
			  while (p->next->next->value != element)
			  {
				  Node* t = p->next;
				  p = p->next;
			  }
			  p->next = p->next->next;
			  delete t;
		  }
	  }
};
int main()
{
	int x = 0;
	Node<int>linkedlist;
	while (true)
	{
		char y, x;
		cout << "are you want to do any operation in Linkedlist" "\n" << "1 - yes \n" << "2 - no \n";
		cout << "entre a number of your operation\n";
		while (true)
		{
			cin >> x;
			if (x == '2')
			{
				break;
			}
			else if (x == '1')
			{
				cout << "which operation you want to do in Linkedlist \n" << "1 - add\n" << "2 - drop\n" << "3 - print\n";
				cout << "entre a number of your operation\n";
				while (true)
				{
					cin >> y;
					if (y == '1')
					{
						cout << "entre your elements of your Linkedlist\n";
						int element;
						cin >> element;
						linkedlist.add(element);
						break;
					}
					else if (y == '2')
					{
						cout << "entre your element of your Linkedlist elements you would to drop \n";
						int element;
						cin >> element;
						linkedlist.delet(element);
						break;
					}
					else if (y == '3')
					{
						linkedlist.print();
						break;
					}
					else
					{
						cout << "=>your choise is not correct \n=>please intre a correct number of operation\n";
					}
				}
				break;
			}
			else
			{
				cout << "=>your choise is not correct \n=>please intre a correct number of operation\n";
			}
		}
		if (x == '2')
		{
			break;
		}

	}
	cout << "the program is ended";
	return 0;
}
