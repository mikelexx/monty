#include "main.h"
int main(int argc, char *argv[])
{
	FILE *file;
	char line_input[256];
	const char delim[] = " \n";
	char *first, *second;

	if (argc != 2)
	{
		fprintf(stderr, "Usage %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line_input, sizeof(line_input), file) != NULL)
	{
                first = strtok(line_input, delim);
		while (first != NULL)
		{
			second = strtok(NULL, delim);
			break;
		}
		printf("%s %s\n", first, second);
	}
	fclose(file);
	return (0);
}


	




