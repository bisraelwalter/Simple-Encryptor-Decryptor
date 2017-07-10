#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



char encrypt(char word[], char key[], int railKey);
void decrypt(char word[], int key, int railKey);
void removeDuplicates(char* word[]);



void main()
{
	char word[25];
	char decryptWord[25];
	char key[25];
	int railKey;
	int decryptKey;


	printf("Enter word to encrypt: ");
	scanf("%s", &word);




	printf("Enter key (0-26): ");
	scanf("%s", &key);
	printf("Enter rail encryption from 2 to 6: ");
	scanf("%d", &railKey);

	printf("Encryption: ");
	encrypt(word, key, railKey);

	//printf("Enter word to decrypt: ");
	//scanf("%s", &decryptWord);

	//printf("Enter the decrypting key: ");
	//scanf("%d", &decryptKey);

	//printf("Decrypted word: ");
	//decrypt(decryptWord, decryptKey, railKey);


}


char encrypt(char word[], char key[], int railKey)
{
	char encryptedWord[25];
	char convertedWord[25];
	char cypherAlph[25];
	int length3 = strlen(word);


	//make sure key to ecrypt is lower case
	for (int s = 0; s < strlen(key); s++)
	{
		key[s] = tolower(key[s]);
	}

	//remove duplicate letters
	for (int p = 0; p < strlen(key); p++)
	{
		for (int q = p + 1; q < strlen(key); q++)
		{
			if (key[p] == key[q])
			{
				for (int r = q; r < strlen(key) - 1; r++)
				{
					key[r] = key[r + 1];
				}
				key[strlen(key) - 1] = NULL;
				q--;
			}
		}
	}

	//make sure word to encrypt is lower case
	for (int h = 0; h < length3; h++)
	{
		convertedWord[h] = tolower(word[h]);
	}

	//puts key into 
	for (int a = 0; a < strlen(key); a++)
	{
		cypherAlph[a] = key[a];
	}

	//adds an x to the end of the word to prepare it for railfence
	int length = strlen(word);

		if (length % railKey != 0)
		{
			while (length % railKey != 0)
			{
				encryptedWord[length] = 'x';
				length++;
			}
		}

	//railfence encrypter
	int railWordCounter = 0;
	char railEncryptWord[25];
	for (int j = 0; j < railKey; j++)
	{
		for (int k = 0; k < length; k = k + railKey)
		{
			railEncryptWord[railWordCounter] = encryptedWord[j + k];
			railWordCounter++;
		}
	}

	//print out ecprypted string
	for (int l = 0; l < length; l++)
	{
		printf("%c", railEncryptWord[l]);
	}
}


void decrypt(char word[], int key, int railKey)
{
	int counter = 0;
	char encryptedWord[25];
	int length = strlen(word);
	for (int i = 0; i < length / railKey; i++)
	{

		for (int j = 0; j < railKey; j++)
		{
			encryptedWord[j + counter] = tolower(word[(j * (length / railKey)) + i]);
		}
		counter = counter + railKey;
	}

	char decryptedWord[25];
	for (int k = 0; k < length; k++)
	{
		if ((encryptedWord[k] - key) < 97) decryptedWord[k] = (encryptedWord[k] - key) + 26;
		else decryptedWord[k] = (encryptedWord[k] - key);
		printf("%c", toupper(decryptedWord[k]));
	}
	printf("\n");
}

void removeDuplicates(char* word[])
{
	for (int i = 0; i < strlen(word); i++)
	{
		for (int j = i + 1; j < strlen(word); j++)
		{
			if (word[i] == *word[j])
			{
				for (int k = word[j]; k < strlen(word); k++)
				{
					word[j] = word[j + 1];
				}
				word[strlen(word) - 1] = NULL;
			}
		}
	}
}