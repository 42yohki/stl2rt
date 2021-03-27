#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define COLOR "255,255,255"

int main(void)
{
	char buf[BUFFER_SIZE];
	char *p;
	double x, y, z;
	int i;

	i = 0;
	while (fgets(buf, BUFFER_SIZE, stdin))
	{
		p = strchr(buf, '\n');
		if (p)
		{
			*p = '\0';
			if (strstr(buf, "vertex"))
			{
				if (i == 0)
					printf("tr ");
				sscanf(buf, "%*s %lf %lf %lf", &x, &y, &z);
				printf("%f,%f,%f ", x, y, z);
				if (i == 2)
					printf("%s\n", COLOR);
				i++;
				i %= 3;
			}
		}
	}
}
