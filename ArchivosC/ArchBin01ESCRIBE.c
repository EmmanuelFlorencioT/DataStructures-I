/*Programa que almacena un dato en un archivo binario*/

#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch, char *nombreArch, char *modo);
int pideNumero();
void escribeNumero(FILE *arch, int num);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    FILE *archivo;
    int numero;
    resp=abreArch(&archivo, "numeroBin.dat","wb");
    if(resp)
    {
        numero=pideNumero();
        escribeNumero(archivo, numero);
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

int pideNumero()
{
    int num;
    printf("Escribe el numero: ");
    scanf("%d", &num);
    return(num);
}

void escribeNumero(FILE *arch, int num)
{
    fwrite(&num, sizeof(int), 1, arch);
}

void cierraArch(FILE *arch)
{
 fclose(arch);
}
