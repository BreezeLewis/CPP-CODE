//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#define ErrOpen(filename){printf("文件%s打开失败\n",filename); exit(1);}
//int main(void)
//{
//	char fOriginFile[] = "1.txt",
//		fCompress[] = "11.txt";
//
//	FILE* pfile_1 = NULL, * pfile_2 = NULL;
//	if ((pfile_1 = fopen(fOriginFile, "rb")) == NULL)
//		ErrOpen(fOriginFile)
//		if ((pfile_2 = fopen(fCompress, "rb")) == NULL)
//		{
//			fclose(pfile_1);
//			ErrOpen(fCompress);
//		}
//	char Byte1, Byte2;
//	int i, j;
//	int kind = 1;
//	printf("请输入种类，1快速，2显示,3.中断错误点并显示信息\n");
//	scanf("%d", &kind); getchar();
//	if (kind == 1)
//		for (i = 0;;)
//		{
//			if (feof(pfile_1) == 0 && feof(pfile_2) == 0)
//			{
//				fread(&Byte1, sizeof(char), 1, pfile_1);
//				fread(&Byte2, sizeof(char), 1, pfile_2);
//				if (Byte1 != Byte2)
//					i++;
//			}
//			else
//				break;
//		}
//	else if (kind == 2)
//		for (i = 0;;)
//		{
//			if (feof(pfile_1) == 0 && feof(pfile_2) == 0)
//			{
//				fread(&Byte1, sizeof(char), 1, pfile_1);
//				fread(&Byte2, sizeof(char), 1, pfile_2);
//				if (Byte1 != Byte2)
//					i++;
//				printf("进行中！\n");
//			}
//			else
//				break;
//		}
//	else if (kind == 3)
//		for (i = 0, j = 0;;)
//		{
//			if (feof(pfile_1) == 0 && feof(pfile_2) == 0)
//			{
//				++j;
//				fread(&Byte1, sizeof(char), 1, pfile_1);
//				fread(&Byte2, sizeof(char), 1, pfile_2);
//				if (Byte1 != Byte2)
//				{
//					printf("第%d个字节不同\n", j);
//					printf("Byte1:%2X,Byte2:%2X", Byte1, Byte2);
//					getchar();
//					i++;
//				}
//
//			}
//			else
//				break;
//		}
//
//	fclose(pfile_1);
//	fclose(pfile_2);
//	printf("\n\n\n有%d个字节不同", i);
//	getchar();
//}
