#include <iostream>
#include <string>
using namespace std;
class Cat
{
public:
	string cat_name;
	int cat_age = 0;
};
Cat cat[101];
class CatFamily
{
public:
	bool add_a_cat(string& name, int age)
	{
		if (this->count > 100)
			return false;
		cat[this->count].cat_name = name;
		cat[this->count].cat_age = age;
		(this->count)++;
		return true;
	}
	bool remove_a_cat(string& name)
	{
		//在数组中查找是否有这只猫
		for (int i = 0;i < this->count;i++)
			if (cat[i].cat_name == name)
			{
				(this->count)--;
				return true;
			}
		return false;
	}
	bool has_cat(string& name)
	{
		for (int i = 0;i < this->count;i++)
			if (cat[i].cat_name == name)
				return true;
		return false;

	}
	Cat get_cat(string& name)
	{
		for (int i = 0;i < this->count;i++)
			if (cat[i].cat_name == name)
				return cat[i];
		return cat[0];
	}
	int number_of_cats()
	{
		return this->count;
	}
	string get_nth_cat(int i)
	{
		return cat[i].cat_name;
	}
private:
	int count = 0;
};