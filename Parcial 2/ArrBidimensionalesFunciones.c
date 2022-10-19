#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 15

void introRenCol(int *nR, int *nC);
void muestraArrBi(int arrBi[TAM][TAM], int nR, int nC);
void llenaArrBi(int arrBi[TAM][TAM], int nR, int nC, int dato);
void capturaArrBi(int arrBi[TAM][TAM], int nR, int nC);

int main()
{
    int ren, col;
    int arregloBi[TAM][TAM];
    introRenCol(&ren, &col);
    capturaArrBi(arregloBi, ren, col);
    muestraArrBi(arregloBi, ren, col);
}

/*Función para capturar el No. de Renglones y Columnas*/
void introRenCol(int *nR, int *nC)
{
    do{
    printf("No. de renglones: ");
    scanf("%d", nR);
      }while(*nR>TAM || *nR<1);
    do{
    printf("No. de columnas: ");
    scanf("%d", nC);
      }while(*nC>TAM || *nC<1);
}

/*Función para capturar los datos de un arreglo bidimensional*/
void capturaArrBi(int arrBi[TAM][TAM], int nR, int nC)
{
    int r, c;
    for(r=0;r<nR;r++)
        for(c=0;c<nC;c++)
        {
            printf("Dato [%d, %d]: ", r, c);
            scanf("%d", &arrBi[r][c]);
    //El '&' es necesario a pesar de ser parámetro por referencia. (Por estar implícito)
        }
}

/*Función para mostrar un arreglo bidimensional*/
void muestraArrBi(int arrBi[TAM][TAM], int nR, int nC)
{
    int r, c;
    for(r=0;r<nR;r++)
    {
        for(c=0;c<nC;c++)  //Tour por todo el arreglo
            printf("%4d", arrBi[r][c]);
        printf("\n");   //Camabio de renglón fuera del ciclo 'c'
    }
}


/*Función para llenar un arreglo con un dato específico*/
void llenaArrBi(int arrBi[TAM][TAM], int nR, int nC, int dato)
/*Se puede simplificar la definición del arreglo
  De la sig manera --> int arrBi[][TAM]*/
{
    int r, c;
    for(r=0;r<nR;r++)
        for(c=0;c<nC;c++)
            arrBi[r][c]=dato;
}

/*Función para llenar un arreglo bidi con datos AL AZAR en un rango 'n'
      numAzar=rand()%rango  -->Son números pseudoaleatorios
     Ejemplo: nombreVar=rando()%100
  La función 'rand' viene en la biblioteca stdlib.h = 'standardlibrary'
  La función 'time' viene en la biblioteca time.h
  Para REVOLVER los datos se usa srand(time(NULL));
  */
void llenarBiAzar(int arrBi[][TAM], int nR, int nC, int rango)
{
    int r, c;
    srand(time(NULL));  //stdlib.h ,  time.h
    for(r=0;r<nR;r++)
        for(c=0;c<nC;c++)
            arrBi[r][c]=rand()%rango;
}

