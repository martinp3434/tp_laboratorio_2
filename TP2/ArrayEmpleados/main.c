#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "MiLibreria.h"

int main()
{
 char seguir = 's';
 char confirmacion;
 char opcion;
 int flag = 0;
 int hayEmpleados = 0;
 Employee lista[TAM];
 int id = 1000;

 initEmployees( lista, TAM);

    while(seguir == 's' )
        {
            printf(" 1.Alta\n 2.Modifica\n 3.Baja\n 4.Informar\n 5.Salir\n\n");
            printf("Seleccione una opcion: \n");
            scanf("%c", &opcion);

            if(opcion != 49)
            {
                hayEmpleados = buscarEmpleadoIngresado(lista, TAM);

                if(hayEmpleados == 0)
                {
                    while(opcion != 49)
                    {
                        system("cls");
                        printf("No hay empleados ingresados, primero debe ingresar al menos uno\n\n");
                        printf("Ingrese la opcion 1.Alta: ");
                        scanf("%c", &opcion);
                    }
                }

            }

            while(opcion < 49 || opcion > 53)
            {
                system("cls");
                printf("Opcion invalida \n\n");
                printf(" 1.Alta\n 2.Modifica\n 3.Baja\n 4.Informar\n 5.Salir\n\n");
                printf("Seleccione una opcion valida: \n");
                scanf("%c", &opcion);

            }

            switch(opcion)
            {
                case '1':
                    {
                        system("cls");

                            int sector;
                            float salario;
                            char nombre[51];
                            char apellido[51];
                            int respuestaAlta;

                            printf("*******Alta Empleado*******\n\n");

                            printf("Ingrse el nombre: ");
                            fflush(stdin);
                            gets(nombre);
                            system("cls");

                            printf("Ingrse el apellido: ");
                            fflush(stdin);
                            gets(apellido);
                            system("cls");

                            printf("Ingrese sector: ");
                            scanf("%d", &sector);
                            system("cls");

                            printf("Ingrese salario: ");
                            scanf("%f", &salario);
                            system("cls");

                            respuestaAlta = addEmployee (lista, TAM, id, nombre, apellido , salario, sector);

                            while(respuestaAlta == 0)
                            {
                                printf("No es posible registrar al empleado, intente otra vez\n\n");
                            }

                            printf("El empleado se ha registrado correctamente\n\n");
                            id = id+1;

                        }

                    break;

                case '2':
                    system("cls");

                    printf("*******Modificar empleado*******\n\n");

                    int idModificar;
                    int rtaModificar;
                    char menuModificar;
                    char nombreDos [51];
                    char apellidoDos [51];
                    int sectorDos;
                    int salarioDos;

                    printf("Ingrese el Id del empleado que desea modificar: \n\n");
                    scanf("%d", &idModificar);
                    system("cls");

                    rtaModificar = findEmployeeById(lista, TAM, idModificar);

                    if(rtaModificar == -1)
                    {
                        printf("No se encontro el empleado\n\n");
                    }
                    else
                    {
                        printf("Se enconto al empleado\n\n");
                        printf(" A. Nombre\n B. Apellido\n C. Salario\n D. Sector\n\n");
                        printf("Ingrese la opcion que desea modificar: ");
                        fflush(stdin);
                        scanf("%c", &menuModificar);

                        while(menuModificar != 'a' && menuModificar != 'A' && menuModificar != 'b' && menuModificar != 'B' && menuModificar != 'c' && menuModificar != 'C' && menuModificar != 'd' && menuModificar != 'D')
                        {
                            system("cls");
                            printf(" A. Nombre\n B. Apellido\n C. Salario\n D. Sector\n\n");
                            printf("Ingrese una opcion valida: ");
                            fflush(stdin);
                            scanf("%c", &menuModificar);
                        }

                        switch(menuModificar)
                        {
                            case 'a':
                            case 'A':
                                system("cls");
                                printf("Reingrese el nombre: ");
                                fflush(stdin);
                                gets(nombreDos);
                                strcpy(lista[rtaModificar].name, nombreDos);
                                system("cls");
                                printf("El nombre fue modificado\n\n");
                                break;

                            case 'b':
                            case 'B':
                                system("cls");
                                printf("Reingrese el apellido: ");
                                fflush(stdin);
                                gets(apellidoDos);
                                strcpy(lista[rtaModificar].lastName, apellidoDos);
                                system("cls");
                                printf("El apellido fue modificado\n\n");
                                break;

                            case 'c':
                            case 'C':
                                system("cls");
                                printf("Reingrese el salario: ");
                                scanf("%d", &salarioDos);
                                lista[rtaModificar].salary = salarioDos;
                                system("cls");
                                printf("El salario fue modificado\n\n");
                                break;

                            case 'd':
                            case 'D':
                                system("cls");
                                printf("Reingrese el sector: ");
                                scanf("%d", &sectorDos);
                                lista[rtaModificar].sector = sectorDos;
                                system("cls");
                                printf("El sector fue modificado\n\n");
                                break;
                        }
                    }
                    break;

                case '3':
                    system("cls");
                    printf("*******Baja empleado*******\n\n");
                    int idBaja;
                    int rtaBaja;

                    printf("Ingrese el Id del empleado que desea dar de baja: \n\n");
                    scanf("%d", &idBaja);

                    rtaBaja = removeEmployee( lista, TAM, idBaja);

                    if(rtaBaja==0)
                    {
                        system("cls");
                        printf("Id erroneo\n\n");
                    }
                    else
                    {
                        system("cls");
                        printf("Se ha removido al empleado con exito\n\n");
                    }

                    break;

                case '4':
                    system("cls");
                    printf("*******Informes*******\n\n");

                    char menuInformes;

                    printf(" A.Listar empleados por apellido y sector\n B.Salarios y promedios\n\n");
                    printf("Ingrese una opcion: \n\n");
                    fflush(stdin);
                    scanf("%c", &menuInformes);

                    while(menuInformes != 'a' && menuInformes != 'b' && menuInformes != 'A' && menuInformes != 'B')
                    {
                        printf(" A.Listar empleados por apellido y sector\n B.No seleccionar(version gamma)\n\n");
                        printf("Ingrese una opcion valida: \n\n");
                        fflush(stdin);
                        scanf("%c", &menuInformes);
                    }
                    switch(menuInformes)
                              {
                                case 'A':
                                case 'a':
                                    system("cls");
                                    printf("*******Informes*******\n\n");
                                    ordenarEmpleados (lista, TAM);
                                    break;

                                case 'B':
                                case 'b':
                                    system("cls");
                                    printf("*******Informes*******\n\n");
                                    salarios (lista, TAM);
                                    break;
                              }
                    break;

                case '5':
                    system("cls");
                    printf("Confirme con 's' si siquiere salir del pograma:\n ");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    if (confirmacion == 's')
                    {
                        system("cls");
                        printf("\n******Fin del programa********\n\n");
                        flag = 1;
                        break;

                    }
            }
            if(flag == 0)
            {
                printf("Para continuar ingrese 's': ");
                fflush(stdin);
                scanf("%c", &seguir);
                system("cls");
            }
            else
            {
                seguir = 'f';
            }
     }
 return 0;
}

