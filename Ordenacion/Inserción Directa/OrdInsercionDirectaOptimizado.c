#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void llenarArr(int arr[], int n, int rango);
void swap(int *izq, int *der);
void insDirOptim(int arr[], int n);
void muestraArr(int arr[], int n);

int main()
{
    int arreglo[TAM], Num, Ran;
    Num=10;
    Ran=100;
    llenarArr(arreglo, Num, Ran);
    muestraArr(arreglo, Num);
    insDirOptim(arreglo, Num);
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

void insDirOptim(int arr[], int n)
{
    int piv, pos, aux;
    for(piv=1;piv<n;piv++)
    {
        aux=arr[piv];
        pos=piv;
        while(pos>0 && arr[pos-1]>aux)
        {
            arr[pos]=arr[pos-1];
            pos--;
        }
        arr[pos]=aux;
    }
}


void muestraArr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%3d", arr[i]);
    printf("\n");
}
