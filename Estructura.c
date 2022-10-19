#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct persona
{
    char nom[25];
    int edad;
    float estatura;
};

void asignaPer(struct persona *p, char n[], int ed, float es); //Es darle datos diretos
void capturaPer(struct persona *p);
void muestraPer(struct persona p);

int main()
{
    struct persona per;
    asignaPer(&per, "Juan Perez", 25, 1.73); //Aqui estamos dejando algo dentro de la estructura
    muestraPer(per);
    capturaPer(&per);
    muestraPer(per);
}

void asignaPer(struct persona *p, char n[], int ed, float es)
{
    strcpy((*p).nom, n);
    (*p).edad=ed;
    (*p).estatura=es;
}

void capturaPer(struct persona *p)
{
    printf("Dime tu nombre: ");
    gets(p->nom);
    printf("Dime tu edad: ");
    scanf("%d", &(*p).edad);
    printf("Dime tu estatura: ");
    scanf("%f", &p->estatura);
}

void muestraPer(struct persona p)
{
    printf("%s    %d    %.2f\n", p.nom, p.edad, p.estatura);
}
