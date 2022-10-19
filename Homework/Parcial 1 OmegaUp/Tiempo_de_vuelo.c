/*
    Objetivo: Obtener el tiempo de vuelo de un objeto a paritr de su Vi y Angulo de inclinación
    Autor: EFT
    Fecha: 24 Feb 2021
    Notas:
*/
#include<stdio.h>
#include<math.h>

#define pi 3.1416
#define G 9.81

float conv_aRad(float anguloDec);

int main()
{
    float Vi, angD, angR, tiempo;
    printf("Velocidad inicial(m/seg): ");
    scanf("%f", &Vi);
    printf("Angulo de inclinación(grados): ");
    scanf("%f", &angD);
    angR=conv_aRad(angD);
    tiempo=(2*Vi*sin(angR))/G;
    printf("Tiempo de vuelo = %.2f seg.", tiempo);
}

float conv_aRad(float anguloDec)
{
    float rad;
    rad=(anguloDec*pi)/180;
    return(rad);
}
