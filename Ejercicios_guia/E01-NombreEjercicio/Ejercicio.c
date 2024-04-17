#include <stdio.h>
#include <math.h>

int main(){

    int tam,condicion;
    float valor = 0;

    printf("Ingrese la cantidad de numeros que quiere calcular: ");
    scanf("%d",&tam);

    float numeros[tam];

    printf("ingrese los numeros a calcular: \n");
    printf("-");

      for(int i = 0 ; i < tam ; i++){
        scanf("%f",&numeros[i]);
        printf("-");
        valor = valor + numeros[i];
    }

    do{
        printf("Para proceder al calculo ingrese el numero 9999: ");
        scanf("%d",&condicion);

    }while(condicion != 9999);

    float promedio = valor / tam;

    printf("El valor de su promedio es : %f", promedio);
}    

