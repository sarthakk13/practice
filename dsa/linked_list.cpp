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
void delete_beg(Node ** head);
void delete_end(Node ** head);
void delete_position(Node **head, int data);
void traverse(Node **head);
void length(Node **head);
void reverse (Node **head);

int main()
{
	Node *head = NULL;
	
	int choice;
	cout << "Press 1 to insert at the beginning\n" << "Press 2 to insert at the end\n" << "Press 3 to insert after some data\n" << "Press 4 to delete data from  the beginning\n"<<"Press 5 to delete data from the end\n"<< "Press 6 to delete a specific data\n" << "Press 7 to find the length of the list\n" << "Press 8 to reverse the list \n" <<"Press 9 to traverse \n" << "Press 10 to exit \n";
	cin >> choice;

	while(choice != 10)
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
				delete_beg(&head);
				break;
				
			case 5:
				delete_end(&head);
				break;
				
			case 6:
				int number;
				cout << "Enter the data you want to delete \n";
				cin >> number;
				delete_position(&head, number);
				break;
			
			case 7:
				length(&head);
				break;
				
			case 8:
				reverse(&head);
				break;
			
			case 9:
				traverse(&head);
				break;
			
			default:
				cout << "Wrong input \n";
		}
		cout << "Press 1 to insert at the beginning\n" << "Press 2 to insert at the end\n" << "Press 3 to insert after some data\n" << "Press 4 to delete data from  the beginning\n"<<"Press 5 to delete data from the end\n"<< "Press 6 to delete a specific data\n" << "Press 7 to find the length of the list\n" << "Press 8 to reverse the list \n" <<"Press 9 to traverse \n" << "Press 10 to exit \n";
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

void delete_beg(Node ** head)
{
	if (*head == NULL)
	{
		cout <<"List is already empty\n";
	}
	else
	{
		Node *temp = *head;
		*head = (*head)->next;
		delete(temp);
	}
}

void delete_end(Node ** head)
{
	if (*head == NULL)
	{
		cout <<"List is already empty\n";
	}	
	else
	{
		Node *temp = *head, *prev_node;
		
		while (temp->next != NULL)
		{
			prev_node = temp;
			temp = temp->next;
		}
		prev_node->next = NULL;
		delete(temp);
	}
}

void delete_position(Node **head, int data)
{
	if (*head == NULL)
	{
		cout <<"List is already empty\n";
	}
	else
	{
		Node *temp = *head, *prev_node;
		while (temp->data != data)
		{
			prev_node = temp;
			temp = temp->next;
		}
		Node *next_node = temp->next;
		prev_node->next = next_node;
		delete(temp);
	}
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

void length(Node **head)
{
	if (*head == NULL)
	{
		cout << "List is empty \n";
	}
	else
	{
		Node *temp = *head;
		int length = 0;
		while (temp != NULL)
		{
			length++;
			temp = temp->next;
		}
		cout << length << endl;
	}
	
}

void reverse (Node **head)
{
	Node *temp = *head;
	Node *prev_node = NULL, *next_node = temp->next;
	
	while (next_node != NULL)
	{
		temp->next = prev_node;
		prev_node = temp;
		temp = next_node;
		next_node = next_node->next;
	}
	temp->next = prev_node; 
	*head = temp;
}
