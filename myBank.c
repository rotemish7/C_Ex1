#include <stdio.h>
#include "myBank.h"

#define firstRow 0
#define secondRow 1
#define numOfRows 2
#define numOfAccounts 50
#define firstAccount 901
double bankAccounts[numOfRows][numOfAccounts];

void openAccount(double amount)
{	
	if (amount < 0)
	{
		printf("Cannot initial with negative value\n");
		return;
	}

	for (int i = 0; i < numOfAccounts; i++)
	{
		if (bankAccounts[firstRow][i] == 0)
		{
			bankAccounts[firstRow][i] += i + firstAccount;
			bankAccounts[secondRow][i] = amount;
			printf("Account num is: %0.0lf\n", bankAccounts[0][i]);
			return;
		}
	}

	printf("Cannot open a new account\n");
	return; 
}

void balance(int account)
{
	int j = account - firstAccount;
	
		if (bankAccounts[firstRow][j] == account)
		{
			printf("Youre balance is: %0.2lf\n", bankAccounts[secondRow][j]);
			return;
		}
		else 
		{
			printf("Not an active account\n");
			return;
		}
}

void deposit(int account_num, double amount)
{
	int j = account_num - firstAccount;

		if (amount < 0)
		{
			printf("Cannot deposit a negative value\n");
			return;
		}
		else
		{
			bankAccounts[secondRow][j] += amount;
			printf("Youre new balance is: %0.2lf\n", bankAccounts[1][j]);
			return;
		}
}

void withdraw(int account_num, double amount)
{
	int j = account_num - firstAccount;

		if ((bankAccounts[secondRow][j] - amount) < 0)
		{
			printf("Cannot withdraw\n");
			return;
		}
		else
		{
			bankAccounts[secondRow][j] -= amount;
			printf("Youre new balance is:%0.2lf\n", bankAccounts[secondRow][j]);
			return;
		}
}

void closeAccount(int account_num)
{
	int j = account_num - firstAccount;
	bankAccounts[firstRow][j] = 0;
	bankAccounts[secondRow][j] = 0;
	return;
}

void interest(double num)
{
	for (int i = 0; i < numOfAccounts; i++)
	{
		if (bankAccounts[firstRow][i] == i + firstAccount)
		{
			bankAccounts[secondRow][i] += (bankAccounts[secondRow][i]*(num/100));
		}
	}
	return;
}

void printAccountsBalance()
{
	for (int i = 0; i < numOfAccounts; i++)
	{
		if (bankAccounts[firstRow][i] == i + firstAccount)
		{
			printf("Account: %0.0lf balance is: %0.2lf\n", bankAccounts[firstRow][i], bankAccounts[secondRow][i]);
		}
	}
	return;
}

void exitAndDelete()
{
	for (int i = 0; i < numOfAccounts; i++)
	{
		bankAccounts[firstRow][i] = 0;
		bankAccounts[secondRow][i] = 0;
	}
	return;
}

int isActive(int account)
{
	int j = account - firstAccount;

	if ((account < 901) || (account > 950) || bankAccounts[firstRow][j] == 0)
	{
		return 1;
	}
	return 0;
}

