int cuentaRelNoDirigidas(GRAFO_MR g)
{
    int aux=1, i, j, cont=0;
    for(i=0;i<(g->cv-1);i++)
    {
        for(j=aux;j<g->cv;j++)
            if(g->matRel[j][i]==g->matRel[i][j]);
                cont++;
    }
    return(cont);
}
