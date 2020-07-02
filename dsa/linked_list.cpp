#include<bits/stdc++.h>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};


void insert_beg(Node **head);
void insert_end(Node **head);
void insert_after(Node **head, int data);
void traverse(Node **head);

int main()
{
	Node *head = NULL;
	
	int choice;
	cout << "Press 1 to insert at the beginning\n" << "Press 2 to insert at the end\n" << "Press 3 to insert after some data\n" << "Press 4 to traverse \n" << "Press 5 to exit \n";
	cin >> choice;

	while(choice != 5)
	{	
		switch(choice)
		{
			case 1:
				insert_beg(&head);
				break;

			case 2:
				insert_end(&head);
				break;
				
			case 3:
				cout << "Enter the data you want to insert after \n";
				int data;
				cin >> data;
				insert_after(&head, data);
				break;

			case 4:
				traverse(&head);
				break;
			
			default:
				cout << "Wrong input \n";
		}
		cout << "Press 1 to insert at the beginning\n" << "Press 2 to insert at the end\n" << "Press 3 to insert after some data\n" << "Press 4 to traverse \n" << "Press 5 to exit \n";
		cin >> choice;
	}
	return 0;
}

void insert_beg(Node** head)
{
	Node *node = (Node *)malloc(sizeof(Node));
	cout << "Enter the data\n";
	cin >> node->data;

	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
	}
	else
	{
		node->next = *head;
		*head = node;
	}
}

void insert_end(Node** head)
{
	Node *node = (Node *)malloc(sizeof(Node));
	cout << "Enter the data\n";
	cin >> node->data;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		Node *temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
}

void insert_after(Node **head, int data)
{
	Node *node = (Node *) malloc(sizeof(Node));
	cout << "Enter the data to insert\n";
	cin >> node->data;
	
	Node *temp = *head;
	
	while (temp->data != data)
	{
		temp = temp->next;
	}
	
	node->next = temp->next;
	temp->next = node;
}

void traverse(Node** head)
{
	Node *temp = *head;
	cout << "Linked list contains :\n";
	while (temp != NULL)
	{
		cout << temp->data <<endl;
		temp = temp->next;
	}
}
