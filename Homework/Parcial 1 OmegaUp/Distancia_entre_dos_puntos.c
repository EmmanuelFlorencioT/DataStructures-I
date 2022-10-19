/*
    Objetivo: Calcular la distancia entre dos puntos a partir de coordenadas.
    Autor: EFT
    Fecha: 24 Feb 2021
    Notas:
*/
#include<stdio.h>
#include<math.h>

int main()
{
    float x1, y1, x2, y2, dist;
    printf("* * * Coordenadas * * *\n");
    printf("x1: ");
    scanf("%f", &x1);
    printf("y1: ");
    scanf("%f", &y1);
    printf("x2: ");
    scanf("%f", &x2);
    printf("y2: ");
    scanf("%f", &y2);
    dist=sqrt(pow((y2-y1),2)+pow((x2-x1),2));
    printf("La distancia entre (%.2f, %.2f) y (%.2f, %.2f) es %.2f", x1, y1, x2, y2, dist);
}
