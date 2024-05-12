#include <math.h>
#include <stdio.h> 

float valor;
float valor1;

struct st_coor3D { int x, y, z; };

union un_coor3D { 
struct st_coor3D N;
int coor[3];
} punto;

union un_coor3D init(int x, int y, int z){ 
union un_coor3D res = {x, y, z};
return res; 
};


float modulo(union un_coor3D * p){

    p->coor[0] = 5, p->coor[1] = 6, p->coor[2] = 7;
    valor = sqrt(pow(p->coor[0],2)+pow(p->coor[1],2)+pow(p->coor[2],2));
    return valor;
}


float modulo1(union un_coor3D * p){

    p->N.x = 5, p->N.y = 6, p->N.z = 7;
    valor1 = sqrt(pow(p->N.x,2)+pow(p->N.y,2)+pow(p->N.z,2));
}

void set_ceros(union un_coor3D * p) {      
    for(int i=0; i<3; i++) { p->coor[i] = 0; }; 
    };

    void imprimir(union un_coor3D * p){ 
        printf("(x, y, z) => (%d, %d, %d)\n",
        p->N.x, p->N.y, p->N.z);
    };

    int main() { 
        union un_coor3D u = init(1, 2, 3);
        imprimir(&u);
        set_ceros(&u);
        imprimir(&u);
        modulo(&u);
        modulo1(&u);
        printf("el valor del modulo es: %f ",valor);
        printf("\nel valor del modulo es: %f ",valor1);
    };

