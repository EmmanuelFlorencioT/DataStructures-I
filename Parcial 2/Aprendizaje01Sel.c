#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>

#define TAM 500000

void llenarArr(int arr[], int n, int rango);
void swap(int *izq, int *der);
void selDir(int arr[], int n);
void status(int tiempo, int cant);

int main()
{
    time_t tPrev, tPost;
    int array[TAM], i, duracion;
    int arrN[]={10000, 50000, 100000, 200000, 500000};
    printf("M\x82todo Seleccion Directa Simple\n");
    for(i=0;i<5;i++)
    {
        llenarArr(array, arrN[i], INT_MAX);
        tPrev=clock();
        selDir(array, arrN[i]);
        tPost=clock();
        duracion=tPost-tPrev;
        status(duracion, arrN[i]);
    }
}

void llenarArr(int arr[], int n, int rango)
{
    int i;
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

void selDir(int arr[], int n)
{
    int piv, barrido;
    for(piv=0;piv<n-1;piv++)
        for(barrido=piv+1;barrido<n;barrido++)
            if(arr[barrido]<arr[piv])
                swap(&arr[barrido], &arr[piv]);
}

void status(int tiempo, int cant)
{
    printf("Me tard\x82 en ordenar %d milisegundo para %d datos\n", tiempo, cant);
}
