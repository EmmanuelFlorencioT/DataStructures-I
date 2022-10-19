void pascal(arrBi[][TAM]; int N)
{
    int r, c, M=0;
    for(r=0;r<N;r++)
    {
        for(c=0;c<=M;c++)
        {
            arrBi[r][c]=(calculaFact(r))/(calculaFact(c)*calculaFact(r-c));
            printf("%4d", arrBi[r][c]);
        }
        M++;
    }
}
