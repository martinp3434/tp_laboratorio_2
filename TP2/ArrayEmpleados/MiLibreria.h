#ifndef MILIBRERIA_H_INCLUDED
#define MILIBRERIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif // MILIBRERIA_H_INCLUDED

/** \brief Valida un numero que esta entre dso numeros
 *
 * \param X Entero ingesado
 * \param min Numero minimo
 * \param max Numero maximo
 * \return Devuelve un cero o un uno
 */
int buscarVacio(Employee* list, int len);


/** \brief Pregunta si hay algun empleado ya registrado
 *
 * \param list* Employee puntero al array de empleados
 * \param len cantidad de estructuras
 * \return Devuelve un cero o un uno
 */
 int buscarEmpleadoIngresado(Employee* list, int len);


 /** \brief Ordena los vectores
 *
 * \param list* Employee puntero al array de empleados
 * \param len cantidad de estructuras
*/
 void ordenarEmpleados (Employee* list, int len);

 /** \brief Calcula el total y el promedio de salarios
 *
 * \param list* Employee puntero al array de empleados
 * \param len cantidad de estructuras
*/
 void salarios (Employee* list, int len);
