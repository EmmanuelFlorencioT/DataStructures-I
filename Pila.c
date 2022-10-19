#define TAM no.ElemMax

typedef struct
{
    /*Tipo de dato*/ pila[TAM];
    int tam;
    int tope;
} PILA;

/*INIPILA prepara el espacio para operar con la pila*/
int iniPila(PILA *p, int nm)
{
    int res=0;
    if(nm<=TAM)
    {
        p->tam=nm;
        p->tope=-1;
        res=1;
    }
    return(res);
}

/*PUSH inserta un elemento dentro de la pila*/
int push(PILA *p, int dato)
{
    int res=0;
    if(p->tope+1 < p->tam)
    {
        p->tope++;
        p->pila[p->tope]=dato;
        res=1;
    }
    return(res);
}

/*POP extrae un elemento de la pila y lo elimina*/
int pop(PILA *p, int *dato)
{
    int res=0;
    if(p->tope > -1)
    {
        *dato=p->pila[p->tope];
        p->tope--;
        res=1;
    }
    return(res);
}

/*PEEK es acceso al último elementos sin eliminarlo*/
int peek(PILA p, int *dato)
{
    int res=0;
    if(p.tope>-1)
    {
        *dato=p.pila[p.tope];
        res=1;
    }
    return(res);
}

/*Determinacion si una pila está vacía*/
int pilaVacia(PILA p)  //1 - vacia  y  0 - NO vacía
{
    int res=0;
    if(p.tope==-1)
        res=1;
    return(res);
}

/*Determinacion si una pila está llena*/
int pilaLlena(PILA p) //1 - Llena   y  0 - NO está llena
{
    int res=0;
    if(p.tope+1==p.tam)
        res=1;
    return(res);
}

/*----------------------------------------------------------------------------------*/

/*Captura los datos para una pila desde el Usuario*/
void capturaPila(PILA *p)
{
    int res, dato;
    char resp;
    do  {
        printf("Dame el dato: ");
        scanf("%d", &dato);
        res=push(p, dato);
        if(res==1)
        {
            fflush(stdin);
            printf("Dato Apilado, otro?(s/n) ");
            scanf("%c", &resp);
        }
        else
            printf("Dato no apilado\n");
        }while(res==1&&resp='s');
}

/*Separar una pila en 2 pilas: Una con valores postivos y otra con negativos*/
int separarPila(PILA *p, PILA *pPos, PILA *pNeg)
{
    int res, dato;
    /*
    res=iniPila(pPos, p->tope+1)//Como pPos esta pasada por referencia pPos=&*pPos
                                //Se toma el tamaño de la pila original con p->tope+1
    res=iniPila(pNeg, p->tope+1)
    Arriba se checa si las dos pilas se inicializaron con exito.
    */

    res=iniPila(pPos, p->tope+1)&&iniPila(pNeg, p->tope+1);
    if(res==1) //Se inicializaron ambas pilas con exito, usando un AND
        while(pop(p, &dato)==1)
            if(dato>=0)
                push(pPos, dato);
            else
                push(pNeg, dato);
    return(res);
}

/*Función para sumar los datos de una pila, usando la pila como acumulador*/
float sumaPila(PILA *p)
{
    int res;
    float cant1, cant2, suma=0;
    while(pop(p, &cant1)==1)
    {
        res=pop(p, &cant2);
        if(res==1) //Para la segunda cantidad
        {
            suma=cant1+cant2;
            push(p, suma);
        }
        else
            suma=cant1;
    }
    return(suma);
}
