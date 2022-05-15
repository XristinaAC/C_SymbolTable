#include "symtable.h"

#define ST_Size 52
#define HASH_MULTIPLIER 65599

/*Hash_Table list node*/
struct Values{
    const void* value;
    const char* key;
    struct Values *next;
};

typedef struct Values val_ST;

/*Hash Table struct*/
struct node_ST{
    struct Values *chain_head;
};

SymTable_T *symbolTable;

/*Hash Function*/
static unsigned int SymTable_hash(const char *pcKey)
{
    unsigned int pos;
    
    pos=pcKey[0]%ST_Size;
    
    return pos;
}
/***************************************************/

/*Function NEW_HASH_T*/
SymTable_T *SymTable_new(void){
    SymTable_T *new_ST;
    int i;
    new_ST = (SymTable_T *) calloc(ST_Size, sizeof(SymTable_T));
    
    for(i = 0 ; i < ST_Size ; ++i){
        new_ST[i].chain_head=NULL;
    }
    
    return new_ST;
}

/*Function FREE_HASH_T*/
void SymTable_free(SymTable_T *oSymTable){
    if(oSymTable == NULL){
        return ;
    }
    
    free(oSymTable);
    
}

/*Function GET_LENGTH_HASH_T*/
unsigned int SymTable_getLength(SymTable_T *oSymTable){
    SymTable_T *tempSymTab;
    unsigned int length;
    int i;
    assert(oSymTable!=NULL);
    tempSymTab=oSymTable;
    length=0;
    
    for(i=0;i < ST_Size;++i){
        while(tempSymTab[i].chain_head!=NULL){
            ++length;
            tempSymTab[i].chain_head=tempSymTab[i].chain_head->next;
        }
    }
        
    return length;
}

/*Function PUT_HASH_T*/
SymTable_T *SymTable_put(SymTable_T *oSymTable,const char *pcKey, const void *pvValue){
    int pos;
    int i;
    
    assert(oSymTable!=NULL);
    assert(pcKey!=NULL);
    SymTable_T *tempSymTab;
    tempSymTab=oSymTable;
    pos=SymTable_hash(pcKey);
    
    while(tempSymTab[pos].chain_head!=NULL){
        if(tempSymTab[pos].chain_head->key == pcKey ){
            printf("The binding exists in the table\n");
            return oSymTable;
        }
        tempSymTab[pos].chain_head=tempSymTab[pos].chain_head->next;
    }
    
    val_ST *new_val;
    new_val=malloc(sizeof(val_ST));
    new_val->value=pvValue;
    new_val->key=pcKey;
  
    if(oSymTable[pos].chain_head == NULL){
      new_val->next=NULL;
      oSymTable[pos].chain_head=new_val;
    }else{
      new_val->next=oSymTable[pos].chain_head;
      oSymTable[pos].chain_head=new_val;
  }
  
 return oSymTable;
 free(new_val);
}

/*Fucntion REMOVE_HASH_T*/
SymTable_T *SymTable_remove(SymTable_T *oSymTable,const char *pcKey){
    
}

/*Function ELEMENT TRACKING_HASH_T*/
int SymTable_contain(SymTable_T *oSymTable,const char *pcKey){
    SymTable_T *tempSymTab;
    tempSymTab=oSymTable;
    int pos;
    assert(oSymTable!=NULL && pcKey!=NULL);
    pos=SymTable_hash(pcKey);
    
    while(tempSymTab[pos].chain_head != NULL){
        if(tempSymTab[pos].chain_head->key == pcKey){
            return 1;
        }
    }
    
    return 0;
}

/*Print Function*/
void printSymTable(SymTable_T *oSymTable){
    int i;
    SymTable_T *tempSymTab;
    tempSymTab=oSymTable;
    
    for(i=0;i<ST_Size;i++){
        while(tempSymTab[i].chain_head!=NULL){
            printf("(key,value)=(%s , %d)\n",tempSymTab[i].chain_head->key,*(const typeof(tempSymTab[i].chain_head->value) *)tempSymTab[i].chain_head->value);
            tempSymTab[i].chain_head=tempSymTab[i].chain_head->next;
        }
    }
}
