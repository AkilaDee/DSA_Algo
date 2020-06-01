#include<stdio.h>
#define MAX 100
void insert();
void delete();
void display();
int arr[MAX];
int rear=-1;
int front=-1;
int main(){
	int n;
	while(1){
	
	printf("select one =1.enqueue  2.dequeue  3.display  ");
	scanf("%d",&n);
	switch (n){
	    case 1:
	    	insert();
		break;
		case 2:
			delete();
		break;
		case 3:
			display();
		break;
		default:
			printf("not valid");
		break;	
	}
}
}
void insert(){
	int num;
	if(rear==MAX-1){
		printf("queue is overflow");
	}else{
		if(front=-1){
			front=0;
		}
		printf("insert the element");
		scanf("%d",&num);
		rear++;
		arr[rear]=num;
		
	}

}
void delete(){
	if(front=-1||front>rear){
		printf("queue is empty");
	}else{
		printf("element deleted is %d",arr[front]);
		front++;
		
}
}
void display(){
	int i;
	if(front==-1||front>rear){
		printf("queue is empty");
	}else{
		for(i=front;i<=rear;i++){
			printf("%d ",arr[i]);
		}
		
}
}




