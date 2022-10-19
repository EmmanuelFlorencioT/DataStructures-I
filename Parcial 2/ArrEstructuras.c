#include<stdio.h>
#include<string.h>


void capturaPers(PER arrPer[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("No.%d\n");
        printf("Nombre: ");
        gets(arrPer[i].nom);
        printf("Edad: ");
        scanf("%d", &arrPer[i].edad);
        printf("Estatura: ");
        scanf("%f", &arrPer[i].estatura);
    }
}

void muestraPers(PER arrPer[], int n)
{
    int i;
    printf("No.\tNombre\t\tEdad\tEstatura\n");
    for(i=0;i<n;i++)
        printf("No.%d\t%s\t\t%d\t%.2f\n", i, arrPer[i].nom, arrPer[i].edad, arrPer[i].estatura);
}

//Función para calcular el promedio de estatura
float promEst(PER arrPer[], int n)
{
    int i;
    float ac=0, prom;
    for(i=0;i<n;i++)
        ac+=arrPer[i].estatura;
    prom=ac/n;
    return(prom);
}

//Funcion para contar el numero de mayores y menores de edad
void cuentaMayMen(PER arrPer[], int n, int *cMay, int *cMen)
{
    int i;
    *cMay=*cMen=0;
    for(i=0;i<n;i++)
        if(arrPer[i].edad<18)
            (*cMen)++;  //Hay que poner los parentesis para que el cambio se haga
                        //sobre el parametro por referencia y el cambio sea permanente.
        else
            (*cMay)++;  // *cMay+=1; o *cMay=*cMay+1;
}

//Encontrar (y entregar) la persona (su nombre) con mayor estatura.
void encuentraMasAlto(PER arrPer[], int n, char nomMayor[])
{
    int i;
    float sMay;
    sMay=arrPer[0].estatura;
    strcpy(nomMayor, arrPer[0].nom);
    for(i=1;i<n;i++)
        if(arrPer[i].estatura>sMay)
        {
            sMayor=arrPer[i].estatura;
            strcpy(nomMayor, arrPer[i].nom);
        }
}

//Funcion que cuente el numero de gente por rangos de edad (bloques de 10 años)
// 0-9 arrCont[0], 10-19 arrCont[1], ... , 90... arrCont[9]
void rangoEdad(PER arrPer[], int n, int arrCont[])
{
    int i;
    for(i=0;i<10;i++)
        arrCont[i]=0;
    for(i=0;i<n;i++)
        if(arrPer[i].edad<10)
            arrCont[0]++;
        else
            if(arrPer[i].edad<20)
                arrCont[1]++;
            else
                if(arrPer[i].edad<30)
                    arrCont[2]++;
                else
                    if(arrPer[i].edad<40)
                        arrCont[3]++;
                    else
                        if(arrPer[i].edad<50)
                            arrCont[4]++;
                        else
                            if(arrPer[i].edad<60)
                                arrCont[5]++;
                            else
                                if(arrPer[i].edad<70)
                                    arrCont[6]++;
                                else
                                    if(arrPer[i].edad<80)
                                        arrCont[7]++;
                                    else
                                        if(arrPer[i].edad<90)
                                            arrCont[8]++;
                                        else
                                            arrCont[9]++;
}

void rangoEdadOpt(PER arrPer[], int n, int arrCont[])
{
    int i;
    for(i=0;i<10;i++)
        arrCont[i]=0;
    for(i=0;i<n;i++)
        if(arrPer[i].edad<90)
            arrCont[arrPer[i].edad/10]++;
        else
            arrCont[9]++;
}

//Funcion para ordenar un arreglo de n personas.
//Nota: La funcion debe recibir el campo con respecto al cual se
//hará la ordenación (1,2,...).   1=nombre. 2=edad.  3=estatura.
void ordenaPers(PER arrPer[], int n, int op)
{
    int i;
    switch(op)
        case 1: //Nombre
            if(strcmp())
                swap(); //Sobre las estrcuturas
            break;

        case 2: //Edad
            if()
                swap(); //Sobre las estrcturas
            break;

        case 3: //Estatura
            if()
                swap(); //Sobre las estrcturas
            break;
}
