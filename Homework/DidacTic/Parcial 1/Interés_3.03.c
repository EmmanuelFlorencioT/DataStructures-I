/*
int interesx2(float dinero)
{
    int i=0;
    float ac;
    ac=dinero;
    while(ac<=(2*dinero))
    {
        i++;
        ac=ac*1.11;
    }
    return(i);
}
*/
#include<stdio.h>

int main()
{
    int i=0;
    float ac, dinero;
    printf("Dinero: ");
    scanf("%f", &dinero);
    ac=dinero;
    printf("%f\n", ac);
    while(ac<=(2*dinero))
    {
        i++;
        ac=ac*1.11;
        printf("Anio %d = %f\n", i, ac);
    }
    printf("Anios para duplicar: %d", i);
}
