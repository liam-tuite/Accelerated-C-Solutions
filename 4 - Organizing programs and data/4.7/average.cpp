#include "average.h"

using std::vector;

double average(const vector<double>& vec)
{
	typedef vector<double>::size_type vec_sz;

	double sum = 0;
	vec_sz count = vec.size();

	for (vec_sz i = 0; i < count; ++i)
		sum += vec[i];

	return sum / count;
}