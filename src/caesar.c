#include "caesar.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char* Caesar(char* input_string)
{	
	int i;
	int shift;
	char* str = NULL;
	str = malloc(strlen(input_string) * sizeof(char));
	strcpy(str, input_string);
	do
	{
	printf("Input shift: ");
	scanf("%d", &shift);
	if (shift >= 26)
		printf("Shift must be less than 26\n");
	} while (shift >= 26);
	
	for(i=0; str[i]!='\0'; i++)
	{
		if ((islower(str[i]) > 0) && (str[i] + shift > 'z'))
		{
			str[i] = 'a' + (shift - (('z' + 1) - str[i]));
		}
		else if ((isupper(str[i]) > 0) && (str[i] + shift > 'Z'))
			str[i] = 'A' + (shift - (('Z' + 1) - str[i]));
		else if (((str[i] >= 'a') && (str[i] < 'z')) || ((str[i] >= 'A') && (str[i] < 'Z')))
			str[i] += shift;
	}

	return str;
}
