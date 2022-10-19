/*Funci�n para llenar un arreglo bidi con datos AL AZAR en un rango 'n'
      numAzar=rand()%rango  -->Son n�meros pseudoaleatorios
     Ejemplo: nombreVar=rando()%100
  La funci�n 'rand' viene en la biblioteca stdlib.h = 'standardlibrary'
  La funci�n 'time' viene en la biblioteca time.h
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
