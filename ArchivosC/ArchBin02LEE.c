/*Programa que lee un dato desde un archivo binario*/

#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch, char *nombreArch, char *modo);
void entregaNumero(int num);
int leeNumero(FILE *arch);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    FILE *archivo;
    int numero;
    resp=abreArch(&archivo, "numeroBin.dat","rb");
    if(resp)
    {
        numero=leeNumero(archivo);
        entregaNumero(numero);
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

void entregaNumero(int num)
{
    printf("El numero leido es: %d\n\n",num);
}

int leeNumero(FILE *arch)
{
    int num;
    fread(&num,sizeof(int), 1, arch);
    return(num);
}

void cierraArch(FILE *arch)
{
    fclose(arch);
}
