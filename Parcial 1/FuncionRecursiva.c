/*Funci�n recursiva para calcular la suma de los primeros 'n' n�meros naturales*/
int sumaNat(int n)
{
    int res;

    if(n==1)   //Caso base
        res=1;
    else        //Casos recursivos
    {
        res=n+sumaNat(n-1);
    }
     return (res);
}
