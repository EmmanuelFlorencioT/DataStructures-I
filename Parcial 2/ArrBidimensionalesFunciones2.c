/*Función para calcular los promedios por materia, por periodo y general de
  un alumno, simulando una boleta.
  NOTA: La boleta tiene una espacio adicional donde se pueden almacenar los promedios*/
void boleta(float arrBol[TAM][TAM], int nPer, int nMat)
{
    int cMat, cPer; //contador de materias y periodos.
    float ac;  //ACumulador
    //Promedios por materia
    for(cMat=0;cMat<nMat;cMat++)
    {
        ac=0;
        for(cPer=0;cPer<nPer;cPer++)
            ac+=arrBol[cMat][cPer];
        arrBol[cMat][nPer]=ac/nPer; //<--Como el promedio va en el mismo arreglo.
                                    //    (en el espacio adicional)
    }
    //Promedios por periodo
    for(cPer=0;cPer<nPer;cPer++)
    {
        ac=0;
        for(cMat=0;cMat<nMat;cMat++)
            ac+=arrBi[cMat][cPer];
        arrBi[nMat][cPer]=ac/nMat;
    }
    //Promedios general
    ac=0;
    for(cMat=0;cMat<nMat;cMat++)
        for(cPer=0;cPer<nPer;cPer++)
            ac+=arrBol[cMat][cPer];  //Se va a sumar durante todo el arreglo
    arrBol[nMat][nPer]=ac/(nMat*nPer);
}

/*Función para calcular los promedios por materia, por periodo y general de
  un alumno, simulando una boleta.
  NOTA: Los promedios de materia, periodo y general se entregan en arreglos
        unidimensionales */
void boleta(float arrBol[TAM][TAM], int nPer, int nMat, float promP[TAM],
             float promM[TAM], float *prGen)
{
    int cMat, cPer; //contador de materias y periodos.
    float ac;  //ACumulador
    //Promedios por materia
    for(cMat=0;cMat<nMat;cMat++)
    {
        ac=0;
        for(cPer=0;cPer<nPer;cPer++)
            ac+=arrBol[cMat][cPer];
        promM[cMat]=ac/nPer;
    }
    //Promedios por periodo
    for(cPer=0;cPer<nPer;cPer++)
    {
        ac=0;
        for(cMat=0;cMat<nMat;cMat++)
            ac+=arrBi[cMat][cPer];
        promP[cPer]=ac/nMat;
    }
    //Promedios general
    ac=0;
    for(cMat=0;cMat<nMat;cMat++)
        for(cPer=0;cPer<nPer;cPer++)
            ac+=arrBol[cMat][cPer];  //Se va a sumar durante todo el arreglo
    *prGen=ac/(nMat*nPer);
}

/*Funcion para sumar por zonas y entregar el resultado en un arreglo unidimensional*/
void sumaZona(int arrBi[][TAM], int nR, int nC, int sumatoria[])
{
    int r, c;
    int start=0, suma;
    for(r=0;r<nR;r++)
    {
        suma=0;
        for(c=start;c<nC;c++)
            suma+=arrBi[r][c];
        start++;
    }
}
