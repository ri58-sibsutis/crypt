#include "affine.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int Gcd(int a, int b)
{
  if (b == 0) return a;
  return Gcd(b, a % b);
}

int Encrypt(int x, int a, int b, int m)
{	
	int y = (a * x + b) % m;
	return y;
}

char* Affine(char* input_string)
{	
	int i, j, x;
	char* str = NULL;
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f',
			     'g', 'h', 'i', 'j', 'k', 'l',
			     'm', 'n', 'o', 'p', 'q', 'r',
			     's', 't', 'u', 'v', 'w', 'x',
			     'y', 'z'};
	int a, b, m;
	int temp;
	str = malloc(strlen(input_string) * sizeof(char));
	strcpy(str, input_string);
	printf("Input a, b, m for encryption function (a*x+b) mod m: ");
	scanf("%d %d %d", &a, &b, &m);
	while ((temp = Gcd(a,m))!= 1)
	{	
		printf("GCD is: %d\n", temp);
		printf("Greatest common divisor of a and m must be equal 1! (for example: a = 4, m = 9)\n");
		printf("Input a, b, m for encryption function (a*x+b) mod m: ");
		scanf("%d %d %d", &a, &b, &m);
	}
	
	for(i=0; str[i]!='\0'; i++)
	{
		for(j=0; j< 26; j++)
		{
			if (str[i] == alphabet[j])
			{	
				x = Encrypt(j, a, b, m);
				printf("Encrypt %c to %c\n", str[i], alphabet[x]);
				str[i] = alphabet[x];
				break;
			}
			else if (str[i] == toupper(alphabet[j]))
			{	
				x = Encrypt(j, a, b, m);
				printf("Encrypt %c to %c\n", str[i], toupper(alphabet[x]));
				str[i] = toupper(alphabet[x]);
				break;
			}
		}
	}
	return str;
}

