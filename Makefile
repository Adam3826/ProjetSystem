all : projet_1 projet_0 testTable

projet_0: projet_0.o
	gcc projet_0.o -o projet_0

projet_0.o: projet_0.c
	gcc -c projet_0.c

projet_1:     projet_1.o projet_1_main.o
	gcc projet_1_main.o projet_1.o -o projet_1

projet_1.o: projet_1.c 
	gcc -c projet_1.c

projet_1_main.o: projet_1_main.c  projet_1.h
	gcc -c projet_1_main.c
      
testTable: testTable.o table.o
	gcc testTable.o table.o -o testTable

testTable.o: testTable.c
	gcc -c testTable.c

table.o: table.c
	gcc -c table.c


clean : 
	@echo "on efface les fichiers objets"
	rm -rf *.o projet_1 projet_0 testTable


