int separaParesBiPila(PILA *p, BI_PILA *bp)
{
    int res=0, dato;
    res=iniPila(&bp->pila1, p->tope+1)&&iniPila(&bp->pila2, p->tope+1);
    if(res==1)
    {
        while(pop(p, dato)==1)
            if(dato%2==0)
                push(&bp->pila1, dato); //Pila 1 es para PARES
            else
                push(&bp->pila2, dato); //Pila 2 es para IMPARES
    }
    return(res);
}
