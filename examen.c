#include <stdio.h>
#include <string.h>

#define  N 2


struct Empleados
{
    int clave;
    char nombres[20];
    float estatura;
    float sueldo;
};

typedef struct Empleados Empleados;


void pedirDatos(struct Empleados Empleado[N]);
int empleadoMasAlto(struct Empleados Empleado[N]);
void SueldoMenor(struct Empleados Empleados [N]);
void imprimir(struct Empleados Empleados [N]);


int main()
{
    struct Empleados Empleado[N];
   
    
    int posicion;

    pedirDatos(Empleado);
    posicion=empleadoMasAlto(Empleado);
    SueldoMenor(Empleado);
    imprimir( Empleado);


    fflush(stdin);
    getchar();
    return 0;
}

void SueldoMenor(struct Empleados Empleados[N])
{
    int i,j;
    float aux;
    int auxi;
    char auxN[20];

    for(i=0; i<N-1; i ++)
    {  
      for(j=0; j<N-1;j++)
       {
           if (Empleados[j].sueldo <Empleados[j+1].sueldo)
           {
               aux=Empleados[j].sueldo;
               Empleados[j].sueldo=Empleados[j+1].sueldo;
               Empleados[j+1].sueldo=aux;

               aux=Empleados[j].estatura;
               Empleados[j].estatura=Empleados[j+1].estatura;
               Empleados[j+1].estatura=aux;

               auxi=Empleados[j].clave;
               Empleados[j].clave=Empleados[j+1].clave;
               Empleados[j+1].clave=auxi;

               strcpy(auxN,Empleados[j].nombres);
               strcpy(Empleados[j].nombres,Empleados[j+1].nombres);
               strcpy(Empleados[j+1].nombres,auxN);
           }   
       }
    }
}

void pedirDatos(struct Empleados em[N])
{
    int i;
    for (i=0; i<N; i++ )
    {
        printf("dame la clave[%d]", i);
        scanf("%d", & em[i].clave);

        printf("dame el nombre del empleado[%d]", i);
        scanf("%s",  em[i].nombres);

        printf("dame la estatura[%d]", i);
        scanf("%f", & em[i].estatura);

        printf("dame el sueldo[%d]", i);
        scanf("%f", & em[i].sueldo);


    }

}

 void imprimir(struct Empleados Empleados[N])
 {
    int i;
    printf("clave    nombre    estatura   sueldo\n");
    for (i=0; i<N ; i++ )
    {
        printf("%d\t",Empleados[i].clave);
        printf("%s\t",Empleados[i].nombres);
        printf("%f\t",Empleados[i].estatura);
        printf("%f\n",Empleados[i].sueldo);
    }
 }


int empleadoMasAlto(struct Empleados Empleado[N])
{
    int i;
    float mayor=Empleado[0].estatura;
    int posicion=0;
    for (i=0; i<N ; i++ )
    { 
        if(Empleado[i].estatura>mayor)
        {
            mayor=Empleado[i].estatura;
            posicion=i;
        }
    }
    return posicion;
}