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
int busquedaBin(int arr[], int n, int buscado);
void status(int tiempo, int cant);

void muestraArr(int arr[], int n);

int main()
{
    time_t tPrev, tPost;
    static int arreglo[TAM], busca[TAM], num[]={10, 20, 30, 40, 50};
    static int resp, ran=100, i, duracion, j;
    for(j=0;j<5;j++)
    {
        llenarArrSinRep(arreglo, num[j], ran);
        muestraArr(arreglo, num[j]);
        llenarArrBusc(arreglo, busca, num[j], ran);
        muestraArr(busca, num[j]);
        quickSort(arreglo, num[j]);
        muestraArr(arreglo, num[j]);
        tPrev=clock();
        for(i=0;i<num[j];i++)
            resp=busquedaBin(arreglo, num[j], busca[i]);
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

int busquedaBin(int arr[], int n, int buscado)
{
    int izq=0, der=n-1, med, codigo=0;
    do{
        med=(izq+der)/2;
        if(buscado==arr[med])
            codigo=1;
        else
            if(buscado<arr[med])
                der=med-1;
            else
                izq=med+1;
      }while(codigo==0&&izq<=der);
    return(codigo);
}

void status(int tiempo, int cant)
{
    printf("Hice %d b\xa3squedas en %d milisegundos\n", cant, tiempo);
}

void muestraArr(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%3d", arr[i]);
    printf("\n");
}
