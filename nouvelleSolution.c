#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#define RED   "\x1b[31m" 
#define RESET   "\x1b[0m"
#define GREEN   "\x1b[32m"

int idIncrement = 6;

struct Poste{
	char gardien[100];
	char defenseur[100]; 
	char milieu[100];
	char attaquant[100];
};

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

struct Equipe equipe;
struct Poste poste = {"gardien","defenseur","milieu","attaquant"};
int i,PositionAjout = 0,NombreJoueurAjout;
int operationMenuPrincipal;
int sizeJoueurs = 5;
int OperationAjout,operationModification,operationTypeRecherche,operationTrier;
char nomRechercher[100],nouvellePoste[100];
int idRechercher,nouvelleAge,nouvelleButs,index,buts;
char confirmationSupprestion;

void AfficherJoueur(struct Joueur joueur){
	if(joueur.Buts >= 10){
		printf(GREEN "ID : %-3d | Nom : %-10s | Prenom : %-10s | Maillot : %-3d | Poste : %-10s | Âge : %-2d | Buts : %-2d  (Star de l equipe)\n" RESET,
			joueur.Id, joueur.Nom, joueur.Prenom, joueur.NumeroMaillot, joueur.Poste, joueur.Age, joueur.Buts);
	}else{
		printf("ID : %-3d | Nom : %-10s | Prenom : %-10s | Maillot : %-3d | Poste : %-10s | Âge : %-2d | Buts : %-2d\n",
			joueur.Id, joueur.Nom, joueur.Prenom, joueur.NumeroMaillot, joueur.Poste, joueur.Age, joueur.Buts);
	}
}
void AjouterJoueur(){
	struct Joueur joueur;
	int i;
	int operationPoste;
	for(i = 1; i <= nombreJoueursAjouter ;i++ ){
		joueur.Id = idIncrement ;
		idIncrement+=1;
		printf("\tDonner le nom de Joueur :");
		scanf("%s",&joueur.Nom);
		printf("\tDonner le prenom de Joueur :");
		scanf("%s",&joueur.Prenom);
		printf("\tDonner le nemero maillot de Joueur :");
		numeroMailotJ :
		if(scanf("%d",&joueur.NumeroMaillot)==0){
			printf(RED"le numero de mailot ne pas correct"RESET);
			goto numeroMailotJ;
		}
		posteJ;
		printf("\tDonner le poste de Joueur(1-gardien||2-défenseur||3-milieu||4-attaquant) :");
		if(scanf("%d",&operationPoste)==1){
			switch(operationPoste){
				case 1:strcpy(joueur.Poste,poste.gardien);break;
				case 2:strcpy(joueur.Poste,poste.defenseur) ;break;
				case 3:strcpy(joueur.Poste,poste.milieu) ;break;
				case 4:strcpy(joueur.Poste,poste.attaquant) ;break;
				default :printf(RED"le nombre entrer ne pas correcte"RESET);
					goto posteJ;
			}
		}else{
			printf(RED"le poste ne pas correct"RESET);
			goto posteJ;
		}
		
		printf("\tDonner age de Joueur :");
		ageJ :
		if(scanf("%d",&joueur.Age)==0){
			printf(RED"age  ne pas correct"RESET);
			goto ageJ;
		}
		printf("\tDonner buts de Joueur :");
		scanf("%d",&joueur.Buts);
		butsJ :
		if(scanf("%d",&joueur.Buts)==0){
			printf(RED"les buts ne pas correct"RESET);
			goto butsJ;
		}
		equipe.Joueurs[index] = joueur;
		index +=1;
	}
	if(nombreJoueursAjouter == 1){
		printf(GREEN"\n\tLe joueur est bien ajouter !! :"RESET);
	}else{
		printf(GREEN"\n\tTous les joueur est bien ajouter !! :"RESET);
	}
}


