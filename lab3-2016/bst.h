// BST.H

#ifndef BST_H_
#define BST_H_
#include <stdlib.h>
#include <stdio.h>

typedef int Key;

// Node in tree has key and pointer to value associated with key.
// Also contains structural components - two pointers to left and
// right subtrees.
typedef struct Node	{
	Key		key ;
	void	*value ;
	struct Node		*leftChild, *rightChild ;
} Node ;

// Tree is basically pointer to top node in a tree.
typedef struct Tree
{
	Node *root ;
} Tree ;


// Prototypes for functions found in BST.C
/**
  * Create a new node with key = k and value = v 
  */
Node *initNode (Key k, void *v);

/**
  * Create a new tree by creating a new node with key = k and value = v and making it the root 
  */
Tree *initTree(Key k, void *v);

/** 
  * Find a node with key k in the tree.  
  * Returns NULL if not found 
  */
Node *find( Key k, Node *root );

/** Create a new node with key=k, value=v and insert it into the tree 
  * Returns 1 upon success 0 otherwise 
  */
int insert(Key k, void *v, Node *root);

/**
  * Print the text representation of the tree
  */
void printTree (Node* root);

/**
  * Returns the Maximum of two numbers 
  */
int max(int a, int b);

/** 
  * Find the parent of a node n where n->key = k
  * Returns NULL if not found
  */
Node* findParent(Key k, Node* root);

/**
  * 1. Make a copy of the node with key=k and returns it
  * 2. Delete node with key=k from the tree
  * Returns NULL if not such node is found
  */
Node* widthdraw(Key k, Node* root);


/* functions you will implement */
/**
  * Return the height of the tree (height of the root)
  */
int height(Node *root);

/**
  * Helper function for findParent
  */
Node* findParentHelper(Key k, Node* root);

/** 
  * Delete a node from the tree while ensuring the tree remains valid
  */  
void delete(Node* p, Node *n);
#endif
