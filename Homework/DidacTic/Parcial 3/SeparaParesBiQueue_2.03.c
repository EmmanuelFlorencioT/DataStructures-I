

int separaParesBiFila(BI_FILA *bq, FILA *q)
{
    int res=0, dato;
    res=iniBiFila(bq, q->nmax);
    if(res==1)
    {
        while(deQueue(q, &dato)==1)
        {
            if(dato%2==0)
            {
                bq->final1++;
                bq->fila1[bq->final1]=dato;
                if(bq->frente1 < 0) //Si la pila1 estaba vacía
                    bq->frente1=0;
            }
            else
            {
                bq->final2++;
                bq->fila2[bq->final2]=dato;
                if(bq->frente2 < 0) //Si la pila2 estaba vacía
                    bq->frente2=0;
            }
        }
    }
    return(res);
}
