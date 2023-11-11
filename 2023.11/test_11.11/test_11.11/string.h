#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
namespace lys
{
	class string
	{
		friend string operator+(const string& s1, const string& s2);
		friend bool operator==(const string& s1, const string& s2);
		friend bool operator!=(const string& s1, const string& s2);
		friend bool operator>(const string& s1, const string& s2);
		friend bool operator<=(const string& s1, const string& s2);
	private:
		char* data;
		int len;
	public:
		string() :data(nullptr), len(0)
		{}
		~string()
		{
			delete[] data;
			len = 0;
		}
		string(const char* d)
		{
			len = (int)strlen(d);
			data = new char[len + 1];
			strcpy(data, d);	
		}
		string(const string& x)
		{
			len = x.len;
			data = new char[len + 1];
			strcpy(data, x.data);
		}
		int size()const
		{
			return len;
		}
		int length()const
		{
			return len;
		}
		void show()const
		{
			printf("%s", data);
		}
		string& operator=(const string& x)
		{
			delete[] data;
			len = x.len;
			data = new char[len + 1];
			strcpy(data, x.data);
			
			return *this;
		}
		char& operator[](const int index)
		{
			return data[index];
		}
		const char& operator[](const int index)const
		{
			return data[index];
		}
	};

	string operator+(const string& s1, const string& s2)
	{
		int newlen = s1.len + s2.len;
		char* newstr = new char[newlen + 1];
		strcpy(newstr, s1.data);
		strcat(newstr, s2.data);
		return string(newstr);
	}
	bool operator==(const string& s1, const string& s2)
	{
		if (s1.len != s2.len)
			return false;
		for (int i = 0; i < s1.len; i++)
		{
			if (s1[i] != s2[i])
				return false;
		}
		return true;
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
	bool operator>(const string& s1, const string& s2)
	{
		int minlen = s1.len < s2.len ? s1.len : s2.len;
		for (int i = 0; i < minlen; i++)
		{
			if (s1[i] > s2[i])
				return true;
			else if (s1[i] < s2[i])
				return false;
		}		
		if (s1.len > s2.len)
			return true;
		return false;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}
}