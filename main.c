#include "NumClass.h"
#include <stdio.h>
#include <math.h>

int main()
{
    int primeRes = 0;
    int isStrongRes = 0;
    int isArmstrongRes = 0;
	int isPalindromeRes = 0;
    int userInput1, userInput2, temp;

    printf("Enter two numbers: ");
	if (scanf("%d %d", &userInput1, &userInput2) != 2 || userInput1 <= 0 || userInput2 <= 0 ) 
	{
		printf("Wrong input\n");
		return -1;
	}

	/* Swap the numbers if the first one is greater than the second one */
	if (userInput1 > userInput2)
	{
		temp = userInput1;
		userInput1 = userInput2;
		userInput2 = temp;
	}

    for (int i = userInput1; i <= userInput2; i++)
    {
        primeRes = isPrime(i);
        if (primeRes)        
            printf("The number %d isPrime=%d\n", i, primeRes);

        isStrongRes = isStrong(i);
        if (isStrongRes)
            printf("The number %d isStrong=%d\n", i, isStrongRes);        

        isArmstrongRes = isArmstrong(i);
		if (isArmstrongRes)
			printf("The number %d is Armstrong\n", i);

		isPalindromeRes = isPalindrome(i);             
		if (isPalindromeRes)
			printf("The number %d is palindrome\n", i);
    }
    return 0;
}
