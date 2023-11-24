//>mycompress soucefile[targetfile]
//
//这里mycompress.exe是压缩文件， soucefile是要压缩的文件，targetfile是压缩后的文件，targetfile没有提供时，压缩后的文件可以用某个默认的文件名。
//
 //这里的哈夫曼编码采用顺序结构
# include <iostream>
# include <fstream>
# include <algorithm>
# include <string>
# define SIZE 128
# define Infinity 1e9
using namespace std;

//字符型结构体
typedef struct Character {
	char c;         //字符
	int weight;     //权重
	char code[20];  //编码结果
}Character, * Chara;

typedef struct HTNode {
	int data;  //对应的权重值
	char c;    //对应的字符（只有叶结点才有）
	int parent, lchild, rchild;
}HTNode, * HufTree;

Chara ch;                 //保存所有字符信息
HufTree HT;               //哈夫曼树
string str;               //以01的形式保存所有的字符
int total = 0;            //字符总数
int Visit[SIZE] = { 0 };  //统计都有哪些字符,并保存字符的数组下标
void CountChar();         //统计文件里的字符及权重
void Hufcode();           //哈夫曼编码
void Print();             //输出每个字符出现的次数和编码
void CodeFile();          //对文件内容进行哈夫曼编码
void DeCode();            //解码

int main()
{
	CountChar();
	Hufcode();
	Print();
	CodeFile();
	DeCode();
	return 0;
}

void CountChar()    //统计文件里的字符及权重
{
	fstream file;
	file.open("Huffman编码材料.txt", ios::in);
	if (file.fail()) {
		cout << "Huffman编码材料.txt打开失败" << endl;
		exit(0);
	}
	char c;
	//ch = (Chara)malloc(SIZE * sizeof(Character));
	ch = new Character[SIZE];
	file.get(c);   //一次读取单个字符
	while (!file.eof()) {
		int k = c;
		//查看该字符是否已在数组中
		if (Visit[k]) {
			ch[Visit[k]].weight++;
		}
		else {
			total++;
			ch[total].c = c;
			ch[total].weight = 1;
			Visit[k] = total;
		}
		file.get(c);
	}
	file.close();
}

void Hufcode()   //哈夫曼编码
{
	//HT = (HufTree)malloc(2 * total * sizeof(HTNode)); //哈夫曼树总结点有2*total-1个，动态分配2*total个空间
	HT = new HTNode[2 * total];
	for (int i = 1; i <= total; i++) {
		//建立原始结点
		HT[i].data = ch[i].weight;
		HT[i].c = ch[i].c;
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
	}
	//构建哈夫曼树
	//哈夫曼树中共有2*total-1个结点，所以循环到2*total-1
	for (int i = total + 1; i < 2 * total; i++) {
		//寻找两个根节点权值最小的树
		int m1 = i - 1, m2 = i - 1;         //m1保存第一小的位置，m2保存第二小的位置
		int x1 = (int)Infinity, x2 = (int)Infinity;   //x1保存第一小的值，x2保存第二小的值
		for (int j = 1; j < i; j++) {
			//从第一个结点到当前的最后一个结点，寻找两个权重最小的位置
			if (HT[j].parent == -1 && HT[j].data < x1) {
				//符合条件的值，双亲必须为空
				x2 = x1;
				x1 = HT[j].data;
				m2 = m1;  //m2接替原m1，保存当前第二小的位置
				m1 = j;   //将当前最小值的位置赋给m1
			}
			else if (HT[j].parent == -1 && HT[j].data < x2) {
				x2 = HT[j].data;
				m2 = j;
			}
		}
		//添加新树
		HT[m1].parent = i;  //添加双亲
		HT[m2].parent = i;  //添加双亲
		HT[i].data = HT[m1].data + HT[m2].data; //新加入的结点，权重为两个最小值的和
		HT[i].lchild = m1;  //将第一小的位置作为左子树
		HT[i].rchild = m2;  //将第二小的位置作为右子树
		HT[i].parent = -1;  //新结点的双亲为空
	}
	//依据哈夫曼树，求各原始节点的编码
	for (int i = 1; i <= total; i++) {
		char s[20];
		int j = i, k = 0;
		int p = HT[j].parent;
		while (p != -1) {
			if (j == HT[p].lchild) {
				s[k] = '0';   //如果是双亲的左子树则编为0
			}
			else {
				s[k] = '1';  //如果是双亲的右子树则编为1
			}
			k++;
			j = p;
			p = HT[p].parent;
		}
		s[k] = '\0';
		for (int l = 0; l < k; l++) {
			//倒序输出的才是正确的编码方式
			ch[i].code[k - 1 - l] = s[l];
		}
		ch[i].code[k] = '\0';
	}
}

