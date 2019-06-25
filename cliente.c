#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "utn.h"
#include "LinkedList.h"

/** \brief Reserva espacio en memoria para un cliente
 * \param void vacio
 * \return Cliente* un puntero al espacio reservado para cargar un cliente
 */
Cliente* cliente_new(void)
{
    return (Cliente*) malloc(sizeof(Cliente));
}

/** \brief Valida los elementos que contiene un empleado y los carga en una variable Cliente
 *
 * \param idStr char* id del cliente.
 * \param nombreStr char* nombre  del cliente.
 * \param apellidoStr char* apellido del cliente.
 * \param dniStr char* dni del cliente.
 * \return Cliente* pAuxCliente, devuelve - NULL si puntero a idStr/nombreStr/apellidoStr/dniStr NULL,
 *                               devuelve - puntero al cliente si valido sus elementos. *
 */
Cliente* cliente_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* dniStr)
{
    Cliente* pCliente = cliente_new();
    Cliente* retorno = NULL;

    if(pCliente != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && dniStr != NULL)
    {
        if(!cliente_setIdStr(pCliente, idStr) &&
                !cliente_setNombre(pCliente, nombreStr) &&
                !cliente_setApellido(pCliente, apellidoStr) &&
                !cliente_setDniStr(pCliente, dniStr))
        {
            retorno = pCliente;
        }
        else
        {
            cliente_delete(pCliente);
        }
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para un cliente.
 *
 * \param Cliente* this puntero al cliente
 * \return int retorno -1 si this NULL,
 *                       0 si logro liberar el espacio reservado.
 *
 */
void cliente_delete(Cliente* this)
{
    if(this != NULL)
    {
        return free(this);
    }
}

/** \brief Valida el elemento id del cliente y lo carga en la estructura Cliente
 *
 * \param this Cliente* puntero al cliente
 * \param id int id del cliente
 * \return int retorno -1 si no pudo validar el ID
 *                      0 si pudo validar y cargar el ID:
 *
 */
int cliente_setId(Cliente* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un cliente.
 *
 * \param this Cliente* puntero a cliente.
 * \param resultado int* id de Cliente
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el id.
 *
 */
int cliente_getId(Cliente* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento nombre del cliente y lo carga en la estructura Cliente.
 *
 * \param this Cliente* puntero al cliente.
 * \param nombre char* nombre del cliente.
 * \return int retorno -1 si no pudo validar el nombre.
 *                      0 si pudo validar y cargar el nombre.
 *
 */
int cliente_setNombre(Cliente* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un cliente.
 *
 * \param this Cliente* puntero a cliente.
 * \param resultado char* nombre de cliente
 * \return int retorno -1 si this es NULL o nombre es NULL,
 *                      0 si se obtuvo el nombre.
 *
 */
int cliente_getNombre(Cliente* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento apellido del cliente y lo carga en la estructura Cliente.
 *
 * \param this Cliente* puntero al cliente.
 * \param apellido char* apellido del cliente.
 * \return int retorno -1 si no pudo validar el apellido.
 *                      0 si pudo validar y cargar el apellido.
 *
 */
int cliente_setApellido(Cliente* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el apellido de un cliente.
 *
 * \param this Cliente* puntero a cliente.
 * \param resultado char* apellido de cliente
 * \return int retorno -1 si this es NULL o apellido es NULL,
 *                      0 si se obtuvo el apellido.
 *
 */
int cliente_getApellido(Cliente* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->apellido);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento dni del cliente y lo carga en la estructura Cliente
 *
 * \param this Cliente* puntero al cliente
 * \param dni int dni del cliente.
 * \return int retorno -1 si no pudo validar el dni.
 *                      0 si pudo validar y cargar el dni.
 *
 */
int cliente_setDni(Cliente* this,int dni)
{
    int retorno = -1;
    if(this != NULL && dni >= 0)
    {
        this->dni = dni;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el dni de un cliente.
 *
 * \param this Cliente* puntero a cliente.
 * \param resultado int* dni de Cliente
 * \return int retorno -1 si this es NULL o dni es NULL,
 *                      0 si se obtuvo el dni.
 *
 */
int cliente_getDni(Cliente* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->dni;
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento id string del cliente y lo carga en la estructura Cliente.
 *
 * \param this Cliente* puntero al cliente.
 * \param id char* id del cliente.
 * \return int retorno -1 si no pudo validar el id.
 *                      0 si pudo validar y cargar el id.
 *
 */
int cliente_setIdStr(Cliente* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && !validarNumero(id))//Validar que lo que recibe es un numero.
    {
        retorno = cliente_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Obtiene el id de tipo string de un cliente.
 *
 * \param this Cliente* puntero a cliente.
 * \param resultado char* ID de cliente
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo el ID.
 *
 */
int cliente_getIdStr(Cliente* this, char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        cliente_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento dni del cliente y lo carga en la estructura Cliente.
 *
 * \param this Cliente* puntero al cliente.
 * \param dni char* dni del cliente.
 * \return int retorno -1 si no pudo validar el dni.
 *                      0 si pudo validar y cargar el dni.
 *
 */
int cliente_setDniStr(Cliente* this,char* dni)
{
    int retorno = -1;
    if(this != NULL && dni != NULL && !validarNumero(dni))//Validar que lo que recibe es un numero.
    {
        retorno = cliente_setDni(
this,atoi(dni));
    }
    return retorno;
}

/** \brief Obtiene el dni de tipo string de un cliente.
 *
 * \param this Cliente* puntero a cliente.
 * \param resultado char* dni de cliente
 * \return int retorno -1 si this es NULL o dni es NULL,
 *                      0 si se obtuvo el dni.
 *
 */
int cliente_getDniStr(Cliente* this,char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        cliente_getDni(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Compara entre dos nombres de la lista de cliente.
 *
 * \param this1 void* primer cliente.
 * \param this2 void* segundo cliente
 * \return int retorno: -1 si el segundo nombre es el mayor,
 *                       1 si el primer nombre es el mayor,
 *                       0 si son iguales.
 *
 */
int cliente_compararPorNombre(void* this1, void* this2)
{
    char auxNombreA[4096];
    char auxNombreB[4096];

    cliente_getNombre((Cliente*)this1, auxNombreA);
    cliente_getNombre((Cliente*)this2, auxNombreB);


    if(strcmp(auxNombreA, auxNombreB) > 0)
    {
        return 1;
    }
    if(strcmp(auxNombreA, auxNombreB) < 0)
    {
        return -1;
    }
    return 0;
}

/** \brief Recorre la lista de cliente, busca el id maximo y lo incrementa en uno al retornarlo
 *
 * \param LinkedList* pArrayCliente puntero al array de cliente.
 * \return retunr el id maximo incrementado en uno.
 *
 */

int cliente_lastId(LinkedList* pArrayListCliente)
{
    int IdAux;
    int IdMax;
    Cliente* pCliente;

    if(pArrayListCliente != NULL)
    {
        for(int i=0 ; i<ll_len(pArrayListCliente); i++)
        {
            pCliente = ll_get(pArrayListCliente, i);
            //cliente_getId(pCliente, &IdAux);
            if(pCliente != NULL)
            {
                cliente_getId(pCliente, &IdAux);
                //printf("%d-", IdAux);
                if(IdAux > IdMax)
                {
                    IdMax = IdAux;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return IdMax+1;
}

/** \brief busca la posicion en la que se encuentra un ID que solicita al usuario.
*
* \param LinkedList* pArrayCliente puntero al array de cliente.
* \param posicionId int* puntero al ID a buscar.
* \return int retorno -1 si pArrayCliente NULL, si pCliente es NULL, o el ID a buscar no existe en la lista.
*                      0 si encontro el ID buscado, y como parametro por referencia la posicion del mismo.
*
*/
int Cliente_findById(LinkedList* pArrayListCliente, int *posicionId, int id)
{
    int ret = -1;
    int idAux;
    Cliente *pCliente = NULL;

    if(pArrayListCliente != NULL && posicionId >= 0 && id >= 0)
    {
        for(int i = 0; i < ll_len(pArrayListCliente); i++)
        {
            pCliente = ll_get(pArrayListCliente, i);
            if(pCliente != NULL)
            {
                cliente_getId(pCliente, &idAux);
                if(id == idAux)
                {
                    *posicionId = i;
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

/*int cliente_Sueldo (void* pElementCliente)
{
    int ret = 0;//falso
    int sueldo;

    if(pElementCliente != NULL)
    {
        cliente_getSueldo(pElementCliente, &sueldo);
        if(sueldo >= 50000)
        {
            ret = 1; //verdadero
        }
    }
    return ret;
}*/
