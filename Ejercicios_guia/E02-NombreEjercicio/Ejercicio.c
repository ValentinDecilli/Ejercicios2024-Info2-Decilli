#include <stdio.h>
#include <math.h>

int main(){

    float intereses[] = {0.05,0.06,0.08,0.09,0.10};
    float valor = 1000;
    int i,j,k;
    float valores[11];
    char porcientos[] = {5,6,8,9,10};

    for(k = 0 ; k <= 4 ; k++){

        valor = 1000;
        printf("Interes del %d%\n",porcientos[k]);

            for (i = 0 ; i <= 10 ; i++){

                valores[i] = valor;
                for(j = 1 ; j <= 12 ; j++){

                    valor = valores[i] * pow(1+intereses[k],12);         
                }
            }

        for( i = 1 ; i <= 10 ; i++){
            printf("El valor de su dinero en el %d° año es: %f\n",i , valores[i]);
        }
    }
}
