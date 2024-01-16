#include "main.h"
int main(int argc, char *argv[])
{
	FILE *file;
	char line_input[256];

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
		printf("%s", line_input);

	}
	fclose(file);
	return (0);
}


	




