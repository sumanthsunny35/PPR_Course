#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node Node;

struct hash_table {
	struct node *head;
};

typedef struct hash_table hash;

Node * create_node() 
{
	Node *temp = (struct node *)malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
}

int get_hash_value(int value) {
	return value % 999983;
}

void insert(hash hash_tab[], int value) {
	Node *newnode = create_node();
	newnode->data = value;
	int key;
	key = get_hash_value(value);	
	newnode->next = hash_tab[key].head;
	hash_tab[key].head = newnode;
}

int search(hash hash_tab[], int value) 
{
	int key;
	key = get_hash_value(value);
	Node *temp;
	temp = hash_tab[key].head;
	while (temp) {
		if (temp->data == value) {
			return 1;
		}
		temp = temp->next;
	}
	
	return -1;
}	

void free_node(Node *temp) {
	free(temp);
	temp = NULL;
}

int delete(hash hash_tab[], int value)
{
	int key;
	key = get_hash_value(value);
	if (hash_tab[key].head == NULL) {
		return -1;
	}
	Node *temp;
	temp  = hash_tab[key].head;
	if (temp->data == value) {
		hash_tab[key].head = temp->next;
		free_node(temp);
		return 1;
	}
	while (temp->next != NULL && temp->next->data != value) {
		temp = temp->next;
	}
	struct node *temp1 = NULL;
	if (temp->next != NULL) {

		temp1 = temp->next;
		temp->next = temp1->next;
		free_node(temp1);
		return 1;
	}
	return -1;
}
	

int main()
{	
	hash hash_tab[1000000] = { NULL };
	int choice;
	int value;
	while (1) {
		printf("1.Insert 2.Search 3.Delete 4.Exit\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:{
				printf("Enter the value to insert\n");
				scanf("%d", &value);
				insert(hash_tab, value);
				printf("Element inserted into the hash table\n");
				}
				break;
			case 2:{
				printf("Enter the value to search\n");
				scanf("%d", &value);
				search(hash_tab, value) != -1 ? printf("Found\n") : printf("Not Found\n");
				}
				break;
			case 3: {
				printf("Enter the value to be deleted\n");
				scanf("%d", &value);
				delete(hash_tab, value) == -1 ? printf("Element not present in hash table to delete.\n"):printf("Element deleted successfully\n");
				}
				break;
			default: exit(0);
		}
	}
	return 0;
}
