#include "avl.h"

// Code for ELEC278 Lab 3.  Some code has already been implemented.
// You will develop your own code - look for the comments.

Node *initNode(Key k, void *v)
// Allocate memory for a new node and initialize fields.
// Returns pointer to node created.
{
	Node *n = malloc(sizeof(Node));
	n->key = k;
	n->value = v;
	n->leftChild = NULL;
	n->rightChild = NULL;
	n->height = -1;
	return n;

}

Tree *initTree()
// Set up a new tree. Allocates memory for the Tree structure,
// then calls initNode() to allocate the first node.
{
	Tree* t = malloc(sizeof(Tree));
	t->root = NULL;
	return t;
}

Node *find(Key k, Node *root) {
	// termination condition #1
	if (root == NULL)
	        return root;
	// termination condition #2
	else if (root->key == k)
		return root;
	else if (k > root->key)
		return find(k, root->rightChild);
	else
		return find(k, root->leftChild);

}

void insert(Key k, void *v, Tree *t) {
	printf("Inserting %d\n", k);
	if (t->root == NULL) {
		Node *n = initNode(k, v);
		n->height = 0;
		t->root = n;
		return;
	}
	t->root = insertNode(k, v, t->root);
}
Node* rotateRight(Node* root) {
    if (!root) {
        return NULL;
    }

    Node* new_parent = root->leftChild;
    if (!new_parent) {  // Cannot rotate!
        return NULL;
    }

    Node* new_parent_right = new_parent->rightChild;
    new_parent->rightChild = root;
    root->leftChild = new_parent_right;
    root->height = calcHeight(root);
    new_parent->height = calcHeight(new_parent);
    
    return new_parent;
}

Node* rotateLeft(Node* root) {
    if (!root) {
        return NULL;
    }

    Node* new_parent = root->rightChild;
    if (!new_parent) {  // Cannot rotate!
        return NULL;
    }

    Node* new_parent_left = new_parent->leftChild;
    new_parent->leftChild = root;
    root->rightChild = new_parent_left;
    root->height = calcHeight(root);
    new_parent->height = calcHeight(new_parent);

    return new_parent;
}

int getBalanceFactor(Node* root) {
    if (!root){
        return -1;
    }
    return calcHeight(root->leftChild) - calcHeight(root->rightChild);
}

int calcHeight(Node* root) {
    if (!root) {
        return -1;
    }

    Node* leftChild = root->leftChild;
    Node* rightChild = root->rightChild;
    int leftHeight = 0;
    int rightHeight = 0;

    if (leftChild) {
        leftHeight = leftChild->height + 1;
    }
    if (rightChild) {
        rightHeight = rightChild->height + 1;
    }

    return max(leftHeight, rightHeight);
}
Node* rebalance(Node* root) {
    int balance_factor = getBalanceFactor(root);
    if (-1 <= balance_factor && balance_factor <= 1) {
        return root;
    }
    printf("Node %d is unbalanced. ", root->key);
    if (balance_factor < -1) { // Right heavy
        if (getBalanceFactor(root->rightChild) < 0) { // Right of right
            printf("Right of Right: Rotate Left\n");
            return rotateLeft(root);
        } 
        else { // Left of right
            printf("Left of Right: Rotate Right\n");
            root->rightChild = rotateRight(root->rightChild);
            return rotateLeft(root);
        }
    }
    else if (balance_factor > 1) { // Left heavy
        if (getBalanceFactor(root->leftChild) > 0) { // Left of Left
            printf("Left of Left: Rotate Right\n");
            return rotateRight(root);
        } 
        else { // Right of left
            printf("Right of Left: Rotate Left\n");
            root->leftChild = rotateLeft(root->leftChild);
            return rotateRight(root);
        }
    }
    else { // Undefined scenario
        return NULL;
    }
}
Node* insertNode(Key k, void *v, Node *root) {

	/* already exists in tree ==> can't insert */
	if (!root) {
		Node *n = initNode(k, v);
		n->height = 0;
		return n;
	}
	if (k < root->key) {
		root->leftChild = insertNode(k, v, root->leftChild);
		root->height = calcHeight(root);
	}

	else if (k > root->key) {
		root->rightChild = insertNode(k, v, root->rightChild);
		root->height = calcHeight(root);
	}

	return rebalance(root);
}

void inOrderT(Node* root) {
	if (root) {
		inOrderT(root->leftChild);
		printf("%d(h=%d,bf=%d) - ", root->key, root->height,getBalanceFactor(root));
		inOrderT(root->rightChild);
	}
}

void printTree(Node* root) {
	// assume printTree magically know the types in the tree node
	printf("{");
	printf("(%ld,%d)", (long) root->key, *(int*) root->value); // need to cast the void pointer first
	printf(",");

	// left child.  if its NULL it will just print two empty braces
	if (root->leftChild) {
		printTree(root->leftChild);
	} else
		printf("{}");

	printf(",");

	// right child.  if its NULL it will just print two empty braces
	if (root->rightChild) {
		printTree(root->rightChild);
	} else
		printf("{}");

	printf("}");
}

int max(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}


int height(Node *root) {
	//termination condition: reached a leaf
	if (root->leftChild == NULL && root->rightChild == NULL)
		return 0; // height of leaf is zero
	else if (!root->rightChild) /* only left child */
		return 1 + height(root->leftChild);
	else if (!root->leftChild) /* only right child */
		return 1 + height(root->rightChild);
	else
		return 1 + max(height(root->leftChild), height(root->rightChild));
}

Node* findParentHelper(Key k, Node* root) {
	/* your code goes here    <<<<<<<<<<<<<<<*/
	if (!root)
		return NULL;

	if (root->leftChild != NULL && root->leftChild->key == k)
		return root;
	if (root->rightChild != NULL && root->rightChild->key == k)
		return root;

	if (root->key > k)
		return findParentHelper(k, root->leftChild);
	if (root->key < k)
		return findParentHelper(k, root->rightChild);
	return NULL;
}

Node* findParent(Key k, Node* root) {
	/* Deal with special special cases which could only happen for the root of the whole tree */
	if (root == NULL)
		return root;
	/* real root doesn't have a parent so we make it the parent of itself */
	if (root->key == k)
		return root;
	/* root has no children */
	if (!(root->leftChild) && !(root->rightChild))
		return NULL;

	/* Deal with the cases where the root has at least one child */
	return findParentHelper(k, root);
}
