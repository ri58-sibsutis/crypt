#include "substitution.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* Substitution(char* input_string)
{	
	int i, j;
	char* str = NULL;
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f',
			     'g', 'h', 'i', 'j', 'k', 'l',
			     'm', 'n', 'o', 'p', 'q', 'r',
			     's', 't', 'u', 'v', 'w', 'x',
			     'y', 'z'};
	char ciphertable[26] = {'c', 'a', 'b', 'd', 'f', 'j',
			        'k', 'e', 'g', 'm', 'h', 'q',
			        't', 'p', 'i', 'l', 's', 'n',
			        'r', 'u', 'x', 'z', 'w', 'y',
                                'o', 'v'};

	str = malloc(strlen(input_string) * sizeof(char));
	strcpy(str, input_string);
	
	for(i=0; str[i]!='\0'; i++)
	{
		for(j=0; j< 26; j++)
		{
			if (str[i] == alphabet[j])
			{
				str[i] = ciphertable[j];
				break;
			}
			else if (str[i] == toupper(alphabet[j]))
			{
				str[i] = toupper(ciphertable[j]);
				break;
			}
		}
	}
	return str;
}
