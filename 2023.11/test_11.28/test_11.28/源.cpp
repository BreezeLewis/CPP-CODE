#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <windows.h>

#define Line 200
#define HuffCodeLen 200//哈夫曼编码最大长度
#define PATH_MAX 300
#define ErrOpen(filename) { printf("文件%s打开失败!\n",filename); exit(1);}

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

/*全局变量*/
char fOriginFile[PATH_MAX] = "1.txt";
char fDataTimes[PATH_MAX] = "DataTimes.txt";
char fCompress[PATH_MAX] = "Compress.txt";
char fHuffmanCode[PATH_MAX] = "HuffmanCode.txt";
char fDeCompress[PATH_MAX] = "DeCompress.txt";

int HexDataTimes[0xFF + 1] = { 0 };

int N;
HTree HT = NULL;
HuffmanCode HC, SearchList;


/*模块一*/
void ReadByte_WriteHex(const char* filename, const char* SaveName = fDataTimes);
void memset_int(int* num, int value, int size);
void TransToHex(char* ByteData, int* HexData, int bytenum);
void AddTimes(int* HexDataTimes, int* HexData);
/*模块二*/
void ReadDataTimes(int* HexDataTimes, const char* filename = fDataTimes);
void CreateHTree(HTree& HT, int& N);
void SelectMin(HTree HT, const int n, int& min1, int& min2);
void HuffmanCoding(HTree HT, HuffmanCode& HC, int n);
/*模块三*/
void CreateSearchList(HuffmanCode& HC, HuffmanCode& SearchList);
void Compress(HuffmanCode SearchList);
void _01StrCat(char* _01Str, char* OriginCode, int strlen, HuffmanCode SearchList);
void TransWrite(char* _01Str, int _01StrLen, FILE* pfile);
inline void Set_bit(char& a, int bit, int _01);
void WriteHuffmanCode(HuffmanCode SearchList, char* _01Str);
void Free(HTree& HT, HuffmanCode& HC, HuffmanCode& SearchList, int N);
/*模块四*/
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
			"|请选择功能:  |\n"
			"|1.压缩       |\n"
			"|2.解压缩     |\n"
			"0-------------0\n"
			">>>");
		function = getchar(); getchar();
		switch (function)
		{
		case '1':
		{
			printf("请输入要压缩的 路径\\文件名:\n>>>");
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
			printf("压缩完毕!\n");
		}
		break;

		case '2':
		{
			printf("请输入要解压的 路径\\文件名:\n>>>");
			scanf("%s", &fCompress); getchar();
			printf("请指定解压后 路径\\文件名:\n>>>");
			scanf("%s", &fDeCompress); getchar();
			DeCompress();
			printf("解压完毕!\n");
		}
		break;
		}
		printf("\n\n回车继续……"); getchar();
		system("cls");
		fflush(stdin);
	}
	return 0;
}

/*模块一*///###############################################################
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
		memset_int(HexData, -1, sizeof(HexData) / sizeof(int));//每次都重置

		for (i = 0, TF = 1; i < Line; ++i)
		{
			TF = (int)fread(&OneByte, sizeof(char), 1, pfile_1);//这里要一个一个字节读，否则是错误行为
			if (TF)
				ByteData[i] = OneByte;
			else
				break;
		}
		bytenum = i;
		if (bytenum)
			TransToHex(ByteData, HexData, bytenum);//ByteData转换成16进制数存储
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
	//抹去高位，保留低位
}
void AddTimes(int* HexDataTimes, int* HexData)
{
	for (int i = 0; HexData[i] != -1; ++i)
		++HexDataTimes[HexData[i]];
}
//###############################################################/*模块一*/

/*模块二*///###############################################################
void ReadDataTimes(int* HexDataTimes, const char* filename)
{
	FILE* pfile = NULL;
	if ((pfile = fopen(filename, "rb")) == NULL)
		ErrOpen(filename);
	for (int i = 0; i < 0xFF + 1; ++i)
		fscanf(pfile, "%02X==%010d", &HexDataTimes[i], &HexDataTimes[i]);
	//这里重复赋值，是因为发现VS2019不支持*赋值跳过，就重复赋值覆盖了
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
			weight[n] = HexDataTimes[i];//把非0权值提取出来
			++n;
		}
	}
	N = n;
	m = 2 * n - 1;//weight[0~n-1]存放了所以非0权值
	HT = (HTree)malloc((m + 1) * sizeof(HTNode));//分配编码空间舍去0单元不用
	for (i = 0; i <= m; ++i)
		HT[i] = { {0},0,0,0 };//初始化
	for (i = 1; i <= n; ++i)
		HT[i].weight = weight[i - 1];//这里错开一位，因为weight[]是从0开始存放的
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
		start = n - 1;//从start开始时指向最后，即编码结束符位置
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
//###############################################################/*模块二*/

/*模块三*///###############################################################
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


	char OriginCode[Line + 10] = { 0 }, _01Str[20 * Line] = { 0 }, OneByte;//特别注意，这里_01Str不可分配太小，否则容易越界，难以排查
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
		}//这里同样一个一个字节读
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
		a &= bit_to_0[bit]; //表示要将bit位变为0，也即是将第bit位&0，其他位&1即可
	}
	else if (_01 == 1)
	{
		a |= bit_to_1[bit];//表示要将bit位变为1，也即时将第bit位|1，其他位|0即可
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
//###############################################################/*模块三*/

/*模块四*///###############################################################
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
			fscanf(pfile_1, "%s\n", SearchList[i]);//读取哈夫曼编码表
		}
	fgets(surplus, 10, pfile_1);//读取多余的那个01字符串
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
		}//这里直接用fread读文件时错误的行为，要一个一个字节读,连接到BitCode
		bytenum = i;
		if (!bytenum)
			break;

		for (i = 0; i < bytenum; ++i)
		{
			BitToStr(BitCode[i], EachStr);
			strcat(_01Str, EachStr);
		}
		if (TF == 0)//说明已经到了文件尾，该把多余的01字符串进行连接了,以便最后一次匹配也能成功
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
				if (strncmp_(&_01Str[i], SearchList[j], (int)strlen(SearchList[j])) == 0)//用自己实现的函数速度会更快
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
	strcpy(_01Str, &_01Str[len]);//将没能匹配的恢复到字符串首
}

//###############################################################/*模块四*/
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

