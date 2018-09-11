#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * create_node()
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
}

void prt_ll(struct node *head)
{
	while (head) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
	
void delete_odd_nodes(struct node **head) 
{
	if (*head == NULL) {
		return;
	}
	struct node *temp = NULL;

	/* deletes all the beginning nodes until we find a null or a even value node */
	while (*head != NULL && ((*head)->data % 2) == 1) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
		temp = NULL;
	}

	if (*head == NULL) {
		return;
	}

	struct node *prev = NULL;
	prev = *head;
	struct node *curr = NULL;
	curr = (*head)->next;
	while (curr) {
		if((curr->data % 2) == 1) {
			temp = curr;
			prev->next = curr->next;
			curr = curr->next;
			free(temp);
			temp = NULL;
		}
		else {
			prev = curr;
			curr = curr->next; 
		}	
	}
}
		 
	


void insert(struct node **head, struct node **tail, int value) 
{
	struct node *newnode = create_node();
	newnode->data = value;
	newnode->next = NULL;

	/* maintaining tail pointer to optimize insertion at the end to O(1) */

	if (*head == NULL) {
		*head = newnode;
		*tail = newnode;
		return;
	}
	(*tail)->next = newnode;
	*tail = newnode;
}	

int main() 
{	struct node *head = NULL;
	struct node *tail = NULL;
	int n;
	int value;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &value);
		insert(&head, &tail, value);
	}
	prt_ll(head);

	/* Time complexity : O(n) space : O(1) */
	delete_odd_nodes(&head);
	prt_ll(head);

	return 0;
}	
