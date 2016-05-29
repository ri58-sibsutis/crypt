#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "viginere.h"

char* Viginere(char input_string[])
{
	int i, k = strlen(input_string), j = 0, l;
	char key[255];
	int in[k];
	int table[k];
	char* output_string;
	
	printf("Input key: ");
	scanf("%s", &key);
	l = strlen(key);
	
	output_string = (char*)malloc(k * sizeof(char));
	memset(output_string, 0, k);
	
	for (i = 0; i < k; i++)
	{
		if ((input_string[i] >= 'A') && (input_string[i] <= 'Z'))
				in[i] = (int)input_string[i] - 65;
		else
				if ((input_string[i] >= 'a') && (input_string[i] <= 'z'))
					in[i] = (int)input_string[i] - 97;
				else
					in[i] = 0;
		
		if (j == l)
			j = 0; 
			
		if ((key[j] >= 'A') && (key[j] <= 'Z'))
				table[i] = (int)key[j]  - 65;
		else
				if ((key[j] >= 'a') && (key[j] <= 'z'))
					table[i] = (int)key[j] - 97;	
			
		j++;
	}
	
	for(i = 0; i < k; i++)

			if ((input_string[i] >= 'A') && (input_string[i] <= 'Z'))
				output_string[i] = (table[i] + in[i]) % 26 + 65;
				else
					if ((input_string[i] >= 'a') && (input_string[i] <= 'z'))
						output_string[i] = (table[i] + in[i]) % 26 + 97;
						else
							output_string[i] = input_string[i];
	output_string[i] = '\0';

	return output_string;
}
