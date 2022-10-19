#include<stdio.h>
#include<math.h>

int pideN();
void sucesion(int n, float *res);

int main()
{
    int N;
    float suc;
    N=pideN();
    sucesion(N, &suc);
    printf("Sucesion: %f", suc);
}

int pideN()
{
    int n;
    printf("Num de términos que desea: ");
    scanf("%d", &n);
    return(n);
}

void sucesion(int n, float *res)
{
    int i, cont=1;
    float temp=1;
    if(n!=0)
    {
        for(i=1;i<n;i++)
        {
            cont+=2;
            temp=temp+pow(-1,i)*1/(cont);
        }
        *res=4*temp;
    }
    else
        *res=0;

}
