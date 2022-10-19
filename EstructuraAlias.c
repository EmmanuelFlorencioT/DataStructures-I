#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char nom[25];
    int edad;
    float estatura;
} PER;

/*  <--Lo de arriba equivale a esto.
typedef struct persona
{
    char nom[25];
    int edad;
    float estatura;
} PER;
*/

//typedef struct persona PER; <--Lo de arriba equivale a esto.

void asignaPer(PER *p, char n[], int ed, float es); //Es darle datos diretos
void capturaPer(PER *p);
void muestraPer(PER p);

int main()
{
    PER per;
    asignaPer(&per, "Juan Perez", 25, 1.73); //Aqui estamos dejando algo dentro de la estructura
    muestraPer(per);
    capturaPer(&per);
    muestraPer(per);
}

void asignaPer(PER *p, char n[], int ed, float es)
{
    strcpy((*p).nom, n);
    (*p).edad=ed;
    (*p).estatura=es;
}

void capturaPer(PER *p)
{
    printf("Dime tu nombre: ");
    gets(p->nom);
    printf("Dime tu edad: ");
    scanf("%d", &(*p).edad);
    printf("Dime tu estatura: ");
    scanf("%f", &p->estatura);
}

void muestraPer(PER p)
{
    printf("%s    %d    %.2f\n", p.nom, p.edad, p.estatura);
}
