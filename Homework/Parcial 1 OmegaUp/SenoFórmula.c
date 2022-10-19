/*
    Objetivo: Calcular el valor del Seno(ang) con fórmula
    Autor: EFT
    Fecha: 2 Mar 2021
    Nota(s):
*/
#include<stdio.h>
#include<math.h>

#define pi 3.1416

float conv_aRad(float angD);

main()
{
    float angDec, angRad, SenoA;
    printf("Angulo(grados): ");
    scanf("%f", &angDec);
    angRad=conv_aRad(angDec);
    SenoA=sqrt(1-pow(cos(angRad),2));
    printf("Seno(%.2f°) = %.2f", angDec, SenoA);
}

float conv_aRad(float angD)
{
    float rad;
    rad=angD*pi/180;
    return(rad);
}
