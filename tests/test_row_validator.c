#include "tests.h"

bool	row_validator_bool;

static bool	result_analyzer(bool row_validator_got, bool row_validator_want)
{
	if (row_validator_got == row_validator_want)
		return (true);
	return (false);
}

bool	row_validator_with_valid_row_1(void)
{
	row_validator_bool = row_validator("11111111111111111111111");
	return (result_analyzer(row_validator_bool, true));
}

bool	row_validator_with_valid_row_2(void)
{
	row_validator_bool = row_validator("10000000000000000000001");
	return (result_analyzer(row_validator_bool, true));
}

bool	row_validator_with_valid_row_3(void)
{
	row_validator_bool = row_validator("1000000000CEP0000000001");
	return (result_analyzer(row_validator_bool, true));
}

bool	row_validator_with_invalid_row_1(void)
{
	row_validator_bool = row_validator("1000000000CEP0000000 01");
	return (result_analyzer(row_validator_bool, false));
}

bool	row_validator_with_invalid_row_2(void)
{
	row_validator_bool = row_validator("1000000000CER0000000001");
	return (result_analyzer(row_validator_bool, false));
}

bool	row_validator_with_invalid_row_3(void)
{
	row_validator_bool = row_validator(" 000000000CEP0000000001");
	return (result_analyzer(row_validator_bool, false));
}

bool	row_validator_with_invalid_row_4(void)
{
	row_validator_bool = row_validator("10000000002340000000001");
	return (result_analyzer(row_validator_bool, false));
}

bool	row_validator_with_invalid_row_5(void)
{
	row_validator_bool = row_validator("");
	return (result_analyzer(row_validator_bool, false));
}

bool	row_validator_with_invalid_row_6(void)
{
	row_validator_bool = row_validator(" ");
	return (result_analyzer(row_validator_bool, false));
}

bool	row_validator_with_invalid_row_7(void)
{
	row_validator_bool = row_validator("P");
	return (result_analyzer(row_validator_bool, false));
}
