#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define pi 3.14

char opcion;
int flag = 0;
char variable[1];
float fvariable, pymax;
long long unsigned int i;

void lectura();

typedef struct vchar
{
    char v1[2];
    char v2[2];
    char v3[2];
    char p0[2];
    char p01[2];
    char pf[2];
    char pf1[2]; 
    char t[2];
    char a[2];
    char agl[2];
    char f[2];
    char p[2];
    char r[2];

}vchar;

vchar c1,c2,c3;

typedef struct vfloat
{
    float v1;
    float v2;
    float v3;
    float p0;
    float p01;
    float pf;
    float pf1;
    float agl;
    float t;
    float a;
    float dd;
    float p;
    float f;
    float r;

}vfloat;

vfloat b1,b2,b3;

int flag1,flag2,flag3,flag4,flag5,flag6,flag7,flag8,flag9;


//----------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------CALCULO DE TIEMPO----------------------------------------------------------------------

void funciont() {

    if (opcion == 'A'){
        if (*c1.t == '*' && *c1.v2 != '*' && *c1.v1 != '*') {
            b1.t = (b1.v1 - b1.v2) / 9.8;
            *c1.t = '-';
        }

        if (*c1.t == '*' && *c1.v1 != '*' && *c1.p0 != '*' && *c1.pf != '*') {   

            double b = b1.v1;
            double c = b1.p0 - b1.pf;
            double discriminante = b * b - 4 * (-4.9) * c; 
            *c1.t = '-';

            if (discriminante >= 0) {
                double t1 = (-b + sqrt(discriminante)) / (2 * (-4.9));
                double t2 = (-b - sqrt(discriminante)) / (2 * (-4.9));
                b1.t = (t1 > 0) ? t1 : t2;
            } 
            else {
                printf("No hay solucion real para el tiempo con los datos proporcionados.\n");
            }
        }
    }

    else if (opcion == 'B'){

        if (*c2.t == '*' && *c2.v3 != '*'){

            b2.t = 2 * b2.v3 /(9.8); 
            *c2.t = '-';
        }

        if (*c2.t == '*' && *c2.v1 != '*' && *c2.pf != '*' && *c2.agl != '*' && *c2.p0 != '*'){
            
            b2.t = (b2.pf - b2.p0) / (b2.v1 * cos(b2.agl));
            *c2.t = '-';
        }   

        if (*c2.t == '*' && *c2.v1 != '*' && *c2.pf1 != '*' && *c2.agl != '*' && *c2.p01 != '*'){
            
            double b = b2.v1 * sin(b2.agl);
            double c = b2.p01 - b2.pf1;
            double discriminante = b * b - 4 * (-4.9) * c; 
            *c2.t = '-';
            if (discriminante >= 0) {
                double t1 = (-b + sqrt(discriminante)) / (2 * (-4.9));
                double t2 = (-b - sqrt(discriminante)) / (2 * (-4.9));
                b2.t = (t1 > 0) ? t1 : t2;
            } 
        }     
    }

    else if(opcion == 'C'){

        if (b3.pf != '*' && b3.p0 != '*' && b3.v1 != '*')
        {
            b3.t = (b3.pf - b3.p0) / b3.v1; 
            *c3.t = '-';  
        }

        if (b3.p0 == b3.pf){
        b3.t = b3.p;
        }  
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------CAIDA LIBRE------------------------------------------------------------------


void funcionvi() {

    if (*c1.v1 == '*' && *c1.v2 != '*' && *c1.t != '*') {
        b1.v1 = b1.v2 + (9.8 * b1.t);
        *c1.v1 = '-';
    }

    if (*c1.v1 == '*' && *c1.pf != '*' && *c1.p0 != '*' && *c1.t != '*'){    
        b1.v1 = (b1.pf - b1.p0 + 4.9 * pow(b1.t, 2)) / b1.t;
        *c1.v1 = '-';
    }

    if (*c1.v1 == '*' && *c1.v2 != '*' && *c1.pf != '*' && *c1.p0 != '*') {  
        b1.v1 = sqrt(pow(b1.v2, 2) - (19.6 * (b1.pf - b1.p0)));
        *c1.v1 = '-';
    }
}


void funcionvf() {

    if (*c1.v2 == '*' && *c1.v1 != '*' && *c1.t != '*') {
        b1.v2 = b1.v1 - (9.8 * b1.t);
        *c1.v2 = '-';
    }

    if (*c1.v2 == '*' && *c1.v1 != '*' && *c1.pf != '*' && *c1.p0 != '*') {
        b1.v2 = -(sqrt(pow(b1.v1, 2) + 19.6 * (b1.p0 - b1.pf)));
        *c1.v2 = '-';
    }
}


void funciondi() {
    if (*c1.p0 == '*' && *c1.pf != '*' && *c1.p0 != '*' && *c1.t != '*') {
        b1.p0 = b1.pf - (b1.p0 * b1.t) + 4.9 * pow(b1.t, 2);
        *c1.p0 = '-';
    }

    if (*c1.p0 == '*' && *c1.v2 != '*' && *c1.v1 != '*' && *c1.pf != '*') {
        b1.p0 = ((pow(b1.v2, 2) - pow(b1.v1, 2)) / 19.6) + b1.pf;
        *c1.p0 = '-';
    }
}


void funciondf() {
    if (*c1.pf == '*' && *c1.p0 != '*' && *c1.v1 != '*' && *c1.t != '*') {
        b1.pf = b1.p0 + (b1.v1 * b1.t) - (4.9 * pow(b1.t, 2));
        *c1.pf = '-';
    }

    if (*c1.pf == '*' && *c1.v2 != '*' && *c1.v1 != '*' && *c1.p0 != '*') {
        b1.pf = ((pow(b1.v2, 2) - pow(b1.v1, 2)) / (-19.6)) + b1.p0;
        *c1.pf = '-';
    }
}


void funciondd(){

    if(*c1.p0 != '*' && *c1.pf != '*'){

        b1.dd = (b1.v1*b1.t) - (4.9 * (pow(b1.t,2)));   

        if (b1.v1 > 0 && b1.v2 <= 0){
            int t = (b1.v1 - 0) / 9.8;
            b1.dd = b1.p0 + (b1.v1 * b1.t) - (4.9 * pow(t, 2));
        }
    }

    else{
        if (b1.p0 >= 0 && b1.pf <= 0){
            b1.dd = b1.p0 - b1.pf;   
        }

        else if(b1.p0 < 0 && b1.pf < 0){
            b1.dd = b1.p0 - b1.pf;
        }        
    }
}


void caidalibre() {
 
    lectura();
    do{
    funciont();
    funcionvi();
    funcionvf();
    funciondi();
    funciondf(); 
    flag += 1;
    }while(flag <= 2);
    funciondd();

    if (b1.t < 0)
    {
        b1.t = b1.t * (-1);
    }
    

    printf("\nResultados:\n");
    printf("vi: %.2f\n", b1.v1);
    printf("vf: %.2f\n", b1.v2);
    printf("di: %.2f\n", b1.p0);
    printf("df: %.2f\n", b1.pf);       
    printf("La distancia total recorrida es: %.2f\n", b1.dd);
    printf("t: %.2f\n", b1.t);

    if (*c1.v1 == '*' || *c1.v2 == '*' || *c1.p0 == '*' || *c1.pf == '*' || *c1.t == '*')
    {
        printf("No se proporcionaron los suficientes datos para poder conocer todos los valores\n");
    }
  
}


//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------MOVIMIENTO EN DOS DIMENSIONES--------------------------------------------------------

void funcionv(){
    
    if (*c2.v1 == '*' && *c2.v2 != '*' && *c2.agl != '*'){
        b2.v1 = b2.v2 / cos(b2.agl/57.29);
        *c2.v1 = '-';
    }

    if (*c2.v1 == '*' && *c2.v3 != '*' && *c2.agl != '*'){
        b2.v1 = b2.v3 / sin(b2.agl/57.29);
        *c2.v1 = '-';
    }

    if (*c2.v1 == '*' && *c2.p0 != '*' && *c2.pf != '*' && *c2.agl != '*' &&  *c2.t != '*'){
        b2.v1 = (b2.pf - b2.p0) / (cos(b2.agl/57.29) * b2.t);
        *c2.v1 = '-';

    }   

    if (*c2.v1 == '*' && *c2.p01 != '*' && *c2.pf1 != '*' && *c2.agl != '*' &&  *c2.t != '*'){
        b2.v1 = ((b2.pf1 - b2.p01) + (4.9 * pow(b2.t,2))) / (sin(b2.agl/57.29) * b2.t);
        *c2.v1 = '-'; 
    }      
}


void velocidadxy(){

    if(*c2.v2 == '*' && *c2.v1 != '*' && *c2.agl != '*'){
        b2.v2 = b2.v1 * cos(b2.agl/57.29);
        *c2.v2 = '-';
    }

    if(*c2.v3 == '*' && *c2.v1 != '*' && *c2.agl != '*'){
        b2.v3 = b2.v1 * sin(b2.agl/57.29);
       *c2.v3 = '-';
    }   
}


void posicionxy0(){

    if (*c2.p0 == '*' && *c2.pf != '*' && *c2.v1 != '*' && *c2.agl != '*' && *c2.t != '*'){
        b2.p0 = b2.pf - (cos(b2.agl/57.29) * b2.t);
        *c2.p0 = '-';
    }
    
    if (*c2.p01 == '*' && *c2.pf1 != '*' && *c2.v1 != '*' && *c2.agl != '*' && *c2.t != '*'){
        b2.p01 = b2.pf1 - (b2.v1 * sin(b2.agl/57.29) * b2.t) - (4.9 * pow(b2.t,2));
        *c2.p01 = '-';
    }
}


void posicionxy(){

    if (*c2.pf == '*' && *c2.p0 != '*' && *c2.v1 != '*' && *c2.agl != '*' && *c2.t != '*'){
        b2.pf = b2.p0 + b2.v1 * (cos(b2.agl/57.29) * b2.t);
        *c2.pf = '-';
    }
    
    if (*c2.pf1 == '*' && *c2.p01 != '*' && *c2.v1 != '*' && *c2.agl != '*' && *c2.t != '*'){
        b2.pf1 = b2.p01 + (b2.v1 * sin(b2.agl/57.29) * b2.t) - (4.9 * pow(b2.t,2));
        *c2.pf1 = '-';
    }
}


void funcionagl(){
    
    if (*c2.agl == '*' && *c2.v2 != '*' && *c2.v1 != '*'){
        b2.agl = (acos(b2.v2/b2.v1) * (180 / pi));
        *c2.agl = '-';

    }

    if (*c2.agl == '*' && *c2.v3 != '*' && *c2.v1 != '*'){
        b2.agl = (asin(b2.v3/b2.v1) * (180 / pi));
        *c2.agl = '-';    
    } 

    if (*c2.agl == '*' && *c2.pf != '*' && *c2.p0 != '*' &&  *c2.v1 != '*' && *c2.t != '*'){
        b2.agl = (acos((b2.pf - b2.p0) / (b2.v1 * b2.t)) * (180 / pi));
        *c2.agl = '-';
    }    


    if (*c2.agl == '*' && *c2.pf1 != '*' && *c2.p01 != '*' &&  *c2.v1 != '*' && *c2.t != '*'){
        b2.agl = (asin(((b2.pf - b2.p01) + (4.9 * pow(b2.t,2))) / (b2.v1 * b2.t)) * (180 / pi));
        *c2.agl = '-';
    }      
}

void funcionpymax(){

    pymax = pow(b2.v3,2)/19.6;
} 


void proyectiles() {

    lectura();
    do{
    funciont();
    funcionv();
    velocidadxy();
    posicionxy0();
    posicionxy();
    funcionagl();
    funcionpymax();
    flag += 1;
    }while(flag <= 2);

    printf("\nResultados:\n");
    if (b2.t == 0){
        printf("No hay solucion real con los datos proporcionados.\n");
    }
    else
    {
        printf("v: %.2f\n", b2.v1);
        printf("vx: %.2f\n", b2.v2);
        printf("vy: %.2f\n", b2.v3);
        printf("pxi: %.2f\n", b2.p0);
        printf("pyi: %.2f\n", b2.p01);
        printf("pxf: %.2f\n", b2.pf);
        printf("pyf: %.2f\n", b2.pf1);
        printf("pyMAX: %.2f\n", pymax);
        printf("agl: %.2f\n", b2.agl);
        printf("t: %.2f\n", b2.t);
    }
    
    if (*c2.v1 == '*' || *c2.v2 == '*' || *c2.v3 == '*' || *c2.pf == '*' || *c2.pf1 == '*' || *c2.p0 == '*' || *c2.p01 == '*' || *c2.agl == '*' || *c2.t == '*')
    {
        printf("No se proporcionaron los suficientes datos para poder conocer todos los valores\n");
    }
}


//---------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------MOVIMIENTO CIRCULAR---------------------------------------------------------------

void velocidadw(){

    if (*c3.v1 == '*' && *c3.v2 != '*' && *c3.r != '*'){
        b3.v1 = b3.v2/b3.r;
        *c3.v1 = '-';
    }
    if (*c3.v1 == '*' && *c3.f != '*'){
        b3.v1 = 2*pi*b3.f;
        *c3.v1 = '-';
    }
    if (*c3.v1 == '*' && *c3.p != '*'){
        b3.v1 = (2*pi)/b3.p;
        *c3.v1 = '-';
    }
    if (*c3.v1 == '*' && *c3.p0 != '*' && *c3.pf != '*' && *c3.t != '*'){
        b3.v1 = (b3.pf - b3.p0) / b3.t; 
        *c3.v1 = '-';
    }
}


void periodo(){

    if (*c3.p == '*' && *c3.f != '*'){
        b3.p = 1/b3.f;
        *c3.p = '-';
    }   
    
    if (*c3.p == '*' && *c3.v1 != '*'){
        b3.p = (2*pi)/b3.v1;
        *c3.p = '-';
    } 
}

void frecuencia(){

    if (*c3.f == '*' && *c3.p != '*'){
        b3.f = 1/b3.p; 
        *c3.f = '-';
    }

    if (*c3.f == '*' && *c3.v1 != '*' ){
        b3.f = b3.v1 / (2*pi);
        *c3.f = '-';   
    }
}

void radio(){

    if (*c3.r == '*' && *c3.v1 != '*' && *c3.v2 != '*'){
        b3.r = b3.v2 / b3.v1;
        *c3.r = '-';  
    }
}

void velocidadlineal(){

    if (*c3.v2 == '*' && *c3.v1 != '*' && *c3.r !='*'){
        b3.v2 = b3.v1 * b3.r;
        *c3.v2 = '-';
    }  
}

void posicion(){
    
    if (*c3.p0 == '*' && *c3.pf != '*' && *c3.v1 != '*' && *c3.t != '*'){
        b3.p0 = b3.pf - (b3.v1 * b3.t);
        *c3.p0 = '-';
    }

    if (*c3.pf == '*' && *c3.p0 != '*' && *c3.v1 != '*' && *c3.t != '*'){
        b3.pf = b3.p0 + (b3.v1 * b3.t);
        *c3.pf = '-';
    }

    if (*c3.v1 != '*' && *c3.t != '*'){
        b3.dd = (b3.v1 * b3.t);
    }   
}

void circular() {

    lectura();
    do{
    velocidadw();
    periodo();
    frecuencia();
    radio();
    velocidadlineal();
    posicion();
    funciont();
    flag += 1;
    }while(flag <= 2);


    printf("\nResultados:\n");
    printf("w: %.2f\n", b3.v1);
    printf("vl: %.2f\n", b3.v2);
    printf("f: %.2f\n", b3.f);
    printf("r: %.2f\n", b3.r);
    printf("p: %.2f\n", b3.p);
    printf("p0: %.2f\n", b3.p0);
    printf("pf: %.2f\n", b3.pf);
    printf("dd: %.2f\n", b3.dd); 
    printf("t: %.2f\n", b3.t); 


    if (*c3.v1 == '*' || *c3.v2 == '*' || *c3.f == '*' || *c3.r == '*' || *c3.p == '*' || *c3.p0 == '*' || *c3.pf == '*' || *c3.t == '*')
    {
        printf("No se proporcionaron los suficientes datos para poder conocer todos los valores\n");
    }
}

//---------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------



float conversion(int *flag, char variable[]){

    *flag = 0;
    for (i = 0; i <= 2; i++)
    {
        if (variable[i] != '*'){
            if(variable[i] != 0 && variable[i] != 45 && variable[i] != 46 && variable[i] != 48 && variable[i] != 49 && variable[i] != 50 && variable[i] != 51 && variable[i] != 52 && variable[i] != 53 && variable[i] != 54 && variable[i] != 55 && variable[i] != 56 && variable[i] != 57){
                *flag = 1;
            }
        }
    }
    if (*flag == 1){
        printf("\nIngrese correctamente su variable\n");
    }
    fvariable = atof(variable);
    return fvariable;
}


void lectura() {

printf("\nIngrese los datos que posea, en caso de no conocerlo ingrese el simbolo '*' \n");

    if(opcion == 'A'){

        b1.a = 9.81;
        do{
        printf("Valor de velocidad inicial (m/s):");
        scanf("%s", c1.v1);
        int *pflag1 = &flag1;
        b1.v1 = conversion(pflag1, c1.v1);
        }while(flag1 != 0);

        do{
        printf("Valor de velocidad final (m/s): ");
        scanf("%s", c1.v2);
        int *pflag2 = &flag2;
        b1.v2 = conversion(pflag2, c1.v2);
        }while(flag2 != 0);

        do{
        printf("Valor de distancia inicial (m):");
        scanf("%s", c1.p0);
        int *pflag3 = &flag3;
        b1.p0 = conversion(pflag3, c1.p0);
        }while(flag3 != 0);

        do{
        printf("Valor de distancia final (m):");
        scanf("%s", c1.pf);
        int *pflag4 = &flag4;
        b1.pf = conversion(pflag4, c1.pf);
        }while(flag4 != 0);

        do{
        printf("Valor de tiempo (s):");
        scanf("%s", c1.t);
        int *pflag5 = &flag5;
        b1.t = conversion(pflag5, c1.t);
        }while(flag5 != 0);
    }

        else if (opcion == 'B')
        {
            do{
            printf("modulo de la velocidad (m/s):"); 
            scanf("%s", c2.v1);
            int *pflag1 = &flag1;
            b2.v1 = conversion(pflag1, c2.v1);
            }while(flag1 != 0);

            do{
            printf("componente en x (m/s):");
            scanf("%s", c2.v2);
            int *pflag2 = &flag2;
            b2.v2 = conversion(pflag2, c2.v2);
            }while(flag2 != 0);

            do{
            printf("componente en y (m/s):");
            scanf("%s", c2.v3);
            int *pflag3 = &flag3;
            b2.v3 = conversion(pflag3, c2.v3);
            }while(flag3 != 0);

            do{
            printf("angulo de lanzamiento (deg):");
            scanf("%s", c2.agl);
            int *pflag4 = &flag4;
            b2.agl = conversion(pflag4, c2.agl);
            }while(flag4 != 0);

            do{
            printf("tiempo (s):");
            scanf("%s", c2.t);
            int *pflag5 = &flag5;
            b2.t = conversion(pflag5, c2.t);
            }while(flag5 != 0);

            do{
            printf("posicion de inicio en x (m):");
            scanf("%s", c2.p0);
            int *pflag6 = &flag6;
            b2.p0 = conversion(pflag6, c2.p0);
            }while(flag6 != 0);

            do{
            printf("posicion de inicion en y (m):");
            scanf("%s", c2.p01);
            int *pflag7 = &flag7;
            b2.p01 = conversion(pflag7, c2.p01);
            }while(flag7 != 0);

            do{
            printf("posicion final en x (m):");
            scanf("%s", c2.pf);
            int *pflag8 = &flag8;
            b2.pf = conversion(pflag8, c2.pf);
            }while(flag8 != 0);

            do{
            printf("posicion final en y (m): ");
            scanf("%s", c2.pf1);
            int *pflag9 = &flag9;
            b2.pf1 = conversion(pflag9, c2.pf1);
            }while(flag5 != 0);
        }

            else if (opcion == 'C')
            {
                do{
                printf("Velocidad angular (rad/s):");
                scanf("%s", c3.v1); 
                int *pflag1 = &flag1;
                b3.v1 = conversion(pflag1, c3.v1);
                }while(flag1 != 0);

                do{
                printf("Velocidad lineal (m/s):");
                scanf("%s", c3.v2);
                int *pflag2 = &flag2;
                b3.v2 = conversion(pflag2, c3.v2);
                }while(flag2 != 0);

                do{
                printf("Radio (m):");
                scanf("%s", c3.r);
                int *pflag3 = &flag3;
                b3.r = conversion(pflag3, c3.r);
                }while(flag3 != 0);

                do{
                printf("Frecuencia (hz):");
                scanf("%s", c3.f);
                int *pflag4 = &flag4;
                b3.f = conversion(pflag4, c3.f);
                }while(flag4 != 0);

                do{
                printf("Periodo (1/hz):");
                scanf("%s", c3.p);
                int *pflag5 = &flag5;
                b3.p = conversion(pflag5, c3.p);
                }while(flag5 != 0);

                do{
                printf("Posicion angular inicial (rad):");
                scanf("%s", c3.p0);
                int *pflag6 = &flag6;
                b3.p0 = conversion(pflag6, c3.p0);
                }while(flag6 != 0);

                do{
                printf("Posicion angular final (rad):");
                scanf("%s", c3.pf);
                int *pflag7 = &flag7;
                b3.pf = conversion(pflag7, c3.pf);
                }while(flag7 != 0);

                do{
                printf("Tiempo (s):");
                scanf("%s", c3.t);
                int *pflag7 = &flag7;
                b3.t = conversion(pflag7, c3.t);
                }while(flag7 != 0);
            }  
}


void eleccion() {
    switch (opcion) {
        case 'A':
            caidalibre();
            break;
        case 'B':
            proyectiles();
            break;
        case 'C':
            circular();
            break;
    }
}


int main() {

    printf("Seleccione la opcion segun el tipo de movimiento: \nCaida libre: A\nMovimiento en dos dimensiones: B\nMovimiento circular: C\nOpcion: ");
    
    do {
        scanf(" %c", &opcion);  
        opcion = toupper(opcion);
        if (opcion != 'A' && opcion != 'B' && opcion != 'C') {
            printf("Por favor ingrese lo que se solicita correctamente\nCaida libre: A\nMovimiento en dos dimensiones: B\nMovimiento circular: C\nOpcion: ");
        }
    } while (opcion != 'A' && opcion != 'B' && opcion != 'C');

    eleccion();

    return 0;
}
