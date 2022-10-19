#define NMAX no.ElemMax

typedef struct
{
    int nmax;
    int cv;
    int vecVer[NMAX];
    int matRel[NMAX][NMAX];
} GRAFO_MR;

/*INICIALIZACIÓN*/
int iniGrafoMR(GRAFO_MR *g, int nm)
{
    res=0;
    if(nm<=NMAX)
    {
        g->nmax=nm;
        g->cv=0;
        res=1;
    }
    return(res);
}

/*Inserta un Vértice*/
int insVerMR(GRAFO_MR *g, int v)
{
    int res=0, i;
    if(g->cv < g->nmax)
    {
        for(i=0;i<g->cv && v!=g->vecVer[i];i++);
        if(i==g->cv) //No lo encontró
        {
            g->vecVer[g->cv]=v;
            for(i=0;i<=g->cv;i++)
                g->matRel[g->cv][i]=g->matRel[i][g->cv]=0;
            g->cv++;
            res=1;
        }
    }
    return(res);
}

/*Inserta una relación*/
/*Los arreglos SIEMPRE pasan por referencia, no necesitan que el parámetro
  de la función esté pasada por referencia*/
int insRelMR(GRAFO_MR g, int vf, int vd)
{
    int res=0, ren, col;
    for(ren=0;ren<g.cv && vf!=g.vecVer[ren];ren++);
    if(ren<g.cv)
    {
        for(col=0;col<g.cv && vd!=g.vecVer[col];col++);
        if(col<g.cv)
            res=g.matRel[ren][col]=1; //Establecemos la relación y se cumplió el obj.
    }
    return(res);
}

/*Elimina una relación*/
int elimRelMR(GRAFO_MR g, int vf, int vd)
{
    int res=0, ren, col;
    for(ren=0;ren<g.cv && vf!=g.vecVer[ren];ren++);
    if(ren<g.cv)
    {
        for(col=0;col<g.cv && vd!=g.vecVer[col];col++);
        if(col<g.cv)
        {
            g.matRel[ren][col]=0;
            res=1;
        }
    }
    return(res);
}

/*Eliminación de vértice*/
int elimVerMR(GRAFO_MR *g, int v)
{
    int res=0, pos, i;
    for(pos=0;pos < g->cv && v!=g->vecVer[pos];pos++);
    if(pos < g->cv)
    {
        g->cv--;
        vecVer[pos]=vecVer[g->cv];
        for(i=0;i <= g->cv;i++)
        {
            matRel[pos][i]=matRel[g->cv][i];
            matRel[i][pos]=matRel[i][g->cv];
        }
        res=1;
    }
    return(res);
}

/*Captura relaciones*/

/*Recorrido de un grafo MR -> acceso a los datos*/
/*Función para mostrar la información del grafo
  A: B D G
  B: A C J
  ...
*/
void muestraGrafoMR(GRAFO_MR g)
{
    int i, j;
    for(i=0;i<g.cv;i++)
    {
        printf("%d: ", g.vecVer[i]);
        for(j=0;j<g.cv;j++)
            if(g.matRel[i][j]==1)
                printf("%d   ", g.vecVer[j]);
        printf("\n");
    }
}

/*Funcion para mostrar los vértices de un grafo con su No. de Relaciones*/
void muestraVerNoRels(GRAFO_MR g)
{
    int i, j, cont;
    for(i=0;i<g.cv;i++)
    {
        cont=0;
        for(j=0;j<g.cv;j++)
            if(g.matRel[i][j]==1)  //Estas dos líneas se pueden abreviar como:
                cont++;             //cont+=g.matRel[i][j];
        printf("%d tiene %d relacion(es)\n", g.vecVer[i], cont);
    }
}

/*Funcion para encontrar el vector más relacionado*/
int encuentraVerMasRel(GRAFO_MR g)
{
    int masRel, i, j, cont, sMayor=0;
    for(i=0;i<g.cv;i++)
    {
        cont=0;
        for(j=0;j<g.cv;j++)
            cont+=g.matRel[i][j];
        if(cont>sMayor) //Algoritmo del mayor
        {
            sMayor=cont;
            masRel=g.vecVer[i];
        }
    }
    return(masRel);
}

/*Determinar si hay relacion(UNIdireccional) entre dos vértices*/
int hayRelUniMR(GRAFO_MR g, int vf, int vd)
{
    int res=0, ren, col;
    for(ren=0;ren<g.cv && vf!=g.vecVer[ren];ren++);
    if(ren<g.cv)
    {
        for(col=0;col<g.cv && vd!=g.vecVer[col];col++);
        if(col<g.cv)
            if(g.matRel[ren][col]==1)   //Se pueden simplicar estas 2 lineas:
                res=1;                  //res=g.matRel[ren][col];
    }
    return(res);
}

/*Determinar si hay relación(BIdireccional) entre dos vértices*/
int hayRelBiMR(GRAFO_MR g, int vf, int vd)
{
    int res=0, ren, col;
    for(ren=0;ren<g.cv && vf!=g.vecVer[ren];ren++);
    if(ren<g.cv)
    {
        for(col=0;col<g.cv && vd!=g.vecVer[col];col++);
        if(col<g.cv)
            if(g.matRel[ren][col]==1&&g.matRel[col][ren]==1) //Se checa la bidireccionalidad
                res=1;   //simplificado: res=g.matRel[ren][col]==1&&g.matRel[col][ren]==1;
    }
    return(res);
}

/*Determinar si hay transitividad entre 3 vértices. v1-->v2-->v3*/
int hayTrans(GRAFO_MR g, int v1, int v2, int v3)
{
    int res=0,ren, col;
    for(ren=0;ren<g.cv && v1!=g.vecVer[ren];ren++);
    if(ren<g.cv)
    {
        for(col=0;col<g.cv && v2!=g.vecVer[col];col++);
        if(col<g.cv && g.matRel[ren][col]==1)
        {
            ren=col;
            for(col=0;col<g.cv && v3!=g.vecVer[col];col++);
            if(col<g.cv && g.matRel[ren][col]==1)
                res=1;
        }
    }
    return(res);
}
