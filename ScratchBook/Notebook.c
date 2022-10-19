/*
    Objetivo: Calcular el volumen de un tanque
    Autor: EFT
    Fecha: 2 Mar 2021
    Notas:  a)Numeros +/- y con decimales
*/
#include<stdio.h>
#include<string.h>

#define TAM 10

typedef struct
{
    char nomPila[25];
    char nomSanto[25];
    char nomAlias[25];
} NOMS; //Nombres

typedef struct
{
    NOMS nom;
    char apPat[25];
    char apMat[25];
} NMCMP; //Nombre completo

typedef struct
{
    int dia;
    char mes[3];
    int anio;
} NAC; //Nacimiento

typedef struct
{
    NMCMP nombre;
    int edad;
    float estatura;
    NAC nacimiento;
} PER; //Persona

void llenaArrPers(PER arrPer[], int n);
void muestraArrPers(PER arrPer[], int n);
int cuentaApRep(PER arrPer[], int n);
void cuentaNomRep(PER arrPer[], int n, int *nomsRep);
void compruebaPar(PER arrPer[], int n, char ap[], int *parientes);
void mesCumple(PER arrPer[], int n);
int diaCumple(PER arrPer[], int n, int diaBusc);

int main()
{
    PER arrPpl[TAM];
    int j=5, cont;
    llenaArrPers(arrPpl, j);
    muestraArrPers(arrPpl, j);
    mesCumple(arrPpl, j);
    //printf("Contador: %d", cont);
}

void llenaArrPers(PER arrPer[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Persona %d\n", i);
        printf("Nombre: ");
        gets(arrPer[i].nombre.nom.nomPila);
        printf("Mes Nacimiento: ");
        gets(arrPer[i].nacimiento.mes);
        printf("\n");
    }
}

void muestraArrPers(PER arrPer[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Persona %d\n", i);
        printf("Nombre Pila: %s  ", arrPer[i].nombre.nom.nomPila);
        printf("Mes: %s  ", arrPer[i].nacimiento.mes);
        printf("\n");
    }
}

void cuentaNomRep(PER arrPer[], int n, int *nomsRep)
{
    int i;
    *nomsRep=0;
    for(i=0;i<n;i++)
        if(strcmp(arrPer[i].nombre.nom.nomPila, arrPer[i].nombre.nom.nomAlias)==0 &&
           strcmp(arrPer[i].nombre.nom.nomSanto, arrPer[i].nombre.nom.nomPila)==0 &&
           strcmp(arrPer[i].nombre.nom.nomAlias, arrPer[i].nombre.nom.nomSanto)==0)
        {
            (*nomsRep)++;
        }
}

int cuentaApRep(PER arrPer[], int n) //Calcular la cantidad de personas diferentes con apellidos iguales
{
    int i, piv=0, apRep=1;
    while(piv<(n-1) && apRep<(n-1))
    {
        for(i=(piv+1);i<n;i++)
            if(strcmp(arrPer[piv].nombre.apPat, arrPer[i].nombre.apPat)==0 ||
                strcmp(arrPer[piv].nombre.apMat, arrPer[i].nombre.apMat)==0 ||
                strcmp(arrPer[piv].nombre.apMat, arrPer[i].nombre.apPat)==0 ||
                strcmp(arrPer[piv].nombre.apPat, arrPer[i].nombre.apMat)==0)
            {
                apRep++;
            }
        piv++;
    }
    if(apRep==1)
        apRep=0;
    return(apRep);
}

void compruebaPar(PER arrPer[], int n, char ap[], int *parientes)
{
    int i;
    *parientes=0;
    for(i=0;i<n;i++)
        if(strcmp(ap, arrPer[i].nombre.apPat)==0 || strcmp(ap, arrPer[i].nombre.apMat)==0)
            (*parientes)++;
}

void mesCumple(PER arrPer[], int n)
{
    int i, piv, cont, marcador=1;
    char mayor[4];
    strcpy(mayor, arrPer[0].nacimiento.mes);
    for(piv=0;piv<(n-1);piv++)
    {
        cont=1;
        for(i=(piv+1);i<n;i++)
            if(strcmp(arrPer[piv].nacimiento.mes, arrPer[i].nacimiento.mes)==0)
                cont++;
        if(cont>marcador)
        {
            marcador=cont;
            strcpy(mayor, arrPer[piv].nacimiento.mes);
        }
        else
            if(cont==marcador && marcador>1)
                printf("Hay mas de un mes que se repite el mismo numero de veces\n");
    }
    if(cont==marcador && marcador==1)
        printf("No se repitieron meses.");
    else
        printf("Mayor: %s", mayor);
}

int diaCumple(PER arrPer[], int n, int diaBusc)
{
    int i, cant=0, piv;
    for(i=0;i<n;i++)
        if(diaBusc==arrPer[i].nacimiento.dia)
            cant++;
    return(cant);
}

