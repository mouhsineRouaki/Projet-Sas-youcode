#include <stdio.h>
#include <string.h>
#include <math.h>
#define RED   "\x1b[31m" 
#define RESET   "\x1b[0m"
#define GREEN   "\x1b[32m"

int idIncrement = 6;
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
	if(joueur.Buts >= 10){
		printf("id : %d | nom : %s | prenom : %s | numero maillot : %d | poste : %s | age : %d | buts : %d (star de l’equipe)\n",joueur.Id,joueur.Nom,joueur.Prenom,joueur.NumeroMaillot,joueur.Poste,joueur.Age,joueur.Buts);
	}else{
		printf("id : %d | nom : %s | prenom : %s | numero maillot : %d | poste : %s | age : %d | buts : %d\n",joueur.Id,joueur.Nom,joueur.Prenom,joueur.NumeroMaillot,joueur.Poste,joueur.Age,joueur.Buts);
	}
}
struct Equipe AjouterJoueur(int nombreJoueursAjouter,int index, struct Equipe equipe){
	struct Joueur joueur;
	int i;
	for(i = 1; i <= nombreJoueursAjouter ;i++ ){
		joueur.Id = idIncrement ;
		idIncrement+=1;
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
		equipe.Joueurs[index] = joueur;
		index +=1;
	}
	if(nombreJoueursAjouter == 1){
		printf("\n\tLe joueur est bien ajouter !! :");
	}else{
		printf("\n\tTous les joueur est bien ajouter !! :");
	}
	return equipe;
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
				if(strcmp(joueurs[j].Poste , joueurs[j+1].Poste) > 0){
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
		joueur.Age=nouvelleValeur;
		joueurs[index] = joueur;
		printf("\tl'age de joueur et bien modifier !!");
	}else{
		joueur.Buts=nouvelleValeur;
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
int Menu(){
	int operation;
	printf("             Menu : \n");
	printf(" 1-Pour ajouter un joueur \n");
	printf(" 2-Pour modifier un joueur \n");
	printf(" 3-Pour supprimer un joueur \n");
	printf(" 4-Pour afficher les joueur \n");
	printf(" 5-Pour rechercher a un joueur\n");
	printf(RED" 6-Pour quitter le programme\n"RESET);
	printf(" Entrez votre numero pour votre operation : ");
	scanf("%d",&operation);
	return operation;
}


int main(){
	struct Equipe equipe;
	struct Equipe nouvelleEquipe;
	int i;
	int operationMenuPrincipal;
	int repetition = 1;
	int sizeJoueurs = 5;
	int OperationAjout,PositionAjout = 0,NombreJoueurAjout;
	
	struct Joueur j1 = {1,"mohsin","rouaki",10,"milieux",25,11};
	struct Joueur j2 = {2,"ahmed","sifi",9,"attaquant",21,20};
	struct Joueur j3 = {3,"khalid","khalid",4,"défenseur",30,2};
	struct Joueur j4 = {4,"ousama","anas",3,"défenseur",18,4};
	struct Joueur j5 = {5,"abdltif","joudi",99,"gardien",24,0};
	equipe.Joueurs[PositionAjout] = j1;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j2;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j3;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j4;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j5;
	PositionAjout+=1;
	
	int OperationAffichage;
	while(repetition == 1){
		operationMenuPrincipal = Menu();
		switch(operationMenuPrincipal){
			case 1:
				printf(" 1-Pour ajouter un joueur \n");
				printf(" 2-Pour modifier plusieurs joueurs \n");
				printf(" 3-Pour retour a la menu principal \n");
				printf(" Entrez le numero d'operation :");
				scanf("%d",&OperationAjout);
				switch(OperationAjout){
					case 1:
						nouvelleEquipe= AjouterJoueur(1,PositionAjout,equipe);
						equipe = nouvelleEquipe;
						PositionAjout+=1;
						sizeJoueurs+=1;
						break;
					case 2:
						printf("Donner le nombre de joueur :");
						scanf("%d",&NombreJoueurAjout);
						nouvelleEquipe = AjouterJoueur(NombreJoueurAjout,PositionAjout,equipe);
						equipe = nouvelleEquipe;
						PositionAjout+=NombreJoueurAjout;
						sizeJoueurs+=NombreJoueurAjout;
						break;
					case 3:
						break;
					default :
						printf("donner nombre de operation ajouter");
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				printf(" 1-Pour les joueur trier par le nom\n");
				printf(" 2-Pour les joueur trier par l'age\n");
				printf(" 3-Pour les joueur trier par le poste\n");
				printf(" Entrez le numero d'operation :");
				scanf("%d",&OperationAffichage);
				switch(OperationAffichage){
					case 1:
						AffichageTrier(1,sizeJoueurs-1,equipe.Joueurs);
						break;
					case 2:
						AffichageTrier(2,sizeJoueurs-1,equipe.Joueurs);
						break;
					case 3:
						AffichageTrier(3,sizeJoueurs-1,equipe.Joueurs);
						break;
					default :
						printf("donner nombre de operation ajouter");
				}
				break;
			case 6:
				repetition = 0;
				break;
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}
