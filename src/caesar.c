#include "caesar.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* Caesar(char* input_string, int shift)
{	
	int i;
	char* str = NULL;
	str = malloc(strlen(input_string) * sizeof(char));
	strcpy(str, input_string);
	for(i=0; str[i]!='\0'; i++)
	{
		if (str[i] == 'z')
			str[i] = 'a' + (shift-1);
		else if (str[i] == 'Z')
			str[i] = 'A' + (shift-1);
		else if (((str[i] >= 'a') && (str[i] < 'z')) || ((str[i] >= 'A') && (str[i] < 'Z')))
			str[i] += shift;
	}

	return str;
}
