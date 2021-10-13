#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 4

int main(int argc, char** argv){


	int pid_pere = getpid();
	int pid_courant;
	int x;

	for(int i = 0; i < N ; i++){                //On veut créer N processus fils

		pid_courant = getpid();             //On veut s'assurer qu'on ne crée pas de petit fils
		if(pid_courant == pid_pere){        //donc on s'assure bien qu'on est dans le processus père pour utiliser fork

			switch(fork()){
			/*case -1 :
				perror("fork");
			case 0 :
				//---------------------------comportement de tous les fils-------------------------------

			default :*/
				//comportement du père
			}
		}

	}














	return 0;
}
