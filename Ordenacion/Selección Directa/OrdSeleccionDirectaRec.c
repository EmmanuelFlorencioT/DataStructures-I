#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void llenarArr(int arr[], int n, int rango);
void swap(int *izq, int *der);
void selDirRec(int arr[], int piv);
void selDirRecAux(int arr[], int n);
void muestraArr(int arr[], int n);

int main()
{
    int arreglo[TAM], Num, Ran;
    Num=10;
    Ran=100;
    llenarArr(arreglo, Num, Ran);
    muestraArr(arreglo, Num);
    selDirRecAux(arreglo, Num);
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

void selDirRec(int arr[], int piv)
{
    int barrido;
    if(piv>0)
    {
        for(barrido=piv-1;barrido>=0;barrido--)
            if(arr[barrido]>arr[piv])
                swap(&arr[barrido], &arr[piv]);

        selDirRec(arr, (piv-1));
    }
}

void selDirRecAux(int arr[], int n)
{
    selDirRec(arr, (n-1));
}

void muestraArr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%3d", arr[i]);
    printf("\n");
}
