#include <stdio.h>

long int Factorial( int ) ;

void main(void)
 {
    int n ;
    printf("Input a number for a factorial value \n");
    scanf("%d", &n);
    printf("%ld \n", Factorial(n) ) ;
}

long int Factorial(int n){
    if(n == 0) return 1;
    return n * Factorial(n - 1);
}
