#include "NumClass.h"
#include <math.h>

#include <stdio.h> // TODO: Remove this

static int factorial(int input)
{
    int result = 1;
    for (int i = 2; i <= input; i++)
    {
        result *= i;
    }
    // printf("Factorial of %d is %d\n", input, result);
    return result;
}

int isPrime(int input)
{
	if ( input <= 1 ) /* 0 or 1 */
		return 0;

    for (int i = 2; i <= (int)sqrt(input); i++)
    {
        if (input % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int isStrong(int input)
{
    // printf("isStrong input is: %d\n", input);

    int mod = input % 10;
    int remainder = input / 10;
    int sum = 0;

    while (mod > 0)
    {
        // printf("Curr factorial (remainder %d mod %d): %d\n", remainder, mod, factorial(mod));
        sum += factorial(mod);

        mod = remainder % 10;
        remainder /= 10;
    }

    if (mod > 0)
    {
        sum += factorial(mod);
    }

    if (sum == input)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
