#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 64

static char buf[MAX_LEN] = {
  'A', 'B', 'C', 'D',
  'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 
  'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T',
  'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b',
  'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j',
  'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 
  's', 't', 'u', 'v',
  'w', 'x', 'y', 'z',
  '0', '1', '2', '3',
  '4', '5', '6', '7',
  '8', '9', '"', ' '
};

int GetIndex(char c) {
  int i;
  for (i=0; i < MAX_LEN; i++)
    if (buf[i] == c)
      return i;
  return -1;
}

char* Verrnam(char *input_string) 
{
  int i, j = 0, k;
  char key[255];
  char *table;
  int len = strlen(input_string);
  char *output_string;
  
  printf("Input key: ");
  scanf("%s", key);
  
  table = (char*) malloc(len * sizeof(char));
  output_string = malloc(strlen(input_string) * sizeof(char));
  
	for(i = 0; i < len; i++) 
{
	 if (j == strlen(key))
	   j = 0;

	table[i] = key[j];
	if ((input_string[i] >= 'A') && (input_string[i] <= 'Z'))
		table[i] = (char) toupper(table[i]);
	else 
		if ((input_string[i] >= 'a') && (input_string[i] <= 'z'))
	j++;
}
	
	for (i=0; i < len; i++) 
  {
		if ((j = GetIndex(input_string[i])) == -1 || (k = GetIndex(table[i])) == -1) 
    {
		free(output_string);
		return NULL;
    }
    else { 
		output_string[i] = buf[(j + k) % MAX_LEN];
		if ((input_string[i] >= 'A') && (input_string[i] <= 'Z'))
		output_string[i] = (char)toupper(output_string[i]);	
        else
        	if ((input_string[i] >= 'a') && (input_string[i] <= 'z'))
			output_string[i] = (char)tolower(output_string[i]);
    }      
  }
  output_string[len] = '\0';
  return output_string;
}
