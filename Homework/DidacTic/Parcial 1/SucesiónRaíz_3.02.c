#include<stdio.h>
#include<math.h>


int pideN();
float sucesion(int n);

int main()
{
    int N;
    float final;
    N=pideN();
    final=sucesion(N);
    printf("%f", final);
}

int pideN()
{
    int n;
    printf("Num de términos que desea: ");
    scanf("%d", &n);
    return(n);
}


float sucesion(int n)
{
    float res;
    if(n==0)
        res=0;
    else
        if(n==1)
            res=sqrt(2);
        else
            res=sqrt(2+sucesion(n-1));
    return(res);
}

float suces(int N)
{
    int i;
    float ac=0;
    if(N==1)
        ac=sqrt(2);
    else
        for(i=0;i<N;i++)
            ac=sqrt(ac+2);
    return(ac);
}
