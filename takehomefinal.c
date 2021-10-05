#include<stdio.h>
#include<stdlib.h>

#define MAX 2560
#define MIN 400
 	
struct node {
	int pid;
	int startadd;
	int endadd;
	int type; //if type==0 free block,
	int size;
	struct node *next;
}; 	


struct node *start=NULL;
struct node* currentMemory=NULL;


void allocate();
void deallocate();
void display();
struct node* create_node(int a, int b);

void create_memory(){
	
    
	
 }
 int main(){
 	create_memory();
 	
	int choice;
	
	while(1){
		printf("\n\tenter choice \n\t 1. Allocate memory \n\t 2. DeAllocate \n\t 3.Review Memory \n\t 0.Exit \n\t-:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				{
					allocate();
					break;
				}
			case 2:
			   {
			   	    deallocate();
			   	    break;
				}
			case 3:
			   {
			   	    display();
			   	    break;
				}	
			case 0:
			    {
			       exit(0);
				   break;	
				}		
			default :
			    {
			    	printf("enter valid choice");
				}	
		}
		
	}
}

void allocate(){
	int amount,pr,count_size=0;
	printf("Enter process id:\n");
	scanf("%d",&pr);
	printf("Enter amount to allocate :\n");
	scanf("%d",&amount);

	struct node *temp, *ptr,*preptr;

	
	if(start==NULL){
			
		struct node *memory=malloc(sizeof(struct node));

		memory->type=0;
		memory->pid=0;
		memory->size=2560;
		memory->startadd=0;
		memory->endadd=0;
		memory->next=NULL;
		start=memory;
	

		if(amount>memory->size-MIN){
			printf("Can not allocate\n");
		}else{
	
			struct node *temp1=	create_node(amount, pr);
			temp1->next=memory;
			temp1->endadd=amount;
			temp1->startadd=0;
			temp1->pid=pr;
			
			start=temp1;
			printf("Successfully allocated!\n");
			memory->size=memory->size-start->size;
			currentMemory=memory;
		
		}	
    }else{
    	if(amount<=currentMemory->size){
		
		ptr=start;
		preptr=ptr;
		temp=create_node(amount, pr);
		
		while(ptr->next->type!=0&&ptr->next->size<=amount){
			preptr=ptr;
			ptr=ptr->next;
			
			count_size+=ptr->size;
		}
		temp->next=ptr->next;
	ptr->next=temp;
	//	ptr=temp;
		
		temp->startadd=count_size+1;
		temp->endadd=count_size+amount+1;
		
		currentMemory->size=currentMemory->size-amount;
		printf("Successfully allocated!\n");
					
	}
	else{
	printf("cannot allocate");
}
}
}

void deallocate(){

	struct node* temp;
	struct node *preptr=start;
	struct node *ptr=start;
    int pID;
	printf("Enter proccess ID\n");
	scanf("%d", &pID);
	
	while(ptr!=NULL){
		if(ptr->pid==pID){
			currentMemory->size=(currentMemory->size)+(ptr->size);
			ptr->type=0;
		//	printf("%d",ptr->size);
			preptr->next=ptr->next;
		//	free(ptr);
			break;
			if(ptr->next->pid==0){
				struct node* temp = ptr->next;
				ptr->size+=temp->size;
				ptr->endadd=temp->endadd;
				ptr->next=temp->next;
			//	free(temp);
			}
			if(preptr->type==0){
				preptr->size+=ptr->size;
				preptr->endadd=ptr->endadd;
				preptr->next=ptr->next;
				//free(ptr);
			}
		} 
		preptr=ptr;
		ptr=ptr->next;
	}
	
		printf("Successfully Deallocated.");
}

void display(){
	
	    printf("Used memory space by OS     :%d \n",MIN);
	    printf("Allocated memory space      :%d \n",MAX-currentMemory->size);
		printf("Available memory space      :%d \n",currentMemory->size-MIN);
		
	}
	
	

struct node* create_node(int a, int b){
	struct node* newNode = malloc(sizeof(struct node));
	newNode->size=a;
	newNode->endadd=0;
	newNode->next=NULL;
	newNode->startadd=0;
	newNode->type=1;
	newNode->pid=b;
	
	return newNode;
}


