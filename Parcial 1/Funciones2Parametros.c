#include<stdio.h>

int pideCant();
int calculaDoble(int cant);  //Aquí entrará un valor momentaneamente a la variable ficticia 'cant'
int calculaTriple(int cant);
void muestraTodo(int doble, int triple);   //Aquí entrará un valor momentaneamente a la variable fictica 'doble' y 'triple'

int main()
{
    int cantidad, elDoble, elTriple;
    cantidad=pideCant();    //Va guardar ahora si en la variable real 'cantidad' el valor que tomó 'cant'
    elDoble=calculaDoble(cantidad);
    elTriple=calculaTriple(cantidad);
    muestraTodo(elDoble, elTriple);
}

/*Función que pida la cantidad */
int pideCant()     //Aquí no necesita parámentros para efectuar la función, solo lo hace.
{
    int cant;
    printf("Escribe la cantidad: ");
    scanf("%d", &cant);
    return(cant);  //Aquí va regresar el valor que guardó momentaneamente en 'cant'
}

/*Función que hace la operación del doble*/
int calculaDoble(int cant)
{
    int doble;
    doble=2*cant;
    return(doble);
}

/*Función que hace la operación del triple*/
int calculaTriple(int cant)
{
    int triple;
    triple=3*cant;
    return(triple);
}

/*Funcíon que imprime el resultado*/
void muestraTodo(int doble, int triple)
{
    printf("El doble es: %d\nEl triple es: %d\n", doble, triple);
}
