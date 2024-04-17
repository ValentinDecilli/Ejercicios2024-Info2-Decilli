
#include <stdio.h>
#include <math.h>


void main (void){

    int almacen;

    int numeros[100];
    int i;
    int sumapar = 0;
    int sumaimpar = 0; 

    printf("ingrese la cantidad de numeros que desee sumar: ");
    scanf("%d",&almacen);

    printf("\nIngrese los numeros: ");

    for(i = 0 ; i < almacen ; i++){

        printf("\n");
        scanf("%d",&numeros[i]);
    }

    for(i = 0 ; i < almacen ; i++){

        if(numeros[i]%2 == 0){

            sumapar += numeros[i];
        } 
        else {
            sumaimpar += numeros[i];
        }
    }

    printf("El resultado de la suma de numeros par es : %d",sumapar);
    printf("\nEl resultado de la suma de numeros impar es : %d",sumaimpar);

}