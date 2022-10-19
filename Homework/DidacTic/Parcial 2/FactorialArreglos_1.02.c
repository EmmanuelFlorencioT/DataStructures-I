void tablaFact(int arrBi[TAM][TAM], int n)
{
    int r, c;
    int aux;
    for(r=1;r<=n;r++)
        for(c=0;c<=1;c++)
        {
            if(c==0)
                arrBi[r][c]=r;
            else
            {
                arrBi[r][c]=1;
                for(aux=1;aux<=r;aux++)
                    arrBi[r][c]*=aux;
            }
        }
}
