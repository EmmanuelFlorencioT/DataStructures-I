typedef struct
{
    char nom[30];
    float calif1;
    float calif2;
    float calif3;
} ALU_F;

void promAlumnoTxt(FILE *aluFte, FILE *aluDest)
{
    ALU_F alu;
    char nombre[30];
    char status[9];
    float prom;

    while(fread(&alu, sizeof(ALU_F), 1, aluFte)>0)
    {
        strcpy(nombre, alu.nom);
        prom=(alu.calif1+alu.calif2+alu.calif3)/3;
        if(prom>=6)
            strcpy(status, "Aprobado");
        else
            strcpy(status, "Reprobado");
        fprintf(aluDest, "%s %.2f %s", nombre, prom, status);
    }
}
