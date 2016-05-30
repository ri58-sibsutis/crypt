#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <memory.h>
#include "affine.h"
#include "caesar.h"
#include "viginere.h"
#include "substitution.h"
#include "verrnam.h"

typedef struct
{
	int input;
	char input_file[255];
	char input_string[255];
	int output;
	char output_file[255];
	int alg;
	char alg_name[255];
}	input_struct;

int str_cmp(char* str1, char* str2, int pos);

int main(int argc, char* argv[])
{
	input_struct data;
	char* output_string;
	int i = 0;
	int option;
	FILE* input_file = NULL;
	FILE* output_file = NULL;
	
	output_file = fopen("output.txt", "w");
	
	while((option = getopt_long(argc, argv, "i:o:a:", 0, 0)) != -1)
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
			default:
					fprintf(stderr, "invalid command line\n");
					return 0;
		}
	}
	if (strcmp(data.input_file, data.output_file) == 0)
	{
		fprintf(stderr,
		"Invalid file name\n");
		return -1;
	}
	if (data.input != 1)
	{
		printf("Input string: ");
		fgets(data.input_string, 255, stdin);
		data.input_string[strlen(data.input_string)-1] = '\0';
	}
	else
	{
		input_file = fopen(data.input_file, "r");
		if (input_file == NULL)
		{
			fprintf(stderr,
				"Invalid input file\n"
				"Missing file\n");
			return -1;
		}
		if (str_cmp(data.input_file, ".txt", strlen(data.input_file) - 4) != 0)
		{
			fprintf(stderr,
				"Invalid input file\n"
				"Uncorrect type\n");
			return -1;
		}
		while (((data.input_string[i] = fgetc (input_file)) != EOF) && (i < 255))
		{
			if (data.input_string[i] == '\n') 
			{
				data.input_string[i] = '\0';
				printf("%s\n",data.input_string);
			}
			else i++;
		}
		data.input_string[i] = '\0';
		fclose(input_file);
		printf("%s\n",data.input_string);
	}
	
	if (data.output == 1)
	{

	if (str_cmp(data.output_file, ".txt", strlen(data.output_file) - 4) != 0)
	{	
		fprintf(stderr,
			"Invalid output file\n"
			"Uncorrect type\n");
		return -1;
	}
	
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
		fgets(data.alg_name, 255, stdin);
		data.alg_name[strlen(data.alg_name)-1] = '\0';
	}

	output_string = (char*)malloc(strlen(data.input_string) * sizeof(char));

	if ((strcmp(data.alg_name, "Caesar") == 0) || (strcmp(data.alg_name, "caesar") == 0))
		output_string = Caesar(data.input_string);
	if ((strcmp(data.alg_name, "Verrnam") == 0) || (strcmp(data.alg_name, "verrnam") == 0))
		output_string = Verrnam(data.input_string);
	if ((strcmp(data.alg_name, "Viginere") == 0) || (strcmp(data.alg_name, "viginere") == 0))
		output_string = Viginere(data.input_string);
	if ((strcmp(data.alg_name, "Affine") == 0) || (strcmp(data.alg_name, "affine") == 0))
		output_string = Affine(data.input_string);
	if ((strcmp(data.alg_name, "Substitution") == 0) || (strcmp(data.alg_name, "substitution") == 0))
		output_string = Substitution(data.input_string);

	fputs(output_string, output_file);
	
	free(output_string);
	fclose(output_file);
	return 0;
}

int str_cmp(char* str1, char* str2, int pos)
{
	int i = 0;
	while ((str1[i+pos] != '\0') && (str2[i+1] != '\0'))
	{
		if (str1[i+pos] > str2[i])
			return 1;
		if (str1[i+pos] < str2[i])
			return -1;
		i++;
	}
	if (str1[i+pos] > str2[i])
		return 1;
	if (str1[i+pos] < str2[i])
		return -1;
	return 0;
}
