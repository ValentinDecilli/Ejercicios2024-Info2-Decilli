#include <stdio.h>
#include <math.h>

struct punto2D{
    float x;
    float y;
};


float distancias(struct punto2D PP){

    float d = pow(PP.x, 2) + pow(PP.y, 2); 
    d = sqrt(d);
    return d;
}

int main(){

    float mayor;
    struct punto2D P1, P2;
    P1.x = 5, P1.y = 3;

    P2.x = 7, P2.y = 8;

    float valor1 = distancias(P1);
    printf("El valor del primer modulo es: %f\n",valor1);

    float valor2 = distancias(P2);
    printf("El valor del segundo modulo es: %f\n",valor2);

    if(valor1 >= valor2){
        mayor = valor1;
    }
    else{
        mayor = valor2;   
    }

    printf("Valor de distancia al punto de origen es : %f",mayor);
}

