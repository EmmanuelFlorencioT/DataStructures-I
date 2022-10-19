#include<stdio.h>

int pideCant();
int calculaDoble(int cant);  //Aqu� entrar� un valor momentaneamente a la variable ficticia 'cant'
int calculaTriple(int cant);
void muestraTodo(int doble, int triple);   //Aqu� entrar� un valor momentaneamente a la variable fictica 'doble' y 'triple'

int main()
{
    int cantidad, elDoble, elTriple;
    cantidad=pideCant();    //Va guardar ahora si en la variable real 'cantidad' el valor que tom� 'cant'
    elDoble=calculaDoble(cantidad);
    elTriple=calculaTriple(cantidad);
    muestraTodo(elDoble, elTriple);
}

/*Funci�n que pida la cantidad */
int pideCant()     //Aqu� no necesita par�mentros para efectuar la funci�n, solo lo hace.
{
    int cant;
    printf("Escribe la cantidad: ");
    scanf("%d", &cant);
    return(cant);  //Aqu� va regresar el valor que guard� momentaneamente en 'cant'
}

/*Funci�n que hace la operaci�n del doble*/
int calculaDoble(int cant)
{
    int doble;
    doble=2*cant;
    return(doble);
}

/*Funci�n que hace la operaci�n del triple*/
int calculaTriple(int cant)
{
    int triple;
    triple=3*cant;
    return(triple);
}

/*Func�on que imprime el resultado*/
void muestraTodo(int doble, int triple)
{
    printf("El doble es: %d\nEl triple es: %d\n", doble, triple);
}
