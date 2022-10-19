/*
    Objetivo: Hacer una función que reciba 3 números y regrese la mediana
    Autor:EFT
    Fecha:
    Notas:
*/
#include<stdio.h>
#define pi 3.1416

int mediana();

int main()
{
    int resp;
    resp=mediana();
    printf("Mediana= %d", resp);
}

int mediana()
{
    int num[3], aux, i, j;
    for(i=0;i<3;i++)
    {
        printf("Introduce el dato %d: ", i);
        scanf("%d", &num[i]);
    }
    for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if (num[i]>num[j])
			{
				aux=num[i];
				num[i]=num[j];
				num[j]=aux;
			}
		}
	}
	return(num[1]);
}