int initEmployees(Employee* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }

    return 0;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int indice = buscarVacio(list, len);
    int flagAlta = 0;

    if(indice == -1)
    {
        flagAlta = 0;
        return flagAlta;
    }
    else
    {
        list[indice].id = id;
        strcpy(list[indice].name, name);
        strcpy(list[indice].lastName, lastName);
        list[indice].salary = salary;
        list[indice].sector = sector;
        list[indice].isEmpty = 0;

        flagAlta = 1;
        return  flagAlta;
    }

}

int buscarVacio(Employee* list, int len)
{
    int indice = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            return i;
            break;
        }
    }

    return indice;
}
int printEmployees(Employee* list, int length)
{
    int flagMostrar = 0;
    printf("Apellido      Nombre       ID       Sector       Salario\n\n\n");

    for(int i=0; i<length; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("%s       %s       %d        %d           %.2f\n\n", list[i].lastName, list[i].name, list[i].id, list[i].sector, list[i].salary);
            flagMostrar = 1;
        }
    }
    if(flagMostrar == 0)
    {
        system("cls");
        printf("No hay empleados registrados\n\n");
    }

    return 0;
}
int removeEmployee(Employee* list, int len, int id)
{
    int flagBaja = 0;
    int flagID = 0;

    for( int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            list[i].isEmpty = 1;
            flagBaja = 1;
        }
    }
    if(flagBaja==0)
    {
        flagID = 0;
        return flagID;
    }
    else
    {
        flagID = 1;
        return flagID;
    }
}
int findEmployeeById(Employee* list, int len,int id)
{
    int indice = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            return indice;
            break;
        }
    }
    return indice;
}

int buscarEmpleadoIngresado(Employee* list, int len)
{
    int primerEmpleado = 0;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            primerEmpleado = 1;
            return primerEmpleado;
            break;
        }
    }

    return primerEmpleado;
}

void ordenarEmpleados (Employee* list, int len)
{
    Employee auxiliar;

    int comparacion;

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            comparacion = strcmp(list[i].lastName, list[j].lastName);

            if(comparacion == 0)
            {
                if(list[i].sector > list[j].sector)
                {
                    auxiliar = list[i];
                    list[i]= list[j];
                    list[j] = auxiliar;
                }
            }
            if(comparacion == 1)
            {
                auxiliar = list[i];
                list[i]= list[j];
                list[j] = auxiliar;
            }
        }
    }

    printEmployees(list, len);
}

void salarios (Employee* list, int len)
{
    int total = 0;
    int contador = 0;
    float promedio = 0;
    int contadorPromedio = 0;

    for(int i=0; i<len; i++)
    {
        total = total + list[i].salary;
        if(total != 0)
        {
            contador = contador + 1;
        }
    }

    promedio = total / contador;

    for(int x=0; x<len; x++)
    {
        if(promedio < list[x].salary)
        {
            contadorPromedio = contadorPromedio + 1;
        }
    }

    printf("Total de los salarios: %d\n", total);
    printf("El promedio de los salarios es: %.2f\n", promedio);
    printf("La cantidad de empleados que superan el promedio es: %d\n\n", contadorPromedio);
}

