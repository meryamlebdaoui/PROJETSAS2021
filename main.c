#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "DataStructure.c"
#include "Stockage.c"

void Espace()
{
	int i;for(i=0;i<100;i++){printf("\n");}
}

void mini_Espace()
{
	int i;for(i=0;i<10;i++){printf("\n");}
}


int main()
{
	Bank *B=creeBank();
	BankAcc A;
	
	B=Load();
	int choix,choixo;
	
	printf("-------------------------------------------\n");
	printf("CE PROGRAMME PERMET LA GESTION D'UNE BANQUE\n");
	printf("-------------------------------------------\n");
	
	do
	{
		mini_Espace();
		printf("\n==== MENU ====\n");
		
		printf("\n1)-Creer un(des) compte(s) bancaire(s)\n");
		printf("2)-Depot\n");
		printf("3)-Retrait\n");
		printf("4)-Affichage\n");
		printf("5)-Recherche\n");
		printf("6)-Fidelisation\n");
		printf("7)-Supprimer un compte\n");
		printf("8)-Supprimer tous les comptes\n");
		printf("0)-Quitter et Sauvegarder\n");
		
		printf("\nEntrez votre choix : ");
		scanf("%d",&choix);
		
		switch (choix)
		{
			case 1:
				Espace();
				A=FillAccount();
				AddAccount(&B,A);
				break;
			case 2:
				Espace();
				printf("Donnez le CIN de compte : ");
				scanf("%s",A.CIN);
				printf("Donnez le montant : ");
				scanf("%f",&A.Montant);
				Deposer(&B,A.CIN,A.Montant);
				break;
			case 3:
				Espace();
				printf("Donnez le CIN de compte : ");
				scanf("%s",A.CIN);
				printf("Donnez le montant : ");
				scanf("%f",&A.Montant);
				Retraiter(&B,A.CIN,A.Montant);	
				break;
			case 4:
				Espace();
				printf("\n==== OPTION ====\n");
				printf("\n1)-Ordre Accendant  (Date de creation)\n");
				printf("2)-Ordre Descendant (Date de creation)\n");
				printf("3)-Ordre Accendant  (Lexical des Noms)\n");
				printf("4)-Ordre Descendant (Lexical des Noms)\n");
				printf("5)-Ordre Accendant  (Montant)\n");
				printf("6)-Ordre Descendant (Montant)\n");
				
				printf("\nEntrez une option : ");
				scanf("%d",&choixo);
				
				Espace();
				
				switch (choixo)
				{
					case 1:Afficher(B);break;
					case 2:AfficherInverse(B);break;
					case 3:Afficher(TrieBankLEXICAL(B));break;
					case 4:AfficherInverse(TrieBankLEXICAL(B));break;
					case 5:printf("Donnez le montant minimal : ");scanf("%f",&A.Montant);Afficher(TrieBank(B,A.Montant));break;
					case 6:printf("Donnez le montant minimal : ");scanf("%f",&A.Montant);AfficherInverse(TrieBank(B,A.Montant));break;
					default:printf("Option non disponible !!\n");break;
				}
				
				printf("\n\nCliquer sur le clavier pour continuer...");
				_getch();
				_getch();
				
				break;
			case 5:
				Espace();
				printf("Donnez le CIN de compte : ");
				scanf("%s",A.CIN);
				DisplayAccID(B,A.CIN);
				break;
			case 6:
				Espace();
				Fidialise(&B);
				mini_Espace();
				printf("Les Comptes sont fidialises (TOP 3) !\n");
				break;
			case 7:
				Espace();
				printf("Donnez le CIN de compte : ");
				scanf("%s",A.CIN);
				SupprimerAcc(&B,A.CIN);
				break;
			case 8:
				Espace();
				SupprimerTous(&B);
				mini_Espace();
				printf("\nTous les comptes sont supprimes !");
				break;
			case 0:mini_Espace();printf("Au revoir :) !\n");mini_Espace();break;
			default : printf("Erreur : Choix Errone !\n"); break;
		}
		
	}while(choix!=0);

	Save(B);
	
	return 0;
}
