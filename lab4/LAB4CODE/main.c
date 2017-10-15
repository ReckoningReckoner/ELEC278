#include"avl.h"

// Code for ELEC278 Lab exercise 3.
//
// NOTE: When you first look at this code, you will see large portions have been
// commented out.  This is because they refer to functions that you will write
// as part of the lab work.  See the instructions in the lab handout.

int main(void) {
	int v1 = 1;
	Tree *t = initTree();
	insert(10, &v1, t);
	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");

	insert(3, &v1, t);

	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");

	insert(1, &v1, t);

	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");

	insert(7, &v1, t);

	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");

	insert(20, &v1, t);

	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");

	insert(15, &v1, t);

	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");

	insert(18, &v1, t);
	
	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");
	
	insert(17, &v1, t);
	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");
	
	insert(16, &v1, t);
	
	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");
	
	insert(22, &v1, t);
	printf("Inorder: ");
	inOrderT(t->root);
	printf("\n-------\n");
	

	return 0;
}
