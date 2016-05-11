#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viginere.h"

char* Viginere(char input_string[])
{
	int i, k = strlen(input_string), j = 0, l;
	char key[255];
	char table[k];
	char output_string[k];
	FILE* output_file = NULL;
	memset(output_string, 0, k);
	
	printf("Input key: ");
	scanf("%s", &key);
	l = strlen(key);
	
	for (i = 0; i < k; i++)
	{
		output_string[i] = 0;
		
		if (j == 5)
			j = 0; 
			
		if ((input_string[i] >= 65) && (input_string[i] <= 90))
			table[i] = key[j] - 32;
		else
			table[i] = key[j];
			
		j++;
	}
	
	for(i = 0; i < k; i++)

			if ((input_string[i] >= 65) && (input_string[i] <= 90))
				output_string[i] = (table[i] + input_string[i]) % 26 + 65;
			else
				if ((input_string[i] >= 97) && (input_string[i] <= 122))
					output_string[i] = (table[i] + input_string[i]) % 26 + 97;
				else
					output_string[i] = input_string[i];
	output_string[i] = '\0';

	return output_string;
}
