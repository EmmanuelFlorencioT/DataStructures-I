/*Programa que guarda una cantidad N de datos*/

#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch,char *nombreArch, char *modo);
int pideN();
void escribeNumeros(FILE *arch,int n);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    FILE *archivo;
    int no;
    resp=abreArch(&archivo,"numeros.txt","w");
    if(resp)
    {
        no=pideN();
        escribeNumeros(archivo,no);
        cierraArch(archivo);
    }
    else
        printf("El archivo no existe\n");
}

int abreArch(FILE **arch,char *nombreArch, char *modo)
{
    int res=0;
    *arch=fopen(nombreArch,modo);
    if(*arch)
        res=1;
    return(res);
}

int pideN()
{
    int n;
    printf("Cuantos datos:");
    scanf("%d",&n);
    return(n);
}

void escribeNumeros(FILE *arch,int n)
{
    int i, num;
    for(i=0;i<n;i++)
    {
        printf("Dato No. %d:",i);
        scanf("%d",&num);
        fprintf(arch,"%d\t",num);
    }
}

void cierraArch(FILE *arch)
{
 fclose(arch);
}