void AffichageTrier(int Trier){
	int i,j;
	if(Trier == 1){
		for(i = 0 ; i < size ;i++){
			for(j = 0 ; j < size-1-i ;j++){
				if(strcmp(equipe.Joueurs[j].Nom,equipe.Joueurs[j+1].Nom) > 0){
					struct Joueur temp = equipe.Joueurs[j];
					equipe.Joueurs[j] = equipe.Joueurs[j+1];
					joueurs[j+1]=temp;
				}
			}
		}
	}else{
		for(i = 0 ; i < size ;i++){
			for(j = 0 ; j < size-1-i ;j++){
				if(joueurs[j].Age > joueurs[j+1].Age){
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
void joueursParPoste(char poste[],int size,struct Equipe equipe){
	int i;
	for(i = 0 ; i < size ;i++){
		if(strcmp(equipe.Joueurs[i].Poste,poste) == 0){
			AfficherJoueur(equipe.Joueurs[i]);
		}
	}
}
int RechercheJoueurParNom(char nomRechercher[100],int size,struct Equipe equipe){
	int i;
	for(i = 0 ; i < size ;i++){
		if(strcmp(nomRechercher,equipe.Joueurs[i].Nom)==0){
			return i;
		}
	}
	return -1;
}
int RechercheJoueurParId(int id,int size,struct Equipe equipe){
	int i;
	for(i = 0 ; i < size ;i++){
		if(equipe.Joueurs[i].Id == id){
			return i;
		}
	}
	return -1;
}

struct Joueur getJoueurByIndex(int index, struct Joueur joueurs[] ){
	return joueurs[index];
}


struct Equipe MoidifierPosteJoueurParId(int id,char nouvelleValeur[100],int size,struct Equipe equipe){
	int index = RechercheJoueurParId(id,size,equipe);
	struct Joueur joueur = getJoueurByIndex(index,equipe.Joueurs);
	strcpy(joueur.Poste,nouvelleValeur);
	equipe.Joueurs[index] = joueur;
	printf("\tle poste de joueur et bien modifier !!");
	return equipe;
}

struct Equipe MoidifierJoueurParId(int id,int nouvelleValeur,int Modifieur,int size,struct Equipe equipe){
	int index = RechercheJoueurParId(id,size,equipe);
	struct Joueur joueur = getJoueurByIndex(index,equipe.Joueurs);
	if(Modifieur == 1){
		joueur.Age=nouvelleValeur;
		equipe.Joueurs[index] = joueur;
		printf("\tl'age de joueur et bien modifier !!");
	}else{
		joueur.Buts=nouvelleValeur;
		equipe.Joueurs[index] = joueur;
		printf("\tles buts de joueur et bien modifier !!");
	}
	return equipe;
}

struct Equipe SupprimerJoueur(int index,int size,struct Equipe equipe){
	int i;
	for(i=index ; i < size ; i++){
		equipe.Joueurs[i] = equipe.Joueurs[i+1];
	}
	printf("le joueur est bien supprimer");
	return equipe ;
}
void AgeMoyenne(int size,struct Equipe equipe){
	int i;
	float moyenne = 0,somme = 0;
	for(i=0 ; i<size ; i++){
		somme += equipe.Joueurs[i].Age;
	}
	moyenne = somme / size;
	printf("age moyenne de ce equipe c est : %2.f",moyenne);
}
void JoueursParButs(int buts,int size,struct Equipe equipe){
	int i;
	for(i=0 ; i<size ; i++){
		if(equipe.Joueurs[i].Buts >= buts){
			AfficherJoueur(equipe.Joueurs[i]);
		}
	}
}
void MeilleurButeur(int size,struct Equipe equipe){
	int i;
	struct Joueur MeilleurButeur =equipe.Joueurs[0];
	for(i=0 ; i < size ; i++){
		if(equipe.Joueurs[i].Buts > MeilleurButeur.Buts){
			MeilleurButeur = equipe.Joueurs[i];
		}
	}
	AfficherJoueur(MeilleurButeur);
}

void PlusJeuneAge(int size,struct Equipe equipe){
	int i;
	struct Joueur plusJeune =equipe.Joueurs[0];
	struct Joueur plusAge =equipe.Joueurs[0];
	for(i=0 ; i<size ; i++){
		if(equipe.Joueurs[i].Age>plusAge.Age){
			plusAge = equipe.Joueurs[i];
		}
		if(equipe.Joueurs[i].Age<plusJeune.Age){
			plusJeune = equipe.Joueurs[i];
		}
		
	}
	printf("le joueur plus jeune cest : ");
	AfficherJoueur(plusJeune);
	printf("le joueur plus age cest   : ");
	AfficherJoueur(plusAge);
}
int Menu(){
	int operation;
	printf("\n===================== " GREEN "MENU PRINCIPAL" RESET " =====================\n");
	printf(" 1 - Ajouter un joueur\n");
	printf(" 2 - Modifier un joueur\n");
	printf(" 3 - Supprimer un joueur\n");
	printf(" 4 - Afficher les joueurs\n");
	printf(" 5 - Rechercher un joueur\n");
	printf(" 6 - Statistiques de l'équipe\n");
	printf(RED " 7 - Quitter le programme\n" RESET);
	printf("============================================================\n");
	printf("Entrez votre choix : ");
	scanf("%d",&operation);
	return operation;
}

int MenuModification(){
	int operationModification;
	printf("\n===== MODIFICATION DU JOUEUR =====\n");
	printf(" 1 - Modifier le poste du joueur\n");
	printf(" 2 - Modifier l'âge du joueur\n");
	printf(" 3 - Modifier les buts du joueur\n");
	printf(" 4 - Retour au menu principal\n");
	printf("==================================\n");
	printf("Votre choix : ");
	scanf("%d", &operationModification);
	return operationModification;
}


int main(){
	
	
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
		menuPrincipal :
		operationMenuPrincipal = Menu();
		switch(operationMenuPrincipal){
			// ajoute de joueur ou des joueur
			case 1:
				printf("    |========== AJOUTE DU JOUEUR =========|\n");
				printf("    |   1-Pour ajouter un joueur          |\n");
				printf("    |   2-Pour ajouter plusieurs joueurs  |\n");
				printf("    |   3-Pour retour a la menu principal |\n");
				printf("    |=====================================|\n");
				printf("     Votre choix : ");
				scanf("%d",&OperationAjout);
				switch(OperationAjout){
					case 1:
						AjouterJoueur(1,PositionAjout,equipe);
						PositionAjout+=1;
						sizeJoueurs+=1;
						goto menuPrincipal;
					case 2:
						printf("    Donner nombre du joueur vous vouler ajouter :");
						scanf("%d",&NombreJoueurAjout);
						AjouterJoueur(NombreJoueurAjout,PositionAjout,equipe);
						PositionAjout+=NombreJoueurAjout;
						sizeJoueurs+=NombreJoueurAjout;
						goto menuPrincipal;
					case 3:
						goto menuPrincipal;
					default :
						printf("choix ne pas correct");
						goto menuPrincipal;
				}
				break;
			// modification de joueur
			case 2:
				printf(" Donner le id de joueur que tu dois modifier : ");
				scanf("%d",&idRechercher);
				if(RechercheJoueurParId(idRechercher,sizeJoueurs,equipe) != -1){
					operationModification = MenuModification();
					switch(operationModification){
						case 1:
							printf("Donner le nouveau poste ");
							scanf("%s",&nouvellePoste);
							nouvelleEquipe = MoidifierPosteJoueurParId(idRechercher,nouvellePoste,sizeJoueurs,equipe);
							equipe = nouvelleEquipe;
							goto menuPrincipal;
						case 2:
							printf("Donner le nouveau age : ");
							scanf("%d",&nouvelleAge);
							nouvelleEquipe = MoidifierJoueurParId(idRechercher,nouvelleAge,1,sizeJoueurs,equipe);
							equipe = nouvelleEquipe;
							goto menuPrincipal;
						case 3:
							printf("Donner les nouveau buts : ");
							scanf("%d",&nouvelleButs);
							nouvelleEquipe= MoidifierJoueurParId(idRechercher,nouvelleButs,1,sizeJoueurs,equipe);
							equipe = nouvelleEquipe;
							goto menuPrincipal;
						case 4:
							goto menuPrincipal;
						default :
							printf("choix ne pas correct");
							goto menuPrincipal;
					}
						}else{
							printf("le joueur ne pas trouver");
						}
						break;
			// supprimer un joueur
			case 3:
				printf(" Donner le id de joueur que tu dois modifier : ");
				scanf("%d",&idRechercher);
				index = RechercheJoueurParId(idRechercher,sizeJoueurs,equipe);
				if(index != -1){
					printf(" vous vouler supprimer ce joueur (y/n) : ");
					scanf(" %c",&confirmationSupprestion);
					if(confirmationSupprestion == 'y' || confirmationSupprestion == 'Y'){
						nouvelleEquipe=SupprimerJoueur(index,sizeJoueurs,equipe);
						equipe = nouvelleEquipe;
						sizeJoueurs-=1;
						PositionAjout -=1;
					}
				}
				goto menuPrincipal;
				
			// Afficher les joueurs
			case 4:
				menuAffichage:
				printf("    |==========+ AFFICHAGE DU JOUEUR +=======|\n");
				printf("    |   1-Pour les joueur trier par le nom   |\n");
				printf("    |   2-Pour les joueur trier par l'age    |\n");
				printf("    |   3-Pour les joueur trier par le poste |\n");
				printf("    |   4-Pour retour a la menu principal    |\n");
				printf("    |========================================|\n");
				printf("     Votre choix : ");
				scanf("%d",&OperationAffichage);
				switch(OperationAffichage){
					case 1:
						AffichageTrier(1,sizeJoueurs,equipe.Joueurs);
						break;
					case 2:
						AffichageTrier(2,sizeJoueurs,equipe.Joueurs);
						break;
					case 3:
						menuTrierParPoste:
						printf("        |==========+ AFFICHAGE PAR POSTE ========|\n");
						printf("        |   1-Pour le poste (gardien)            |\n");
						printf("        |   2-Pour le poste (milieu)             |\n");
						printf("        |   3-Pour le poste (defenseur)          |\n");
						printf("        |   4-Pour le poste (attaquant)          |\n");
						printf("        |   5-Pour retour a menu affichage       |\n");
						printf("        |========================================|\n");
						printf("         Votre choix : ");
						scanf("%d",&operationTrier);
						switch(operationTrier){
							case 1:
								joueursParPoste(poste.gardien,sizeJoueurs,equipe);
								break;
							case 2:
								joueursParPoste(poste.milieu,sizeJoueurs,equipe);
								break;
							case 3:
								joueursParPoste(poste.defenseur,sizeJoueurs,equipe);
								break;
							case 4:
								joueursParPoste(poste.attaquant,sizeJoueurs,equipe);
								break;
							case 5:
								goto menuAffichage;
							default:
								printf("donner un nombre exist dans le sous menu");
								goto menuTrierParPoste;
						}
						break;
					default :
						printf("donner nombre de operation ajouter");
				}
				break;
			case 5:
				printf("    |==========+ RECHERCHE DU JOUEUR +=======|\n");
				printf("    |   1-Pour Rechrcher par le nom          |\n");
				printf("    |   2-Pour Rechercher par id             |\n");
				printf("    |   3-Pour Retour a menu principal       |\n");
				printf("    |========================================|\n");
				printf("     Votre choix : ");
				scanf("%d",&operationTypeRecherche);
				switch(operationTypeRecherche){
					case 1:
						printf("     Donner le Nom du joueur :");
						scanf("%s",&nomRechercher);
						index  = RechercheJoueurParNom(nomRechercher,sizeJoueurs,equipe);
						if( index != -1){
							AfficherJoueur(getJoueurByIndex(index,equipe.Joueurs));
						}else{
							printf("     le joueur ne pas trouver");
						}
						break;
					case 2:
						printf("     Donner le Id du joueur :");
						scanf("%d",&idRechercher);
						index = RechercheJoueurParId(idRechercher,sizeJoueurs,equipe);
						if( index != -1){
							AfficherJoueur(getJoueurByIndex(index,equipe.Joueurs));
						}else{
							printf("Donner le Nom du joueur :le joueur ne pas trouver");
						}
						break;
					case 3:
						break;
					default :
						printf("donner nombre de operation ajouter");
				}
				break;
			// les statistique de equipe
			case 6 :
				printf(" 1-Pour afficher le nombre total de joueurs dans l’equipe\n");
				printf(" 2-Pour afficher age moyen des joueurs.\n");
				printf(" 3-Pour afficher les joueurs ayant marque plus de X buts\n");
				printf(" 4-Pour afficher le meilleur buteur\n");
				printf(" 5-Pour afficher le joueur le plus jeune et le plus age\n");
				printf(" Entrez le numero d'operation :");
				scanf("%d",&OperationAffichage);
				switch(OperationAffichage){
					case 1:
						printf("le nombre total de ce equipe c est : %d",sizeJoueurs);
						break;
					case 2:
						AgeMoyenne(sizeJoueurs,equipe);
						break;
					case 3:
						printf("donner le nombre de buts :");
						scanf("%d",&buts);
						JoueursParButs(buts,sizeJoueurs,equipe);
						break;
					case 4:
						MeilleurButeur(sizeJoueurs,equipe);
						break;
					case 5:
						PlusJeuneAge(sizeJoueurs,equipe);
						break;
					default :
						printf("donner nombre exist dans le sous menu !!");
				}
				break;
				
				// Quitter le programme
			case 7:
				repetition = false;
				break;
		}
	return 0;
}
