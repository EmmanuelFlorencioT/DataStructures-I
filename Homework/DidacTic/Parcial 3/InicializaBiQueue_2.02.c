int iniBiFila(BI_FILA *bq, int nm)
{
    int res=0;
    if(nm <= NMAX)
    {
        bq->nmax1=bq->nmax2=nm;
        bq->frente1=bq->final1=bq->frente2=bq->final2=-1;
        res=1;
    }
    return(res);
}
