void comprime(char num[])
{
    int i, j;
    for(i=0;i<strlen(frase);i++)
        if(frase[i]==' ')
            for(j=i;frase[j]!='\0';j++)
                frase[j]=frase[j+1];
}
