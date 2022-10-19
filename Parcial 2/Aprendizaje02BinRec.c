#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define TAM 500000

void llenarArr(int arr[], int n, int rango);
void llenarArrSinRep(int arr[], int n, int rango);
void llenarArrBusc(int arrBase[], int arrBusc[], int n, int rango);
void qSort(int arr[], int izq, int der);
void quickSort(int arr[], int n);
void swap(int *izq, int *der);
int busquedaBinRec(int arr[], int izq, int der, int buscado);
int busquedaBinRecAux(int arr[], int n, int buscado);
void status(int tiempo, int cant);


int main()
{
    static int arreglo[TAM], busca[TAM], num[]={10000, 50000, 100000, 200000, 500000};
    time_t tPrev, tPost;
    static int resp, ran=INT_MAX, i, duracion, j;
    printf("Busqueda Binaria Recursiva\n");
    for(j=0;j<5;j++)
    {
        //printf("LLenando arreglo...\n");
        llenarArr(arreglo, num[j], ran);
        //printf("Llenando busqueda...\n");
        llenarArrBusc(arreglo, busca, num[j], ran);
        tPrev=clock();
        quickSort(arreglo, num[j]);
        for(i=0;i<num[j];i++)
            resp=busquedaBinRecAux(arreglo, num[j], busca[i]);
        tPost=clock();
        duracion=tPost-tPrev;
        status(duracion, num[j]);
    }
}


void llenarArr(int arr[], int n, int rango)
{
    int i;
    for(i=0;i<n;i++)
        arr[i]=1+rand()%rango;
}

void llenarArrSinRep(int arr[], int n, int rango)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        arr[i]=1+rand()%rango;
        j=0;
        while(j<i)
            if(arr[j]==arr[i])
            {
                arr[i]=rand()%rango;
                j=0;
            }
            else
                j++;
    }
}

void llenarArrBusc(int arrBase[], int arrBusc[], int n, int rango)
{
    int i;
    for(i=0;i<(n*6)/10;i++)
        arrBusc[i]=arrBase[i];
    for(i=(n*6)/10;i<n;i++)
        arrBusc[i]=1+rand()%rango;
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

void swap(int *izq, int *der)
{
    int aux;
    aux=*izq;
    *izq=*der;
    *der=aux;
}

int busquedaBinRec(int arr[], int izq, int der, int buscado)
{
    int cod, med;
    if(izq>der)
        cod=0;
    else
    {
        med=(izq+der)/2;
        if(buscado==arr[med])
            cod=1;
        else
            if(buscado<arr[med])
                cod=busquedaBinRec(arr, izq, med-1, buscado);
            else
                cod=busquedaBinRec(arr, med+1, der, buscado);
    }
    return(cod);
}

int busquedaBinRecAux(int arr[], int n, int buscado)
{
    int codigo;
    codigo=busquedaBinRec(arr, 0, n-1, buscado);
    return(codigo);
}

void status(int tiempo, int cant)
{
    printf("Hice %d b\xa3squedas en %d milisegundos\n", cant, tiempo);
}
