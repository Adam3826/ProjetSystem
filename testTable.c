//ZODJIHOUE Hubert
//MOUSSOLNA Adam


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "table.h"

#define MAX_SIZE 128



//Demande à l'utilisateur de rentrer 4 clés et 4 valeurs associées et les stocke dans la table
void ajouter_valeurs(PTable_entry *table){
	int k = -1;
	char* v;
	
	for(int i =0; i < 4; i++){
		printf("Saisir la clé (decimal number): \n");
		if(scanf("%d", &k) == 0){ //on teste que scanf a bien fonctionné (que l'utilisateur ait bien saisi un entier)
		
			printf("Veuillez sélectionner une entrée valide (nombre entier)\n");
			scanf("%d", &k);					
		}

		printf("Saisir la valeur (chaine de caracteres, max 128chars):\n");
		scanf("%s", v);
		store(table,k,v);

	}

}



//Demande à l'utilisateur une clé à chercher et affiche la valeur correspondante
void rechercher_valeur(PTable_entry *table){
	char* v;
	int cle;
	printf("saisir clé à chercher\n");
	scanf("%d",&cle);
	if(lookup(*table, cle)==NULL){
		printf("Pas de valeur trouvee\n");
	}
	else{
	v = lookup(*table, cle);
	printf("Valeur trouvee = %s\n", v);
	}
}




int main(int argc, char** argv){

	PTable_entry *table = malloc(4*sizeof(PTable_entry*));;
	

	ajouter_valeurs(table);

	display(*table);

	rechercher_valeur(table);

	
	return 0;


}





















