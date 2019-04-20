#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

typedef struct node * Node;

struct node {

	Node left;
	Node right;
	int data;

};



Node create(int val) {

	Node temp = (Node)malloc(sizeof(struct node));
	temp -> data = val;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;

}


Node insert(Node root, int val) {

	if (root == NULL)
		return create(val);

	if (val <= root -> data)
		root -> left = insert(root -> left, val);
	else
		root -> right = insert(root -> right, val);

	return root;

}

void print_preorder(Node root) {

	if (root == NULL)
		return;

	printf("%d ", root -> data);
	print_preorder(root -> left);
	print_preorder(root -> right);
	return;

}

void print_postorder(Node root) {

	if (root == NULL)
		return;

	print_postorder(root -> left);
	print_postorder(root -> right);
	printf("%d ", root -> data);
	return;

}

void print_inorder(Node root) {

	if (root == NULL)
		return;

	print_inorder(root -> left);
	printf("%d ", root -> data);
	print_inorder(root -> right);
	return;

}

Node findMin(Node root) {

	if (root -> left == NULL)
		return root;
	else
		return findMin(root -> left);

}

Node delete(Node root, int val) {

	if (root == NULL)
		return root;

	if (root -> data < val)
		root -> right = delete(root -> right, val);

	else if (root -> data > val)
		root -> left = delete(root -> left, val);

	else if (root -> left == NULL) {

		printf("Left node is NULL!\n");
		Node temp = root -> right;
		free(root);
		return temp;

	}

	else if (root -> right == NULL) {

		printf("Right node is NULL!\n");
		Node temp = root -> left;
		free(root);
		return temp;

	}

	else {

		printf("none of child node is NULL!\n");
		Node temp = findMin(root -> right);
		printf("inorder successor: %d\n", temp -> data);
		root -> data = temp -> data;
		
		root -> right = delete(root -> right, temp -> data);

	}

	return root;

}



int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

   //        50                            50
   //     /     \         delete(20)      /   \
   //    30      70       --------->    30     70 
   //   /  \    /  \                     \    /  \ 
   // 20   40  60   80                   40  60   80


      //     50                            50
      //  /     \         delete(30)      /   \
      // 30      70       --------->    40     70 
      //   \    /  \                          /  \ 
      //   40  60   80                       60   80


      //     50                            60
      //  /     \         delete(50)      /   \
      // 40      70       --------->    40    70 
      //        /  \                            \ 
      //       60   80                           80


    Node tree = NULL;

    tree = insert(tree, 50);
    tree = insert(tree, 30);
    tree = insert(tree, 70);
    tree = insert(tree, 20);
    tree = insert(tree, 40);
    tree = insert(tree, 60);
    tree = insert(tree, 80);

    tree = delete(tree, 20);
    tree = delete(tree, 30);
    tree = delete(tree, 50);
    
    print_inorder(tree);


    


    return 0;
}