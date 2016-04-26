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
	//...
	return 0;
}
