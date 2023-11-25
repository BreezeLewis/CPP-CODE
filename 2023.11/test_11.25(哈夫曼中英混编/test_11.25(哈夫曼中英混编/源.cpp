#include<string>
#include<fstream>
#include <iostream>
#include<vector>
#include<map>
using namespace std;
typedef struct huffmannode {
	string ch;	//�ַ�(�ȿ�����Ӣ���ַ���Ҳ�����Ǻ���)
	int weight = 0;	//Ȩ��
	int father = 0;	//���ڵ�
	int lc = 0, rc = 0;	//�ӽڵ�
}huffmanNode;

map<string, int>weightMap;//Ȩ��ͼ
vector<huffmanNode>huffmanTree;//��������
map<string, string>passworldMap;//������洢ÿ���ַ���Ӧ�Ĺ��������룩

//�ж��ַ��Ƿ�ΪӢ���ַ��������ĺ���(�����ı�ֻ������Ӣ��)
bool judgeEng(unsigned char c)
{
	if (!(c & 0x80))
		return true;
	return false;
}

//��ȡҪѹ�����ļ�,��ȡÿ���ַ���Ȩ��
void getWeightMap(ifstream& fin, const char* fileName, map<string, int>& _weightMap)
{
	fin.open(fileName, ios::in);
	if (!fin.is_open())
	{
		cout << "����" << endl;
		return;
	}
	unsigned char c;
	string s;
	while (!fin.eof())
	{
		c = fin.get();
		if (fin.eof())
			break;
		s = "";
		if (judgeEng(c))
			s += c;
		else
		{
			s += c;
			c = fin.get();
			s += c;
			c = fin.get();
			s += c;
		}
		_weightMap[s]++;
	}
	fin.close();
}

//ѡ��������С��Ȩ��
void selectTwo(vector<huffmannode>& _huffmanTree, int n, int& s1, int& s2)
{
	int min = 200000000;
	for (int i = 0; i < n; ++i) {
		if (_huffmanTree.at(i).father == 0) {
			if (_huffmanTree.at(i).weight < min) {
				min = _huffmanTree.at(i).weight;
				s1 = i;
			}
		}
	}
	min = 200000000;
	for (int i = 0; i < n; ++i) {
		if (_huffmanTree.at(i).father == 0) {
			if (_huffmanTree.at(i).weight < min && i != s1) {
				min = _huffmanTree.at(i).weight;
				s2 = i;
			}
		}
	}
}

//������������
void getHuffmanTree(map<string, int>& _weightMap, vector<huffmanNode>& _huffmanTree)
{
	int n = (int)_weightMap.size();
	for (auto it : _weightMap) {
		huffmannode t;
		t.ch = it.first;
		t.weight = it.second;
		_huffmanTree.push_back(t);
	}
	int s1 = 0, s2 = 0;
	for (int i = n; i < 2 * n - 1; ++i) {
		huffmannode t;
		selectTwo(_huffmanTree, i, s1, s2);
		_huffmanTree.at(s1).father = i;
		_huffmanTree.at(s2).father = i;
		t.lc = s1;
		t.rc = s2;
		t.weight = _huffmanTree.at(s1).weight + _huffmanTree.at(s2).weight;
		_huffmanTree.push_back(t);
	}
}

//���ݹ��������õ�ÿ���ַ��Ĺ���������
void getPassworld(vector<huffmannode>& _huffmanTree, map<string, string>& _passworldMap)
{
	int n = ((int)_huffmanTree.size() + 1) / 2;
	for (int i = 0; i < n; ++i) {
		string passworld = "";
		int t = i;
		int fa = _huffmanTree.at(i).father;
		while (fa) {
			if (_huffmanTree.at(fa).lc == t)
				passworld = '0' + passworld;
			else if (_huffmanTree.at(fa).rc == t)
				passworld = '1' + passworld;
			t = fa;
			fa = _huffmanTree.at(t).father;
		}
		_passworldMap.emplace(huffmanTree.at(i).ch, passworld);
	}
}

//���õ��������ַ��Ĺ���������ÿ8λת����һ��uchar
unsigned char binaryStringToChar(string binarystring)
{
	int sum = 0;
	for (int i = 0; i < binarystring.size(); i++)
	{
		if (binarystring[i] == '1')
		{
			int j = (int)pow(2, binarystring.size() - i - 1);
			sum += j;
		}
	}
	unsigned char ch = sum;
	return ch;
}

//ѹ���ļ�
void compressFile(ifstream& fin, const char* fileName, ofstream& fout, const char* compressFileName)
{
	if (!weightMap.empty())
		weightMap.clear();
	if (!huffmanTree.empty())
		huffmanTree.clear();
	if (!passworldMap.empty())
		passworldMap.clear();
	getWeightMap(fin, fileName, weightMap);
	getHuffmanTree(weightMap, huffmanTree);
	getPassworld(huffmanTree, passworldMap);

	string binary = "";
	fin.open(fileName, ios::in);
	unsigned char c;
	binary = "";
	while (!fin.eof())
	{
		c = fin.get();
		if (fin.eof())
			break;
		string s = "";
		if (judgeEng(c))
			s += c;
		else
		{
			s += c;
			c = fin.get();
			s += c;
			c = fin.get();
			s += c;
		}
		binary += passworldMap[s];
	}
	fin.close();
	//����8λ�ĺ��油0
	int add0Num = binary.size() % 8;
	if (add0Num)
		add0Num = 8 - add0Num;
	for (int i = 0; i < add0Num; ++i, binary += '0');

	fout.open(compressFileName, ios::out | ios::binary);

	// ��������Ϣ(ÿ���ַ����ַ���Ȩ�أ��Լ�����0�ĸ���)д��ѹ���ļ���
	fout << weightMap.size() << " " << add0Num << " ";
	for (auto it : weightMap)
	{
		fout << it.first << " " << it.second << " ";
	}

	//���õ��Ķ������ַ���ÿ8λתΪһ��uchar����д��ѹ���ļ�
	for (int i = 0; i < binary.size(); i += 8)
	{
		string k = binary.substr(i, 8);
		c = binaryStringToChar(k);
		fout << c;
	}
	fout.close();
}

//��uchar�ַ�ת����2���Ƶ��ַ���
string ucharToBinaryString(unsigned char value)
{
	string b = "";
	for (int n = 0x80; n > 0; n >>= 1)
	{
		if (n & value)
			b += '1';
		else
			b += '0';
	}
	return b;
}

//��ѹ�ļ�
void decompressFile(ifstream& fin, const char* compressFileName, ofstream& fout, const char* decompressfileName)
{
	fin.open(compressFileName, ios::in | ios::binary);

	if (!fin.is_open())
		cout << "����";

	unsigned char c;
	int size, add0;
	map<string, int>_weightmap;
	fin >> size >> add0;	//��ȡ������Ϣ�в���0�ĸ���
	fin.get();
	for (int i = 0; i < size; ++i)	//��ȡ������Ϣ��ÿ���ַ�����Ȩ�أ��õ�ԭ�ļ���Ȩ��ͼ
	{
		string s = "";
		int weight = 0;
		c = fin.get();
		if (judgeEng(c))
			s += c;
		else
		{
			s += c;
			c = fin.get();
			s += c;
			c = fin.get();
			s += c;
		}
		c = fin.get();
		c = fin.get();
		for (; c != ' '; c = fin.get())
		{
			weight = weight * 10 + c - '0';
		}
		_weightmap.emplace(s, weight);
	}

	//ͨ��Ȩ��ͼ��ԭ��������
	vector<huffmannode>_huffmantree;
	getHuffmanTree(_weightmap, _huffmantree);

	string binary = "";
	while (!fin.eof())	//��ѹ���ļ��е�ucharת���� 2�����ַ���(��ԭ�ļ��еĹ���������)
	{
		c = fin.get();
		if (fin.eof())
			break;
		binary += ucharToBinaryString(c);
	}
	fin.close();

	for (int i = 0; i < add0; binary.pop_back(), ++i);

	//���ݹ���������ѹ���ļ������ݽ�ѹ
	fout.open(decompressfileName, ios::out);
	int n = (int)binary.size();
	int len = (int)_huffmantree.size();
	int fa = len - 1;
	for (int k = 0; k < n; ++k) {
		if (binary.at(k) == '0')
			fa = _huffmantree.at(fa).lc;
		else if (binary.at(k) == '1')
			fa = _huffmantree.at(fa).rc;

		if (_huffmantree.at(fa).lc == _huffmantree.at(fa).rc)
		{
			fout << _huffmantree.at(fa).ch;
			fa = len - 1;
		}
	}
	fout.close();
}

int main()
{
	ifstream fin;
	ofstream fout;
	char filename[] = "D:\\code\\2023��\\2023��11��\\test_11.25(��������Ӣ���\\test_11.25(��������Ӣ���\\Huffman�������.txt";//��Ҫѹ�����ļ�·��
	char compressfilename[] = "D:\\code\\2023��\\2023��11��\\test_11.25(��������Ӣ���";//ѹ������ļ�·��
	char decompressfilename[] = "D:\\code\\2023��\\2023��11��\\test_11.25(��������Ӣ���";//��ѹ������ļ�·��
	compressFile(fin, filename, fout, compressfilename);
	decompressFile(fin, compressfilename, fout, decompressfilename);
	return 0;
}