#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define RED   "\x1b[31m" 
#define RESET   "\x1b[0m"
#define GREEN   "\x1b[32m"

int idIncrement = 16;
int sizeEquipeTrier = 0;
struct Poste{
	char gardien[100];
	char defenseur[100]; 
	char milieu[100];
	char attaquant[100];
};
struct Status{
	char titulaire[100];
	char remplacant[100];
};
struct Status status = {"titulaire","remplacant"};
struct Poste poste = {"gardien","defenseur","milieu","attaquant"};

struct Joueur {
	int Id;
	char Nom[100];
	char Prenom[100];
	int NumeroMaillot;
	char Poste[100];
	int Age ;
	int Buts;
	char Statu[100];
};
struct Equipe {
	struct Joueur Joueurs[100];
};
int validEnter(char entryStr[],char erreurEntry[]){
	bool isValid = true;
	int operation;
	while(isValid){
			printf("\t%s",entryStr);
			if(scanf("%d",&operation)==0){
				printf(RED"\t%s"RESET,erreurEntry);
				fflush(stdin);
			}else{
				isValid = false;
			}
	}
}
void AfficherJoueur(struct Joueur joueur){
	if(joueur.Buts >= 10){
		printf(GREEN "  ID : %-3d | Nom : %-8s | Prenom : %-8s | Maillot : %-3d | Poste : %-9s    | Age : %-2d | Buts : %-2d | Staus : %-8s  (Star de l equipe)\n" RESET,
			joueur.Id, joueur.Nom, joueur.Prenom, joueur.NumeroMaillot, joueur.Poste, joueur.Age, joueur.Buts,joueur.Statu);
	}else{
		printf("  ID : %-3d | Nom : %-8s | Prenom : %-8s | Maillot : %-3d | Poste : %-9s    | Age : %-2d | Buts : %-2d | Staus : %-8s\n",
			joueur.Id, joueur.Nom, joueur.Prenom, joueur.NumeroMaillot, joueur.Poste, joueur.Age,joueur.Buts ,joueur.Statu);
	}
}
struct Equipe AjouterJoueur(int nombreJoueursAjouter,int index, struct Equipe equipe){
	struct Joueur joueur;
	bool numeroMailotJ=true,ageJ=true,posteJ=true,butsJ=true,statu=true;
	int i;
	int operationPoste,operationStatu;
	for(i = 1; i <= nombreJoueursAjouter ;i++ ){
		joueur.Id = idIncrement ;
		idIncrement+=1;
		printf("\tDonner le nom de Joueur :");
		scanf("%s",&joueur.Nom);
		printf("\tDonner le prenom de Joueur :");
		scanf("%s",&joueur.Prenom);
		while(numeroMailotJ){
			printf("\tDonner le nemero maillot de Joueur :");
			if(scanf("%d",&joueur.NumeroMaillot)==0){
				printf(RED"\tle numero de mailot ne pas correct(donner un entier)\n"RESET);
				fflush(stdin);
			}else{
				numeroMailotJ = false;
			}
		}
		while(posteJ){
			printf("\tDonner le poste de Joueur(1-gardien||2-défenseur||3-milieu||4-attaquant) :");
			if(scanf("%d",&operationPoste)==1){
				posteJ = false;
				switch(operationPoste){
					case 1:strcpy(joueur.Poste,poste.gardien);break;
					case 2:strcpy(joueur.Poste,poste.defenseur) ;break;
					case 3:strcpy(joueur.Poste,poste.milieu) ;break;
					case 4:strcpy(joueur.Poste,poste.attaquant) ;break;
					default :printf(RED"\tle nombre entrer ne pas correcte\n"RESET);
						posteJ = true;
				}
			}else{
				printf(RED"\tle poste ne pas correct(donner un entier)\n"RESET);
				fflush(stdin);
			}
		}
		
		while(numeroMailotJ){
			printf("\tDonner age de Joueur :");
			if(scanf("%d",&joueur.Age)==0){
				printf(RED"\tage ne pas correct(donner un entier)\n"RESET);
				fflush(stdin);
			}else{
				ageJ = false;
			}
		}
		while(ageJ){
			printf("\tDonner age de Joueur :");
			if(scanf("%d",&joueur.Age)==0){
				printf(RED"\tage ne pas correct(donner un entier)\n"RESET);
				fflush(stdin);
			}else{
				ageJ = false;
			}
		}
		while(butsJ){
			printf("\tDonner buts de Joueur :");
			if(scanf("%d",&joueur.Buts)==0){
				printf(RED"\tles buts ne pas correct(donner un entier)\n"RESET);
				fflush(stdin);
			}else{
				butsJ = false;
			}
		}
		while(statu){
			printf("\tDonner le status de joueur( 1-titulaire || 2-remplacant ) :");;
			if(scanf("%d",&operationStatu)==1){
				statu=false;
				switch(operationStatu){
					case 1:strcpy(joueur.Statu,status.titulaire);break;
					case 2:strcpy(joueur.Statu,status.remplacant) ;break;
					default :printf(RED"\tle nombre entrer ne pas correcte\n"RESET);
						statu=true;
				}
			}else{
				printf(RED"	les buts ne pas correct(donner un entier)\n"RESET);
				fflush(stdin);
			}
		}
		numeroMailotJ=true;
		ageJ=true;
		posteJ=true;
		butsJ=true;
		statu=true;
		equipe.Joueurs[index] = joueur;
		index +=1;
	}
	if(nombreJoueursAjouter == 1){
		printf(GREEN"\n\t======================Le joueur est bien ajouter========================="RESET);
	}else{
		printf(GREEN"\n\tTous les joueur est bien ajouter !! :"RESET);
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
	}else if (Trier == 2){
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
		joueurs = joueurs;
	}
	for(i = 0 ; i < size ;i++){
		AfficherJoueur(joueurs[i]);
	}
}

