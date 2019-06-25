#ifndef cliente_H_INCLUDED
#define cliente_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    int dni;
}Cliente;

Cliente* cliente_new();
Cliente* cliente_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void cliente_delete();

int cliente_setId(Cliente* this,int id);
int cliente_getId(Cliente* this,int* id);

int cliente_setNombre(Cliente* this,char* nombre);
int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setApellido(Cliente* this,char* apellido);
int cliente_getApellido(Cliente* this,char* apellido);

int cliente_setDni(Cliente* this,int dni);
int cliente_getDni(Cliente* this,int* dni);

int cliente_setIdStr(Cliente* this, char* id);
int cliente_getIdStr(Cliente* this, char* resultado);

int cliente_setDniStr(Cliente* this,char* dni);
int cliente_getDniStr(Cliente* this,char* resultado);

int cliente_lastId(LinkedList* pArrayListCliente);
int cliente_findById(LinkedList* pArrayListCliente, int *posicionId, int id);
int cliente_compararPorNombre(void* this1, void* this2);

//int cliente_Sueldo (void* pElementCliente);


#endif // cliente_H_INCLUDED
