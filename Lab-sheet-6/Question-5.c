#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

typedef struct node * Node;

struct node
{
	int data;
	Node next;
	
};

Node newNode() {
	Node temp = (Node)malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

Node addNode(Node head, int value) {

	Node p = head;
	while (p -> next != NULL)
		p = p -> next;

	Node New = newNode();
	New -> data = value;
	p -> next = New;
	return head;

}

void print(Node head1) {
	Node temp = head1;
    while (temp -> next != NULL) {
    	printf("%d ", temp -> next -> data);
    	temp = temp -> next;
    }
    printf("\n");
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node head1 = newNode();
    Node head2 = newNode();

    int n;
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
    	int t;
    	scanf("%d", &t);
    	head1 = addNode(head1, t);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
    	int t;
    	scanf("%d", &t);
    	head2 = addNode(head2, t);
    }
    print(head2);

    Node p1 = head1 -> next;
    Node p2 = head2 -> next;
    Node p = p1;
    p1 = p1 -> next;

    while (p1 -> next != NULL || p2 -> next != NULL) {

    	if (p1 -> data < p2 -> data) {
    		
    		p -> next = p1;
    		p = p1;
    		p1 = p1 -> next;
    	}
    	else {
    		p -> next = p2;
    		p = p2;
    		p2 = p2 -> next;
    	}

    }

    print(head1);





    


    return 0;
}