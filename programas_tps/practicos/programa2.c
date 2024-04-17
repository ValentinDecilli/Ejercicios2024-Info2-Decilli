#include <stdio.h>
#include <math.h>

int main(){

    int numero = 7;
    int flag = 0;

    for(int i = 1 ; i <= numero ; i++){

        if(numero % i == 0 && i != 1 && i != numero){

            flag = 1;
        }
    }

    if (flag == 1){
        printf("su numero no es primo");
    }
    else{
        printf("su numero es primo");       
    }

}
