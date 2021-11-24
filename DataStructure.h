#pragma once

typedef struct y
{
	char CIN[10];
	char Nom[50];
	char Prenom[50];
	float Montant;
	
}BankAcc;

typedef struct x
{
	BankAcc A;
	struct x *next;
}Bank;


//BANK ACCOUNTS FUNCTIONS :
BankAcc FillAccount();
BankAcc FillAccountWith(char CIN[10],char Nom[10],char Prenom[10],float Montant);
void AfficherBankAcc(BankAcc A);
void Retrait(BankAcc *A,float montant);
void Depot(BankAcc *A,float montant);

//LINKED LISTS FUNCTIONS :
Bank* creeBank();
void AddAccount(Bank **B,BankAcc A);
void AddWithMontant(Bank **B,BankAcc A);
Bank* TrieBank(Bank *B,float montant);

//DISPLAY :
void Afficher(Bank *B);
void AfficherInverse(Bank *B);

//RECHERCHE :
int DisplayAccID(Bank *B,char CIN[10]);


//FIDIALISATION:
void FindTopTree(char i[10],char j[10],char z[10],Bank *B);
void Fidialise(Bank **B);

//OTHERS :
int Deposer(Bank **B,char CIN[10],float m);
int Retraiter(Bank **B,char CIN[10],float m);


//SUPPRESSION :
void SupprimerAcc(Bank **B,char CIN[10]);
void SupprimerTous(Bank **B);









