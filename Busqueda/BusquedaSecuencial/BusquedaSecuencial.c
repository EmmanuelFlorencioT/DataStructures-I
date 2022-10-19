#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 10

void llenarArr(int arr[TAM], int n, int rango);
void muestraArr(int arr[TAM], int n);
int busquedaSecA(int arr[TAM], int n, int buscado);
int busquedaSecB(int arr[TAM], int n, int buscado);

int main()
{
    int arreglo[TAM];
    int num=10, resp, busca=63, ran=100;
    llenarArr(arreglo, num, ran);
    muestraArr(arreglo, num);
    resp=busquedaSecB(arreglo, num, busca);
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

void llenarArr(int arr[TAM], int n, int rango)
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

int busquedaSecA(int arr[], int n, int buscado)
{
    int i, codigo=0;
    for(i=0;i<n;i++)
        if(buscado==arr[i])
            codigo=1;
    return(codigo);
}

int busquedaSecB(int arr[], int n, int buscado)
{
    int i, codigo=1;
    for(i=0;i<n&&buscado!=arr[i];i++);
    if(i==n)
        codigo=0;
    return(codigo);
}
