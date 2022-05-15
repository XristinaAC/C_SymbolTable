Exercise fulfilled during a University course about software basics. 

The exercise creates an abstract data type (ADT) called SymTable. Each copy (instance) of SymTable ADT will be a symbol table. The SymTable ADT is designed to be "general", which means the values ​​to be void pointers, and therefore to be able to show in data of any type.

Two implementations of SymTable ADT are created: an implementation that uses an interconnected one
list and one that uses a hash table.

(Some background: A symbol table is a collection of bindings. A commitment pair consists of a key and a value. The key is a string that uniquely identifies the corresponding binding pair. The value is data that somehow corresponds to the specific key. The symbol table allows the user to enter (put) new bindings, to read (get) the values ​​of the key-based bindings, and remove key-based bindings).

A Makefile is provided for running the programs and a main test file. 
