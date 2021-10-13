#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){


	int pid_pere = getpid();
	int pid_courant;
  int N = atoi(argv[1]);
	int x;
	int pipe_pere[2];
	
	//------------------------------CREATION DES TUBES----------------------------------------
	
	int tableau_tubes[N][2];
	for(int i = 0; i < N; i++){
		pipe(tableau_tubes[i]);
	
	}
	pipe(pipe_pere);
	

	
	
	//--------------------------------------------------------------------------------------
	
	
	
	
	
	
	
	
	
	

	for(int i = 0; i < N ; i++){                //On veut créer N processus fils

		pid_courant = getpid();             //On veut s'assurer qu'on ne crée pas de petit fils
		if(pid_courant == pid_pere){        //donc on s'assure bien qu'on est dans le processus père pour utiliser fork

			switch(fork()){
	
	    case -1:
    		perror("fork");
    		exit(1);
	    case 0:


// ---------------------------------------------LES FILS ----------------------------------------------------
//--------------------------------------------------------------------------------------------------------
		int numero_fils = getpid()-pid_pere;
		
    //----------------------------fermeture des pipes inutilisés depuis le fils i----------------------------
    //------------------------------------------------------------------------------------------------------


//--------------------------CAS INITIAL : Node 0 --------------------------------
        if(numero_fils == 0){
            close(tableau_tubes[N][1]);   //fermeture de l'entrée du tube N dans le fils 0
		    close(tableau_tubes[0][0]);   //fermeture de la sortie du tube 0 dans le fils 0
//-------------------------------------------------------------------------------






        }

        //---------------------------CAS GENERAL----------------------------------------------------------
        for(int i = 1; i < N; i++){                           //i parcourt les Nodes de 1 à N (le cas du Node 0 est déjà traité)
            if(i > numero_fils + 1 || i < numero_fils - 1){   //on ferme les pipes sauf les deux adjacents
                close(tableau_tubes[i][0]);
                close(tableau_tubes[i][1]);



            }if(i == numero_fils - 1){                     //si on est sur le pipe entrant
                close(tableau_tubes[i][1]);                 //on ferme l'entrée du pipe rentrant dans le node

                close(0);                         //redirection de l'entrée standard vers le pipe
		        dup(tableau_tubes[i][0]);         
		        close(tableau_tubes[i][0]);


            }if(i == numero_fils + 1){             //si on est sur le pipe sortant
                close(tableau_tubes[i][0]);         //on ferme la sortie de ce pipe

                close(1);                         //redirection de la sortie standard vers le pipe
		        dup(tableau_tubes[i][1]);         
		        close(tableau_tubes[i][1]);
            }


        }
        
		 
		
		//redirection de la sortie standard vers le pipe
		close(1);          
		dup(tube1[1]);
		close(tube1[1]);
		}
		
	//---------------------------------------------------------------------------------------------------------------------
	//------------------------------------------FIN DU FILS 1--------------------------------------------------------------
	default:
		//comportement du père
		}

	}














	return 0;
}
