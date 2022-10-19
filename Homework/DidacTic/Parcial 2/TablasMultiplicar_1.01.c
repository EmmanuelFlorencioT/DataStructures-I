void tablas(int arrBi[][TAM], int n)
{
    int r, c;
    arrBi[0][0]=x;
    for(r=1;r<=n;r++)
        arrBi[r][0]=r;

    for(c=1;c<=n;c++)
        arrBi[0][c]=c;

    for(c=1;c<=n;c++)
        for(r=1;r<=n;r++)
            arrBi[r][c]=r*c;
}
