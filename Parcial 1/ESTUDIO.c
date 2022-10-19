#include<stdio.h>
#include<math.h>
#define pi 3.141592654

int pideCant();
float beta(float a, float b, float c);
float conv_aDecimal(float anguloRad);
void imprime(float cant);

int main()
{
    float angRad, A, B, C, final;
    A=pideCant();
    B=pideCant();
    C=pideCant();
    angRad=beta(A,B,C);
    final=conv_aDecimal(angRad);
    imprime(final);
}

int pideCant()     //Aquí no necesita parámentros para efectuar la función, solo lo hace.
{
    int cant;
    printf("Escribe la cantidad: ");
    scanf("%f", &cant);
    return(cant);  //Aquí va regresar el valor que guardó momentaneamente en 'cant'
}

float beta(float a, float b, float c)
{
    int res;
    res=acos((a*a+c*c-b*b)/2*a*c);
    return (res);
}

float conv_aDecimal(float anguloRad)
{
    float dec;
    dec=(anguloRad*180)/pi;
    return(dec);
}

void imprime(float cant)
{
    printf("El resultado es %f grados", cant);
}



/*
void soloDesc(int prod[SZ], int desc[SZ], int solo[cont])
{
    int i, cont=0;
    for(i=0;i<SZ;i++)
        if(desc[i]!=0)
        {
            cont++;
            solo[i]=prod[i]*desc[i];
        }
}

void arreglo(char dig[], char cad[])
{
    int i;
    char aux;
    for(i=0;i<10;i++)
        if(dig[i]>='A'&&dig[i]<='Z' || dig[i]>='a'&&dig[i]<='z')
        {
            aux=dig[i];
            dig[i]=cad[i];
            cad[i]=aux;
        }
}
*/
