#include <stdio.h>

int main(){

    int a = 5;
    int b = 6;
  
    int *pa = &a;
    int *pb = &b;

    int c = *pa;
    a = *pb;
    b = c; 

    printf("%d %d",a,b); 
}