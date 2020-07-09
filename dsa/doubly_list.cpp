#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *prev;
		Node *next;
};

void traverse(Node **head);
void create(Node **head, Node **tail);
void insert_beg(Node **head, Node **tail);
void insert_end(Node **head, Node **tail);
int length(Node **head);
void insert_position(Node **head, Node ** tail);

int main()
{
	Node *head = NULL, *tail = NULL;
	
	int choice;
	cout << "Press 1 to create the list \n" << "Press 2 to traverse the list \n" << "Press 3 to insert at the beginning\n" << "Press 4 to insert at the end \n" << "Press 5 to insert at a position \n"<< "Press 6 to calculate the length\n"<<"Press 7 to exit \n";
	cin >> choice;
	
	while (choice != 7)
	{
		switch(choice)
		{
			case 1:
				create(&head, &tail);
				break;
			
			case 2:
				traverse(&head);
				break;
				
			case 3:
				insert_beg(&head, &tail);
				break;
			
			case 4:
				insert_end(&head, &tail);
				break;
				
			case 5:
				insert_position(&head, &tail);
				break;
			
			case 6:
				cout <<"Length of the list is : "<<length(&head) << endl;
				break;
			
			default:
				cout << "Wrong input \n";
		}
		cout << "Press 1 to create the list \n" << "Press 2 to traverse the list \n" << "Press 3 to insert in the beginning\n" << "Press 4 to insert at the end \n" << "Press 5 to insert at a position \n" <<"Press 6 to calculate the legth\n" <<"Press 7 to exit \n";
		cin >> choice;
	}
}

void create(Node **head, Node **tail)
{
	int choice = 1;
	while (choice != 0)
	{
		Node *n = new(Node);
		if(*head == NULL)
		{
			cout << "Enter the data \n";
			cin >> n->data;
			n->prev = n->next = NULL;
			*head = *tail = n;
		}
		else
		{
			cout << "Enter the data \n";
			cin >> n->data;
			n->prev = *tail;
			n->next = NULL;
			(*tail)->next = n;
			*tail = n;
		}
		cout << "Press 1 to add more to the list \n" << "Press 0 to go to main menu \n";
		cin >> choice;
	}	
}

void traverse(Node **head)
{
	Node *temp = *head;
	
	cout << "List contains :\n";
	
	while (temp != NULL)
	{
		cout << temp->data <<endl;
		temp = temp->next;
	}
	
}

void insert_beg(Node **head, Node **tail)
{
	if (*head == NULL)
	{
		Node *n = new(Node);
		n->prev = n->next = NULL;
		cout << "Enter the data \n";
		cin >> n->data;
		*head = *tail = n;
	}
	else
	{
		Node *n = new(Node);
		cout << "Enter the data \n";
		cin >> n->data;
		n->next = *head;
		(*head)->prev = n;
		n->prev = NULL;
		*head = n;
	}
	
	
}

void insert_end(Node **head, Node **tail)
{
	if (*head == NULL)
	{
		Node *n = new(Node);
		n->prev = n->next = NULL;
		cout << "Enter the data \n";
		cin >> n->data;
		*head = *tail = n;
	}
	else
	{
		Node *n = new(Node);
		cout << "Enter the data \n";
		cin >> n->data;
		n->next = NULL;
		n->prev = *tail;
		(*tail)->next = n;
		*tail = n;	
	}
}

void insert_position(Node **head, Node ** tail)
{
	int position;
	cout << "Enter the position \n";
	cin >> position;
	
	if (position == 1)
	{
		insert_beg(head, tail);	
	}
	else if(position == (length(head) + 1))
	{
		insert_end(head, tail);
	}
	else if (position > (length(head) + 1))
	{
		cout << "Invalid position \n";
	}
	else
	{
		int count = 1;
		Node *temp = *head;
		while(count < (position - 1))
		{
			temp = temp->next;
			count ++;
		}
		Node *n = new(Node);
		cout << "Enter the data \n";
		cin >> n->data;
		n->next = temp->next;
		n->prev = temp;
		temp->next->prev = n;
		temp->next = n;
	}

}

int length(Node **head)
{
	Node *temp = *head;
	int length = 0;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	return  length;
}
