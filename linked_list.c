#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;

void insertFront(struct node *abc){
	struct node *new=malloc(sizeof(struct node));
	printf("enter element to front:");
	scanf("%d",&new->data);
	new->next=abc;
	new->prev=NULL;
	head=new;
}
void printList(struct node *akila){
	 struct node *temp=akila;
    while(temp!=NULL){
	
    printf("%d\n",temp->data);
    
    temp=temp->next;
}
}

void deleteFirst(){

	struct node *temp;
	temp=head;
	head=head->next;
	free(temp);
	
}
void insertMid(){
	struct node *temp=head;
	int n;
	struct node *num;
	num=malloc(sizeof(struct node));
	printf("number should be inserted after which node:");
	scanf("%d",&n);
	printf("enter number:");
	scanf("%d",&num->data);
	while(temp->next->data!=n){
		temp=temp->next;
	}
	num->next=temp->next;
	temp->next=num;
	
	
	
}

void enterLast(struct node *num){
	struct node *temp=num;
	struct node *n;
	n=malloc(sizeof(struct node));
	while(temp->next!=NULL){
		temp=temp->next;
	}
	printf("enter the last node:");
	scanf("%d",&n->data);
	temp->next=n;
	n->next=NULL;
	n->prev=temp;
}

int main(){
	struct node *one=NULL;
	struct node *two=NULL;
	struct node *three=NULL;
	struct node *four=NULL;
	struct node *five=NULL;
	
	one=malloc(sizeof(struct node));
	two=malloc(sizeof(struct node));
	three=malloc(sizeof(struct node));
	four=malloc(sizeof(struct node));
	five=malloc(sizeof(struct node));
	
	 
    one->data=10;
    two->data=20;
    three->data=30;
    four->data=40;
    five->data=50;
	
	one->next=two;
	one->prev=NULL;
	two->next=three;
	two->prev=one;
	three->next=four;
	three->prev=two;
	four->next=five;
	four->prev=three;
	five->next=NULL;
	five->prev=four;
	
	head=one;
	
	insertFront(head);
    deleteFirst();
    enterLast(head);
    insertMid();
	printList(head);

	

}
