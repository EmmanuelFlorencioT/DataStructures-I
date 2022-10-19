void sumaZonaInv(float arrBi[TAM][TAM], float arrUni[TAM], int n)
{
    int r, c, aux;
    float suma;
    aux=n-1;
    for(r=0;r<n;r++)
    {
        suma=0;
        for(c=(n-1);c>=aux;c--)
            suma+=arrBi[r][c];
        arrUni[r]=suma;
        aux--;
    }
}
