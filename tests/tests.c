#include "tests.h"

static int	err;

static void print_result(bool check)
{
	static short	print_result_counter;

	if (check)
		printf("%i.OK   ", print_result_counter);
	else
	{
		printf("%i.KO   ", print_result_counter);
		err = 1;
	}
	print_result_counter++;
}

int	main(void)
{
	print_result(is_map_with_valid_name());
	print_result(is_map_with_invalid_name_1());
	print_result(is_map_with_invalid_name_2());
	print_result(is_map_with_invalid_name_3());
	print_result(is_map_with_invalid_name_4());
	print_result(is_map_with_invalid_name_5());
	print_result(is_map_with_invalid_name_6());
	print_result(is_map_with_invalid_name_7());
	print_result(is_map_with_invalid_name_8());
	print_result(is_map_with_invalid_name_9());
	return (err);
}
