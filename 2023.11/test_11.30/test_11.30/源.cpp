#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>

#include <fstream>

using namespace std;

#define KEEPFILE "CharTimes.txt"

struct HTNode
{
	int weight; // 权重
	char c = 0;		// 对应的字符
	int parent, lchild, rchild;
	int Hex = 0;
};

struct Char
{
	Char(char c = 0, int r = 0, int h = 0, string s = "") : ch(c), rate(r), code(s), Hex(h)
	{
	}
	char ch;
	int rate;
	string code;
	int Hex;
};

HTNode* HT; // 哈夫曼树
int HexDataCount[0xFF + 1];
// char Char[0xFF + 1];
int leaves = 0; // 叶子结点的个数
vector<Char> exist_char;
vector<Char> all_char(0xFF + 1);
// string Char_Code[0xFF + 1];

void Usage();

void CountChar(string& name);

void CreateHTree();

void HuffmanCoding(vector<string>& HuffmanCode);

void PrintCode(vector<string>& HuffmanCode); // 查看编码，调试用

void Compress(string sourcefile, string targetfile);

void SaveHTree(string filename = "HTree");

void SaveBinaryHTree(fstream& file);

void Uncompress(string sourcefile, string targetfile);

void PrintHTree();

void PrintCode();

int main(int argc, char* argv[])
{
	string sourcefile = "test.txt";
	string targetfile = sourcefile + "_";
	if (argc == 3)
		targetfile = argv[2];
	printf("正在把%s压缩为%s,请稍后\n", sourcefile.c_str(), targetfile.c_str());

	CountChar(sourcefile); // 第一步，统计目标文件的字符对应数量

	CreateHTree(); // 构造哈夫曼树

	//PrintHTree();

	vector<string> HuffmanCode(leaves + 1);
	HuffmanCoding(HuffmanCode); // 根据哈夫曼树进行编码，存储在HuffmanCode中

	// PrintCode();

	Compress(sourcefile, targetfile);

	//SaveHTree(targetfile);

	Uncompress(sourcefile + "_", targetfile + "__");

	return 0;
}

void Usage()
{
	cout << "压缩使用说明书" << endl;
}

void check_file_open(const fstream& file, const string& name)
{
	if (file.fail())
	{
		cout << name << "打开失败" << endl;
		exit(0);
	}
}

void CountChar(string& name)
{
	fstream file, save;
	file.open(name.c_str(), ios::in | ios::binary); // 从该文件中读取字符并统计
	check_file_open(file, name);
	save.open(KEEPFILE, ios::out | ios::binary); // 向该文件中写入字符的个数
	check_file_open(save, KEEPFILE);

	char Byte;
	file.read(&Byte, sizeof(char));
	while (!file.eof())
	{
		// file.read(&Byte, sizeof(char));
		HexDataCount[Byte & 0b11111111]++;
		all_char[Byte & 0b11111111].ch = Byte;
		all_char[Byte & 0b11111111].rate++;
		file.read(&Byte, sizeof(char));
	}
	char buffer[256];
	for (int i = 0; i <= 0xFF; i++)
	{
		all_char[i].Hex = i;
		if (HexDataCount[i])
		{
			leaves++;
			// sprintf(buffer, "%c : %d", Char[i], HexDataCount[i]);
			// save << buffer << endl;
			exist_char.push_back(Char(all_char[i].ch, all_char[i].rate, all_char[i].Hex));
		}
		sprintf(buffer, "%02X==%010d\n", i, HexDataCount[i]);
		save << buffer;
	}

	file.close();
	save.close();
}

void SelectMin(HTNode*& HT, const int n, int& min1, int& min2)
{
	int min_value = INT_MAX;
	for (int i = 1; i <= n; i++)
		if (HT[i].parent == -1 && HT[i].weight < min_value)
		{
			min_value = HT[i].weight;
			min1 = i;
		}

	for (int i = 1, min_value = INT_MAX; i <= n; i++)
		if (HT[i].parent == -1 && HT[i].weight < min_value && i != min1)
		{
			min_value = HT[i].weight;
			min2 = i;
		}
}

