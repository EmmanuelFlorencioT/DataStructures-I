/*
    Objetivo: Calcular el área de un triángulo con la fórmula de Herón.
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
    printf("Un triángulo de dimensiones (%.2f, %.2f, %.2f) tiene un área de (%.2f)", a, b, c, area);
}
