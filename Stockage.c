#include "Stockage.h"

void Save(Bank *B)
{
    FILE *fPtr;
	char tmp[50];
    fPtr = fopen("DATABASE/data.txt", "w");


	while(B)
	{
		fputs(B->A.CIN, fPtr);
		fputs("\n", fPtr);
		fputs(B->A.Nom, fPtr);
		fputs("\n", fPtr);
		fputs(B->A.Prenom, fPtr);
		fputs("\n", fPtr);
		gcvt(B->A.Montant,20,tmp);
		fputs(tmp,fPtr);
		fputs("\n", fPtr);
		B=B->next;
	}

    fclose(fPtr);
}

Bank* Load()
{
	Bank *B=NULL;
	int totalRead=0;
	char buffer[50];
	BankAcc A;
	FILE *fPtr;
    fPtr = fopen("DATABASE/data.txt", "r");

 	while(fgets(buffer, 50, fPtr)) 
    {
    	//elimination de /n et le remplacer avec /0
        totalRead = strlen(buffer);
		buffer[totalRead - 1] = buffer[totalRead - 1] == '\n' ? '\0' : buffer[totalRead - 1];
        strcpy(A.CIN,buffer);
        
       	fgets(buffer, 50, fPtr);
       	totalRead = strlen(buffer);
		buffer[totalRead - 1] = buffer[totalRead - 1] == '\n' ? '\0' : buffer[totalRead - 1];
		strcpy(A.Nom,buffer);
		
		fgets(buffer, 50, fPtr);
       	totalRead = strlen(buffer);
		buffer[totalRead - 1] = buffer[totalRead - 1] == '\n' ? '\0' : buffer[totalRead - 1];
		strcpy(A.Prenom,buffer);
		
		fgets(buffer, 50, fPtr);
       	totalRead = strlen(buffer);
		buffer[totalRead - 1] = buffer[totalRead - 1] == '\n' ? '\0' : buffer[totalRead - 1];
		A.Montant=atof(buffer);
		
		//l'ajout de l'element:
		AddAccount(&B,A);
    } 

    fclose(fPtr);
	return B;
	
}
