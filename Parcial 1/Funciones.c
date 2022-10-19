#include<stdio.h>

int pideCant();
int calculaDoble(int cant);  //Aquí entrará un valor momentaneamente a la variable ficticia 'cant'
void muestraTodo(int doble);   //Aquí entrará un valor momentaneamente a la variable fictica 'doble' y 'triple'

int main()
{
    int cantidad, elDoble;
    cantidad=pideCant();    //Va guardar ahora si en la variable real 'cantidad' el valor que tomó 'cant'
    elDoble=calculaDoble(cantidad);
    muestraDoble(elDoble);
}

/*Función que pida la cantidad */
int pideCant()     //Aquí no necesita parámentros para efectuar la función, solo lo hace.
{
    int cant;
    printf("Escribe la cantidad: ");
    scanf("%d", &cant);
    return(cant);  //Aquí va regresar el valor que guardó momentaneamente en 'cant'
}

/*Función que hace la operación*/
int calculaDoble(int cant)
{
    int doble;
    doble=2*cant;
    return(doble);
}

/*Funcíon que imprime el resultado*/
void muestraDoble(int doble)
{
    printf("El doble es: %d\n", doble);
}
