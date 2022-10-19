/*Leer una lista de datos enteros almacenados en un archivo
de texto con formato. Nota: USANDO detección de fin de archivo*/

#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch,char *nombreArch, char *modo);
void leerNumeros(FILE *arch);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    FILE *archivo;
    resp=abreArch(&archivo,"numeros.txt","r");
    if(resp)
    {
        leerNumeros(archivo);
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

void leerNumeros(FILE *arch)
{
    int num;
    while(fscanf(arch, "%d", &num) > 0) //Detección el EndOfFile EOF
        printf("%d\t",num);
}

void cierraArch(FILE *arch)
{
    fclose(arch);
}
