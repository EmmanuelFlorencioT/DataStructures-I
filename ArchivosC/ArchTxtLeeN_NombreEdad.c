/*Programa que lee una serie de datos (nomnbre, edad) desde un archivo de texto
  Nota: Usando deteccion de fin de archivo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int abreArch(FILE **arch, char *nombreArch, char *modo);
void leeDatos(FILE *arch);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    FILE *archivo;
    resp=abreArch(&archivo,"datos.txt","r");
    if(resp)
    {
        leeDatos(archivo);
        cierraArch(archivo);
    }
    else
    printf("El archivo no existe\n");
}

int abreArch(FILE **arch, char *nombreArch, char *modo)
{
    int res=0;
    *arch=fopen(nombreArch, modo);
    if(*arch)
        res=1;
    return(res);
}

void leeDatos(FILE *arch)
{
    int edad;
    char nombre[30];
    while(fgets(nombre,30,arch) > 0)
    {
        nombre[strlen(nombre)-1]=0;
        fscanf(arch, "%d", &edad);
        printf("%s%5d\n", nombre, edad);
    }
}

void cierraArch(FILE *arch)
{
    fclose(arch);
}