void Print()  //输出每个字符出现的次数和编码
{
	fstream file;
	file.open("Huffman.txt", ios::out);
	if (file.fail()) {
		cout << "Huffman.txt打开失败" << endl;
		exit(0);
	}
	file << "编号" << '\t' << "字符" << '\t' << "个数" << '\t' << "编码" << endl;
	for (int i = 1; i <= total; i++) {
		//将字符、字符出现的次数和编码转换成字符串保存到文本文件Huffman.txt中
		file << i << '\t' << ch[i].c << '\t' << ch[i].weight << '\t' << ch[i].code << endl;
	}
	file.close();
	cout << "每个字符出现的次数和编码:\n" << endl;
	file.open("Huffman.txt", ios::in);
	if (file.fail()) {
		cout << "Huffman.txt打开失败" << endl;
		exit(0);
	}
	char s[100];
	file.getline(s, 100);
	while (!file.eof()) {
		cout << s << endl;
		file.getline(s, 100);
	}
	file.close();
}

void CodeFile()   //对文件内容进行哈夫曼编码
{
	fstream file1, file2;
	file1.open("Huffman编码材料.txt", ios::in);
	file2.open("code.dat", ios::out | ios::binary);
	if (file1.fail()) {
		cout << "Huffman编码材料.txt文件打开失败" << endl;
		exit(0);
	}
	if (file2.fail()) {
		cout << "code.dat文件打开失败" << endl;
		exit(0);
	}
	char c;
	file1.get(c);
	while (!file1.eof()) {
		int k = c;
		for (int i = 0; i < strlen(ch[Visit[k]].code); i++) {
			str.append(1, ch[Visit[k]].code[i]);
		}
		file1.get(c);
	}
	string str1;
	//采用无符号字符类型，范围为0-255（与8位对应）
	unsigned char c1;
	int a;
	for (int i = 0; i < str.length(); i++) {
		//每8位取一个，组成一个新字符（无符号）
		if (i % 8 == 0 && i != 0) {
			a = 0;
			for (int j = 0; j < 8; j++) {
				a = a + (int)(pow(2, 7 - j) * (str1[j] - '0'));
			}
			c1 = a;
			file2.write((char*)&c1, sizeof(c1));
			str1.clear();
			str1.append(1, str[i]);
		}
		else {
			str1.append(1, str[i]);
		}
	}
	a = 0;
	for (int j = 0; j < str1.length(); j++) {
		a = a + (int)(pow(2, 7 - j) * (str1[j] - 48));
	}
	c1 = a;
	file2.write((char*)&c1, sizeof(c1));
	c1 = (unsigned char)str1.length() + 48;   //多读一位，作为对前一位的位数的提示
	file2.write((char*)&c1, sizeof(c1));
	file1.close();
	file2.close();
}

void DeCode()    //解码
{
	fstream file1, file2;
	file1.open("code.dat", ios::in | ios::binary);
	file2.open("recode.txt", ios::out);
	if (file1.fail()) {
		cout << "code.dat文件打开失败" << endl;
		exit(0);
	}
	if (file2.fail()) {
		cout << "recode.txt文件打开失败" << endl;
		exit(0);
	}
	file1.seekg(-1L, ios::end);
	int p = (int)file1.tellg();       //获取倒数第二的位置
	file1.seekg(0L, ios::beg);
	string s, s1;
	unsigned char c, c1;
	int a, b = 0, d;
	file1.read((char*)&c, sizeof(c));
	while (!file1.eof()) {
		if (file1.tellg() == p) {
			//读到倒数第二个字符
			b = 1;
		}
		a = c;
		while (a > 0) {
			c1 = a % 2 + '0';
			s1.append(1, c1);
			a = a / 2;
		}
		int len = (int)s1.length();
		for (int i = 0; i < 8 - len; i++) {
			//如果转成的二进制数不足8位，则要在前面补0
			s1.append(1, '0');
		}
		reverse(s1.begin(), s1.end());
		if (b) {
			//读取最后一个数位提示符，说明保留几位
			file1.read((char*)&c, sizeof(c));
			d = c - '0';
			s1.assign(s1, 0, d);
		}
		s.append(s1);
		s1.clear();
		if (b) {
			break;
		}
		else {
			file1.read((char*)&c, sizeof(c));
		}
	}
	int k = 0;
	while (k < s.length()) {
		int i = 2 * total - 1;
		while (HT[i].lchild != -1 || HT[i].rchild != -1) {
			if (s[k] == '0') {
				i = HT[i].lchild;
			}
			else {
				i = HT[i].rchild;
			}
			k++;
		}
		file2.put(HT[i].c);
	}
	file1.close();
	file2.close();
}