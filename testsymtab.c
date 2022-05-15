#include "symtable.h"

int main(){
    unsigned int len=0;
    int *c;
    int *c2;
    int u;
    int i;
    int result;
    /*int *bindingValue;*/
    symbolTable = SymTable_new();
    u=67;
    c=&u;
    i=900;
    c2=&i;

    symbolTable = SymTable_put(symbolTable,"x",c);
    symbolTable = SymTable_put(symbolTable,"x",c);
    symbolTable = SymTable_put(symbolTable,"no",c2);

    printSymTable(symbolTable);

    len=SymTable_getLength(symbolTable);
    printf("the length of the symbol table is %u\n",len);

    symbolTable=SymTable_remove(symbolTable,"no");
    printSymTable(symbolTable);

    result = SymTable_contain(symbolTable,"no");
    if(result == 0){
        printf("The element doesn't exist in the Symbol Table\n");
    }else{
        printf("The element exists in the Symbol Table\n");
    }
        
    SymTable_free(symbolTable);
    return 0;
}