void CreateHTree()
{
	int total = 2 * leaves; // total表示总结点个数
	int min1 = 0, min2 = 0; // 最小值和倒数第二小的值

	HT = new HTNode[total];
	for (int i = 1; i < total; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		if (i <= leaves)
		{
			HT[i].c = exist_char[i - 1].ch;
			HT[i].weight = exist_char[i - 1].rate;
			HT[i].Hex = exist_char[i - 1].Hex;
		}
	}

	for (int i = leaves + 1; i < total; i++)
	{
		SelectMin(HT, i - 1, min1, min2); // 在区间[0,i)区间找
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
}

void HuffmanCoding(vector<string>& HuffmanCode)
{
	string EachCode(leaves, 0);
	for (int i = 1; i <= leaves; i++)
	{
		EachCode.clear();
		int j = i, parent = HT[j].parent;
		while (parent != -1)
		{
			if (j == HT[parent].lchild)
				EachCode.push_back('0');
			else
				EachCode.push_back('1');
			j = parent;
			parent = HT[parent].parent;
		}
		reverse(EachCode.begin(), EachCode.end());

		HuffmanCode[i] = EachCode;
		all_char[exist_char[i - 1].ch & 0b11111111].code = EachCode;
		exist_char[i - 1].code = EachCode;
	}
}

void PrintCode()
{
	// for (int i = 0; i <= 0xFF; i++)
	// {
	// 	cout << i << ":";
	// 	if (all_char[i].rate == 0)
	// 		cout << "(null)";
	// 	else
	// 		cout << all_char[i].code;
	// 	cout << endl;
	// }
	for (int i = 0; i < exist_char.size(); i++)
	{
		cout << exist_char[i].ch << ":" << exist_char[i].code << endl;
	}
}

void PrintCode(vector<string>& HuffmanCode)
{
	for (int i = 1; i <= leaves; i++)
	{
		printf("%c出现%d次，编码为：", exist_char[i - 1].ch, exist_char[i - 1].rate);
		cout << HuffmanCode[i] << endl;
	}
}

void Compress(string sourcefile, string targetfile)
{
	fstream file1, file2;
	file1.open(sourcefile.c_str(), ios::in | ios::binary);
	file2.open(targetfile.c_str(), ios::out | ios::binary);

	if (leaves == 1)
	{
		//
	}
	SaveBinaryHTree(file2);

	char Byte;
	string s;
	file1.read(&Byte, sizeof(char));
	while (!file1.eof())
	{
		s.append(all_char[Byte & 0b11111111].code);
		file1.read(&Byte, sizeof(char));
	}

	fstream file3;
	file3.open("string.txt", ios::out | ios::binary);
	file3 << s;
	file3.close();

	string tmp;
	for (int i = 0; i < s.size(); i++)
	{
		if (i % 8 == 0 && i)
		{
			int byte = 0;
			for (int j = 0; j < 8; j++)
			{
				byte <<= 1;
				byte += tmp[j] - '0';
			}
			unsigned char c = byte;
			file2.write((char*)&c, sizeof(c));
			tmp.clear();
			tmp.append(1, s[i]);
		}
		else
			tmp.append(1, s[i]);
	}

	int byte = 0;
	for (int j = 0; j < tmp.size(); j++)
	{
		byte <<= 1;
		byte += tmp[j] - '0';
	}
	unsigned char c = byte;
	file2.write((char*)&c, sizeof(c));

	c = (unsigned char)tmp.size() + 48;
	file2.write((char*)&c, sizeof(c));

	file1.close();
	file2.close();
}

// 	a = 0;
// 	for (int j = 0; j < tmp.length(); j++)
// 	{
// 		a = a + (int)(pow(2, 7 - j) * (tmp[j] - 48));
// 	}
// 	c1 = a;
// 	file2.write((char *)&c1, sizeof(c1));
// }

void SaveHTree(string filename)
{
	// fstream file;
	// file.open(filename.c_str(), ios::out | ios::binary);

	// file << leaves << endl;
	// for(int i = 1; i < 2 * leaves; i++)
	// {
	// 	file << HT[i].c << " " << HT[i].lchild << " " << HT[i].rchild << endl;
	// }
	// file.close();
	filename += "_HTree";

	FILE* file;
	file = fopen(filename.c_str(), "wb");
	if (file == NULL)
	{
		printf("文件%s打开失败\n", filename.c_str());
		exit(-1);
	}

	fprintf(file, "%d\n", leaves);

	for (int i = 1; i < 2 * leaves; i++)
	{
		fprintf(file, "%02X %d %d\n", HT[i].Hex, HT[i].lchild, HT[i].rchild);
	}

	fclose(file);
}

void PrintHTree()
{
	// int total = 2 * leaves;
	// for (int i = 1; i < total; i++)
	// {
	// 	//cout << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild << " " << HT[i].rchild << endl;
	// 	cout << exist_char[i].code << endl;
	// }

	/*for (int i = 0; i < exist_char.size(); i++)
	{
		cout << exist_char[i].code << endl;
	}*/

	for (int i = 1; i < 2 * leaves; i++)
	{
		cout << (int)HT[i].c << " " << HT[i].lchild << " " << HT[i].rchild << endl;
	}
}

void ReadBinaryHTree(fstream& file)
{
	// 先读16位，然后解析成整数num，循环num次，分别读8位、16位、16位、代表ch，lc，rc
	int num = 0;
	char Byte1;
	char Byte2;
	file.read(&Byte1, sizeof(char));
	file.read(&Byte2, sizeof(char));
	
	num += (int)((unsigned char)Byte1);
	num <<= 8;
	num += (int)((unsigned char)Byte2);

	leaves = num;

	HT = new HTNode[2 * leaves];

	for (int i = 1; i < 2 * leaves; i++)
	{
		num = 0;
		file.read(&Byte1, sizeof(Byte1));
		HT[i].c = Byte1;

		num = 0;
		file.read(&Byte1, sizeof(char));
		file.read(&Byte2, sizeof(char));
		num += (int)((unsigned char)Byte1);
		num <<= 8;
		num += (int)((unsigned char)Byte2);
		HT[i].lchild = num;

		num = 0;
		file.read(&Byte1, sizeof(char));
		file.read(&Byte2, sizeof(char));
		num += (int)((unsigned char)Byte1);
		num <<= 8;
		num += (int)((unsigned char)Byte2);
		HT[i].rchild = num;
	}
}

void Uncompress(string sourcefile, string targetfile)
{
	fstream file1, file2;
	file1.open(sourcefile.c_str(), ios::in | ios::binary);
	check_file_open(file1, sourcefile);
	file2.open(targetfile.c_str(), ios::out | ios::binary);
	check_file_open(file2, targetfile);

	ReadBinaryHTree(file1); // 新添加的代码
	for (int i = 1; i <= leaves; i++)
		HT[i].lchild = HT[i].rchild = -1;
	//PrintHTree();

	string s, tmp;
	// unsigned char c;
	char Byte;
	// file1.read((char *)&c, sizeof(c));
	file1.read(&Byte, sizeof(char));
	while (!file1.eof())
	{
		// int a = c;
		int a = Byte & 0b11111111;
		while (a > 0)
		{
			tmp.append(1, (a % 2) + '0');
			a /= 2;
		}

		int len = (int)tmp.size();
		for (int i = 0; i < 8 - len; i++)
			tmp.append(1, '0');

		reverse(tmp.begin(), tmp.end());

		s.append(tmp);
		tmp.clear();

		// file1.read((char *)&c, sizeof(c));
		file1.read(&Byte, sizeof(char));
	}

	fstream file3;
	file3.open("string_.txt", ios::out | ios::binary);
	file3 << s;
	file3.close();

	string last;
	int num = 0, ret = 1;
	int size = (int)s.size();
	for (int i = 0; i < 8; i++)
	{
		num += (s[size - 1 - i] - '0') * ret;
		ret *= 2;
		s.pop_back();
	}
	num -= 48;
	// cout << num << endl;
	size = (int)s.size();
	for (int i = 0; i < 8; i++)
	{
		last += s[size - 1 - i];
		s.pop_back();
	}
	for (int i = 0; i < 8 - num; i++)
		last.pop_back();

	reverse(last.begin(), last.end());
	// cout << last << endl;
	s += last;
	// cout << s << endl;

	int k = 0;
	while (k < s.size())
	{
		int i = 2 * leaves - 1;
		while (HT[i].lchild != -1 || HT[i].rchild != -1)
		{
			if (s[k] == '0')
				i = HT[i].lchild;
			else
				i = HT[i].rchild;
			k++;
		}
		// file2.put(HT[i].c);
		file2.write(&HT[i].c, sizeof(char));
	}

	file1.close();
	file2.close();
}

void SaveBinaryHTree(fstream& file)
{
	// 把leaves用16位来存储，ch用8位，lc和rc用16位
	string s;
	int ret = leaves;
	while (ret)
	{
		s += (ret % 2) + '0';
		ret /= 2;
	}

	int len = (int)s.size();
	for (int i = 0; i < 16 - len; i++)
		s += '0';
	reverse(s.begin(), s.end());

	string tmp;

	for (int i = 1; i < 2 * leaves; i++)
	{
		ret = HT[i].Hex;
		while (ret)
		{
			tmp += (ret % 2) + '0';
			ret /= 2;
		}

		len = (int)tmp.size();
		for (int i = 0; i < 8 - len; i++)
			tmp += '0';
		reverse(tmp.begin(), tmp.end());

		s += tmp;
		tmp.clear();

		ret = HT[i].lchild;
		while (ret)
		{
			tmp += (ret % 2) + '0';
			ret /= 2;
		}

		len = (int)tmp.size();
		for (int i = 0; i < 16 - len; i++)
			tmp += '0';
		reverse(tmp.begin(), tmp.end());

		s += tmp;
		tmp.clear();

		ret = HT[i].rchild;
		while (ret)
		{
			tmp += (ret % 2) + '0';
			ret /= 2;
		}

		len = (int)tmp.size();
		for (int i = 0; i < 16 - len; i++)
			tmp += '0';
		reverse(tmp.begin(), tmp.end());

		s += tmp;
		tmp.clear();
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (i % 8 == 0 && i)
		{
			int byte = 0;
			for (int j = 0; j < 8; j++)
			{
				byte <<= 1;
				byte += tmp[j] - '0';
			}
			unsigned char c = byte;
			file.write((char*)&c, sizeof(c));
			tmp.clear();
			tmp.append(1, s[i]);
		}
		else
			tmp.append(1, s[i]);
	}
	if (tmp.size() != 8)
	{
		cout << "该字符串长度不为8" << endl;
		exit(-1);
	}
	int byte = 0;
	for (int j = 0; j < 8; j++)
	{
		byte <<= 1;
		byte += tmp[j] - '0';
	}
	unsigned char c = byte;
	file.write((char*)&c, sizeof(c));
	tmp.clear();
}