#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <memory.h>

typedef struct
{
	int input;
	char input_file[255];
	char input_string[255];
	int output;
	char output_file[255];
	int alg;
	char alg_name[255];
	int shift;
}	input_struct;

int main(int argc, char* argv[])
{
	input_struct data;
	int i = 0, j;
	int option;
	FILE* input_file = NULL;
	FILE* output_file = NULL;
	
	data.shift = 0;
	while((option = getopt_long(argc, argv, "i:o:a:s:", 0, 0)) != -1)
	{
		switch (option)
		{
			case 'i':
				if ((data.input != 1) && (optarg[0] != '-') && (strlen(optarg) < 255))
				{
					data.input = 1;
					memcpy(data.input_file, optarg, strlen(optarg) + 1);
				}
				break;
			case 'o':
				if ((data.output != 1)  && (optarg[0] != '-') && (strlen(optarg) < 255))
				{
					data.output = 1;
					memcpy(data.output_file, optarg, strlen(optarg) + 1);
				}
				break;
			case 'a':
				if ((data.alg != 1) && (optarg[0] != '-') && (strlen(optarg) < 255))
				{
					data.alg = 1;
					memcpy(data.alg_name, optarg, strlen(optarg) + 1);
				}
				break;
			case 's':
				if ((data.shift == 0) && (optarg[0] != '-') && (strlen(optarg) < 255))
				{
					data.shift = *optarg - 48;
				}
				break;
			default:
					printf("invalid command line\n");
					return 0;
		}
	}
	
	if (data.input != 1)
	{
		printf("Input string: ");
		scanf("%s", &data.input_file);
	}
	else
	{
		input_file = fopen(data.input_file, "r");
		if (input_file == NULL)
		{
			printf("Invalid input file\n");
			return -1;
		}
		while ((data.input_string[i] = fgetc (input_file)) != EOF) 
		{
			if (data.input_string[i] == '\n') 
			{
				data.input_string[i] = '\0';
				printf("%s\n",data.input_string);
			}
			else i++;
		}
		data.input_string[i] = '\0';
		printf("%s\n",data.input_string);
	}
	
	if (data.output == 1)
	{
		output_file = fopen(data.output_file, "w");
		if (output_file == NULL)
		{
			printf("Invalid output file\n");
			return -1;
		}
	}
		
	if(data.alg != 1)
	{
		printf("Input alg name: ");
		scanf("%s", &data.alg_name);
	}
	
	if ((strcmp(data.alg_name, "Caesar") == 0) || (strcmp(data.alg_name, "caesar") == 0));
		//calling Caesar Cipher
	if ((strcmp(data.alg_name, "Verrnam") == 0) || (strcmp(data.alg_name, "verrnam ") == 0));
		//calling Verrnam Cipher
	if ((strcmp(data.alg_name, "Viginere") == 0) || (strcmp(data.alg_name, "viginere") == 0));
		//calling Viginere Cipher
	if ((strcmp(data.alg_name, "Affine") == 0) || (strcmp(data.alg_name, "affine") == 0));
		//calling Affine Cipher
	if ((strcmp(data.alg_name, "Substitution") == 0) || (strcmp(data.alg_name, "substitution") == 0));
		//calling Substitution Cipher
	
	//...
	return 0;
}
