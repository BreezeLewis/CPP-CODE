//>mycompress soucefile[targetfile]
//
//����mycompress.exe��ѹ���ļ��� soucefile��Ҫѹ�����ļ���targetfile��ѹ������ļ���targetfileû���ṩʱ��ѹ������ļ�������ĳ��Ĭ�ϵ��ļ�����
//
 //����Ĺ������������˳��ṹ
# include <iostream>
# include <fstream>
# include <algorithm>
# include <string>
# define SIZE 128
# define Infinity 1e9
using namespace std;

//�ַ��ͽṹ��
typedef struct Character {
	char c;         //�ַ�
	int weight;     //Ȩ��
	char code[20];  //������
}Character, * Chara;

typedef struct HTNode {
	int data;  //��Ӧ��Ȩ��ֵ
	char c;    //��Ӧ���ַ���ֻ��Ҷ�����У�
	int parent, lchild, rchild;
}HTNode, * HufTree;

Chara ch;                 //���������ַ���Ϣ
HufTree HT;               //��������
string str;               //��01����ʽ�������е��ַ�
int total = 0;            //�ַ�����
int Visit[SIZE] = { 0 };  //ͳ�ƶ�����Щ�ַ�,�������ַ��������±�
void CountChar();         //ͳ���ļ�����ַ���Ȩ��
void Hufcode();           //����������
void Print();             //���ÿ���ַ����ֵĴ����ͱ���
void CodeFile();          //���ļ����ݽ��й���������
void DeCode();            //����

int main()
{
	CountChar();
	Hufcode();
	Print();
	CodeFile();
	DeCode();
	return 0;
}

