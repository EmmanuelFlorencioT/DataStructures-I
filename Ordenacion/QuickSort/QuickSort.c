#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void llenarArr(int arr[], int n, int rango);
void swap(int *izq, int *der);
void qSort(int arr[], int izq, int der);
void quickSort(int arr[], int n);
void muestraArr(int arr[], int n);

int main()
{
    int arreglo[TAM], Num, Ran;
    Num=10;
    Ran=100;
    llenarArr(arreglo, Num, Ran);
    muestraArr(arreglo, Num);
    quickSort(arreglo, Num);
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

void qSort(int arr[], int izq, int der)
{
    int i=izq, d=der, piv;
    piv=arr[(i+d)/2];
    while(i<=d)
    {
        while(arr[i]<piv) i++;
        while(arr[d]>piv) d--;
        if(i<=d)
        {
            swap(&arr[i], &arr[d]);
            i++;
            d--;
        }
    }
    if(izq<d)
        qSort(arr, izq, d);
    if(i<der)
        qSort(arr, i, der);
}

void quickSort(int arr[], int n)
{
    qSort(arr, 0, n-1);
}

void muestraArr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%3d", arr[i]);
    printf("\n");
}
