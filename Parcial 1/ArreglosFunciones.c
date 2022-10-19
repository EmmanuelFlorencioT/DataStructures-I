/*
    Objetivo: Capturar e Imprimir un arreglo de N datos.
    Autor: EFT
    Fecha: 4 Mar 2021
    Notas:
*/
#include<stdio.h>

#define SZ 25

int pideN();
void captArr(int arr[SZ], int n);
void imprimeArr(int arr[SZ], int n);

int main()
{
    int N;
    int datos[SZ];
    N=pideN();
    captArr(datos, N);
    imprimeArr(datos, N);
}

int pideN()
{
    int n;
    do{
        printf("Dame la cantidad de datos(max. 25): ");
        scanf("%d", &n);
      }while(n<1||n>SZ);
    return(n);
}

void captArr(int arr[SZ], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Dame el dato No.%d: ", i);
        scanf("%d", &arr[i]);
    }

}

void imprimeArr(int arr[SZ], int n)
{
    int i2;
    for(i2=0;i2<n;i2++)
    {
        printf("Dato No.%d= %d\n", i2, arr[i2]);
    }
    //printf("%d", n);
}
