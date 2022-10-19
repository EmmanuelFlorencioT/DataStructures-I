#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void llenarArr(int arr[], int n, int rango);
void swap(int *izq, int *der);
void burbujaRecRec(int arr[], int quedan, int barrido);
void burbujaRecRecAux(int arr[], int n);
void muestraArr(int arr[], int n);

int main()
{
    int arreglo[TAM], Num, Ran;
    Num=10;
    Ran=100;
    llenarArr(arreglo, Num, Ran);
    muestraArr(arreglo, Num);
    burbujaRecRecAux(arreglo, Num);
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

void burbujaRecRec(int arr[], int quedan, int barrido)
{
    if(quedan>0)
    {
        if(barrido<quedan)
        {
            if(arr[barrido]>arr[barrido+1])
                swap(&arr[barrido], &arr[barrido+1]);
            burbujaRecRec(arr, quedan, barrido+1);
        }
        burbujaRecRec(arr, quedan-1, 0);
    }
}

void burbujaRecRecAux(int arr[], int n)
{
    burbujaRecRec(arr, n-1, 0);
}

void muestraArr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%3d", arr[i]);
    printf("\n");
}
