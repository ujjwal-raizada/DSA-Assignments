#include<stdio.h>
#include<stdlib.h>
#define ll long long

struct node {
	struct node *next;
	struct node *prev;
	int data;
};

struct node* new_node(int value) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp -> next = NULL;
	temp -> prev = NULL;
	temp -> data = value;

	return temp;
}

void print_list(struct node *head) {

	struct node *temp = head;
	while(temp -> next != NULL) {
		printf("%d ", temp -> next -> data);
		temp = temp -> next;
	}
	printf("\n");

}

void print_list_reverse(struct node *tail) {

	struct node *temp = tail;
	while(temp -> prev != NULL) {
		printf("%d ", temp -> prev -> data);
		temp = temp -> prev;
	}
	printf("\n");

}

struct node* single_linked_list(struct node *head) {
	//node *head = (node)malloc(sizeof(struct node));
	struct node *temp = head;
	int choice = 0;
	do {

		int v;
		printf("Enter Value: ");
		scanf("%d", &v);
		struct node *t = new_node(v);
		temp -> next = t;
		temp = t; 


		printf("Add elements:\n0: Yes\n1: No\n:");
		scanf("%d", &choice);

	}while(choice == 0);
	return head;
}

struct node* double_linked_list(struct node *head, struct node *tail) {
	//node *head = (node)malloc(sizeof(struct node));
	struct node *temp = head;
	tail -> next = NULL;
	tail -> prev = head -> next;
	int choice = 0;
	do {

		int v;
		printf("Enter Value: ");
		scanf("%d", &v);
		struct node *t = new_node(v);
		temp -> next = t;
		t -> prev = temp;
		temp = t;
		tail -> prev = temp;


		printf("Add elements:\n0: Yes\n1: No\n:");
		scanf("%d", &choice);

	}while(choice == 0);
	return head;
}

struct node* circular_linked_list(struct node *head) {
	//node *head = (node)malloc(sizeof(struct node));
	struct node *temp = head;
	int choice = 0;
	do {

		int v;
		printf("Enter Value: ");
		scanf("%d", &v);
		struct node *t = new_node(v);
		temp -> next = t;
		temp = t;
		temp -> next = head -> next;


		printf("Add elements:\n0: Yes\n1: No\n:");
		scanf("%d", &choice);

	}while(choice == 0);
	return head;
}



int main() {
	    //Using text files for input output
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> next = NULL;
    head -> prev = NULL;
    struct node *tail = (struct node*)malloc(sizeof(struct node));
    tail -> next = NULL;
    tail -> prev = NULL;
    circular_linked_list(head);
    print_list(head);



	return 0;
}