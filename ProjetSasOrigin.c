#include <stdio.h>
#include <string.h>
#include <math.h>
struct Joueur {
	int Id;
	char Nom[100];
	char Prenom[100];
	int NumeroMaillot;
	char Poste[100];
	int Age ;
	int Buts;
};
struct Equipe {
	struct Joueur Joueurs[100];
};
void AfficherJoueur(struct Joueur joueur){
	if(joueur.Buts > 10){
		printf("id : %d | nom : %s | prenom : %s | numero maillot : %d | poste : %s | age : %d | buts : %d (star de l’equipe)\n",joueur.Id,joueur.Nom,joueur.Prenom,joueur.NumeroMaillot,joueur.Poste,joueur.Age,joueur.Buts);
	}else{
		printf("id : %d | nom : %s | prenom : %s | numero maillot : %d | poste : %s | age : %d | buts : %d\n",joueur.Id,joueur.Nom,joueur.Prenom,joueur.NumeroMaillot,joueur.Poste,joueur.Age,joueur.Buts);
	}
}
void AjouterJoueur(int nombreJoueursAjouter,int index, struct Joueur joueurs[]){
	struct Joueur joueur;
	int i;
	for(i = 1; i <= nombreJoueursAjouter ;i++ ){
		joueur.Id = index+1 ;
		printf("\tDonner le nom de Joueur :");
		scanf("%s",&joueur.Nom);
		printf("\n\tDonner le prenom de Joueur :");
		scanf("%s",&joueur.Prenom);
		printf("\n\tDonner le nemero maillot de Joueur :");
		scanf("%d",&joueur.NumeroMaillot);
		printf("\n\tDonner le poste de Joueur :");
		scanf("%s",&joueur.Poste);
		printf("\n\tDonner age de Joueur :");
		scanf("%d",&joueur.Age);
		printf("\n\tDonner buts de Joueur :");
		scanf("%d",&joueur.Buts);
		joueurs[index] = joueur;
	}
	if(nombreJoueursAjouter == 1){
		printf("\n\tLe joueur est bien ajouter !! :");
	}else{
		printf("\n\tTous les joueur est bien ajouter !! :");
	}
}
void AffichageTrier(int Trier,int size,struct Joueur joueurs[]){
	int i,j;
	if(Trier == 1){
		for(i = 0 ; i < size ;i++){
			for(j = 0 ; j < size-1-i ;j++){
				if(strcmp(joueurs[j].Nom,joueurs[j+1].Nom) > 0){
					struct Joueur temp = joueurs[j];
					joueurs[j] = joueurs[j+1];
					joueurs[j+1]=temp;
				}
			}
		}
	}else if(Trier == 2){
		for(i = 0 ; i < size ;i++){
			for(j = 0 ; j < size-1-i ;j++){
				if(joueurs[j].Age > joueurs[j+1].Age){
					struct Joueur temp = joueurs[j];
					joueurs[j] = joueurs[j+1];
					joueurs[j+1]=temp;
				}
			}
		}
	}else{
		for(i = 0 ; i < size ;i++){
			for(j = 0 ; j < size-1-i ;j++){
				if(joueurs[j].Poste > joueurs[j+1].Poste){
					struct Joueur temp = joueurs[j];
					joueurs[j] = joueurs[j+1];
					joueurs[j+1]=temp;
				}
			}
		}
	}
	for(i = 0 ; i < size ;i++){
		AfficherJoueur(joueurs[i]);
	}
}
int RechercheJoueurParNom(char nomRechercher[100],int size,struct Joueur joueurs[]){
	int i;
	for(i = 0 ; i < size ;i++){
		if(strcmp(nomRechercher,joueurs[i].Nom)==0){
			return i;
		}
	}
	return -1;
}
int RechercheJoueurParId(int id,int size,struct Joueur joueurs[]){
	int i;
	for(i = 0 ; i < size ;i++){
		if(id==joueurs[i].Id){
			return i;
		}
	}
	return -1;
}
struct Joueur getJoueurByIndex(int index, struct Joueur joueurs[] ){
	return joueurs[index];
}
void MoidifierPosteJoueur( char nomRechercher[100],char nouvelleValeur[100],int size,struct Joueur joueurs[]){
	int index = RechercheJoueurParNom(nomRechercher,size,joueurs);
	struct Joueur joueur = getJoueurByIndex(index,joueurs);
	strcpy(joueur.Poste,nouvelleValeur);
	joueurs[index] = joueur;
	printf("\tle poste de joueur et bien modifier !!");
	
}
void MoidifierJoueur(char nomRechercher[100],int nouvelleValeur,int Modifieur,int size,struct Joueur joueurs[]){
	int index = RechercheJoueurParNom(nomRechercher,size,joueurs);
	struct Joueur joueur = getJoueurByIndex(index,joueurs);
	if(Modifieur == 1){
		strcpy(joueur.Age,nouvelleValeur);
		joueurs[index] = joueur;
		printf("\tl'age de joueur et bien modifier !!");
	}else{
		strcpy(joueur.Buts,nouvelleValeur);
		joueurs[index] = joueur;
		printf("\tles buts de joueur et bien modifier !!");
	}
}
int SupprimerJoueur(int index,int size,struct Joueur joueurs[]){
	int i,j;
	for(i=index ; i>size ; i++){
		joueurs[i] = joueurs[i+1];
	}
}
void NombreTotalEquipe(struct Equipe equipe){
	int size = sizeof(equipe.Joueurs) / sizeof(equipe.Joueurs[0]);
	printf("le nombre total de ce equipe c est : %d",size);
}
void AgeMoyenne(struct Equipe equipe){
	int i,moyenne,somme = 0,size = sizeof(equipe.Joueurs) / sizeof(equipe.Joueurs[0]);
	for(i=0 ; i>size ; i++){
		somme += equipe.Joueurs[i].Age;
	}
	moyenne = somme / size;
	printf("age moyenne de ce equipe c est : %d",moyenne);
}
void JoueurParButs(int buts,struct Equipe equipe){
	int i,size = sizeof(equipe.Joueurs) / sizeof(equipe.Joueurs[0]);
	for(i=0 ; i>size ; i++){
		if(equipe.Joueurs[i].Buts == buts){
			AfficherJoueur(equipe.Joueurs[i]);
		}
	}
}
void MeilleurButeur(struct Equipe equipe){
	int i;
	struct Joueur MeilleurButeur =equipe.Joueurs[0];
	int size=sizeof(equipe.Joueurs) / sizeof(equipe.Joueurs[0]);
	for(i=0 ; i>size ; i++){
		if(equipe.Joueurs[i].Buts > MeilleurButeur.Buts){
			MeilleurButeur = equipe.Joueurs[i];
		}
	}
	AfficherJoueur(MeilleurButeur);
}

void PlusJeuneAge(struct Equipe equipe){
	int i;
	struct Joueur plusJeune =equipe.Joueurs[0];
	struct Joueur plusAge =equipe.Joueurs[0];
	int size=sizeof(equipe.Joueurs) / sizeof(equipe.Joueurs[0]);
	for(i=0 ; i>size ; i++){
		if(equipe.Joueurs[i].Age>plusAge.Age){
			plusAge = equipe.Joueurs[i];
		}
		if(equipe.Joueurs[i].Age<plusJeune.Age){
			plusJeune = equipe.Joueurs[i];
		}
		
	}
	printf("le joueur plus jeune cest /n");
	AfficherJoueur(plusJeune);
	printf("le joueur plus age cest /n");
	AfficherJoueur(plusAge);
}



int main(){
	
	
	
	
	
	
	
	return 0;
}
