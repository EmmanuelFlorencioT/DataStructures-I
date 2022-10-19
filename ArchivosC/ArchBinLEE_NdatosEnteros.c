/*Programa que lee n datos enteros desde un archivo binario*/

#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch, char *nombreArch, char *modo);
void leeNumeros(FILE *arch);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    FILE *archivo;
    resp=abreArch(&archivo, "numerosBin.dat","rb");
    if(resp)
    {
        leeNumeros(archivo);
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

void leeNumeros(FILE *arch)
{
    int num, i=0;
    while(fread(&num,sizeof(int), 1, arch) > 0)
        printf("Dato No. %d: %d\n", ++i, num);
}

void cierraArch(FILE *arch)
{
    fclose(arch);
}
