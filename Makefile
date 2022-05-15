list: symtablelist.o testsymtab.o
	gcc -o testsymtab symtablelist.o testsymtab.o;
	
symTablelist.o: symtable.h symtablelist.c
	gcc -c symtablelist.c;
	
testsymtab.o: symtable.h testsymtab.c
	gcc -c testsymtab.c;
	
hash: symtablehash.o testsymtab.o
	gcc -o testsymtab symtablehash.o testsymtab.o;
	
symTablehash.o: symtable.h symtablehash.c
	gcc -c symtablehash.c;
	
clean: cleant
	rm *.o
cleant:
	rm testsymtab 
