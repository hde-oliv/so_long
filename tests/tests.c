#include "tests.h"

static void print_result(bool check)
{
	static short	print_result_counter;

	if (check)
		printf("%i.OK   ", print_result_counter);
	else
		printf("%i.KO   ", print_result_counter);
	print_result_counter++;
}

int	main(void)
{
	return (0);
}
