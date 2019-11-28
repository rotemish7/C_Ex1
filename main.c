#include <stdio.h>
#include "myBank.h"


int main()
{
	//adding variables for the main function
	int test;
	double amount;
	int account_num;
	char operator='e';
	do
	{
		printf("Transaction type ?: \n");
		scanf(" %c", &operator);
	
		switch (operator)
		{
		case 'O':
			printf("Amount: ?\n");
			scanf("%lf", &amount);
			openAccount(amount);
			break;

		case 'B':
			printf("Account number ? :\n");
			scanf("%d", &account_num);
			balance(account_num);
			break;

		case 'D':
			printf("Account number ? :\n");
			scanf("%d", &account_num);
		
			test = isActive(account_num);
			if (test == 0)
			{
			printf("Amount : ?\n");
			scanf("%lf", &amount);
			deposit(account_num,amount);
			break;
			}
			printf("Not an acctive bank account\n");
			break;
			
		case 'W':
			printf("Account number ? :\n");
			scanf("%d", &account_num);
			test = isActive(account_num);
			if (test == 0)
			{
			printf("Amount : ?\n");
			scanf("%lf", &amount);
			withdraw(account_num, amount);
			break;
			}
			printf("Not an acctive bank account\n");
			break;

		case 'C':
			printf("Account number ? :\n");
			scanf("%d", &account_num);
			test = isActive(account_num);
			if (test == 0)
			{
			closeAccount(account_num);
			break;
			}
			printf("Not an acctive bank account\n");
			break;
			

		case 'I':
			printf("Interest rate: ?\n");
			scanf("%lf", &amount);
			interest(amount);
			break;

		case 'P':
			printAccountsBalance();
			break;

		case 'E':
			exitAndDelete();
			break;

			// operator doesn't match any case constant O, B, D, W, C, I, P, E
		default:
			printf("Error! operator is not correct\n");
		}
	} while (operator != 'E');

	printf("Bye Bye \n");
	return 0;
}


