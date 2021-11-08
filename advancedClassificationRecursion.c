#include "NumClass.h"
#include <math.h>

int numDigits(int input);
int getArmstrongSum(int input, int n);

int isArmstrong(int input)
{
	int sum = 0;
	int n = numDigits( input );	

	/* Stop condition */
	if (n == 0)
		return 0;

	sum = getArmstrongSum(input, n);
	return (input == sum); /* 0 if false, 1 if true */
}

int isPalindrome(int input)
{
	int n = numDigits(input);
	int dig1, dig2; 

	/* Stop condition */
	if (input < 10)
		return 1;

	dig1 = input % 10;
	dig2 = input / (int)pow(10, n - 1);
	if (dig1 != dig2)
		return 0;

	input -= dig2 * (int)pow(10, n - 1);
	input /= 10;
	return isPalindrome(input);
}

int numDigits(int input)
{
	if (input == 0)
		return 0;

	return ( numDigits(input / 10) + 1 );
}

int getArmstrongSum(int input, int n)
{
	int dig;
	if (input == 0)
		return 0;

	dig = input % 10;
	return ( (int)pow(dig, n) + getArmstrongSum( input/10, n) );
}