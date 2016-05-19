#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "viginere.h"

char* Viginere(char input_string[])
{
	int i, k = strlen(input_string), j = 0, l;
	char key[] = "LEMON";
	int in[k];
	int table[k];
	char* output_string;
	
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
			
		table[i] = (int)key[j] - 65;
			
		j++;
	}
	
	for(i = 0; i < k; i++)

			if ((input_string[i] >= 'A') && (input_string[i] <= 'Z'))
				output_string[i] = (table[i] + in[i]) % 26 + 65;
				else
					if ((input_string[i] >= 'a') && (input_string[i] <= 'z'))
						output_string[i] = (table[i] + in[i]) % 26 + 65;
						else
							output_string[i] = input_string[i];
	output_string[i] = '\0';

	return output_string;
}
