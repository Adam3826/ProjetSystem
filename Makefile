all : projet


projet:     projet_1.o projet_1_main.o
	gcc projet_1_main.o projet_1.o -o projet

projet_1.o: projet_1.c 
	gcc -c projet_1.c

projet_1_main.o: projet_1_main.c  projet_1.h
	gcc -c projet_1_main.c          

clean : 
	@echo "on efface les fichiers objets"
	rm -rf *.o projet         



