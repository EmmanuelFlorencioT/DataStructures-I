/*
    Objetivo: Calcular el promedio por materia, periodo y general de ul alumno.
    Autor: EFT
    Fecha: 8 Abril 2021
    Notas:
*/
#include<stdio.h>
#include<conio.h>

#define TAM 25

void introRenCol(int *Mat, int *Per);
void capturaArrBi(float arrBi[TAM][TAM], int Mat, int Per);
void boleta(float arrBi[][TAM], int nPer, int nMat);
void muestraArrBi(float arrBi[][TAM], int nPer, int nMat);

int main()
{
    int per, mat;
    float calif[TAM][TAM];
    introRenCol(&per, &mat);
    capturaArrBi(calif, mat, per);
    boleta(calif, per, mat);
    muestraArrBi(calif, per, mat);
}

void introRenCol(int *Per, int *Mat)
{
    printf("No. de Periodos: ");
    scanf("%d", &*Per);
    printf("No. de Materias: ");
    scanf("%d", Mat);
}

void capturaArrBi(float arrBi[][TAM], int Mat, int Per)
{
    int r, c;
    for(c=0;c<Per;c++)
    {
        printf("\tPeriodo No.%d\n", c+1);
        for(r=0;r<Mat;r++)
        {
            printf("Materia %d: ", r+1);
            scanf("%f", &arrBi[r][c]);
        }
    }
}

void boleta(float arrBi[][TAM], int nPer, int nMat)
{
    int cMat, cPer;
    float suma;
    //Promedio por Periodo
    for(cPer=0;cPer<nPer;cPer++)
    {
        suma=0;
        for(cMat=0;cMat<nMat;cMat++)
            suma+=arrBi[cMat][cPer];
        arrBi[nMat][cPer]=suma/nMat;
    }
    //Promedio por Materia
    for(cMat=0;cMat<nMat;cMat++)
    {
        suma=0;
        for(cPer=0;cPer<nPer;cPer++)
            suma+=arrBi[cMat][cPer];
        arrBi[cMat][nPer]=suma/nPer;
    }
    //Promedio General
    suma=0;
    for(cMat=0;cMat<nMat;cMat++)
        for(cPer=0;cPer<nPer;cPer++)
            suma+=arrBi[cMat][cPer];
    arrBi[nMat][nPer]=suma/(nMat*nPer);
}

void muestraArrBi(float arrBi[][TAM], int nPer, int nMat)
{
    int cMat, cPer;
    for(cMat=0;cMat<=nMat;cMat++)
    {
        printf("\n");
        for(cPer=0;cPer<=nPer;cPer++)
            printf("%6.2f", arrBi[cMat][cPer]);
    }
}
