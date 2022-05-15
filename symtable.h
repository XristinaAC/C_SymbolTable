/********************************************************************
* INTERFACE OF THE SymTable ADT
*********************************************************************/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node_ST SymTable_T;

/*Function NEW*/
SymTable_T *SymTable_new(void);

/*Function FREE*/
void SymTable_free(SymTable_T *oSymTable);

/*Function GET_LENGTH*/
unsigned int SymTable_getLength(SymTable_T *oSymTable);

/*Function PUT*/
SymTable_T *SymTable_put(SymTable_T *oSymTable,const char *pcKey, const void *pvValue);

/*Fucntion REMOVE*/
SymTable_T *SymTable_remove(SymTable_T *oSymTable,const char *pcKey);

/*Function ELEMENT TRACKING*/
int SymTable_contain(SymTable_T *oSymTable,const char *pcKey);

/*Function GET_ELEMENT*/
void* SymTable_get(SymTable_T *oSymTable,const char *pcKey);

/*Function 8*/
void SymTable_map(SymTable_T *oSymTable,void (*pfApply)(const char *pcKey, void *pvValue,void *pvExtra),const void *pvExtra);

/*Function PRINT*/
void printSymTable(SymTable_T *oSymTable);

/*******************************/
extern SymTable_T *symbolTable;

