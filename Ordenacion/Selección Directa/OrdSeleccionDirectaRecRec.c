#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void llenarArr(int arr[], int n, int rango);
void swap(int *izq, int *der);
void selDirRecRec(int arr[], int piv, int barrido);
void selDirRecRecAux(int arr[], int n);
void muestraArr(int arr[], int n);

int main()
{
    int arreglo[TAM], Num, Ran;
    Num=10;
    Ran=100;
    llenarArr(arreglo, Num, Ran);
    muestraArr(arreglo, Num);
    selDirRecRecAux(arreglo, Num);
    muestraArr(arreglo, Num);
}

void llenarArr(int arr[], int n, int rango)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
        arr[i]=1+rand()%rango;
}

void swap(int *izq, int *der)
{
    int aux;
    aux=*izq;
    *izq=*der;
    *der=aux;
}

void selDirRecRec(int arr[], int piv, int barrido)
{
    if(piv>0)
    {
        if(barrido>=0)
        {
            if(arr[barrido]>arr[piv])
                swap(&arr[barrido], &arr[piv]);
            selDirRecRec(arr, piv, barrido-1);
        }
        selDirRecRec(arr, piv-1, piv-2);
    }
}

void selDirRecRecAux(int arr[], int n)
{
    selDirRecRec(arr, n-1, n-2);
}

void muestraArr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%3d", arr[i]);
    printf("\n");
}
