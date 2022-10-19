typedef struct
{
    char nom[30];
    float calif1;
    float calif2;
    float calif3;
} ALU_F;

void promsAlumSepara(FILE *aluFte, FILE *aluAp, FILE *aluRep)
{
    ALU_F alu;
    char nombre[30];
    float prom;

    while(fread(&alu, sizeof(ALU_F), 1, aluFte)>0)
    {
        strcpy(nombre, alu.nom);
        prom=(alu.calif1+alu.calif2+alu.calif3)/3;
        if(prom>=6)
            fprintf(aluAp, "%s %.2f ", nombre, prom);
        else
            fprintf(aluRep, "%s %.2f ", nombre, prom);
    }
}
