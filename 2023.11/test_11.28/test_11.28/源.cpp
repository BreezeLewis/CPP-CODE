#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <windows.h>

#define Line 200
#define HuffCodeLen 200//������������󳤶�
#define PATH_MAX 300
#define ErrOpen(filename) { printf("�ļ�%s��ʧ��!\n",filename); exit(1);}

typedef struct
{
	int hufnode;
}DataType;

typedef struct HTNode
{
	DataType data;
	int weight;
	int lchild, rchild, parent;
}HTNode, * HTree;

typedef char** HuffmanCode;

/*ȫ�ֱ���*/
char fOriginFile[PATH_MAX] = "1.txt";
char fDataTimes[PATH_MAX] = "DataTimes.txt";
char fCompress[PATH_MAX] = "Compress.txt";
char fHuffmanCode[PATH_MAX] = "HuffmanCode.txt";
char fDeCompress[PATH_MAX] = "DeCompress.txt";

int HexDataTimes[0xFF + 1] = { 0 };

int N;
HTree HT = NULL;
HuffmanCode HC, SearchList;


/*ģ��һ*/
void ReadByte_WriteHex(const char* filename, const char* SaveName = fDataTimes);
void memset_int(int* num, int value, int size);
void TransToHex(char* ByteData, int* HexData, int bytenum);
void AddTimes(int* HexDataTimes, int* HexData);
/*ģ���*/
void ReadDataTimes(int* HexDataTimes, const char* filename = fDataTimes);
void CreateHTree(HTree& HT, int& N);
void SelectMin(HTree HT, const int n, int& min1, int& min2);
void HuffmanCoding(HTree HT, HuffmanCode& HC, int n);
/*ģ����*/
void CreateSearchList(HuffmanCode& HC, HuffmanCode& SearchList);
void Compress(HuffmanCode SearchList);
void _01StrCat(char* _01Str, char* OriginCode, int strlen, HuffmanCode SearchList);
void TransWrite(char* _01Str, int _01StrLen, FILE* pfile);
inline void Set_bit(char& a, int bit, int _01);
void WriteHuffmanCode(HuffmanCode SearchList, char* _01Str);
void Free(HTree& HT, HuffmanCode& HC, HuffmanCode& SearchList, int N);
/*ģ����*/
void DeCompress();
void BitToStr(char a, char* Each_Str);
void TransWrite2(char* _01Str, char SearchList[0xFF + 1][HuffCodeLen], FILE* pfile);
int strncmp_(char* str1, char* str2, int strlen);

int main(void)
{

	int function = 0;
	while (1)
	{
		printf("o-------------o\n"
			"|��ѡ����:  |\n"
			"|1.ѹ��       |\n"
			"|2.��ѹ��     |\n"
			"0-------------0\n"
			">>>");
		function = getchar(); getchar();
		switch (function)
		{
		case '1':
		{
			printf("������Ҫѹ���� ·��\\�ļ���:\n>>>");
			scanf("%s", &fOriginFile); getchar();
			strcpy(fCompress, fOriginFile);
			strcat(fCompress, "_");
			//printf("%s  \n%s  \n%s  \n%s   \n%s",fOriginFile,fDataTimes,fCompress,fHuffmanCode,fDeCompress);
			ReadByte_WriteHex(fOriginFile);
			CreateHTree(HT, N);
			HuffmanCoding(HT, HC, N);
			CreateSearchList(HC, SearchList);
			Compress(SearchList);
			Free(HT, HC, SearchList, N);
			//remove(fDataTimes);
			printf("ѹ�����!\n");
		}
		break;

		case '2':
		{
			printf("������Ҫ��ѹ�� ·��\\�ļ���:\n>>>");
			scanf("%s", &fCompress); getchar();
			printf("��ָ����ѹ�� ·��\\�ļ���:\n>>>");
			scanf("%s", &fDeCompress); getchar();
			DeCompress();
			printf("��ѹ���!\n");
		}
		break;
		}
		printf("\n\n�س���������"); getchar();
		system("cls");
		fflush(stdin);
	}
	return 0;
}