struct Equipe joueursParPoste2(char poste[],int size,struct Equipe equipe){
	int i,cmpAjout=0;
	struct Equipe NouvelleEquipe;
	for(i = 0 ; i < size ;i++){
		if(strcmp(equipe.Joueurs[i].Poste,poste) == 0){
			NouvelleEquipe.Joueurs[cmpAjout] = equipe.Joueurs[i];
			cmpAjout+=1;
			sizeEquipeTrier+=1;
		}
	}
	return NouvelleEquipe;
}

char* toLowerCase(char str[]){
	int i,size = strlen(str);
	for(i = 0;i <size;i++){
		str[i] = tolower(str[i]);
	}
	return str;
}

int RechercheJoueurParNom(char nomRechercher[100],int size,struct Equipe equipe){
	int i;
	for(i = 0 ; i < size ;i++){
		if(strcmp(toLowerCase(nomRechercher),toLowerCase(equipe.Joueurs[i].Nom))==0){
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
	printf(GREEN"	le poste de joueur et bien modifier !!"RESET);
	return equipe;
}

struct Equipe MoidifierJoueurParId(int id,int nouvelleValeur,int Modifieur,int size,struct Equipe equipe){
	int index = RechercheJoueurParId(id,size,equipe);
	struct Joueur joueur = getJoueurByIndex(index,equipe.Joueurs);
	if(Modifieur == 1){
		joueur.Age=nouvelleValeur;
		equipe.Joueurs[index] = joueur;
		printf(GREEN"	l'age de joueur et bien modifier !!"RESET);
	}else{
		joueur.Buts=nouvelleValeur;
		equipe.Joueurs[index] = joueur;
		printf(GREEN"	les buts de joueur et bien modifier !!"RESET);
	}
	return equipe;
}

struct Equipe SupprimerJoueur(int index,int size,struct Equipe equipe){
	int i;
	for(i=index ; i < size ; i++){
		equipe.Joueurs[i] = equipe.Joueurs[i+1];
	}
	printf(GREEN"	le joueur est bien supprimer"RESET);
	return equipe ;
}
void AgeMoyenne(int size,struct Equipe equipe){
	int i;
	float moyenne = 0,somme = 0;
	for(i=0 ; i<size ; i++){
		somme += equipe.Joueurs[i].Age;
	}
	moyenne = somme / size;
	printf("age moyenne de ce equipe c est : %2.f\n",moyenne);
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
	printf(" 6 - Statistiques de l equipe\n");
	printf(RED " 7 - Quitter le programme\n" RESET);
	printf("============================================================\n");
	printf(GREEN"Entrez votre choix : "RESET);
	scanf("%d",&operation);
	return operation;
}

int MenuModification(){
	int operationModification;
	printf("    |====== "GREEN"MODIFICATION DU JOUEUR"RESET" =======|\n");
	printf("    |   1-Modifier le poste du joueur     |\n");
	printf("    |   2-Modifier l'age du joueur        |\n");
	printf("    |   3-Modifier les buts du joueur     |\n");
	printf("    |   4-Retour au menu principal        |\n");
	printf("    |=====================================|\n");
	printf(GREEN"     Votre choix : "RESET);
	scanf("%d", &operationModification);
	return operationModification;
}
int MenuPosteTrier(){
	int operation;
	printf("                |======="GREEN" AFFICHAGE DU POSTES TRIER"RESET" ======|\n");
	printf("                |   1-Trier par age                      |\n");
	printf("                |   2-Trier par ordre alphabetique       |\n");
	printf("                |   3-Pour retour a menu affichage       |\n");
	printf("                |   4-Pour retour a menu principal       |\n");
	printf("                |========================================|\n");
	printf(GREEN"                 Votre choix : "RESET);
	scanf("%d",&operation);
	return operation;
}

int main(){
	struct Equipe equipe;
	struct Equipe nouvelleEquipe;
	int i,PositionAjout = 0,NombreJoueurAjout;
	int operationMenuPrincipal;
	bool repetition = true;
	int sizeJoueurs = 15;
	int OperationAjout,operationModification,operationTypeRecherche,operationTrier,operationTrier2,OperationAffichage,operationPoste;
	char nomRechercher[100],nouvellePoste[100];
	int idRechercher,nouvelleAge,nouvelleButs,index,buts;
	char confirmationSupprestion;
	bool posteJ=true;
	
	struct Joueur j1 = {1, "Benzema", "Karim", 9, "attaquant", 35, 22, "titulaire"};
	struct Joueur j2 = {2, "Mbappe", "Kylian", 7, "attaquant", 26, 30, "titulaire"};
	struct Joueur j3 = {3, "Kante", "NGolo", 13, "milieu", 32, 3, "titulaire"};
	struct Joueur j4 = {4, "Varane", "Raphael", 4, "defenseur", 31, 2, "titulaire"};
	struct Joueur j5 = {5, "Lloris", "Hugo", 1, "gardien", 37, 0, "titulaire"};
	struct Joueur j6 = {6, "Pavard", "Benjamin", 2, "defenseur", 29, 1, "remplacant"};
	struct Joueur j7 = {7, "Grizman", "Antoine", 8, "milieu", 34, 18, "titulaire"};
	struct Joueur j8 = {8, "Camavng", "Eduardo", 6, "milieu", 22, 4, "remplacant"};
	struct Joueur j9 = {9, "Kimpemb", "Presnel", 3, "defenseur", 30, 0, "remplacant"};
	struct Joueur j10 = {10, "Areola", "Alphonse", 16, "gardien", 32, 0, "remplacant"};
	struct Joueur j11 = {11, "Theo", "Hernandz", 22, "defenseur", 27, 5, "titulaire"};
	struct Joueur j12 = {12, "Giroud", "Olivier", 18, "attaquant", 38, 21, "remplacant"};
	struct Joueur j13 = {13,"Tchomin", "Aurelien", 14, "milieu", 25, 3, "titulaire"};
	struct Joueur j14 = {14, "Coman", "Kingsley", 11, "attaquant", 29, 12, "remplacant"};
	struct Joueur j15 = {15, "Maigan", "Mike", 23, "gardien", 30, 0, "titulaire"};

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
	equipe.Joueurs[PositionAjout] = j6;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j7;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j8;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j9;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j10;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j11;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j12;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j13;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j14;
	PositionAjout+=1;
	equipe.Joueurs[PositionAjout] = j15;
	PositionAjout+=1;
		menuPrincipal :
		operationMenuPrincipal = Menu();
		switch(operationMenuPrincipal){
			//============================================================= ajoute de joueur ou des joueur==============================================================
			case 1:
				printf("    |=========="GREEN" AJOUTE DU JOUEUR "RESET"=========|\n");
				printf("    |   1-Pour ajouter un joueur          |\n");
				printf("    |   2-Pour ajouter plusieurs joueurs  |\n");
				printf("    |   3-Pour retour a la menu principal |\n");
				printf("    |=====================================|\n");
				printf(GREEN"     Votre choix : "RESET);
				scanf("%d",&OperationAjout);
				switch(OperationAjout){
					case 1:
						nouvelleEquipe= AjouterJoueur(1,PositionAjout,equipe);
						equipe = nouvelleEquipe;
						PositionAjout+=1;
						sizeJoueurs+=1;
						goto menuPrincipal;
					case 2:
						printf("    Donner nombre du joueur vous vouler ajouter :");
						scanf("%d",&NombreJoueurAjout);
						nouvelleEquipe = AjouterJoueur(NombreJoueurAjout,PositionAjout,equipe);
						equipe = nouvelleEquipe;
						PositionAjout+=NombreJoueurAjout;
						sizeJoueurs+=NombreJoueurAjout;
						goto menuPrincipal;
					case 3:
						goto menuPrincipal;
					default :
						printf(RED"choix ne pas correct"RESET);
						goto menuPrincipal;
				}
				break;
			// ========================================================================modification de joueur====================================================================
			case 2:
				printf("    Donner le id de joueur que tu dois modifier : ");
				scanf("%d",&idRechercher);
				if(RechercheJoueurParId(idRechercher,sizeJoueurs,equipe) != -1){
					menuModification:
					operationModification = MenuModification();
					switch(operationModification){
						case 1:
							while(posteJ){
								printf("\tDonner le poste de Joueur(1-gardien||2-defenseur||3-milieu||4-attaquant) :");
								if(scanf("%d",&operationPoste)==1){
									posteJ = false;
									switch(operationPoste){
										case 1:strcpy(nouvellePoste,poste.gardien);break;
										case 2:strcpy(nouvellePoste,poste.defenseur) ;break;
										case 3:strcpy(nouvellePoste,poste.milieu) ;break;
										case 4:strcpy(nouvellePoste,poste.attaquant) ;break;
										default :printf(RED"\tle nombre entrer ne pas correcte\n"RESET);
											posteJ = true;
									}
								}else{
									printf(RED"\tle poste ne pas correct(donner un entier)\n"RESET);
									fflush(stdin);
								}
							}
							nouvelleEquipe = MoidifierPosteJoueurParId(idRechercher,nouvellePoste,sizeJoueurs,equipe);
							equipe = nouvelleEquipe;
							goto menuModification;
						case 2:
							printf("Donner le nouveau age : ");
							scanf("%d",&nouvelleAge);
							nouvelleEquipe = MoidifierJoueurParId(idRechercher,nouvelleAge,1,sizeJoueurs,equipe);
							equipe = nouvelleEquipe;
							goto menuPrincipal;
						case 3:
							printf("Donner les nouveau buts : ");
							scanf("%d",&nouvelleButs);
							nouvelleEquipe= MoidifierJoueurParId(idRechercher,nouvelleButs,2,sizeJoueurs,equipe);
							equipe = nouvelleEquipe;
							goto menuPrincipal;
						case 4:
							goto menuPrincipal;
						default :
							printf(RED"choix ne pas correct"RESET);
							goto menuModification;
					}
						}else{
							printf(RED"le joueur ne pas trouver"RESET);
						}
						break;
			// ========================================================================supprimer un joueur=====================================================================
			case 3:
				printf(" Donner le id de joueur que tu dois modifier : ");
				scanf("%d",&idRechercher);
				index = RechercheJoueurParId(idRechercher,sizeJoueurs,equipe);
				if(index != -1){
					printf(RED" vous vouler supprimer ce joueur (y/n) : "RESET);
					scanf(" %c",&confirmationSupprestion);
					if(confirmationSupprestion == 'y' || confirmationSupprestion == 'Y'){
						nouvelleEquipe=SupprimerJoueur(index,sizeJoueurs,equipe);
						equipe = nouvelleEquipe;
						sizeJoueurs-=1;
						PositionAjout -=1;
					}
				}
				goto menuPrincipal;
				
			// ==========================================================================Afficher les joueurs=================================================================
			case 4:
				menuAffichage:
				printf("    |==========+ AFFICHAGE DU JOUEUR +=======|\n");
				printf("    |   1-Afficher tous les joueurs          |\n");
				printf("    |   2-Pour les joueur trier par le nom   |\n");
				printf("    |   3-Pour les joueur trier par l'age    |\n");
				printf("    |   4-Pour les joueur trier par le poste |\n");
				printf("    |   5-Pour retour a la menu principal    |\n");
				printf("    |========================================|\n");
				printf(GREEN"     Votre choix : "RESET);
				scanf("%d",&OperationAffichage);
				switch(OperationAffichage){
					case 1:
						AffichageTrier(3,sizeJoueurs,equipe.Joueurs);
						goto menuPrincipal;
					case 2:
						AffichageTrier(1,sizeJoueurs,equipe.Joueurs);
						goto menuPrincipal;
					case 3:
						AffichageTrier(2,sizeJoueurs,equipe.Joueurs);
						goto menuPrincipal;
					case 4:
						menuTrierParPoste:
						printf("        |==========+ AFFICHAGE PAR POSTE ========|\n");
						printf("        |   1-Pour le poste (gardien)            |\n");
						printf("        |   2-Pour le poste (milieu)             |\n");
						printf("        |   3-Pour le poste (defenseur)          |\n");
						printf("        |   4-Pour le poste (attaquant)          |\n");
						printf("        |   5-Pour retour a menu affichage       |\n");
						printf("        |   6-Pour retour a menu principal       |\n");
						printf("        |========================================|\n");
						printf(GREEN"         Votre choix : "RESET);
						scanf("%d",&operationTrier);
						switch(operationTrier){
							case 1:
								menuPosteTrierGardien:
								operationTrier2=MenuPosteTrier();//afficher le menu de poste trier
								switch(operationTrier2){
									case 1:
										nouvelleEquipe=joueursParPoste2(poste.gardien,sizeJoueurs,equipe);
										AffichageTrier(2,sizeEquipeTrier,nouvelleEquipe.Joueurs);
										sizeEquipeTrier = 0;
										goto menuPrincipal;
									case 2:
										nouvelleEquipe=joueursParPoste2(poste.gardien,sizeJoueurs,equipe);
										AffichageTrier(1,sizeEquipeTrier,nouvelleEquipe.Joueurs);
										sizeEquipeTrier = 0;
										goto menuPrincipal;
									case 3:
										goto menuTrierParPoste;
									case 4:
										goto menuPrincipal;
									default:
										printf("le choix ne pas correcte (retour a la derniere menu)");
										goto menuPosteTrierGardien;
								}
							case 2:
								menuPosteTrierMilieu:
								operationTrier2=MenuPosteTrier();
								switch(operationTrier2){
									case 1:
										nouvelleEquipe=joueursParPoste2(poste.milieu,sizeJoueurs,equipe);
										AffichageTrier(2,sizeEquipeTrier,nouvelleEquipe.Joueurs);
										sizeEquipeTrier = 0;
										goto menuPrincipal;
									case 2:
										nouvelleEquipe=joueursParPoste2(poste.milieu,sizeJoueurs,equipe);
										AffichageTrier(1,sizeEquipeTrier,nouvelleEquipe.Joueurs);
										sizeEquipeTrier = 0;
										goto menuPrincipal;
									case 3:
										goto menuTrierParPoste;
									case 4:
										goto menuPrincipal;
									default:
										printf("le choix ne pas correcte (retour a la derniere menu)");
										goto menuPosteTrierMilieu;
								}
							case 3:
								menuPosteTrierDefenseur:
									operationTrier2=MenuPosteTrier();
									switch(operationTrier2){
										case 1:
											nouvelleEquipe=joueursParPoste2(poste.defenseur,sizeJoueurs,equipe);
											AffichageTrier(2,sizeEquipeTrier,nouvelleEquipe.Joueurs);
											sizeEquipeTrier = 0;
											goto menuPrincipal;
										case 2:
											nouvelleEquipe=joueursParPoste2(poste.defenseur,sizeJoueurs,equipe);
											AffichageTrier(1,sizeEquipeTrier,nouvelleEquipe.Joueurs);
											sizeEquipeTrier = 0;
											goto menuPrincipal;
										case 3:
											goto menuTrierParPoste;
										case 4:
											goto menuPrincipal;
										default:
											printf("le choix ne pas correcte (retour a la derniere menu)");
											goto menuPosteTrierDefenseur;
									}
							case 4:
								menuPosteTrierAttaquant:
								operationTrier2=MenuPosteTrier();
								switch(operationTrier2){
									case 1:
										nouvelleEquipe=joueursParPoste2(poste.attaquant,sizeJoueurs,equipe);
										AffichageTrier(2,sizeEquipeTrier,nouvelleEquipe.Joueurs);
										sizeEquipeTrier = 0;
										goto menuPrincipal;
									case 2:
										nouvelleEquipe=joueursParPoste2(poste.attaquant,sizeJoueurs,equipe);
										AffichageTrier(1,sizeEquipeTrier,nouvelleEquipe.Joueurs);
										sizeEquipeTrier = 0;
										goto menuPrincipal;
									case 3:
										goto menuTrierParPoste;
									case 4:
										goto menuPrincipal;
									default:
										printf("le choix ne pas correcte (retour a la derniere menu)");
										goto menuPosteTrierAttaquant;
								}
							case 5:
								goto menuAffichage;
							case 6:
								goto menuPrincipal;
							default:
								printf("donner un nombre exist dans le sous menu");
								goto menuTrierParPoste;
							}
						case 5:
							goto menuPrincipal;
							
					default :
						printf("le choix ne pas trouver");
						goto menuTrierParPoste;
				}
			//======================================================================Recherche un joueur =========================================================================
			case 5:
				menuRecherche:
				printf("    |==========+ RECHERCHE DU JOUEUR +=======|\n");
				printf("    |   1-Pour Rechrcher par le nom          |\n");
				printf("    |   2-Pour Rechercher par id             |\n");
				printf("    |   3-Pour Retour a menu principal       |\n");
				printf("    |========================================|\n");
				printf(GREEN"     Votre choix : "RESET);
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
						goto menuPrincipal;
					case 2:
						printf("     Donner le Id du joueur :");
						scanf("%d",&idRechercher);
						index = RechercheJoueurParId(idRechercher,sizeJoueurs,equipe);
						if( index != -1){
							AfficherJoueur(getJoueurByIndex(index,equipe.Joueurs));
						}else{
							printf("Donner le Nom du joueur :le joueur ne pas trouver");
						}
						goto menuPrincipal;
					case 3:
						goto menuPrincipal;
					default :
						printf(RED"le choix ne pas trouver\n"RESET);
						goto menuRecherche;
				}
				goto menuPrincipal;
			// ===================================================================les statistique de equipe==========================================================================
			case 6 :
				menuStatistique:
				printf("    |=================+ STATISTIQUES DU JOUEURS +====================|\n");
				printf("    |   1-Pour afficher le nombre total de joueurs dans l’equipe     |\n");
				printf("    |   2-Pour afficher age moyen des joueurs                        |\n");
				printf("    |   3-Pour afficher les joueurs ayant marque plus de X buts      |\n");
				printf("    |   4-Pour afficher le meilleur buteur                           |\n");
				printf("    |   5-Pour afficher le joueur le plus jeune et le plus age       |\n");
				printf("    |   6--Pour Retour a menu principal                              |\n");
				printf("    |================================================================|\n");
				printf(GREEN"     Votre choix : "RESET);
				scanf("%d",&OperationAffichage);
				switch(OperationAffichage){
					case 1:
						printf("le nombre total de ce equipe c est : %d\n",sizeJoueurs);
						goto menuStatistique;
					case 2:
						AgeMoyenne(sizeJoueurs,equipe);
						goto menuStatistique;
					case 3:
						printf("donner le nombre de buts :");
						scanf("%d",&buts);
						JoueursParButs(buts,sizeJoueurs,equipe);
						goto menuStatistique;
					case 4:
						MeilleurButeur(sizeJoueurs,equipe);
						goto menuStatistique;
					case 5:
						PlusJeuneAge(sizeJoueurs,equipe);
						goto menuStatistique;
					case 6:
						goto menuPrincipal;
					default :
						printf(RED"le choix ne pas trouver\n"RESET);
						goto menuStatistique;
				}
				
				// ===================================================================Quitter le programme=================================================================
			case 7:
				printf("au revoir");
				break;
		}
	return 0;
}
