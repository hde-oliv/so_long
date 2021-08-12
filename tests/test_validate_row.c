#include "tests.h"

bool	validate_row_bool;

static bool	result_analyzer(bool validate_row_got, bool validate_row_want)
{
	if (validate_row_got == validate_row_want)
		return (true);
	return (false);
}

bool	validate_row_with_valid_row_1(void)
{
	validate_row_bool = validate_row("11111111111111111111111");
	return (result_analyzer(validate_row_bool, true));
}

bool	validate_row_with_valid_row_2(void)
{
	validate_row_bool = validate_row("10000000000000000000001");
	return (result_analyzer(validate_row_bool, true));
}

bool	validate_row_with_valid_row_3(void)
{
	validate_row_bool = validate_row("1000000000CEP0000000001");
	return (result_analyzer(validate_row_bool, true));
}

bool	validate_row_with_invalid_row_1(void)
{
	validate_row_bool = validate_row("1000000000CEP0000000 01");
	return (result_analyzer(validate_row_bool, false));
}

bool	validate_row_with_invalid_row_2(void)
{
	validate_row_bool = validate_row("1000000000CER0000000001");
	return (result_analyzer(validate_row_bool, false));
}

bool	validate_row_with_invalid_row_3(void)
{
	validate_row_bool = validate_row(" 000000000CEP0000000001");
	return (result_analyzer(validate_row_bool, false));
}

bool	validate_row_with_invalid_row_4(void)
{
	validate_row_bool = validate_row("10000000002340000000001");
	return (result_analyzer(validate_row_bool, false));
}
