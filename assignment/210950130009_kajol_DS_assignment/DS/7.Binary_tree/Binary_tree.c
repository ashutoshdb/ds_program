#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct BST 
{
   int data;
   struct BST *lchild;
   struct BST *rchild;
}node;

node *search(node *, int, node **);
node *get_node();

int main()
{
   int c;
   int num;
   node *new_node, *root, *tmp, *parent;
   root = NULL;

  
   while (1)
   {
      printf("\n1.Create");
      printf("\n2.Search");
      printf("\n3.Recursive Traversals");
      printf("\n4.Exit");
      
      
      printf("\nEnter your choice :");
      scanf("%d", &c);

      switch (c) {
      case 1:
            new_node = get_node();
            printf("\nEnter The Element ");
            scanf("%d", &new_node->data);

            if (root == NULL) /* Tree is not Created */
               root = new_node;
            else
               insert(root, new_node);

         break;

      case 2:
         printf("\nEnter Element to be searched :");
         scanf("%d", &num);

         tmp = search(root, num, &parent);
         printf("\nParent of node %d is %d", tmp->data, parent->data);
         break;

      case 3:
         if (root == NULL)
            printf("Tree Is Not Created");
         else {
            printf("\nThe In-order display : ");
            inorder(root);
            printf("\nThe Pre-order display : ");
            preorder(root);
            printf("\nThe Post-order display : ");
            postorder(root);
         }
         break;
      }
   } 
   return 0;
}

/* Get new Node */

node *get_node() 
{
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}
/*
This function is for creating a binary search tree
*/
int insert(node *root, node *new_node) {
   if (new_node->data < root->data) {
      if (root->lchild == NULL)
         root->lchild = new_node;
      else
         insert(root->lchild, new_node);
   }

   if (new_node->data > root->data) {
      if (root->rchild == NULL)
         root->rchild = new_node;
      else
         insert(root->rchild, new_node);
   }
}
/*
This function is for searching the node from
binary Search Tree
*/
node *search(node *root, int key, node **parent) {
   node *temp;
   temp = root;
   while (temp != NULL)
  {
      if (temp->data == key) {
         printf("\nThe %d Element is Present", temp->data);
         return temp;
      }
      *parent = temp;

      if (temp->data > key)
         temp = temp->lchild;
      else
         temp = temp->rchild;
   }
   return NULL;
}
/*
This function displays the tree in inorder fashion
*/
int inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d\t", temp->data);
      inorder(temp->rchild);
   }
}
/*
This function displays the tree in preorder fashion
*/
int preorder(node *temp) {
   if (temp != NULL) {
      printf("%d\t", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}
/*
This function displays the tree in postorder fashion
*/
int postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d\t", temp->data);
   }
}


