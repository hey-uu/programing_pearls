#include <stdio.h>

const char *alphabet[24] = {"\
   ___ \n\
  / _ |\n\
 / __ |\n\
/_/ |_|\n\
       \n\
", "\
   ___ \n\
  / _ )\n\
 / _  |\n\
/____/ \n\
       \n\
", "\
  _____\n\
 / ___/\n\
/ /__  \n\
\\___/  \n\
       \n\
", "\
   ___ \n\
  / _ \\\n\
 / // /\n\
/____/ \n\
       \n\
", "\
   ____\n\
  / __/\n\
 / _/  \n\
/___/  \n\
       \n\
"};

int	print_alphabet_banner(int c)
{
	int	idx;
	if (c >= 'a')
		idx = c - 'a';
	else
		idx = c - 'A';
	if (idx < 0 || idx > 'E' - 'A')
		return (0);
	printf("%s\n", alphabet[idx]);
	return (1);
	
}


int main(void)
{
	char	c;

	while (1)
	{
		printf("If you want to stop, enter 0.\n\n");
		printf("Or enter an alphabet(A - E): ");
		scanf("%c", &c);
		if (c == '0')
			return (0);
		if (!print_alphabet_banner(c))
			printf("Input error...\n\n");
		scanf("%c", &c);
	}
}