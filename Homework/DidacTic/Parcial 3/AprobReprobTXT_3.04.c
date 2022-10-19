typedef struct
{
    char nom[30];
    char stat[9];
} ALU;

void cuentaApRep(FILE *alu, int *ap, int *rep)
{
    char nombre[30];
    char status[9];
    *ap=*rep=0;

    while(fgets(nombre, 30, alu)>0)
    {
        fgets(status, 9, alu); //Asuminedo que no hay problema con la leída
        if(strcmp(tolower(status), "aprobado")==0)
            (*ap)++;
        else
            (*rep)++;
    }
}
