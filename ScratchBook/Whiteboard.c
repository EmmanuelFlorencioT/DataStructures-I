int cuentaSumidero(GRAFO_MR g)
{
    int i, j, disc, cont, res=-1;
    for(i=0;i<g.cv;i++)
    {
        cont=0;
        for(j=0;j<g.cv;j++)
            cont+=g.matRel[i][j];
        if(cont==0)
        {
            disc=0;
            for(j=0;k<g.cv;j++)
                disc+=g.matRel[j][i];
            if(disc!=0)
                res=i;
        }
    }
    return(res); //Si res=-1, no encontró vértice sumidero
}

int deQueueBiFila(BI_FILA *bq, int *dato, int selecFila)
{
    int res=0;
    if(selecFila==1)
    {
        if(bq->frente1 > -1)
        {
            *dato=bq->fila1[bq->frente1];
            if(bq->frente1==bq->final1)
                bq->frente1=bq->final1=-1;
            else
                bq->frente1++;
            res=1;
        }
    }
    if(selecFila==2)
    {
        if(bq->frente2 > -1)
        {
            *dato=bq->fila2[bq->frente2];
            if(bq->frente2==bq->final2)
                bq->frente2=bq->final2=-1;
            else
                bq->frente2++;
            res=1;
        }
    }
    return(res);
}

int push_npila(N_PILA *np, int dato, int v)
{
    int res=0;
    np->n=(v-1); //Suponiendo que el usuario quiere la "segunda" pila, la cantidad va desfasada por 1
    if(np->pilas[np->n].tope+1 < np->pilas[np->n].nmax)
    {
        np->pilas[np->n].tope++;
        np->pilas[np->n].pila[np->pilas[np->n].tope]=dato;
        res=1;
    }
    return(res);
}


typedef struct
{
    int claveAlu;
    char nombreAlu[30];
    float calif1;
    float calif2;
    float calif3;
    char carrera[3]; //Suponiendo que la cadena venga como IC, II o ISI
} ALU;

typedef struct
{
    int cAlu;
    char nAlu[30];
    float cal1;
    float cal2;
    float cal3;
} ALU_D;


void separaAlum(FILE *alum, FILE *alumIC, FILE *alumII, FILE *alumISI)
{
    ALU a;
    ALU_D aDiff;

    while(fscanf(alum, "%d", &a.claveAlu)>0)
    {
        fgets(a.nombreAlu, 30, alum)
        a.nombreAlu[strlen(a.nombreAlu)-1]='\0';
        fscanf(alum, "%f%f%f", &a.calif1, &a.calif2, &a.calif3);
        fgets(a.carrera, 3, alum)
        a.carrera[strlen(a.carrera)-1]='\0';
        aDiff.cAlu=a.claveAlu;
        strcpy(aDiff.nAlu, a.nombreAlu);
        aDiff.cal1=a.calif1;
        aDiff.cal2=a.calif2;
        aDiff.cal3=a.calif3;
        if(strcmp(strlwr(a.carrera), "ic")==0)
        {
            fwrite(&aDiff, sizeof(ALU_D), 1, alumIC);
        }
        if(strcmp(strlwr(a.carrera), "ii")==0)
        {
            fwrite(&aDiff, sizeof(ALU_D), 1, alumII);
        }
        if(strcmp(strlwr(a.carrera), "isi")==0)
        {
            fwrite(&aDiff, sizeof(ALU_D), 1, alumISI);
        }
    }
}
