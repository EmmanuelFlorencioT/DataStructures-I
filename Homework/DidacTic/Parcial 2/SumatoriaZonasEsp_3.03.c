void sumaZonaEsp(float arrBi[TAM][TAM], float arrUni[TAM], int n)
{
    int ren, col, aux;
    float suma;
    for(aux=0;aux<n;aux++)
    {
        suma=0;
        //Suma de las columnas a la derecha de la casilla clave [aux, aux]
        for(ren=aux;ren<(aux+1);ren++)
            for(col=(aux+1);col<n;col++)
                suma+=arrBi[ren][col];
        //Suma de los renglones abajo de la casilla clave [aux, aux]
        for(col=aux;col<(aux+1);col++)
            for(ren=(aux+1);ren<n;ren++)
                suma+=arrBi[ren][col];
        //Suma de la casilla clave [aux, aux]
        arrUni[aux]=arrBi[aux][aux]+suma;
    }
}