/*ģ��һ*///###############################################################
void ReadByte_WriteHex(const char* filename, const char* SaveName)
{

	FILE* pfile_1 = NULL, * pfile_2 = NULL;
	if ((pfile_1 = fopen(filename, "rb")) == NULL)
		ErrOpen(filename);
	if ((pfile_2 = fopen(SaveName, "wb")) == NULL)
	{
		fclose(pfile_1);
		ErrOpen(SaveName);
	}


	int i, bytenum, TF;
	char ByteData[Line + 5] = { 0 }, OneByte;
	int HexData[Line + 1] = { 0 };

	while (feof(pfile_1) == 0)
	{
		memset_int(HexData, -1, sizeof(HexData) / sizeof(int));//ÿ�ζ�����

		for (i = 0, TF = 1; i < Line; ++i)
		{
			TF = (int)fread(&OneByte, sizeof(char), 1, pfile_1);//����Ҫһ��һ���ֽڶ��������Ǵ�����Ϊ
			if (TF)
				ByteData[i] = OneByte;
			else
				break;
		}
		bytenum = i;
		if (bytenum)
			TransToHex(ByteData, HexData, bytenum);//ByteDataת����16�������洢
		AddTimes(HexDataTimes, HexData);
	}
	for (i = 0; i <= 0xFF; ++i)
		fprintf(pfile_2, "%02X==%010d\n", i, HexDataTimes[i]);

	fclose(pfile_1);
	fclose(pfile_2);
}
void memset_int(int* num, int value, int size)
{
	for (int i = 0; i < size; ++i)
		num[i] = value;
}
void TransToHex(char* ByteData, int* HexData, int bytenum)
{
	for (int i = 0; i < bytenum; ++i)
		HexData[i] = ByteData[i] & 0b11111111;
	//Ĩȥ��λ��������λ
}
void AddTimes(int* HexDataTimes, int* HexData)
{
	for (int i = 0; HexData[i] != -1; ++i)
		++HexDataTimes[HexData[i]];
}
//###############################################################/*ģ��һ*/

/*ģ���*///###############################################################
void ReadDataTimes(int* HexDataTimes, const char* filename)
{
	FILE* pfile = NULL;
	if ((pfile = fopen(filename, "rb")) == NULL)
		ErrOpen(filename);
	for (int i = 0; i < 0xFF + 1; ++i)
		fscanf(pfile, "%02X==%010d", &HexDataTimes[i], &HexDataTimes[i]);
	//�����ظ���ֵ������Ϊ����VS2019��֧��*��ֵ���������ظ���ֵ������
	fclose(pfile);
}

