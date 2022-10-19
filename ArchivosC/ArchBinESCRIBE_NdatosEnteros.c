/*Programa que escribe n daots enteros en un archivo binario*/

#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch, char *nombreArch, char *modo);
int pideN();
void escribeNumeros(FILE *arch, int n);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    FILE *archivo;
    int numero;
    resp=abreArch(&archivo, "numerosBin.dat","wb");
    if(resp)
    {
        numero=pideN();
        escribeNumeros(archivo, numero);
        cierraArch(archivo);
    }
    else
        printf("Archivo no disponible\n");
}

int abreArch(FILE **arch, char *nombreArch, char *modo)
{
    int res=0;
    *arch=fopen(nombreArch, modo);
    if(*arch)
        res=1;
    return(res);
}

int pideN()
{
    int n;
    printf("Cuántos datos? ");
    scanf("%d",&n);
    return(n);
}

void escribeNumeros(FILE *arch,int n)
{
    int i,num;
    for(i=0; i<n; i++)
    {
        printf("Dato No. %d:",i+1);
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, arch);
    }
}

void cierraArch(FILE *arch)
{
    fclose(arch);
}
