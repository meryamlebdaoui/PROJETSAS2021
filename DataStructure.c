#include "DataStructure.h"

//////////////////////////////////////////////////////////

BankAcc FillAccount()
{
	BankAcc A;
	
	printf("===============================");
	printf("CREATION D'UN COMPTE BANCAIRE :");
	printf("===============================");
	
	printf("\nEntrez votre CIN : ");
	scanf("%s",A.CIN);
	
	printf("Entrez votre Nom : ");
	scanf("%s",A.Nom);
	
	printf("Entrez votre Prenom :");
	scanf("%s",A.Prenom);
	
	printf("Entrez votre montant initial : ");
	scanf("%f",&A.Montant);
	
	return A;
}

//////////////////////////////////////////////////////////

BankAcc FillAccountWith(char CIN[10],char Nom[10],char Prenom[10],float Montant)
{
	BankAcc A;
	
	strcpy(A.CIN,CIN);
	strcpy(A.Prenom,Prenom);
	strcpy(A.Nom,Nom);
	A.Montant=Montant;
	
	return A;
}

//////////////////////////////////////////////////////////

void AfficherBankAcc(BankAcc A)
{
	printf("\n------------------------------------------\n");
	printf("CIN     : %s \n",A.CIN);
	printf("Nom     : %s \n",A.Nom);
	printf("Prenom  : %s \n",A.Prenom);
	printf("Montant : %f\n",A.Montant);
	printf("------------------------------------------\n");
}

//////////////////////////////////////////////////////////

void Retrait(BankAcc *A,float montant)
{
	if(A->Montant<montant)
	{
		printf("\nSolde Insuffisant!!");
	}
	else
	{
		A->Montant-=montant;
		printf("\nVous avez retire %f",montant);
	}
}

//////////////////////////////////////////////////////////

void Depot(BankAcc *A,float montant)
{
	if(montant>0)
	{
		printf("\nVous avez depose %f",montant);
		A->Montant+=montant;
	}
}
//////////////////////////////////////////////////////////

Bank* creeBank()
{
	return NULL;
}

//////////////////////////////////////////////////////////

void AddAccount(Bank **B,BankAcc A)
{
	if((*B)==NULL)
	{	
		Bank *n=(Bank*)malloc(sizeof(Bank));
		n->A=A;
		n->next=NULL;
		*B=n;
	}
	else
	{
		AddAccount(&(*B)->next,A);
	}
	
}

//////////////////////////////////////////////////////////

void AddWithMontant(Bank **B,BankAcc A)
{
	Bank *n;
	
	if(*B==NULL)
	{
		n=(Bank*)malloc(sizeof(Bank));
		n->A=A;
		n->next=NULL;
		*B=n;
	}
	else if((*B)->A.Montant<A.Montant)
	{
		n=(Bank*)malloc(sizeof(Bank));
		n->A=A;
		n->next=*B;
		*B=n;
	}
	else
	{
		AddWithMontant(&(*B)->next,A);
	}
}

//////////////////////////////////////////////////////////

Bank* TrieBank(Bank *B,float montant)
{
	Bank *R=creeBank();
	
	while(B)
	{
		if(B->A.Montant>montant)
		{
			AddWithMontant(&R,B->A);
		}
		B=B->next;
	}
	
	return R;
}

//////////////////////////////////////////////////////////

void Afficher(Bank *B)
{
	if(B)
	{
		AfficherBankAcc(B->A);
		Afficher(B->next);
	}
}

//////////////////////////////////////////////////////////

void AfficherInverse(Bank *B)
{
	if(B)
	{
		AfficherInverse(B->next);
		AfficherBankAcc(B->A);
	}
}

//////////////////////////////////////////////////////////

int DisplayAccID(Bank *B,char CIN[10])
{
	while(B)
	{
		if(strcmp(B->A.CIN,CIN)==0)
		{
			AfficherBankAcc(B->A);
			return 1;
		}
		B=B->next;
	}
	printf("\nCe Compte n'existe pas !");
	return 0;
}

//////////////////////////////////////////////////////////

void FindTopTree(char i[10],char j[10],char z[10],Bank *B)
{
	B=TrieBank(B,0);
	
	if(B!=NULL)
	{
		strcpy(i,B->A.CIN);
		if(B->next!=NULL)
		{
			strcpy(j,B->next->A.CIN);
			if(B->next->next!=NULL)
			{
				strcpy(z,B->next->next->A.CIN);
			}
		}
	}
	
}

//////////////////////////////////////////////////////////

void Fidialise(Bank **B)
{
	char i[10],j[10],z[10];
	
	FindTopTree(i,j,z,*B);
	
	Bank *tmp=*B;
	
	while(tmp!=NULL)
	{
		if(strcmp(i,tmp->A.CIN)==0 || strcmp(j,tmp->A.CIN)==0 || strcmp(z,tmp->A.CIN)==0)
		{
			(*B)->A.Montant*=1.3;
		}
		tmp=tmp->next;
	}
}

//////////////////////////////////////////////////////////

void AddWithLexi(Bank **B,BankAcc A)
{
	Bank *n;
	
	if(*B==NULL)
	{
		n=(Bank*)malloc(sizeof(Bank));
		n->A=A;
		n->next=NULL;
		*B=n;
	}
	else if(strcmp((*B)->A.Nom,A.Nom)==-1)
	{
		n=(Bank*)malloc(sizeof(Bank));
		n->A=A;
		n->next=*B;
		*B=n;
	}
	else
	{
		AddWithLexi(&((*B)->next),A);
	}
}

//////////////////////////////////////////////////////////

Bank* TrieBankLEXICAL(Bank *B)
{
	Bank *R=creeBank();
	
	while(B!=NULL)
	{
		AddWithLexi(&R,B->A);
		B=B->next;
	}
	
	return R;
}

//////////////////////////////////////////////////////////

int Deposer(Bank **B,char CIN[10],float m)
{
	Bank *tmp=*B;
	
	while(tmp)
	{
		if(strcmp(tmp->A.CIN,CIN)==0)
		{
			Depot(&tmp->A,m);
			return 1;
		}
		tmp=tmp->next;
	}
	printf("Compte non disponible !\n");
	return 0;
}

int Retraiter(Bank **B,char CIN[10],float m)
{
	Bank *tmp=*B;
	
	while(tmp)
	{
		if(strcmp(tmp->A.CIN,CIN)==0)
		{
			Retrait(&tmp->A,m);
			return 1;
		}
		tmp=tmp->next;
	}
	printf("Compte non disponible !\n");
	return 0;
}

//////////////////////////////////////////////////////////

void SupprimerAcc(Bank **B,char CIN[10])
{
	if(*B!=NULL)
	{
		if(strcmp((*B)->A.CIN,CIN)==0)
		{
			Bank *tmp=*B;
			*B=(*B)->next;
			free(tmp);
			printf("\nLe compte est supprime avec Succee !\n");
		}
		else
		{
			SupprimerAcc(&(*B)->next,CIN);
		}
	}

}

//////////////////////////////////////////////////////////

void SupprimerTous(Bank **B)
{
	Bank *tmp;
	
	while(*B)
	{
		tmp=*B;
		*B=(*B)->next;
		free(tmp);
	}
	*B=NULL;
}

//////////////////////////////////////////////////////////
