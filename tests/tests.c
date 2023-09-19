#include "tests.h"

static int	error;

static void print_result(bool check, int number)
{
	if (check)
		printf("%i.OK   ", number);
	else
	{
		printf("%i.KO   ", number);
		error = 1;
	}
}

int	main(void)
{
	printf("\nis_map Function: ");
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

	printf("\nvalidate_row Function: ");
	print_result(validate_row_with_valid_row_1(), 0);
	print_result(validate_row_with_valid_row_2(), 1);
	print_result(validate_row_with_valid_row_3(), 2);
	print_result(validate_row_with_invalid_row_1(), 3);
	print_result(validate_row_with_invalid_row_2(), 4);
	print_result(validate_row_with_invalid_row_3(), 5);
	print_result(validate_row_with_invalid_row_4(), 6);
	printf("\n");

	return (error);
}
