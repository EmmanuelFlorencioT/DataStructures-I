#include<stdio.h>

void capCant(float *cant1, float *cant2);
void calcOpBas(float canti1, float canti2, float *rSuma,
               float *rResta, float *rMulti, float *rDiv);
void impRes(float suma, float resta, float multi, float divi);

int main()
{
    float a, b, rS, rR, rM, rD;
    capCant(&a, &b);
    calcOpBas(a, b, &rS, &rR, &rM, &rD);
    impRes(rS, rR, rM, rD);
}

/*Escribir una función que calcule las 4 operaciones básicas a partir de dos cantidades*/

void calcOpBas(float canti1, float canti2, float *rSuma,
               float *rResta, float *rMulti, float *rDiv)
{
    *rSuma=canti1+canti2;
    *rResta=canti1-canti2;
    *rMulti=canti1*canti2;
    *rDiv=canti1/canti2;
}

/*Escribe una función para capturar 2 cantidades*/

void capCant(float *cant1, float *cant2)
{
    printf("Dame la primera cantidad: ");
    scanf("%f", cant1); //Aquí como & y el * son operaciones contrarias entonces se pueden quitar
    printf("Dame la segunda cantidad: ");
    scanf("%f", cant2); //Por lo que hará lo mismo si se dejan o quitar.
}

void impRes(float suma, float resta, float multi, float divi)
{
    printf("La suma es: %.2f\n", suma);
    printf("La resta es: %.2f\n", resta);
    printf("La multiplicaci\xa2n es: %.2f\n", multi);
    printf("La divisi\xa2n es: %.2f\n", divi);
}
