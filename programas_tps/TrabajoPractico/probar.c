#include <stdio.h>
#include <stdlib.h>
#include <math.h>

  char vi,vf,di,df,t; 
  float fvi,fvf,fdi,fdf,ft;
  int flag = 0;
  int flag1 = 0;


void funciont(){
    if(df == '-' && di == '-' && t == '-' && vf != '-' && vi != '-'){
        ft = (fvf - fvi)/(-9.81);
        float vd = (pow(fvf,2)-pow(fvi,2))/(-19.6);
        printf("se recorre una distancia de %f\n",vd);
        flag = 1;
    }

    if(vf == '-' && vi != '-' && di != '-' && df != '-' && t == '-'){

        double discriminante = pow(fvi,2) - 4 * (fdi-fdf) * -4.9;
        ft = (-(fvi) + sqrt(discriminante)) / (2 * (fdi-fdf));
        ft = (-(fvi) - sqrt(discriminante)) / (2 * (fdi-fdf));
    }
        flag1 = 1;
}


void funcionvi(){

    if(df == '-' && di == '-' && t != '-' && vf != '-' && vi == '-'){

        fvi = fvf -9.8*ft;
        float vd = (pow(fvf,2)-pow(fvi,2))/(19.6);
        printf("Se recorre una distancia de %f\n",vd);
        flag = 1;
    }

    if(df != '-' && di != '-' && t != '-' && vf == '-' && vi == '-'){

        fvi = (fdf-fdi+(4.9*(pow(t,2))))/t;
    }

    if(df != '-' && di != '-' && t == '-' && vf != '-' && vi == '-'){

        fvi = pow(fvf,2)+(19.6*(fdf-fdi));
    }
        flag1 = 1;

}


void funcionvf(){

    if(vf == '-' && vi != '-' && di != '-' && df != '-' && t == '-'){
        fvf = sqrt((pow(fvi,2))-(19.6*(fdf-fdi)));
        
        if(ft == 0){
            ft = (fvf - fvi)/(-9.81);
        }
    }
    flag1 = 1;
}


void funcionprint(){

        if (flag1 == 1){
        printf("Velocidad inicial: %.2f",fvi);
        printf("\nVelocidad final: %.2f",fvf);
        if(flag == 0){
        printf("\nDistancia inicial: %.2f",fdi);
        printf("\nDistancia final: %.2f",fdf);
        }
        printf("\nTiempo: %.2f",ft);
    }
    else{
        printf("No se proporciona suficiente informacion");
    }
}




void main(){

    printf("Usted selecciono caida libre \n");
    printf("A continuacion se le va a pedir que ingrese los datos que posea, en caso de no conocerlo ingrese el simbolo '-'\n");
    printf("Velocidad inicial: ");
    scanf("%s",&vi);
    fvi = atof(&vi);

    printf("Velocidad final: ");
    scanf("%s",&vf); 
    fvf = atof(&vf);

    printf("Distancia inicial: ");
    scanf("%s",&di);
    fdi = atof(&di);

    printf("Distancia final: ");
    scanf("%s",&df); 
    fdf = atof(&df);

    printf("ingrese el tiempo en el que completo su trayectoria: ");
    scanf("%s",&t);
    ft = atof(&t);
    printf("\n\n\n");

    funciont();
    funcionvf();
    funcionvi();
    funcionprint();

}

