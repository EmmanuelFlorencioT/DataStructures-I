/*
    Objetivo: Calcular el �rea de un tri�ngulo con la f�rmula de Her�n.
    Autor: EFT
    Fecha: 24 Feb 2021
    Notas:
*/
#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c, area;
    printf("Lado a: ");
    scanf("%f", &a);
    printf("Lado b: ");
    scanf("%f", &b);
    printf("Lado c: ");
    scanf("%f", &c);
    area=sqrt(((a+b+c)*(b+c-a)*(a+c-b)*(a+b-c))/16);
    printf("Un tri�ngulo de dimensiones (%.2f, %.2f, %.2f) tiene un �rea de (%.2f)", a, b, c, area);
}
