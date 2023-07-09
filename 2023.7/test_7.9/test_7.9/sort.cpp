#include <algorithm>
#include "rational.h"

bool cmp(rational x, rational y)
{
    return x > y;
}
void sortRational(vector<rational>& vec)
{
    sort(vec.begin(), vec.end(), cmp);
}