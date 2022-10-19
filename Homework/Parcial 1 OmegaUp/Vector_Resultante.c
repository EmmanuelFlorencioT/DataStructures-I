/*
    Objetivo: Calcular el vecotr resultante a partir de la suma de dos vecotres.
    Autor: EFT
    Fecha: 24 Feb 2021
    Notas:
*/
#include<stdio.h>
#include<math.h>

#define pi 3.141592654

float componenteX(float vector, float ang);
float componenteY(float vector, float ang);
float conv_aRadianes(float anguloDec);
float conv_aDecimal(float anguloRad);

int main()
{
    float v1, v1x, v1y, a1, aR1; //aR1=angulo en Radianes 1
    float v2, v2x, v2y, a2, aR2; //aR2=angulo en Radianes 2
    float r, rx, ry, ar, arR;  //arR=angulo resultante en Radianes
    printf("Magnitud del vector 1: ");
    scanf("%f", &v1);
    printf("Dirección(grados) del vector 1: ");
    scanf("%f", &a1);
    printf("Magnitud del vector 2: ");
    scanf("%f", &v2);
    printf("Dirección(grados) del vector 2: ");
    scanf("%f", &a2);
    aR1=conv_aRadianes(a1);
    aR2=conv_aRadianes(a2);
    v1x=componenteX(v1, aR1);
    v2x=componenteX(v2, aR2);
    v1y=componenteY(v1, aR1);
    v2y=componenteY(v2, aR2);
    rx=v1x+v2x;
    ry=v1y+v2y;
    r=sqrt(pow(rx, 2)+pow(ry, 2));  //Magnitud del vector 'r'esultante
    arR=atan(ry/rx);
    ar=conv_aDecimal(arR);  //ar=angulo resultante (en decimal)
    printf("Vector resultante (%.2f, %.2f°)", r, ar);
}

float conv_aRadianes(float anguloDec)
{
    float rad;
    rad=(anguloDec*pi)/180;
    return(rad);
}

float componenteX(float vector, float ang)
{
    float compX;
    compX=vector*cos(ang);
    return(compX);
}

float componenteY(float vector, float ang)
{
    float compY;
    compY=vector*sin(ang);
    return(compY);
}

float conv_aDecimal(float anguloRad)
{
    float dec;
    dec=(anguloRad*180)/pi;
    return(dec);
}
