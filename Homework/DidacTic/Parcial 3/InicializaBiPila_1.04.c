int iniBiPila(BI_PILA *bp, int nm)
{
    int res=0;
    if(nm<NMAX)
    {
        bp->pila1.nmax=nm;
        bp->pila1.tope=-1;
        bp->pila2.nmax=nm;
        bp->pila2.tope=-1;
        res=1;
    }
    return(res);
}
