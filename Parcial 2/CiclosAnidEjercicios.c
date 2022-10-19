#include <stdio.h>

int pideN();
void checaIgualdad(int num);  //c^2=a^2+b^2

int main()
{
    int N;
    N=pideN();
    checaIgualdad(N);
}

int pideN()
{
    int n;
    printf("Dame un rango: ");
    scanf("%d", &n);
    return(n);
}

void checaIgualdad(int num)
{
    int c, a, b;
    for(c=1;c<=num;c++)
        for(a=1;a<=num; a++)
            for(b=1;b<=num;b++)
                if(c*c==a*a+b*b)
                    printf("%d, %d, %d\n", c, a, b);
}
