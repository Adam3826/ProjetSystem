#include "projet_1.h"


void creer_pipes(int N,int tableau_tubes[N][2]){
	for(int i = 0; i < N; i++){
		pipe(tableau_tubes[i]);
	
	}

}

int creer_fils(int N){
	int pid_pere = getpid();
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
				close(pipe_pere[0]);
		
    //----------------------------fermeture des pipes inutilisés depuis le fils i----------------------------
    //------------------------------------------------------------------------------------------------------


	//--------------------------CAS INITIAL : Node 1 --------------------------------
				if(numero_fils == 1){
 			    		close(tableau_tubes[N][1]);   //fermeture de l'entrée du tube N dans le fils 0
  		    			close(tableau_tubes[0][0]);   //fermeture de la sortie du tube 0 dans le fils 0

				
			        }

        //---------------------------CAS GENERAL----------------------------------------------------------
				for(int i = 1; i < N; i++){                           //i parcourt les Tubes de 1 à N 
				    if(i >= numero_fils  || i < numero_fils - 2){   //on ferme les pipes sauf les deux adjacents
					close(tableau_tubes[i][0]);
					close(tableau_tubes[i][1]);



				    }
				    if(i == numero_fils - 2){                     //si on est sur le pipe entrant
					close(tableau_tubes[i][1]);                 //on ferme l'entrée du pipe rentrant dans le node



				    }
				    if(i == numero_fils - 1){             //si on est sur le pipe sortant
					close(tableau_tubes[i][0]);         //on ferme la sortie de ce pipe

            			    }
				


        			}
				
        
		 

		
	//---------------------------------------------------------------------------------------------------------------------
	//------------------------------------------FIN DES FILS--------------------------------------------------------------
			    default:
		//comportement du père
				//wait(NULL);
				close(tableau_tubes[i][0]);  //ferme toutes les extremités sortantes pour le père
				
			}
		

		}
	}
}




int lire();
void ecrire(int x);
void ecrire_pere(int x);

void lire_pere(int x);
















