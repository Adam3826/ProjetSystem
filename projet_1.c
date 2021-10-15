#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){


	int pid_pere = getpid();
  	int N = atoi(argv[1]);
	int x;
	int pipe_pere[2];
	int numero_fils;
	
	//------------------------------CREATION DES TUBES----------------------------------------
	
	int tableau_tubes[N][2];
	for(int i = 0; i < N; i++){
		pipe(tableau_tubes[i]);
	
	}
	pipe(pipe_pere);
	

	
	
	//--------------------------------------------------------------------------------------
	
	
	
	
	
	
	
	
	
	

	for(int i = 0; i < N ; i++){                //On veut créer N processus fils

				             //On veut s'assurer qu'on ne crée pas de petit fils
		if(getpid() == pid_pere){        //donc on s'assure bien qu'on est dans le processus père pour utiliser fork

			switch(fork()){
	
			    case -1:
		    		perror("fork");
		    		exit(1);
			    case 0:


// ---------------------------------------------LES FILS ----------------------------------------------------
//--------------------------------------------------------------------------------------------------------
				numero_fils = getpid()-pid_pere;
		
    //----------------------------fermeture des pipes inutilisés depuis le fils i----------------------------
    //------------------------------------------------------------------------------------------------------


	//--------------------------CAS INITIAL : Node 1 --------------------------------
				if(numero_fils == 1){
		   			close(tableau_tubes[N][1]);   //fermeture de l'entrée du tube N dans le fils 0
			    		close(tableau_tubes[0][0]);   //fermeture de la sortie du tube 0 dans le fils 0


					close(0);			//redirection sortie std vers pipe
					dup(tableau_tubes[0][1]);
					close(tableau_tubes[0][1]);

					close(1);			//redirection entrée std vers pipe
					dup(tableau_tubes[N][0]);
					close(tableau_tubes[N][0]);
			        }

        //---------------------------CAS GENERAL----------------------------------------------------------
				for(int i = 1; i < N; i++){                           //i parcourt les Tubes de 1 à N 
				    if(i >= numero_fils  || i < numero_fils - 2){   //on ferme les pipes sauf les deux adjacents
					close(tableau_tubes[i][0]);
					close(tableau_tubes[i][1]);



				    }
				    if(i == numero_fils - 2){                     //si on est sur le pipe entrant
					close(tableau_tubes[i][1]);                 //on ferme l'entrée du pipe rentrant dans le node

					close(0);                         //redirection de l'entrée standard vers le pipe
					dup(tableau_tubes[i][0]);         
					close(tableau_tubes[i][0]);


				    }
				    if(i == numero_fils - 1){             //si on est sur le pipe sortant
					close(tableau_tubes[i][0]);         //on ferme la sortie de ce pipe

					close(1);                         //redirection de la sortie standard vers le pipe
					dup(tableau_tubes[i][1]);         
					close(tableau_tubes[i][1]);
            			    }
				


        			}
				printf("\n Fils n° %d pid = %d\n", numero_fils,getpid());
        
		 
		
		//redirection de la sortie standard vers le pipe
		/*close(1);          
		dup(tube1[1]);
		close(tube1[1]);*/
		
	//---------------------------------------------------------------------------------------------------------------------
	//------------------------------------------FIN DES FILS--------------------------------------------------------------
			    default:
		//comportement du père
				wait(NULL);
				close(tableau_tubes[i][0]);
				close(tableau_tubes[i][1]);
			}
		

		}
	}
	if(getpid()==pid_pere){
		
		printf("pid du père : %d\n",getpid());

	}














	return 0;
}
