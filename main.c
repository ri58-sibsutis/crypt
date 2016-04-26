#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <memory.h>

typedef struct
{
	int input;
	char input_file[255];
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
	//...
	return 0;
}
