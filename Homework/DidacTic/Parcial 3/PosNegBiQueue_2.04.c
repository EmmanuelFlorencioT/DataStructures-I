int formarBiFila(BI_FILA *bq, int dato)
{
    int res=0;
    if(dato>=0) //Positivo?
        if(bq->final1+1 < bq->nmax1)  //Hay espacio en pila1?
        {
            bq->final1++;
            bq->fila1[bq->final1]=dato;
            res=1;
            if(bq->frente1 < 0) //Si la pila1 estaba vacía
                bq->frente1=0;
        }
    else  //Negativo
        if(bq->final2+1 < bq->nmax2) //Hay espacio en pila2?
        {
            bq->final2++;
            bq->fila2[bq->final2]=dato;
            res=1;
            if(bq->frente2 < 0) //Si la pila2 estaba vacía
                bq->frente2=0;
        }
    return(res);
}
