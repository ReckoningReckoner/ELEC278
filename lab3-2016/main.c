#include"bst.h"

// Code for ELEC278 Lab exercise 3.
//
// NOTE: When you first look at this code, you will see large portions have been
// commented out.  This is because they refer to functions that you will write
// as part of the lab work.  See the instructions in the lab handout.


int main(void)
{
	int v1 = 1;
	Tree *t = initTree (10,&v1);
	//insert(10,&v1,t->root);
	insert(3,&v1,t->root);
	insert(1,&v1,t->root);
	insert(7,&v1,t->root);
	insert(20,&v1,t->root);
	insert(15,&v1,t->root);
	insert(18,&v1,t->root);
	insert(17,&v1,t->root);
	insert(16,&v1,t->root);
	
	printf("Original Tree: \n");
	printTree(t->root);
	printf("\n\n");

	
	printf("Height of tree: %d\n\n", height(t->root));
    //Uncomment once you have implemented findParentHelper
	printf("Parent of root (key = 10): %d\n", findParent(10,t->root)->key);
	printf("Parent of leaf (key = 16): %d\n", findParent(16,t->root)->key);
	printf("Parent of other (key = 15): %d\n\n", findParent(15,t->root)->key);
	
    //Uncomment once you have implemented delete
    
    Node* n = NULL;
	printf("Tree after deleting 1:\n");
	withdraw(1,t->root,n);
	printTree(t->root);
	printf("\n\n");
	free(n);
	
	printf("Tree after deleting 3:\n");
	withdraw(3,t->root,n);
	printTree(t->root);
	printf("\n\n");
	free(n);

    printf("Tree after deleting 20:\n");
	withdraw(20,t->root,n);
	printTree(t->root);
	printf("\n");
	free(n);
	
	return 0;
}
