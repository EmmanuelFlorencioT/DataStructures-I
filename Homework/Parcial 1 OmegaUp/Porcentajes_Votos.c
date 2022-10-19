/*
    Objetivo: Calcular el porcentaje de votos a favor, en contra y abestenciones
    Autor: EFT
    Fecha: 24 Feb 2021
    Notas:
*/
#include<stdio.h>

int main()
{
    float total, favor, contra, abst;
    float perfavor, percontra, perabst;
    printf("A favor: ");
    scanf("%f", &favor);
    printf("En contra: ");
    scanf("%f", &contra);
    printf("Abstenciones: ");
    scanf("%f", &abst);
    total=favor+contra+abst;
    perfavor=(favor*100)/total;
    percontra=(contra*100)/total;
    perabst=(abst*100)/total;

    printf("Porcentajes calculados:\n");
    printf("A favor: %.2f\n", perfavor);
    printf("En contra: %.2f\n", percontra);
    printf("Abstenciones: %.2f\n", perabst);

}
