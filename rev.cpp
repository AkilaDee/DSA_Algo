#include<iostream>
#include<string.h>

using namespace std;

int main() {
  
  string word;
  cout<<"enter string";
  cin>>word;
  
  int len = word.length();
  int n=len-1;
  for(int i=0;i<(len/2);i++,n--){

    char temp = word[i];
    word[i] = word[n];
    word[n] = temp;
    

  }
  cout<<word<<endl;
}
