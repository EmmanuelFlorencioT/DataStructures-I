#include<stdio.h>
#include<time.h>

void muestraMsj();

int main()
{
    time_t tPrev, tPost;
    int lapse;
    tPrev=clock();
    muestraMsj();
    tPost=clock();
    lapse=tPost-tPrev;
    printf("Me tard\x82 %d miliseg", lapse);
}

void muestraMsj()
{
    int i;
    for(i=0;i<10000;i++)
        printf("HolaMundo\n");
}
