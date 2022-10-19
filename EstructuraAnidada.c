#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char nom[25];
    char apPat[25];
    char apMat[25];
} NOM;

typedef struct
{
    NOM nombre;
    int edad;
    float estatura;
} PER;

void capturaPer(PER *p);
void muestraPer(PER p);
int parienteDe(PER p, char ap[]);

int main()
{
    PER per;

    capturaPer(&per);
    muestraPer(per);
}

void capturaPer(PER *p)
{
    printf("Nombre: ");
    gets(p->nombre.nom);
    printf("Apellido Paterno: ");
    gets(p->nombre.apPat);
    printf("Apellido Materno: ");
    gets(p->nombre.apMat);
    printf("Edad: ");
    scanf("%d", &p->edad);
    printf("Estatura: ");
    scanf("%f", &p->estatura);
}

void muestraPer(PER p)
{
    printf("Nombre: %s\n", p.nombre.nom);
    printf("Apellido Paterno: %s\n", p.nombre.apPat);
    printf("Apellido Materno: %s\n", p.nombre.apMat);
    printf("Edad: %d\n", p.edad);
    printf("Estatura: %.2f\n", p.estatura);
}

int parienteDe(PER p, char ap[])
{
    int codigo=0;
    if(strcmp(p.nombre.apPat, ap)==0 || strcmp(p.nombre.apMat, ap)==0)
        codigo=1;
    return(codigo);
}

