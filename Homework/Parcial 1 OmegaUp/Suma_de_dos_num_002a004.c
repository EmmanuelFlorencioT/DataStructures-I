/*
    Objetivo: Suma de dos números
    Autor: EFT
    Fecha: 19 Feb 2021
    Notas:  a)Numeros +/- y enteros
*/
#include<stdio.h>

int main()
{
    int a, b, res;
    printf("Dame la 1era. cantidad: ");
    scanf("%d", &a);
    printf("Dame la 2da. cantidad: ");
    scanf("%d", &b);
    res=a+b;
    printf("%5d\n", a);
    printf("+%4d\n", b);
    printf(" ----\n");
    printf("%5d\n", res);
}
