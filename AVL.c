
#include <stdio.h>
#include <stdlib.h>
typedef enum{FALSE,TRUE} boolean;
struct node{
int info;
int balance;
struct node* lchild;
struct node* rchild;
};
struct node* insert(int, struct node*, int*);
struct node* search(struct node*, int);
void display(struct node*, int);    
void inorder(struct node*);          
int main(){
int ht_inc = FALSE; 
int info;
int choice;
struct node* root = NULL;
printf("1.Insert\n");
printf("2.Display\n");
printf("3.Exit\n");
while(1){
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice){
case 1:
printf("Enter the value to be inserted: ");
scanf("%d", &info);
if(search(root, info) == NULL)
root = insert(info, root, &ht_inc);
else
printf("Duplicate value ignored\n");
break;
case 2:
if(root == NULL){
printf("Tree is empty\n");
continue;
}
printf("Tree is:\n");
display(root, 1);
printf("\n\n");
printf("Inorder traversal is:\n");
inorder(root);
printf("\n");
break;
case 3:
exit(0);  
default:
printf("Wrong choice\n");
}
}
return 0;   
}
struct node* search(struct node* ptr, int info){
if(ptr != NULL){
if(info < ptr->info)
ptr = search(ptr->lchild, info);
else if(info > ptr->info)
ptr = search(ptr->rchild, info);
}
return(ptr);
}
struct node* insert(int info, struct node* pptr, int* ht_inc){
struct node* aptr;
struct node* bptr;
if(pptr == NULL){
pptr = (struct node*)malloc(sizeof(struct node));
pptr->info = info;
pptr->lchild = NULL;
pptr->rchild = NULL;
pptr->balance = 0;
*ht_inc = TRUE;
return(pptr);
}
if(info < pptr->info){
pptr->lchild = insert(info, pptr->lchild, ht_inc);
if(*ht_inc == TRUE){
switch(pptr->balance){
case -1:
pptr->balance = 0;
*ht_inc = FALSE;
break;
case 0:
pptr->balance = 1;
break;
case 1:
aptr = pptr->lchild;
if(aptr->balance == 1){
printf("Left to left rotation\n");
pptr->lchild = aptr->rchild;
pptr->balance = 0;
aptr->balance = 0;
pptr = aptr;
}
else{
printf("Left to right rotation\n");
bptr = aptr->rchild;
aptr->rchild = bptr->lchild;
bptr->lchild = aptr;
pptr->lchild = bptr->rchild;
bptr->rchild = pptr;
if(bptr->balance == 1)
pptr->balance = -1;
else
pptr->balance = 0;
if(bptr->balance == -1)
aptr->balance = 1;
else
aptr->balance = 0;
bptr->balance = 0;
pptr = bptr;
}
*ht_inc = FALSE;
}
}
if(info > pptr->info){
pptr->rchild = insert(info, pptr->rchild, ht_inc);
if(*ht_inc == TRUE){
switch(pptr->balance){
case 1:
pptr->balance = 0;
*ht_inc = FALSE;
break;
case 0:
pptr->balance = -1;
break;
case -1:
aptr = pptr->rchild;
if(aptr->balance == -1){
printf("Right to right rotation\n");
pptr->rchild = aptr->lchild;
aptr->lchild = pptr;
pptr->balance = 0;
aptr->balance = 0;
pptr = aptr;
}
else{
printf("Right to left rotation\n");
bptr = aptr->lchild;
aptr->lchild = bptr->rchild;
bptr->rchild = aptr;
pptr->rchild = bptr->lchild;
bptr->lchild = pptr;
if(bptr->balance == -1)
pptr->balance = 0;
else
pptr->balance = -1;
if(bptr->balance == 1)
aptr->balance = 0;
else
aptr->balance = -1;
bptr->balance = 0;
pptr = bptr;
}
}
}
return(pptr);
}
void display(struct node* ptr, int level){
int i;
if(ptr != NULL){
display(ptr->rchild, level + 1);
printf("\n");
for(i = 0; i < level; i++)
printf(" ");
printf("%d", ptr->info);
display(ptr->lchild, level + 1);
}
}
void inorder(struct node* ptr){
if(ptr != NULL){
inorder(ptr->lchild);
printf("%d ", ptr->info);
inorder(ptr->rchild);
}
}
