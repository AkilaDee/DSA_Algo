#include <stdio.h>

int Fibonacci( int ) ;

void main(void)
  {
    int n ;
    printf("Input a number for a fibnacci value \n");
    scanf("%d", &n);
    printf("%d \n", Fibonacci(n) ) ;
}

int Fibonacci( int n )
{
  int Result ;
  if ( n == 0 )
    Result = 0 ;
  else
    if ( n == 1)
      Result = 1;
    else 
      Result = Fibonacci( n-1 ) + Fibonacci(n-2);
  return( Result ) ;
}
