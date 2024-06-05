#include<stdio.h>
#include<stdlib.h>

#define min_lobster_name 3
#define max_lobster_name 20

int main(int argc, char* argv[])
	{
	
	//Variable delcaration
	unsigned long number_of_lobsters, index, bag_size;
       	unsigned long min_lobster_value, max_lobster_value, min_lobster_size, max_lobster_size;
	FILE* output, *input;
	short unsigned name_lenght, j;
	
	input=fopen(argv[1], "r");
	output=fopen("output","w");

	//Error handling
	
	if(argc!=2)
	{
		fprintf(stderr, "The program needs exactly one command line argument");
		return 1;
	}

	if(input==NULL || output==NULL)
	{	
		fprintf(stderr, " Failed to open files");
		return 2;
	}

	//input

	fscanf(input,"%lu",&bag_size);
	fscanf(input,"%lu",&number_of_lobsters);
	fscanf(input,"%lu",&min_lobster_value);
	fscanf(input,"%lu",&max_lobster_value);
	fscanf(input,"%lu",&min_lobster_size);
	fscanf(input,"%lu",&max_lobster_size);

	//generating randomized output;
	
	fprintf(output,"%lu\n",bag_size);
	for(index=0;index<number_of_lobsters;index++)
	{
		if(index%100000==0) printf("generating...\n");

		name_lenght=min_lobster_name + rand()%(max_lobster_name-min_lobster_name);

		for(j=0; j<name_lenght; j++)
		fprintf(output, "%c", 'a'+rand()%('z'-'a'));

		fprintf(output," %lu", min_lobster_size+rand()%(max_lobster_size-min_lobster_size));
		fprintf(output," %lu\n", min_lobster_value+rand()%(max_lobster_value-min_lobster_value));
	}


	//Clean up
	
	fclose(input);
	fclose(output);
		
	return 0;
	
	}
