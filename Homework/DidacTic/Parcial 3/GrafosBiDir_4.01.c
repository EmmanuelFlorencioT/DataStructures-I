/*Suponiendo que se comienza con el rengl�n cero y se revisan los valores del rengl�n y
estas relaciones se pasan a la columna cero*/

void convRelNoDirigida(GRAFO_MR g)
{
    int aux=1, i, j;
    for(i=0;i<(g->cv-1);i++)
    {
        for(j=aux;j<g->cv;j++)
            g->matRel[j][i]=g->matRel[i][j];
        aux++;
    }
}
