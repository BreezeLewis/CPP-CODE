#include "Safehouse.h"
Safehouse& Safehouse::operator = (const Safehouse& another)
{
	Safehouse ret(another);
	auto* tmp = _owns;
	_owns = ret._owns;
	ret._owns = tmp;
	_count_own_types = ret._count_own_types;
	return *this;
}
Safehouse Safehouse::operator + (const Resource& new_resource)
{
	Safehouse ret(*this);
	if (ret.CountOfResource(new_resource.name))
	{//’“µΩ
		int index = ret.IndexOfResource(new_resource.name);
		ret._owns[index].count += new_resource.count;
		return ret;
	}
	if (ret._count_own_types == 16)
		return ret;
	ret._owns[ret._count_own_types].count = (new_resource.count);
	ret._owns[ret._count_own_types++].name = new_resource.name;
	return ret;
}
Safehouse Safehouse::operator + (const Safehouse& another)
{
	Safehouse ret(*this);
	for (int i = 0; i < another._count_own_types; i++)
	{
		ret = ret + another._owns[i];
	}
	return ret;
}
Safehouse& Safehouse::operator += (const Resource& new_resource)
{
	if (CountOfResource(new_resource.name))
	{//’“µΩ
		int index = IndexOfResource(new_resource.name);
		_owns[index].count += new_resource.count;
		return *this;
	}
	if (_count_own_types == 16)
		return *this;
	_owns[_count_own_types++] = new_resource;
	return *this;
}
Safehouse& Safehouse::operator += (const Safehouse& another)
{
	for (int i = 0; i < another._count_own_types; i++)
	{
		(*this) += another._owns[i];
	}
	return *this;
}
const Resource& Safehouse::operator[](const int& index) const
{
	return _owns[index];
}
bool Safehouse::operator >= (const Safehouse& target)
{
	for (int i = 0; i < target._count_own_types; i++)
	{
		string name = target._owns[i].name;
		int count = target._owns[i].count;
		if (!CountOfResource(name))
			return false;
		if (CountOfResource(name) < count)
			return false;
	}
	return true;
}
ostream& operator << (ostream& os, const Safehouse& house)
{
	for (int i = 0; i < house._count_own_types; i++)
	{
		os << house._owns[i].name << ": " << house._owns[i].count << endl;
	}
	return os;
}