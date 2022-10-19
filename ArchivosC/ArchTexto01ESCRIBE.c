#include <stdio.h>
#include <stdlib.h>

int abreArch(FILE **arch,char *nombreArch, char *modo);
char pideCaracter();
void escribeCaracter(FILE *arch, char ch);
void cierraArch(FILE *arch);

int main()
{
    int resp;
    char caracter;
    FILE *archivo;
    resp=abreArch(&archivo,"caracter.txt","w");
    if(resp==1)
    {
        caracter=pideCaracter();
        escribeCaracter(archivo,caracter);
        printf("El caracter se almacenó correctamente\n");
        cierraArch(archivo);
    }
    else
        printf("El archivo no existe\n");
}


/*FUNCIÓN para abrir/crear un archivo*/
//La variable 'arch' recibirá el valor de NULL o diferente de NULL, por eso necesita
//pasar por referencia
/*Las cadenas se puede representar como:
char nombreArch[30] = char nombreArch[] = char *nombreArch
TODAS son maneras válidas de referir al arreglo de caracteres o cadena*/
int abreArch(FILE **arch,char *nombreArch, char *modo) //Inicializar
{
    int res=0;
    *arch=fopen(nombreArch,modo); //Aqui 'arch' recibe el valor y se lo debe llevar de la función
    if(*arch!=NULL) //Se puede abreviar en C:   if(*arch)
        res=1;
    return(res);
}

char pideCaracter()
{
    char ch;
    printf("Dame el caracter: ");
    scanf("%c", &ch);
    return(ch);
}

void escribeCaracter(FILE *arch,char ch)
{
    fprintf(arch,"%c",ch);
}

void cierraArch(FILE *arch)
{
    fclose(arch);
}
