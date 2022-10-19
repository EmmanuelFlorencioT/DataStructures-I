/*
    Objetivo: Repetir una instrucción 10 veces
    Autor: EFT
    Fecha: 18 Febrero 2021
    Notas:
*/
#include<stdio.h>


int main()
{
    //Sentencia for
    int i;
    for(i=1; i<=10; i++)
    {
        printf("Hola Mundo, %d\n", i);
    }
    printf("\n");
    //Sentencia while
    i=1;
    while(i<=10)
    {
        printf("Hola Mundo, %d\n", i);
        i++;
    }
    printf("\n");
    //Sentencia do-while
    i=1;
    do
    {
        printf("Hola Mundo, %d\n", i);
        i++;
    } while (i<=10);
}
