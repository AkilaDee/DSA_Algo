#include<stdio.h>
#include<string.h>
#define MAX 20
#define true 1
#define false 0
int arr[MAX];
int top=-1;
char push(char item){
	if(top==MAX-1)
	    printf("overflow");
	else{
		top=top+1;
		arr[top]=item;
	}    
}
char pop(){
	if(top==-1)
	   printf("stack underflow");
	else
	return(arr[top--]) ;  
}


int main(){
	int i;
	int valid=true;
	char temp;
	char exp[MAX];
	printf("enter an expression :");
	gets(exp);
	for( i=0;i<strlen(exp);i++){
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
			push(exp[i]);
		}if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
			if(top==-1){
				valid=false;
			}else{
				temp=pop();
				if(exp[i]==')'&&(temp=='{'||temp=='[')){
					valid=false;
				}if(exp[i]=='}'&&(temp=='('||temp=='[')){
					valid=false;
		     	}if(exp[i]==']'&&(temp=='{'||temp=='()')){
					valid=false;
			    }
			}
		}
		  
	}
	if(top>=0){
		valid=false;
	}if(valid==false)
	printf("expression is invalid");
   else
   printf("expression is valid");
   
}


