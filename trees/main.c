#include <stdio.h>
#include <stdlib.h>

struct node
{
  int value;
  struct node *left;
  struct node *right;
};

struct bst
{
  struct node *root;
};

struct node* create_node(int value)
{
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->value = value;
  temp->left = temp->right = NULL;
  return temp;
}

struct node* insert(struct node* n, int value)
{
  if(!n)
    return  create_node(value);
  if(value > n->value)
    n->right = insert(n->right,value);
  if(value < n->value)
    n->left = insert(n->left,value);
  return n;
}

void inorder(struct node* n)
{
  if(n != NULL)
  {
    inorder(n->left);
    printf("%d\n", n->value);
    inorder(n->right);
  }
}

int search(struct node* n, int key)
{
  while(n)
  {
    if(n->value == key)
      return 1;
    else if(n->value > key)
      n = n->left;
    else
      n = n->right;
  }
  return 0;
}

int main()
{
  struct  node *tree = NULL;
  tree = insert(tree, 2);
  insert(tree, 1);
  insert(tree, 3);
  inorder(tree);

  printf("%d\n", search(tree,1));
  printf("%d\n", search(tree,10));
  return 0;
}