void CountChar()    //ͳ���ļ�����ַ���Ȩ��
{
	fstream file;
	file.open("Huffman�������.txt", ios::in);
	if (file.fail()) {
		cout << "Huffman�������.txt��ʧ��" << endl;
		exit(0);
	}
	char c;
	//ch = (Chara)malloc(SIZE * sizeof(Character));
	ch = new Character[SIZE];
	file.get(c);   //һ�ζ�ȡ�����ַ�
	while (!file.eof()) {
		int k = c;
		//�鿴���ַ��Ƿ�����������
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

void Hufcode()   //����������
{
	//HT = (HufTree)malloc(2 * total * sizeof(HTNode)); //���������ܽ����2*total-1������̬����2*total���ռ�
	HT = new HTNode[2 * total];
	for (int i = 1; i <= total; i++) {
		//����ԭʼ���
		HT[i].data = ch[i].weight;
		HT[i].c = ch[i].c;
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
	}
	//������������
	//���������й���2*total-1����㣬����ѭ����2*total-1
	for (int i = total + 1; i < 2 * total; i++) {
		//Ѱ���������ڵ�Ȩֵ��С����
		int m1 = i - 1, m2 = i - 1;         //m1�����һС��λ�ã�m2����ڶ�С��λ��
		int x1 = (int)Infinity, x2 = (int)Infinity;   //x1�����һС��ֵ��x2����ڶ�С��ֵ
		for (int j = 1; j < i; j++) {
			//�ӵ�һ����㵽��ǰ�����һ����㣬Ѱ������Ȩ����С��λ��
			if (HT[j].parent == -1 && HT[j].data < x1) {
				//����������ֵ��˫�ױ���Ϊ��
				x2 = x1;
				x1 = HT[j].data;
				m2 = m1;  //m2����ԭm1�����浱ǰ�ڶ�С��λ��
				m1 = j;   //����ǰ��Сֵ��λ�ø���m1
			}
			else if (HT[j].parent == -1 && HT[j].data < x2) {
				x2 = HT[j].data;
				m2 = j;
			}
		}
		//�������
		HT[m1].parent = i;  //���˫��
		HT[m2].parent = i;  //���˫��
		HT[i].data = HT[m1].data + HT[m2].data; //�¼���Ľ�㣬Ȩ��Ϊ������Сֵ�ĺ�
		HT[i].lchild = m1;  //����һС��λ����Ϊ������
		HT[i].rchild = m2;  //���ڶ�С��λ����Ϊ������
		HT[i].parent = -1;  //�½���˫��Ϊ��
	}
	//���ݹ������������ԭʼ�ڵ�ı���
	for (int i = 1; i <= total; i++) {
		char s[20];
		int j = i, k = 0;
		int p = HT[j].parent;
		while (p != -1) {
			if (j == HT[p].lchild) {
				s[k] = '0';   //�����˫�׵����������Ϊ0
			}
			else {
				s[k] = '1';  //�����˫�׵����������Ϊ1
			}
			k++;
			j = p;
			p = HT[p].parent;
		}
		s[k] = '\0';
		for (int l = 0; l < k; l++) {
			//��������Ĳ�����ȷ�ı��뷽ʽ
			ch[i].code[k - 1 - l] = s[l];
		}
		ch[i].code[k] = '\0';
	}
}

void Print()  //���ÿ���ַ����ֵĴ����ͱ���
{
	fstream file;
	file.open("Huffman.txt", ios::out);
	if (file.fail()) {
		cout << "Huffman.txt��ʧ��" << endl;
		exit(0);
	}
	file << "���" << '\t' << "�ַ�" << '\t' << "����" << '\t' << "����" << endl;
	for (int i = 1; i <= total; i++) {
		//���ַ����ַ����ֵĴ����ͱ���ת�����ַ������浽�ı��ļ�Huffman.txt��
		file << i << '\t' << ch[i].c << '\t' << ch[i].weight << '\t' << ch[i].code << endl;
	}
	file.close();
	cout << "ÿ���ַ����ֵĴ����ͱ���:\n" << endl;
	file.open("Huffman.txt", ios::in);
	if (file.fail()) {
		cout << "Huffman.txt��ʧ��" << endl;
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

void CodeFile()   //���ļ����ݽ��й���������
{
	fstream file1, file2;
	file1.open("Huffman�������.txt", ios::in);
	file2.open("code.dat", ios::out | ios::binary);
	if (file1.fail()) {
		cout << "Huffman�������.txt�ļ���ʧ��" << endl;
		exit(0);
	}
	if (file2.fail()) {
		cout << "code.dat�ļ���ʧ��" << endl;
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
	//�����޷����ַ����ͣ���ΧΪ0-255����8λ��Ӧ��
	unsigned char c1;
	int a;
	for (int i = 0; i < str.length(); i++) {
		//ÿ8λȡһ�������һ�����ַ����޷��ţ�
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
	c1 = (unsigned char)str1.length() + 48;   //���һλ����Ϊ��ǰһλ��λ������ʾ
	file2.write((char*)&c1, sizeof(c1));
	file1.close();
	file2.close();
}

void DeCode()    //����
{
	fstream file1, file2;
	file1.open("code.dat", ios::in | ios::binary);
	file2.open("recode.txt", ios::out);
	if (file1.fail()) {
		cout << "code.dat�ļ���ʧ��" << endl;
		exit(0);
	}
	if (file2.fail()) {
		cout << "recode.txt�ļ���ʧ��" << endl;
		exit(0);
	}
	file1.seekg(-1L, ios::end);
	int p = (int)file1.tellg();       //��ȡ�����ڶ���λ��
	file1.seekg(0L, ios::beg);
	string s, s1;
	unsigned char c, c1;
	int a, b = 0, d;
	file1.read((char*)&c, sizeof(c));
	while (!file1.eof()) {
		if (file1.tellg() == p) {
			//���������ڶ����ַ�
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
			//���ת�ɵĶ�����������8λ����Ҫ��ǰ�油0
			s1.append(1, '0');
		}
		reverse(s1.begin(), s1.end());
		if (b) {
			//��ȡ���һ����λ��ʾ����˵��������λ
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