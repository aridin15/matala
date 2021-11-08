#include "NumClass.h"
#include <math.h>

int isArmstrong(int input)
{
    int n = 0 , temp = input , temp2 = input , sum = 0;
    while(temp != 0){
        temp /= 10;
        n++;
    }
    while(temp2 != 0){
        sum = sum + (int)pow(temp2 % 10 , n);
        temp2 /= 10;
    }
    if (sum == input){
        return 1;   
    }

    return 0;
}

int isPalindrome(int input)
{
	int n = 0, temp = input;
	int dig1, dig2;

	while (temp != 0) 
	{
		temp /= 10;
		n++;
	}

	while (input >= 10) /* one digit is palindrome */
	{
		dig1 = input % 10;
		dig2 = input / (int) pow(10, n - 1);
		if (dig1 != dig2)
			return 0;
		
		input -= dig2 * (int)pow(10, n - 1);
		input /= 10;
		n -= 2;
	}

	return 1;
}