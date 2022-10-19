/*Programa que ESCRIBE n datos (nombre, edad) en un archivo de texto*/

#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch, char *nombreArch, char *modo);
int pideN();
void escribeDatos(FILE *arch, int n);
void cierraArch(FILE *arch);

int main()
{
    int resp, no;
    FILE *archivo;
    resp=abreArch(&archivo,"datos.txt","w");
    if(resp)
    {
        no=pideN();
        escribeDatos(archivo,no);
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

int pideN()
{
    int n;
    printf("Cuántos datos? ");
    scanf("%d", &n);
    return(n);
}

void escribeDatos(FILE *f,int n)
{
    int i, edad;
    char nombre[30];
    for(i=0;i<n;i++)
    {
        printf("Dato No. %d:\n",i);
        fflush(stdin);  //Para limpiar el caracter <enter> que se queda 'colgado' o pendiente
        printf("Nombre: ");
        gets(nombre);
        printf("Edad: ");
        scanf("%d",&edad); fprintf(f,"%s\n%d",nombre,edad);
    }
}

void cierraArch(FILE *arch)
{
    fclose(arch);
}
