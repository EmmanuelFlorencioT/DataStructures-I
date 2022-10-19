#define TAM no.ElemMax

typedef struct
{
    "TipoDato" set[TAM];
    int tam;
    int num;
} SET;

/*INICIALIZACIÓN*/
int iniSet(SET *s, int nm)
{
    int res=0;
    if(nm<=TAM)
    {
        s->tam=nm;
        s->num=0;
        res=0;
    }
}

/*INSERTAR un dato al set*/
int insert(SET *s, int dato)
{
    int res=0, cont;
    if(s->num < s->tam)
    {
        cont=0;
        while(cont < s->num && dato!=s->set[cont])
            cont++;
        if(cont==s->num) //No encontró coincidencias
        {
            s->set[s->num]=dato; //Va desfasado por 1
            s->num++;
            res=1;
        }
    }
    return(res);
}

/*REMOVER un dato del set*/
int remove(SET *s, int dato)
{
    int res=0, cont;
    cont=0;
    while(cont < s->num && dato!=s->set[cont])
        cont++;
    if(cont < s->num) //Logró encontrar el dato
    {
        s->set[cont]=s->set[s->num-1]; //Recorremos el elem. final al lugar a "vaciar"
        s->num--;
        res=1;
    }
    return(res);
}

/*BUSCAR un dato dentro del set*/
int contains(SET s, int dato)
{
    int res=0, cont;
    cont=0;
    while(cont < s->num && dato!=s->set[cont])
        cont++;

    if(cont < s->num)
        res=1;

    return(res);
}

/*--------------------------------------------------------*/

/*Regresa la UNION entre dos sets*/
int unionSet(SET s1, SET s2, SET *sUn)
{
    int res, cont;
    res=(sUn, s1.num+s2.num);
    if(res==1)
    {
        for(cont=0;cont<s1.num;cont++)
            insert(sUn, s1.set[cont]);
        for(cont=0;cont<s2.num;cont++)
            insert(sUn, s2.set[cont]);
    }
    return(res);
}

/*Regresa la INTERSECCIÓN entre dos sets*/
int intersSet(SET s1, SET s2, SET *s3)
{
    int res, cont;
    res=iniSet(s3, s1.num<s2.num? s1.num:s2.num);
    if(res==1)
    {
        for(cont=0;cont<s1.num; cont++)
            if( contains(s2, s1.set[cont])==1)
                insert(s3, s1.set[cont]);
    }
    return(res);
}

/*Regresa un set con la DIFERENCIA entre dos sets*/
int diffSet(SET s1, SET s2, SET *s3)
{
    int res, cont;
    res=iniSet(s3, s1.num);
    if(res==1)
    {
        for(cont=0;cont<s1.num; cont++)
            if( contains(s2, s1.set[cont])==0)
                insert(s3, s1.set[cont]);
    }
    return(res);
}

/*Determina si un set es subset de otro*/
int isSubSet(SET subSet, SET s)
{
    int cont, det=0;
    if(subSet.num<=s.num)
    {
        det=1;
        for(cont=0;cont<subSet.num && det==1; cont++)
            det=contains(s, subSet.set[cont]);
        //det, es decir, el determinante saldrá del ciclo con valor de 1
        //solamente si el set 's', contuvo a todos los elementos de 'subSet'
    }
    return(band);
}
