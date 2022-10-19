int push_bipila(BI_PILA *bp, int dato)
{
    int res=0;
    if(dato>=0) //pila1 es para POSITIVOS
        if(bp->pila1.tope+1 < bp->pila1.tam)
        {
            bp->pila1.tope++;
            bp->pila1.pila[bp->pila1.tope]=dato;
            res=1;
        }
    else       //pila2 es para NEGATIVOS
        if(bp->pila2.tope+1 < bp->pila2.tam)
        {
            bp->pila2.tope++;
            bp->pila2.pila[bp->pila2.tope]=dato;
            res=1;
        }
    return(res);
}
