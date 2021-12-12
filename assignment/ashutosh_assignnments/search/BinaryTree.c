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
   int choice;
   int key;
   node *new_node, *root, *tmp, *parent;
   root = NULL;

   printf("\nProgram For Binary Search Tree ");
   do {
      printf("\n1.Create");
      printf("\n2.Search");
      printf("\n3.Recursive Traversals");
      printf("\n4.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);

      switch (choice) {
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
         scanf("%d", &key);

         tmp = search(root, key, &parent);
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
   } while (choice != 4);
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

int inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d\t", temp->data);
      inorder(temp->rchild);
   }
}

int preorder(node *temp) {
   if (temp != NULL) {
      printf("%d\t", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}

int postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d\t", temp->data);
   }
}
