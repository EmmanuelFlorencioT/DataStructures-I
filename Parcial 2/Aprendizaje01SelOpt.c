#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>

#define TAM 500000

void llenarArr(int arr[], int n, int rango);
void swap(int *izq, int *der);
void selDirOptim(int arr[], int n);
void status(int tiempo, int cant);

int main()
{
    time_t tPrev, tPost;
    int array[TAM], i, duracion;
    int arrN[]={10000, 50000, 100000, 200000, 500000};
    printf("M\x82todo Seleccion Directa Optimizado\n");
    for(i=0;i<5;i++)
    {
        llenarArr(array, arrN[i], INT_MAX);
        tPrev=clock();
        selDirOptim(array, arrN[i]);
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

void selDirOptim(int arr[], int n)
{
    int piv, barrido, menor;
    for(piv=0;piv<(n-1);piv++)
    {
        menor=piv;
        for(barrido=(piv+1);barrido<n;barrido++)
            if(arr[barrido]<arr[menor])
                menor=barrido;
        swap(&arr[piv], &arr[menor]);
    }
}

void status(int tiempo, int cant)
{
    printf("Me tard\x82 en ordenar %d milisegundo para %d datos\n", tiempo, cant);
}