void CreateHTree(HTree& HT, int& N)
{
	int i, n, m;
	int min1, min2;
	ReadDataTimes(HexDataTimes);
	int weight[0xFF + 1];
	for (i = 0, n = 0; i < 0xFF + 1; ++i)
	{
		if (HexDataTimes[i] != 0)
		{
			weight[n] = HexDataTimes[i];//�ѷ�0Ȩֵ��ȡ����
			++n;
		}
	}
	N = n;
	m = 2 * n - 1;//weight[0~n-1]��������Է�0Ȩֵ
	HT = (HTree)malloc((m + 1) * sizeof(HTNode));//�������ռ���ȥ0��Ԫ����
	for (i = 0; i <= m; ++i)
		HT[i] = { {0},0,0,0 };//��ʼ��
	for (i = 1; i <= n; ++i)
		HT[i].weight = weight[i - 1];//�����һλ����Ϊweight[]�Ǵ�0��ʼ��ŵ�
	for (i = n + 1; i <= m; ++i)
	{
		SelectMin(HT, i - 1, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}

}

void SelectMin(HTree HT, const int n, int& min1, int& min2)
{
	int i, min_value = INT_MAX;
	for (i = 1; i <= n; ++i)
		if (HT[i].parent == 0 && HT[i].weight < min_value)
		{
			min_value = HT[i].weight;
			min1 = i;
		}
	for (i = 1, min_value = INT_MAX; i <= n; ++i)
		if (HT[i].parent == 0 && HT[i].weight < min_value && i != min1)
		{
			min_value = HT[i].weight;
			min2 = i;
		}
}

void HuffmanCoding(HTree HT, HuffmanCode& HC, int n)
{
	int start, parent, current;
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	char* Each_Code = (char*)malloc(n * sizeof(char));
	Each_Code[n - 1] = '\0';
	for (int i = 1; i <= n; ++i)
	{
		start = n - 1;//��start��ʼʱָ����󣬼����������λ��
		current = i;
		parent = HT[i].parent;
		while (parent != 0)
		{
			--start;
			if (HT[parent].lchild == current)
				Each_Code[start] = '0';
			else
				Each_Code[start] = '1';
			current = parent;
			parent = HT[parent].parent;
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &Each_Code[start]);
	}
	free(Each_Code);
}
//###############################################################/*ģ���*/

/*ģ����*///###############################################################
void CreateSearchList(HuffmanCode& HC, HuffmanCode& SearchList)
{
	int i, j;
	SearchList = (HuffmanCode)malloc((0xFF + 1) * sizeof(char*));
	for (i = 0; i <= 0xFF; ++i)
		SearchList[i] = NULL;
	for (i = 0, j = 1; i <= 0xFF; ++i)
	{
		if (HexDataTimes[i] != 0)
		{
			SearchList[i] = HC[j];
			++j;
		}
	}
}
void Compress(HuffmanCode SearchList)
{
	FILE* pfile_1 = NULL, * pfile_2 = NULL;
	if ((pfile_1 = fopen(fOriginFile, "rb")) == NULL)
		ErrOpen(fOriginFile)

		if ((pfile_2 = fopen(fCompress, "wb")) == NULL)
		{
			fclose(pfile_1);
			//ErrOpen(pfile_2);
		}


	char OriginCode[Line + 10] = { 0 }, _01Str[20 * Line] = { 0 }, OneByte;//�ر�ע�⣬����_01Str���ɷ���̫С����������Խ�磬�����Ų�
	int TF, i, bytenum;
	for (; feof(pfile_1) == 0;)
	{
		for (TF = 1, i = 0; i < Line; ++i)
		{
			TF = (int)fread(&OneByte, sizeof(char), 1, pfile_1);
			if (TF)
				OriginCode[i] = OneByte;
			else
				break;
		}//����ͬ��һ��һ���ֽڶ�
		bytenum = i;

		_01StrCat(_01Str, OriginCode, bytenum, SearchList);
		TransWrite(_01Str, (int)strlen(_01Str), pfile_2);
	}
	fclose(pfile_1);
	fclose(pfile_2);
	WriteHuffmanCode(SearchList, _01Str);
}

void _01StrCat(char* _01Str, char* OriginCode, int bytenum, HuffmanCode SearchList)
{

	int i;
	for (i = 0; i < bytenum; ++i)
	{

		strcat(_01Str, SearchList[OriginCode[i] & 0b11111111]);
	}
}

void TransWrite(char* _01Str, int _01StrLen, FILE* pfile)
{
	int i, last, bytenum;
	char* BitCode = (char*)malloc(sizeof(char) * (_01StrLen / 8 + 10));
	char temp[10];
	last = _01StrLen % 8;
	_01StrLen -= last;
	for (i = 7, bytenum = 0; i < _01StrLen; i += 8)
	{

		Set_bit(BitCode[bytenum], 1, _01Str[i] - 48);
		Set_bit(BitCode[bytenum], 2, _01Str[i - 1] - 48);
		Set_bit(BitCode[bytenum], 3, _01Str[i - 2] - 48);
		Set_bit(BitCode[bytenum], 4, _01Str[i - 3] - 48);
		Set_bit(BitCode[bytenum], 5, _01Str[i - 4] - 48);
		Set_bit(BitCode[bytenum], 6, _01Str[i - 5] - 48);
		Set_bit(BitCode[bytenum], 7, _01Str[i - 6] - 48);
		Set_bit(BitCode[bytenum], 8, _01Str[i - 7] - 48);
		++bytenum;
	}
	BitCode[bytenum] = '\0';
	strcpy(temp, &_01Str[_01StrLen]);
	strcpy(_01Str, temp);

	fwrite(BitCode, sizeof(char), bytenum, pfile);
	free(BitCode);
}

inline void Set_bit(char& a, int bit, int _01)
{
	char bit_to_1[9] = { 0, 0b1 , 0b10, 0b100, 0b1000, 0b10000,
							0b100000, 0b1000000, (char)0b10000000 };
	char bit_to_0[9] = { 0,(char)0b11111110,(char)0b11111101,(char)0b11111011,(char)0b11110111
						,(char)0b11101111,(char)0b11011111,(char)0b10111111,(char)0b01111111 };
	if (_01 == 0)
	{
		a &= bit_to_0[bit]; //��ʾҪ��bitλ��Ϊ0��Ҳ���ǽ���bitλ&0������λ&1����
	}
	else if (_01 == 1)
	{
		a |= bit_to_1[bit];//��ʾҪ��bitλ��Ϊ1��Ҳ��ʱ����bitλ|1������λ|0����
	}
}

void WriteHuffmanCode(HuffmanCode SearchList, char* _01Str)
{
	int i;
	FILE* pfile = NULL;
	if ((pfile = fopen(fHuffmanCode, "wb")) == NULL)
		ErrOpen(fHuffmanCode);
	for (i = 0; i <= 0xFF; ++i)
	{
		fprintf(pfile, "%s\n", SearchList[i]);
	}
	fprintf(pfile, "%s", _01Str);

	fclose(pfile);
}

void Free(HTree& HT, HuffmanCode& HC, HuffmanCode& SearchList, int N)
{
	int i;
	for (i = 1; i <= N; ++i)
	{
		free(HC[i]);
	}
	free(HC);
	free(HT);
	HC = NULL;
	HT = NULL;
	free(SearchList);
	SearchList = NULL;

}
//###############################################################/*ģ����*/

/*ģ����*///###############################################################
void DeCompress()
{
	int i;
	char surplus[12] = { 0 };
	char  SearchList[0xFF + 1][HuffCodeLen];

	FILE* pfile_1 = NULL, * pfile_2 = NULL;

	if ((pfile_1 = fopen(fHuffmanCode, "rb")) == NULL)
		ErrOpen(fHuffmanCode)
		for (i = 0; i <= 0xFF; ++i)
		{
			fscanf(pfile_1, "%s\n", SearchList[i]);//��ȡ�����������
		}
	fgets(surplus, 10, pfile_1);//��ȡ������Ǹ�01�ַ���
	fclose(pfile_1);

	for (i = 0; i <= 0xFF; ++i)
		if (strcmp(SearchList[i], "(null)") == 0)
			SearchList[i][0] = '\0';

	if ((pfile_1 = fopen(fCompress, "rb")) == NULL)
		ErrOpen(fCompress)
		if ((pfile_2 = fopen(fDeCompress, "wb")) == NULL)
			ErrOpen(fDeCompress);

	char BitCode[Line + 10], _01Str[8 * Line + 20] = { 0 }, EachStr[10];
	char OneByte;
	int bytenum, TF;

	while (1)
	{
		for (i = 0, TF = 1; i < Line; ++i)
		{
			TF = (int)fread(&OneByte, sizeof(char), 1, pfile_1);
			if (TF)
				BitCode[i] = OneByte;
			else
				break;
		}//����ֱ����fread���ļ�ʱ�������Ϊ��Ҫһ��һ���ֽڶ�,���ӵ�BitCode
		bytenum = i;
		if (!bytenum)
			break;

		for (i = 0; i < bytenum; ++i)
		{
			BitToStr(BitCode[i], EachStr);
			strcat(_01Str, EachStr);
		}
		if (TF == 0)//˵���Ѿ������ļ�β���ðѶ����01�ַ�������������,�Ա����һ��ƥ��Ҳ�ܳɹ�
			strcat(_01Str, surplus);
		TransWrite2(_01Str, SearchList, pfile_2);
	}
	fclose(pfile_1);
	fclose(pfile_2);
}
void BitToStr(char a, char* Each_Str)
{
	int bit[8] = { 0b00000001,0b00000010,0b00000100,
	0b00001000,0b00010000,0b00100000,0b01000000,0b10000000 };
	Each_Str[0] = ((a & bit[7]) >> 7) + 48;
	Each_Str[1] = ((a & bit[6]) >> 6) + 48;
	Each_Str[2] = ((a & bit[5]) >> 5) + 48;
	Each_Str[3] = ((a & bit[4]) >> 4) + 48;
	Each_Str[4] = ((a & bit[3]) >> 3) + 48;
	Each_Str[5] = ((a & bit[2]) >> 2) + 48;
	Each_Str[6] = ((a & bit[1]) >> 1) + 48;
	Each_Str[7] = ((a & bit[0]) >> 0) + 48;
	Each_Str[8] = '\0';
}
void TransWrite2(char* _01Str, char SearchList[0xFF + 1][HuffCodeLen], FILE* pfile)
{
	int i = 0, j, Bitnum, len = 0, times = 0;
	char ManyCode[8 * Line + 20] = { 0 };
	Bitnum = (int)strlen(_01Str);
	for (i = 0; i < Bitnum;)
	{
		for (j = 0; j <= 0xFF; ++j)
		{
			if (SearchList[j][0] != '\0')
				if (strncmp_(&_01Str[i], SearchList[j], (int)strlen(SearchList[j])) == 0)//���Լ�ʵ�ֵĺ����ٶȻ����
				{
					len += (int)strlen(SearchList[j]);

					ManyCode[times] = j;
					++times;
					i += (int)strlen(SearchList[j]);
					break;
				}
		}
		if (j == 0xFF + 1)
			break;
	}
	fwrite(ManyCode, sizeof(char), times, pfile);
	strcpy(_01Str, &_01Str[len]);//��û��ƥ��Ļָ����ַ�����
}

//###############################################################/*ģ����*/
int strncmp_(char* str1, char* str2, int strlen)
{
	int i = 0;
	while (i < strlen)
	{
		if (str1[i] != str2[i])
			return 1;
		++i;
	}
	return 0;
}

