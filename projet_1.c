#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//-------------------gérer argc ok ?
//------------------gérer malloc
//-----------------père rouvrir les extremites d'ecritures ok?
//---------------pas de redirection ok ?
int main(int argc, char** argv){

	if(argc !=2){
		printf("Erreur d'argument. Usage : projet_0 [nb_processus]");
		exit(1);
	}
	int pid_pere = getpid();
  	int N = atoi(argv[1]);
	int x;
	int pipe_pere[2];
	int numero_fils;
	int tableau_tubes[N][2];
	/*int* tableau_tubes[2] = malloc(sizeof(int[2])*N);
	for (int k = 0; k < N; k++){
		
		tableau_tubes=malloc(sizeof(int[2]));*/

	
	//------------------------------CREATION DES TUBES----------------------------------------
	
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
//-------------------------------------------FIN D'INITIALISATION TUBES---------------------------------------------------------------
//-------------------------------------------FIN D'INITIALISATION TUBES---------------------------------------------------------------


//--------------------------------------COMPORTEMENT DU PERE-------------------------------------------

	if(getpid()==pid_pere){
		
		printf("pid du père : %d\n",getpid());
		close(pipe_pere[1]);
		if (read(pipe_pere[0], &x, sizeof(int)) < 0){
			perror("read père");
   		}
		printf("valeurs de x : %d\n",x);

		
		while(wait(NULL)!=-1);

	}

   	



//--------------------------------------------lecture depuis les fils-------------------------------------

	if(numero_fils==1){

			x=72; //test de la communication inter fils
			if (write(tableau_tubes[0][1], &x, sizeof(int)) < 0){
		        	perror("write");
			}
		
	}
	if(numero_fils > 1){

		if (read(tableau_tubes[numero_fils-2][0], &x, sizeof(int)) < 0){
			perror("read fils i");
   		}
	}

//---------------------------------------------ECRITURE DEPUIS LES FILS-----------------------------	


	if(numero_fils < N){			

		if (write(tableau_tubes[numero_fils-1][1], &x, sizeof(int)) < 0){
				        perror("write");
   				}




	}

	if(numero_fils == N){
		if (write(pipe_pere[1], &x, sizeof(int)) < 0){
			perror("write pipe père");
   		}


	}





	return 0;
}
