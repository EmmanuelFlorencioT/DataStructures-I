#define TAM no.ElemMax

typedef struct
{
    /*Tipo de dato*/ queue[TAM];
    int frente, final;
    int tam;
} QUEUE;

/*Inicialización*/
int iniQueue(QUEUE *q, int nm)
{
    int res=0;
    if(nm<=TAM)
    {
        q->tam=nm;
        q->frente=q->final=-1;
        res=1;
    }
    return(res);
}

/*enQueue es para insertar un dato a la cola*/
int enQueue(QUEUE *q, int dato)
{
    int res=0;
    if(q->final+1 < q->tam) //NO está llena
    {
        q->final++;
        q->queue[q->final]=dato;
        if(q->frente < 0)
            q->frente=0;
        res=1;
    }
    return(res);
}

/*deQueue accesa al dato del frente y luego remueve dicho dato*/
int deQueue(QUEUE *q, int *dato)
{
    int res=0;
    if(q->frente > -1)  //Tiene datos?
    {
        *dato=q->queue[q->frente];
        if(q->frente==q->final)
            q->frente=q->final=-1; //Regresamos el estado: vacío
        else
            q->frente++;
        res=1;
    }
    return(res);
}



/*------------------------------------------------------------------------------*/

/*Funcion para moestrar los datos de una fila y los elimina*/
void muestraQueue(QUEUE *q)
{
    int dato;
    while(deQueue(q, &dato)==1)
        printf("%d\t", dato);
}

/*Funcion para moestrar los datos de una fila y los CONSERVA*/
void muestraQueueTruc(QUEUE q)
{
    int dato;
    while(deQueue(&q, &dato)==1)
        printf("%d\t", dato);
}

/*Función para sumar los datos de una fila*/
int sumaQueue(QUEUE *q)
{
    int dato, suma=0;
    while(deQueue(q, &dato)==1)
        suma+=dato;
    return(suma);
}

/*Función para contar Pares e Impares en una fila*/
void cParImpQueue(QUEUE *q, int *cPar, int cImp*)
{
    int dato;
    *cPar=*cImp=0;
    while(deQueue(q, &dato)==1)
        if(dato%2==0)
            (*cPar)++;
        else
            (*cImp)++;  //También se puede *cImp+=1;
}

/*Simular una fila de tal manera que con valores al azar
se agreguen o quiten elementos a la misma (0-Poner, 1-Quitar, 2-Salir)*/
void queueAzar(QUEUE *q)
{
    int dato, res, op;
    srand(time(NULL));
    do {
        op=rand()%3;  //0, 1, 2
        switch(op)
        {
            case 0:
                printf("Dato: ");
                scanf("%d", &dato);
                res=enQueue(q, dato);
                if(res==1)
                    printf("Cliente formado\n");
                else
                    printf("No podemos atenderle\n");
                break;

            case 1:
                res=deQueue(q, &dato);
                if(res==1)
                    printf("Atendiendo a: %d\n", dato);
                else
                    printf("No hay clientes\n");
                break;

            case 2:
                printf("La tienda está cerrando\n");
                break;
        }
       } while(op!=2);
}

/*Función para vaciar los datos de una pila y formarlos en una fila*/
int pilaToQueue(PILA *p, QUEUE *q)
{
    int res, dato;
    res=iniQueue(q, p->tope+1) //La fila queda justa
  /*res=iniQueue(q, p->tam)  La fila queda más holgada*/
    if(res==1)
        while(pop(p, &dato)==1)
            enQueue(q, dato);
    return(res);
}
