typedef struct
{
    char nom[30];
    float calif1;
    float calif2;
    float calif3;
} ALU_F;

typedef struct
{
    char nom[30];
    float prom;
    char status[9];
} ALU_D;

void promAlumno(FILE *alumFte, FILE *alumDest)
{
    ALU_F aluF;
    ALU_D aluD;
    while(fread(&aluF, sizeof(ALU_F), 1, alumFte)>0)
    {
        strcpy(aluD.nom, aluF.nom);
        aluD.prom=(aluF.calif1+aluF.calif2+aluF.calif3)/3;
        if(aluD.prom>=6)
            aluD.status='Aprobado';
        else
            aluD.status='Reprobado';
        fwrite(&aluD, sizeof(ALU_D), 1, alumDest);
    }
}
