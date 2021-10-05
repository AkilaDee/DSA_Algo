#include <stdio.h>
#define SIZE 10
int items[SIZE];
int front = -1, rear =-1;
int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}
int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}
void insert(int element)
{
    if(isFull()) printf("\n Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}
int delete()
{
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else {
            front = (front + 1) % SIZE;
            
        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}
void display()
{
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}
int main(){
//  int choice,item;
//  do{
//     printf(" 1.Insert \n");
//     printf(" 2.Delete \n");
//	printf(" 3.Display \n");
//	printf(" 4.Quit \n");
//	printf(" Enter your choice : \n");
//	scanf("%d",&choice);
//	switch(choice)
//{
//	case 1 :
//		printf("Input the element for insertion in queue : ");
//		scanf("%d", &item);
//		insert(item);
//	break;
//	case 2 :
//		delete();
//	break;
//	case 3:
//		display();
//	break;
//	case 4:
//	break;
//	default:
//		printf("Wrong choicen");
//   }
//  }while(choice!=4);
//return 0;
int k;
	for(k=1;k<=7;k++){
		insert(k);
		
			for(k=1;k<=7;k++){
				insert(delete());
			}
	
	}
 display();	
}

