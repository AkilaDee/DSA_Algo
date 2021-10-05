#include<iostream>
#include<string.h>

using namespace std;

int main(){
	int n=4;
	for(int i=0;i<=n;i++){
		for(int j=0;j<i;j++){
			cout<<" ";
		}
		for(int k=n;k>i;k--){
			cout<<"*";
		}
	cout<<endl;
	}
	
	

	
}
