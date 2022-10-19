/*
    Objetivo: Calcular el promedio por materia, periodo y general de un alumno.
    Autor: EFT
    Fecha: 8 Abril 2021
    Notas: Los promedios deben estar en arreglos unidimesionales aparte.
*/
#include<stdio.h>
#include<conio.h>

#define TAM 25

void introRenCol(int *Mat, int *Per);
void capturaArrBi(float arrBi[TAM][TAM], int Mat, int Per);
void boleta(float arrBol[TAM][TAM], int nPer, int nMat, float promP[TAM],
             float promM[TAM], float *prGen);
void muestraArrBi(float arrBi[][TAM], int nPer, int nMat);
void muestraArrUni(float arr[TAM], int n);
void muestraDato(float dato);

int main()
{
    int per, mat;
    float calif[TAM][TAM];
    float prPer[TAM], prMat[TAM], prGral;
    introRenCol(&per, &mat);
    capturaArrBi(calif, mat, per);
    boleta(calif, per, mat, prPer, prMat, &prGral);
    printf("\nPromedio por Periodo:\n");
    muestraArrUni(prPer, per);
    printf("\nPromedio por Materia:\n");
    muestraArrUni(prMat, mat);
    printf("\nPromedio General:\n");
    muestraDato(prGral);

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

void boleta(float arrBol[TAM][TAM], int nPer, int nMat, float promP[TAM],
             float promM[TAM], float *prGen)
{
    int cMat, cPer;
    float ac;
    //Promedios por materia
    for(cMat=0;cMat<nMat;cMat++)
    {
        ac=0;
        for(cPer=0;cPer<nPer;cPer++)
            ac+=arrBol[cMat][cPer];
        promM[cMat]=ac/nPer;
    }
    //Promedios por periodo
    for(cPer=0;cPer<nPer;cPer++)
    {
        ac=0;
        for(cMat=0;cMat<nMat;cMat++)
            ac+=arrBol[cMat][cPer];
        promP[cPer]=ac/nMat;
    }
    //Promedios general
    ac=0;
    for(cMat=0;cMat<nMat;cMat++)
        for(cPer=0;cPer<nPer;cPer++)
            ac+=arrBol[cMat][cPer];  //Se va a sumar durante todo el arreglo
    *prGen=ac/(nMat*nPer);
}

void muestraArrBi(float arrBi[][TAM], int nPer, int nMat)
{
    int cMat, cPer;
    for(cMat=0;cMat<nMat;cMat++)
    {
        printf("\n");
        for(cPer=0;cPer<nPer;cPer++)
            printf("%6.2f", arrBi[cMat][cPer]);
    }
}

void muestraArrUni(float arr[TAM], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%6.2f\n", arr[i]);
}

void muestraDato(float dato)
{
    printf("%6.2f", dato);
}
