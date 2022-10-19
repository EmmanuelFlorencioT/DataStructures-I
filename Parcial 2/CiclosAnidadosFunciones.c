#include<stdio.h>

void capturaNM(int *n, int *m);
void ciclosAnid(int nCe, int nCi);

int main()
{
    int N, M;
    capturaNM(&N, &M);
    ciclosAnid(N, M);
}

void capturaNM(int *n, int *m)
{
    printf("Veces del ciclo externo: ");
    scanf("%d", &*n);
    printf("Veces del ciclo interno: ");
    scanf("%d", m);   //Ya que * y & son operadores contrarios y se pueden omitir.
}

void ciclosAnid(int nCe, int nCi)
{
    int i, j;
    for(i=1;i<=nCe;i++)
        for(j=1;j<=nCi;j++)
            printf("Hola CE:%d - CI:%d\n", i, j);
}
