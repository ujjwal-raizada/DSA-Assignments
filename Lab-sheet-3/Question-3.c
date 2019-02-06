#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

typedef struct link *node;

struct link {
	int data;
	node next;
};

node createNode() {
	node temp;
	temp = (node)malloc(sizeof(struct link));
	temp -> next = NULL;
	return temp;
}

node addNode(node Head, int value) {
	node temp, p;
	p = Head;
	temp = createNode();
	temp -> data = value;
	temp -> next = NULL;

	while (p -> next != NULL)
			p = p -> next;
	p -> next = temp;
	return Head;
}

node addStart(node Head, int value) {
	node temp, p;
	p = Head;
	temp = createNode();
	temp -> data = value;
	temp -> next = Head -> next;
	Head -> next = temp;
	return Head;

	
}

void transverse(node Head) {

	node p = Head;

	while (p -> next != NULL) {
		printf("%d ", p -> next -> data);
		p = p -> next;
	}

}


int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int k;
    scanf("%d", &k);

    node head1, head2;
    head1 = createNode();
    head2 = createNode();

    int x;
    scanf("%d", &x);
    int c = 0;

    while (x != -1) {
    	c++;
    	if (c % k == 0) {
    		head2 = addNode(head2, x);
    		c = 0;
    	}
    	else {
    		head1 = addStart(head1, x);
    	}


    	scanf("%d", &x);
    }

    node p = head2;

    while (p -> next != NULL)
    	p = p -> next;

    p -> next = head1 -> next;

    transverse(head2);


    return 0;
}