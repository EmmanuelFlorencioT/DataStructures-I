#include <stdio.h>

int fibonacci(int n);

int main()
{
    int N, resp;
    printf("Termino: ");
    scanf("%d", &N);
    resp=fibonacci(N);
    printf("%d", resp);
}

int fibonacci(int n)
{
    int term, aux;
    if(n==1)
        term=1;
    else
        if(n==2)
            term=1;
        else
            term=fibonacci(n-1)+fibonacci(n-2);
    return(term);
}
