void sumaZona(float arrBi[TAM][TAM], float arrUni[TAM], int n)
{
    int r, c, aux=0;
    float suma;
    for(r=0;r<n;r++)
    {
        suma=0;
        for(c=0;c<=aux;c++)
            suma+=arrBi[r][c];
        arrUni[r]=suma;
        aux++;
    }
}
