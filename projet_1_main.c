#include "projet_1.h"


int main(int argc, char** argv){

	if(argc !=2){
		printf("Erreur d'argument. Usage : projet_1 [nb_processus]");
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

	if (numero_fils == 1){
		x = 5;
		ecrire(x);
	}
	else if(numero_fils != -1){
		x = lire();
		ecrire(x);
	}
	if(numero_fils == N){
		ecrire_pere(x);
	}
 




	





	return 0;	
}

















