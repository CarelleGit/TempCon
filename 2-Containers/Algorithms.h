#pragma once
template<typename t, typename s>
static s addRange(t start, t end)
{
	s total = 0;
	t iter = start;
	while (iter != end)
	{
		total += *iter;
		++iter;
	}
	return total;
}