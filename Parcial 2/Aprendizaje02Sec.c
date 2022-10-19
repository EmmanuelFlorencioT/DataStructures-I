#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define TAM 500000

void llenarArr(int arr[], int n, int rango);
void llenarArrSinRep(int arr[], int n, int rango);
void llenarArrBusc(int arrBase[], int arrBusc[], int n, int rango);
int busquedaSec(int arr[TAM], int n, int buscado);
void status(int tiempo, int cant);


int main()
{
    static int arreglo[TAM], busca[TAM], num[]={10000, 50000, 100000, 200000, 500000};
    time_t tPrev, tPost;
    static int resp, ran=INT_MAX, i, duracion, j;
    printf("Busqueda Secuencial\n");
    for(j=0;j<5;j++)
    {
        llenarArr(arreglo, num[j], ran);
        llenarArrBusc(arreglo, busca, num[j], ran);
        tPrev=clock();
        for(i=0;i<num[j];i++)
            resp=busquedaSec(arreglo, num[j], busca[i]);
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

int busquedaSec(int arr[], int n, int buscado)
{
    int i, codigo=0;
    for(i=0;i<n;i++)
        if(buscado==arr[i])
            codigo=1;
    return(codigo);
}

void status(int tiempo, int cant)
{
    printf("Hice %d b\xa3squedas en %d milisegundos\n", cant, tiempo);
}

