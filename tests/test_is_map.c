#include "tests.h"

bool	is_map_bool;

static bool	result_analyzer(bool is_map_got, bool is_map_want)
{
	if (is_map_got == is_map_want)
		return (true);
	return (false);
}

bool	is_map_with_valid_name(void)
{
	is_map_bool = is_map("abc.ber");
	return (result_analyzer(is_map_bool, true));
}

bool	is_map_with_invalid_name_1(void)
{
	is_map_bool = is_map("abc.be");
	return (result_analyzer(is_map_bool, false));
}

bool	is_map_with_invalid_name_2(void)
{
	is_map_bool = is_map("abc.b");
	return (result_analyzer(is_map_bool, false));
}

bool	is_map_with_invalid_name_3(void)
{
	is_map_bool = is_map("abc.");
	return (result_analyzer(is_map_bool, false));
}

bool	is_map_with_invalid_name_4(void)
{
	is_map_bool = is_map("abc");
	return (result_analyzer(is_map_bool, false));
}

bool	is_map_with_invalid_name_5(void)
{
	is_map_bool = is_map(".ber");
	return (result_analyzer(is_map_bool, true));
}

bool	is_map_with_invalid_name_6(void)
{
	is_map_bool = is_map("ber");
	return (result_analyzer(is_map_bool, false));
}

bool	is_map_with_invalid_name_7(void)
{
	is_map_bool = is_map(".be");
	return (result_analyzer(is_map_bool, false));
}

bool	is_map_with_invalid_name_8(void)
{
	is_map_bool = is_map(".b");
	return (result_analyzer(is_map_bool, false));
}

bool	is_map_with_invalid_name_9(void)
{
	is_map_bool = is_map(".");
	return (result_analyzer(is_map_bool, false));
}
