#include<stdio.h>

/*
int main()
{
    float C1, C2;
    printf("Dame la primera cantidad: ");
    scanf("%f", &C1);
    printf("Dame la segunda cantidad: ");
    scanf("%f", &C2);
    if(C1>C2)
        printf("La cantidad mayor fue la primera.\n");
    else
        printf("La cantidad mayor fue la segunda.\n");
}
*/

int main()
{
    int Select;
    float a, b, res;
    printf("Dame la primera cantidad: ");
    scanf("%f", &a);
    printf("Dame la segunda cantidad: ");
    scanf("%f", &b);

    printf("Seleccione 1 para sumar\n");
    printf("Seleccione 2 para restar\n");
    printf("Seleccione 3 para multiplicar\n");
    printf("Seleccione 4 para dividir\n");
    printf("\nOpci\xa2n: ");
    scanf("%d", &Select);

    if(Select<1 || Select>4)
        printf("Opci\xa2n inv\xa0lida\n");
    else
    {
        switch(Select)
        {
        case 1:
            res=a+b;
            break;
        case 2:
            res=a-b;
            break;
        case 3:
            res=a*b;
            break;
        case 4:
            res=a/b;
            break;
        default:
            break;
        }
        printf("\nEl resultado de la operaci\xa2n fue: %.3f\n", res);
    }

}
