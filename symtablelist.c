#include "symtable.h"
#include <assert.h>

struct node_ST{
    const char *key;
    const void *value;
    struct node_ST *next;
};

SymTable_T *symbolTable;

/*Function NEW_List*/
SymTable_T *SymTable_new(void){
    SymTable_T *new_ST;

    new_ST=NULL;

    return new_ST;
}

/*Function FREE_List*/
void SymTable_free(SymTable_T *oSymTable){
    if(oSymTable == NULL){
        return;
    }

    free(oSymTable);
}

/*Function GET_LENGTH_List*/
unsigned int SymTable_getLength(SymTable_T *oSymTable){
    unsigned int st_len;
    SymTable_T *tempSY;

    assert(oSymTable != NULL);
    st_len=0;
    tempSY=oSymTable;

    while(tempSY != NULL){
        st_len++;
        tempSY=tempSY->next;
    }

    return st_len;
}

/*Function PUT_List*/
SymTable_T *SymTable_put(SymTable_T *oSymTable,const char *pcKey, const void *pvValue){
    SymTable_T *tempSY;
    SymTable_T *newElement;

    assert(oSymTable!=NULL || pcKey != NULL);
    tempSY=oSymTable;
    while(tempSY != NULL){
        if(tempSY->key == pcKey){
        printf("the element exists\n");
        return oSymTable;
    }
    tempSY=tempSY->next;
    }

    newElement=malloc(sizeof(SymTable_T));
    newElement->key=pcKey;
    newElement->value=pvValue;

    if(oSymTable ==NULL){
        newElement->next=NULL;
        oSymTable=newElement;
    }else{
        newElement->next=oSymTable;
        oSymTable=newElement;
    }

    return oSymTable;
    free(newElement);
}

/*Fucntion REMOVE_List*/
SymTable_T *SymTable_remove(SymTable_T *oSymTable,const char *pcKey){
    assert(oSymTable!=NULL || pcKey != NULL);

    SymTable_T *tempSY=oSymTable;
    SymTable_T *tempPrevNode=NULL;
    SymTable_T *tempNode=NULL;
    SymTable_T *temp=NULL;

    while(tempSY != NULL && tempSY->key != pcKey ){
        tempPrevNode=tempSY;
        tempSY=tempSY->next;
    }
    tempSY=oSymTable;

    if(tempPrevNode == NULL){
        temp=tempSY->next;
        tempSY=NULL;
        oSymTable=temp;
        return oSymTable;
    }else if(tempPrevNode->next->next == NULL ){
        while(tempSY!=NULL){
            if(tempSY==tempPrevNode){
                tempSY->next=NULL;
                oSymTable=tempSY;
                return oSymTable;
            }
            tempSY=tempSY->next;
        }
    }else{
         while(tempSY!=NULL){
            if(tempSY==tempPrevNode){
                tempSY=tempSY->next->next;
                oSymTable=tempSY;
                return oSymTable;
            }
            tempSY=tempSY->next;
        }
    }

    return oSymTable;
}

/*Function ELEMENT TRACKING_List*/
int SymTable_contain(SymTable_T *oSymTable,const char *pcKey){
    SymTable_T *tempSY;
    tempSY=oSymTable;

    while(tempSY != NULL){
        if(tempSY->key == pcKey){
            return 1;
        }
    }

    return 0;
}

/*Function GET_ELEMENT_List*/
void* SymTable_get(SymTable_T *oSymTable,const char *pcKey){
    SymTable_T *tempSY;
    tempSY=oSymTable;

    while(tempSY != NULL){
        if(tempSY->key == pcKey){
            return *(typeof(oSymTable->value) *)tempSY->value;
        }
        tempSY=tempSY->next;
    }
    return NULL;
}

/*Print Function*/
void printSymTable(SymTable_T *oSymTable){
    while(oSymTable!=NULL){
        printf("(key , value) = (%s , %d)\n",oSymTable->key,*(const typeof(oSymTable->value) *)oSymTable->value);
        oSymTable=oSymTable->next;
    }
}
