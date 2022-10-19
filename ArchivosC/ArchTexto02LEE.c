#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch,char *nombreArch, char *modo);
char leeCaracter(FILE *arch);
void muestraCaracter(char ch);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    char caracter;
    FILE *archivo;
    resp=abreArch(&archivo,"caracter.txt","r");
    if(resp)
    {
        caracter=leeCaracter(archivo);
        muestraCaracter(caracter);
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

void muestraCaracter(char ch)
{
    printf("El carácter leído es: %c\n", ch);
}

char leeCaracter(FILE *arch)
{
    char ch;
    fscanf(arch,"%c", &ch);
    return(ch);
}

void cierraArch(FILE *arch)
{
    fclose(arch);
}
