/*Se van a hacer con arreglos ya que de una manera t�cnica no se acostumbra
  a return(cadena). Y los arreglos como trabajan con param por referencia.*/

//Las cadenas son arreglos de caracteres, por lo tanto trabajan como arreglos.

//El parametro podr�a ser (char *nom, )             \
//El paramtero tambi�n puede ser (char nom[TAM])     > Todas son equivalentes
//El paramtero tambi�n puede ser (char nom[])       /

/*Funci�n que reciba los componentes del nombre y entregue una cadena con el
  nombre completo
*/
void nomComp(char nom[], char apPat[20], char *apMat, char *nomCompleto)
{
    strcpy(nomCompleto, nom);   //nomCompleto <-- nom
    strcat(nomCompleto, " ");
    strcat(nomCompleto, apPat);
    strcat(nomCompleto, " ");
    strcat(nomCompleto, apMat);
}


/*Funcion para mostrar una cadena letra por letra*/
void muestraLxL(char cad[])
{
    int i;
    for(i=0;i<strlen(cad);i++)
        printf("%c", cad[i]);
    //Hay que tener cuidado con el especificador, son caracteres(%c), no strings(%s).
}

void muestraLxL2(char cad[])
{
    int i;
    for(i=0;cad[i]!='\0';i++) //La compu se pregunta si el caracter es diferente al terminador de cadena '\0'
                              //Las posici�nes de una cadena comienzan desde el 0.
        printf("%c", cad[i]);
    //Hay que tener cuidado con el especificador, son caracteres(%c), no strings(%s).
}


/*Funci�n para mostra una frase palabra por palabra con salto de linea*/
void muestraPxP(char frase[])
{
    int i;
    for(i=0;i<strlen(frase);i++)  //Tour sobre la cadena
    {
        if(frase[i]==' ') //El espacio se puede representar por 32 por codigo ASCII
            printf("\n");
        else
            printf("%c", frase[i]);
    }
}


/*Funci�n que cambia las letras a por @, ejemplo: casa->c@s@*/
void cambia(char cad[])
{
    int i;
    for(i=0;i<strlen(cad);i++)  //Tour sobre la cadena
    {
        if(cad[i]=='a' || cad[i]=='A')
            cad[i]='@';  //@ -> 64 en ASCII
        else
            printf("%c", cad[i]);
    }
}

/*----------------2da. Parte-------------------*/
/*Funci�n para contar el el No. de "letras" que contiene una cadena*/
int cuentaLetras(char cad[])
{
    int contLet=0, i;
    for(i=0;i<strlen(cad);i++)  //cad[i]!='\0'  <--Es m�s eficiente para la compu
    {
        if(cad[i]>='A' && cad[i]<='Z' || cad[i]>='a' && cad[i]<='z')
            contLet++;
    /*Checa el c�digo ASCII de las letras y entonces ponemos nuestor l�mite
      para el rango de las may�sculas o en las min�suclas*/
    }
    return(contLet);
}

// Hay una funci�n   isalpha(cad[i]) -> �Es letra?   ctype.h

/*Funci�n para contar el n�mero de palabras en una frase*/
int cuentaPalabras(frase[])
{
    int contPal=1, i;
    for(i=0;i<strlen(frase),i++)
    {
        if(frase[i]==' ')
            contPal++;
    }
    return(contPal);
}

/*Funci�n para convertir una frase de may�suclas a min�sculas*/
void cambio_aMin(frase[])
{
    /*Los caracteres de A a Z van desde 65 a 90 y
      los caracteres de a a z van desde 97 a 122*/
    int i;
    for(i=0;i<strlen(frase);i++)
    {
        if(frase[i]>='A' || frase[i]<='Z')
            frase[i]+=32; //frase[i]=frase[i]+32;
    }
}

/*Funci�n para invertir una cadena  Hola --> aloH*/
void invCad(char cad[], char inv[])
{
    for(i=0;i<strlen(cad);i++)
    {
        inv[strleng(cad)-i-1]=cad[i]
    }
    inv[strlen(cad)]='\0';
    strcpy(cad, inv);
}

void invCad2(char cad[])
{
    int izq=0, der=strlen(cad)-1;
    char aux;
    while(izq<der)
    {
        aux=cad[izq];
        cad[izq]=cad[der];
        cad[der]=aux;
        izq++;
        der--;
    }
}

/*Generar una cadena con las consonantes de una frase   avion --> vn*/
void cadConso(char frase[], conso[])
{
    int i, pos=0;
    for(i=0;i<strlen(frase);i++)
    {
        if(frase[i]!='a' && frase[i]!='e' && . . . ) //Min�sculas y may�suclas
            conso[pos++]=frase[i];  //Usa primero el valor de pos y luego le suma +1
    }
    conso[pos]='\0';
}
