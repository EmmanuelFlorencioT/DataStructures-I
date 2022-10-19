/*  Objetivo: Calcular el valor para un producto en un tienda que tiene rebajas.
    Autor: EFT
    Fecha: 8 Mar 2021
    Notas: Cuando el valor del producto es...
            a) > 2500, el descuento es de 12%
            b) < 2500, el descuento es de 7%
*/
#include <stdio.h>

float pedirPrecio();
void precioFinal(float preOrig, float *preDesc);
void imprimePrecio(float precio);

int main()
{
    float precio, preFinal;
    precio=pedirPrecio();
    precioFinal(precio, &preFinal);
    imprimePrecio(preFinal);
}

float pedirPrecio()
{
    float prec;
    printf("Precio del producto sin descuento: ");
    scanf("%f", &prec);
    return(prec);
}

void precioFinal(float preOrig, float *preDesc)
{
    if(preOrig>2500)
        *preDesc=preOrig*0.88;
    else
        *preDesc=preOrig*0.93;
}

void imprimePrecio(float precio)
{
    printf("Precio con descuento: %.2f\n", precio);
}
