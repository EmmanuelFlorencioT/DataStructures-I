#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 10

void llenarArr(int arr[], int n, int rango);
void muestraArr(int arr[], int n);
void qSort(int arr[], int izq, int der);
void quickSort(int arr[], int n);
void swap(int *izq, int *der);
int busquedaBinRec(int arr[], int izq, int der, int buscado);
int busquedaBinRecAux(int arr[], int n, int buscado);

int main()
{
    int arreglo[TAM];
    int num=10, resp, busca=63, ran=100;
    llenarArr(arreglo, num, ran);
    muestraArr(arreglo, num);
    quickSort(arreglo, num);
    muestraArr(arreglo, num);
    resp=busquedaBinRecAux(arreglo, num, busca);
    switch(resp)
    {
        case 0:
            printf("No se han encontrado coincidencias");
            break;
        case 1:
            printf("Elemento encontrado");
            break;
        default:
            printf("Error");
            break;
    }
}

void llenarArr(int arr[], int n, int rango)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
        arr[i]=1+rand()%rango;
}

void muestraArr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%3d", arr[i]);
    printf("\n");
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
