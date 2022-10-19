#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>

#define TAM 500000

void llenarArr(int arr[], int n, int rango);
int selectMet();
void swap(int *izq, int *der);
void burbuja(int arr[], int n);
void selDir(int arr[], int n);
void selDirOptim(int arr[], int n);
void insDir(int arr[], int n);
void insDirOptim(int arr[], int n);
void qSort(int arr[], int izq, int der);
void quickSort(int arr[], int n);
void status(int tiempo, int cant);

int main()
{
    time_t tPrev, tPost;
    int array[TAM], i, duracion, select;
    int arrN[]={10000, 50000, 100000, 200000, 500000};
    select=selectMet();
    switch(select)
    {
        case 1:
            printf("M\x82todo Burbuja Simple\n");
            for(i=0;i<5;i++)
            {
                llenarArr(array, arrN[i], INT_MAX);
                tPrev=clock();
                burbuja(array, arrN[i]);
                tPost=clock();
                duracion=tPost-tPrev;
                status(duracion, arrN[i]);
            }
            break;

        case 2:
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

        case 3:
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

        case 4:
            printf("M\x82todo Insercion Directa Simple\n");
            for(i=0;i<5;i++)
            {
                llenarArr(array, arrN[i], INT_MAX);
                tPrev=clock();
                insDir(array, arrN[i]);
                tPost=clock();
                duracion=tPost-tPrev;
                status(duracion, arrN[i]);
            }
            break;

        case 5:
            printf("M\x82todo Insercion Directa Optimizado\n");
            for(i=0;i<5;i++)
            {
                llenarArr(array, arrN[i], INT_MAX);
                tPrev=clock();
                insDirOptim(array, arrN[i]);
                tPost=clock();
                duracion=tPost-tPrev;
                status(duracion, arrN[i]);
            }
            break;

        case 6:
            printf("M\x82todo Quick Sort\n");
            for(i=0;i<5;i++)
            {
                llenarArr(array, arrN[i], INT_MAX);
                tPrev=clock();
                quickSort(array, arrN[i]);
                tPost=clock();
                duracion=tPost-tPrev;
                status(duracion, arrN[i]);
            }
            break;

    }
}

void llenarArr(int arr[], int n, int rango)
{
    int i;
    for(i=0;i<n;i++)
        arr[i]=1+rand()%rango;
}

int selectMet()
{
    int select;
    printf("Menu:\n");
    printf("1- Burbuja\n");
    printf("2- Seleccion Directa Simple\n");
    printf("3- Seleccion Directa Optimizado\n");
    printf("4- Insercion Directa Simple\n");
    printf("5- Insercion Directa Optimizado\n");
    printf("6- Quick Sort\n");
    printf("\nMetodo: ");
    scanf("%d", &select);
    return(select);
}

void swap(int *izq, int *der)
{
    int aux;
    aux=*izq;
    *izq=*der;
    *der=aux;
}

void burbuja(int arr[], int n)
{
    int barrido, quedan;
    for(quedan=n-1;quedan>0;quedan--)
        for(barrido=0;barrido<quedan;barrido++)
            if(arr[barrido]>arr[barrido+1])
                swap(&arr[barrido], &arr[barrido+1]);
}

void selDir(int arr[], int n)
{
    int piv, barrido;
    for(piv=0;piv<n-1;piv++)
        for(barrido=piv+1;barrido<n;barrido++)
            if(arr[barrido]<arr[piv])
                swap(&arr[barrido], &arr[piv]);
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

void insDir(int arr[], int n)
{
    int piv, pos;
    for(piv=1;piv<n;piv++)
    {
        pos=piv;
        while(pos>0 && arr[pos-1]>arr[pos])
        {
            swap(&arr[pos], &arr[pos-1]);
            pos--;
        }
    }
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

void status(int tiempo, int cant)
{
    printf("Me tard\x82 en ordenar %d milisegundo para %d datos\n", tiempo, cant);
}
