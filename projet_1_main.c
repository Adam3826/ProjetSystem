//ZODJIHOUE Hubert
//MOUSSOLNA Adam

#include "projet_1.h"


int main(int argc, char** argv){

	if(argc !=2){
		printf("Erreur d'argument. Usage : projet_1 [nb_processus]\n");
		exit(1);
	}




	int pid_pere = getpid();
  	int N = atoi(argv[1]);
	int x;
	int pipe_pere[2];
	int numero_fils;
	int tableau_tubes[N][2];


	creer_pipes(N, tableau_tubes);
	pipe(pipe_pere);

	numero_fils = creer_fils(N);

	fermer_pipes(N, pid_pere, numero_fils, tableau_tubes, pipe_pere);


	
//--------------------------------ECRITURE D'UN ENTIER DANS L'ANNEAU DES TUBES-----------------------------------------------------------------
	if (numero_fils == 1){
		x = 5;
		if (write(tableau_tubes[0][1], &x, sizeof(int)) < 0){
		perror("write");
   		}
		printf("le fils 1 meurt\n");
		exit(0);
	}



//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------LES FILS------------------------------------------------------------------------------
	else if(getpid() != pid_pere){
		if (read(tableau_tubes[numero_fils-2][0], &x, sizeof(int)) < 0){
			perror("read");
   		}
		printf("Je suis le fils %d et j'ai lu x = %d\n", numero_fils, x);

		if (write(tableau_tubes[numero_fils - 1][1], &x, sizeof(int)) < 0){
			perror("write");
   		}
		if (write(pipe_pere[1], &x, sizeof(int)) < 0){
				perror("write");
		}
		if(numero_fils == N){
			if (write(pipe_pere[1], &x, sizeof(int)) < 0){
				perror("write");
			}
		}
		printf("le fils %d meurt\n",numero_fils);
		exit(0);
		
	}
//-----------------------------------------------FIN DES FILS--------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
	else if (getpid() == pid_pere){
		for(int k = 2; k < N; k++){
			if (read(pipe_pere[0], &x, sizeof(int)) < 0){
				perror("read père");
			}
			printf("le père a lu x = %d\n", x);
		}
		
		while(wait(NULL)!= -1);
		printf("les fils sont morts\n");
	}
 




	





	return 0;	
}

















