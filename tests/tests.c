#include "tests.h"

static int	err;

static void print_result(bool check, int number)
{
	if (check)
		printf("%i.OK   ", number);
	else
	{
		printf("%i.KO   ", number);
		err = 1;
	}
}

int	main(void)
{
	print_result(is_map_with_valid_name(), 0);
	print_result(is_map_with_invalid_name_1(), 1);
	print_result(is_map_with_invalid_name_2(), 2);
	print_result(is_map_with_invalid_name_3(), 3);
	print_result(is_map_with_invalid_name_4(), 4);
	print_result(is_map_with_invalid_name_5(), 5);
	print_result(is_map_with_invalid_name_6(), 6);
	print_result(is_map_with_invalid_name_7(), 7);
	print_result(is_map_with_invalid_name_8(), 8);
	print_result(is_map_with_invalid_name_9(), 9);
	printf("\n");
	return (err);
}
