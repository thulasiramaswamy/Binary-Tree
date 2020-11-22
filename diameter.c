/* C Program to find diameter of a binary tree */
/* Diameter is the number of nodes in the longest path from one node to any other node in a binary tree
It is not necessary that diameter of a tree passes through a root */
#include <stdio.h>
#include <stdio.h>

struct Node
{
 int dat;
 struct Node* left;
 struct Node* right;
};
struct Node* newNode(int value)
{
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 temp->dat = value;
 temp->left = temp->right = NULL;
 return temp;
}
/*
1. Find the height of left sub tree
2. Find the height of right sub tree
3. Find the diameter of left sub tree using recursion
4. Find the diameter of right sub tree using recursion
5. take the max of (lheight + rheight + 1), max(ldiameter, rdiameter) 
*/
int diameter(struct Node* p)
{
 if(p == NULL) return 0;
 int lheight = height(p->left);
 int rheight = height(p->right);
 int ldiameter = diameter(p->left);
 int rdiameter = diameter(p->right);
 int fd = max((lheight + rheight + 1), max(ldiameter, rdiameter));
 return fd;
}
int main()
{
 struct node* root = newNode(1); 
 root->left = newNode(2); 
 root->right = newNode(3); 
 root->left->left = newNode(4); 
 root->left->right = newNode(5); 
  
 printf("Diameter of the given binary tree is %d\n", diameter(root)); 
 return 0;
}
