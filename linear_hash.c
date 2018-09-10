#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define deleted INT_MIN
#define hash 101

int get_hash_value(int value)
{
	return value % hash;
}

int is_free_for_insert(int ar[], int i)
{
	return ar[i] == 0 || ar[i] == deleted ? 0 : 1;
}

int is_not_free(int ar[], int i)
{
	return ar[i] == 0 ? 0 : 1;
}

int search(int ar[], int value, int capacity) {
	int i;
	i = get_hash_value(value);

	while (is_not_free(ar, i) && ar[i] != value && i < capacity) {
		i++;
	}
	
	if(i != capacity && ar[i] == value) {
		printf("Element found at index %d\n", i);
		return i;
	}
	printf("Element not found\n");
	return -1;
}

void delete(int ar[], int value, int capacity) {
	int i;
	i = get_hash_value(value);

	int position;
	position = search(ar, value, capacity);

	if(position != -1) {
	        ar[position] = deleted;
		printf("deleted\n");
		return;
	}
	printf("Not Present\n");
}	



void insert(int ar[], int value, int capacity) {
	int i;
	i = get_hash_value(value);

	while (is_free_for_insert(ar, i) && i < capacity) {
		i++;
	}
	
	if (i != capacity) {
		ar[i] = value;
	}
}

int main()
{
	int size;
	size = 100;
	int ar[100] = {0};
	
	int choice;
	int value;
	
	while (1) {
		printf("1.Insert 2.Delete 3.Search 4.Exit \n");
		scanf("%d", &choice);
		switch(choice) {

			case 1:{
				       printf("Read value to enter\n");
				       scanf("%d", &value);
				       insert(ar, value, size);
			       }
			       break;
			case 2:{
				       printf("Read value to delete\n");
				       scanf("%d", &value);
				       delete(ar,value,size);
			       }
			       break;
			case 3:{
				       printf("Read value to search\n");
				       scanf("%d", &value);
				       search(ar, value, size);
			       }
			       break;
			default:exit(0);
		}
	}
	return 0;
}

