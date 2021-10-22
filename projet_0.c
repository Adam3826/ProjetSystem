#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char** argv){

	if(argc != 2){
		printf("erreur d'arguments. utilisation : ./projet_0 nombre_fils\n");
		exit(1);
	}

	int N = atoi(argv[1]);
	int pid_pere = getpid();
	//int pid_courant;
	int x;

	for(int i = 0; i < N ; i++){                //On veut créer N processus fils, N est à saisir sur la ligne de commande 

		//pid_courant = getpid();             //On veut s'assurer qu'on ne crée pas de petit fils
		if(getpid() == pid_pere){        //donc on s'assure bien qu'on est dans le processus père pour utiliser fork

			switch(fork()){
			case -1 :
				perror("fork");
			case 0 :
				//---------------------------comportement de tous les fils-------------------------------
				printf("\n Fils n° %d pid = %d\n", i,getpid());

			default :
				//comportement du père
				wait(NULL);
			}
		}

	}if(getpid()==pid_pere){
		printf("père\n");
	}














	return 0;
}
