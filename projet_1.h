#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



//crée N tubes.
void creer_pipes(int N,int tableau_tubes[N][2]);


//crée N processus fils sans créer de petit fils, renvoie le numéro du node actuel (1 à N)
int creer_fils(int N);

//Ferme les pipes non utilisés et les extrémités non utilisées par les fils
void fermer_pipes(int N, int pid_pere, int numero_fils, int tableau_tubes[N][2], int pipe_pere[2]);


//permet à  un fils de lire un entier dans le pipe entrant
int lire();

//permet à  un fils d'écrire un entier dans le pipe sortant
void ecrire(int x);

//permet à un fils d'écrire un entier au père
void ecrire_pere(int x);

//permet au père de lire dans son pipe entrant
void lire_pere(int x);

