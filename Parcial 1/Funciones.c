#include<stdio.h>

int pideCant();
int calculaDoble(int cant);  //Aqu� entrar� un valor momentaneamente a la variable ficticia 'cant'
void muestraTodo(int doble);   //Aqu� entrar� un valor momentaneamente a la variable fictica 'doble' y 'triple'

int main()
{
    int cantidad, elDoble;
    cantidad=pideCant();    //Va guardar ahora si en la variable real 'cantidad' el valor que tom� 'cant'
    elDoble=calculaDoble(cantidad);
    muestraDoble(elDoble);
}

/*Funci�n que pida la cantidad */
int pideCant()     //Aqu� no necesita par�mentros para efectuar la funci�n, solo lo hace.
{
    int cant;
    printf("Escribe la cantidad: ");
    scanf("%d", &cant);
    return(cant);  //Aqu� va regresar el valor que guard� momentaneamente en 'cant'
}

/*Funci�n que hace la operaci�n*/
int calculaDoble(int cant)
{
    int doble;
    doble=2*cant;
    return(doble);
}

/*Func�on que imprime el resultado*/
void muestraDoble(int doble)
{
    printf("El doble es: %d\n", doble);
}
