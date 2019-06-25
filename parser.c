#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cliente.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo (modo texto).
 *
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListCliente LinkedList* puntero al array de cliente.
* \return int ret -1 si el puntero pFile es NULL o el puntero pArrayListCliente es NULL,
                   0 si logro parsear el archivo.
 *
 */
int parser_ClienteFromText(FILE* pFile, LinkedList* pArrayListCliente)
{
    int ret = -1;
    char bufferId[400];
    char bufferNombre[400];
    char BufferApellido[400];
    char bufferDni[400];
    Cliente *pAuxCliente;


    if(pFile != NULL && pArrayListCliente != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"\t%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,BufferApellido,bufferDni);
            pAuxCliente = cliente_newParametros(bufferId,bufferNombre,BufferApellido,bufferDni);
            if(pAuxCliente != NULL)
            {
                ll_add(pArrayListCliente, pAuxCliente);
                ret = 0;
            }
        }
        fclose(pFile);
    }
    return ret;
}

/** \brief Parsea los datos los datos de los cliente desde el archivo (modo binario).
 *
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListCliente LinkedList* puntero al array de cliente.
 * \return int ret -1 si pFile es NULL o pArrayListCliente es NULL,
                    0 si logro parsear el archivo.
 *
 */
int parser_ClienteFromBinary(FILE* pFile, LinkedList* pArrayListCliente)
{
    int ret = -1;
    Cliente auxCliente;
    Cliente* pCliente= NULL;

    if(pFile != NULL && pArrayListCliente != NULL)
    {
        while(!feof(pFile))
        {
            pCliente = cliente_new();
            fread(&auxCliente, sizeof(Cliente), 1, pFile);
            if(!cliente_setId(pCliente, auxCliente.id) &&
                    !employee_setNombre(pCliente, auxCliente.nombre) &&
                    !employee_setApellido(pCliente, auxCliente.apellido) &&
                    !employee_setDni(pCliente, auxCliente.dni))
            {
                fread(&auxCliente, sizeof(Cliente), 1, pFile);
                if(pCliente!= NULL)
                {
                    ll_add(pArrayListCliente, pCliente);
                    ret = 0;
                }

            }
            else
            {
                employee_delete(pCliente);
            }

        }
        fclose(pFile);
    }
    return ret;
}




