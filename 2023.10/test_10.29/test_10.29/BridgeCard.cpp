#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
using namespace std;

void getCard(int a[])   // Լ�� 0-12��ʾ���� 2~A; Լ�� 13-25��ʾ���� 2~A; Լ�� 26-38��ʾ���� 2~A; Լ�� 39-51��ʾ�ݻ� 2~A;
{   int num = 0, j, x;  // ���� 0~51 ����������� a[52] ������ 
    bool flag;          // a[0]~a[12] �����ƣ� a[13]~a[25] �����ƣ�a[26]~a[38] �����ƣ�a[39]~a[51] �ϵ���
        
    srand((unsigned int)time(0));
    while (num < 52)
    {   x = (int)(abs((rand()*12345+100)*777))%52;
        flag = false;
        for(j = 0; j < num; j++)
            if(a[j] == x)
            {   flag = true;
                break;
            }
                    
        if(flag)
            continue;
        a[num ++] = x;
    }
}

void rangeSort(int a[], int s, int p) // �������Ƶ��������� a[0]~a[12]�������� a[13]~a[25]��������a[26]~a[38]��������a[39]~a[51]���ϣ�
{   int i, j, n, k, t;
    
    n=p-s+1;
    for(i=0;i<n-1;i++)
    {   k=i;
        for(j=i+1;j<n;j++)
            if(a[s+j]<a[s+k])
                k=j;
        if(k!=i)
        {   t=a[s+i];
            a[s+i]=a[s+k];
            a[s+k]=t;
        }
    }
}

string getLineCard(int a[], char type, int s, int p)  //  �γ�ĳһ��ɫ���ַ��� 
{   int i;
    string CardStyle[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string str = "  ";
    str[0] = type;
        
    for(i=0;i<13;i++)
        if(a[s+i]/13 == p)
            str += CardStyle[a[s+i]%13]+" ";
        
    return str;
}

string getBlank(int x)  // ����ո��� 
{   string str="";
    for(int i=0;i<x;i++)
        str += " ";
    return str;
}

int countMaxLeft(int a[])  // ���� �� ���ɫ 
{   int i, maxlen=0;
    int count[4] = {0};
        
    for(i=0;i<13;i++)
        count[a[13+i]/13] ++;
        
    for(i=0;i<4;i++)
        if(count[i]>maxlen)
            maxlen = count[i];
                
    return maxlen+1 ;
}

void cardEastWestShow(int a[])  // ��ʾ ���� ���� 
{
    int i, maxl = 0;
    (void)i;
    string oneLine;
       
    maxl = 2*countMaxLeft(a)+1;
    cout << getBlank(maxl+1) << "������������������"  << endl;
    oneLine = getLineCard(a, '\006', 13, 0);
    cout << " " << oneLine << getBlank(maxl-(int)oneLine.length());
    oneLine = getLineCard(a, '\006', 26, 0);
    cout << "��    North     ��" << oneLine << endl;            // ��ʾ ���� �Ƶ����� 
        
    oneLine = getLineCard(a, '\003', 13, 1);
    cout << " " << oneLine << getBlank(maxl- (int)oneLine.length());
    oneLine = getLineCard(a, '\003', 26, 1);
    cout << "��West      East��" << oneLine << endl;           // ��ʾ ���� �Ƶ����� 
        
    oneLine = getLineCard(a, '\004', 13, 2);
    cout << " " << oneLine << getBlank(maxl- (int)oneLine.length());
    oneLine = getLineCard(a, '\004', 26, 2);
    cout << "��              ��" << oneLine << endl;           // ��ʾ ���� �Ƶ����� 
        
    oneLine = getLineCard(a, '\005', 13, 3);
    cout << " " << oneLine << getBlank(maxl- (int)oneLine.length());
    oneLine = getLineCard(a, '\005', 26, 3);
    cout << "��    South     ��" << oneLine << endl;           // ��ʾ �ݻ� �Ƶ����� 
        
    cout << getBlank(maxl+1) << "������������������" ;
}
    
void cardSouthNorthShow(int a[], int s)  // ��ʾ ������ ���� 
{   int i, maxl=0;
    string CardStyle[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string leftEmpty = "  ";
        
    maxl = countMaxLeft(a);  // ���� �� ������ʾ���� 
    for(i=0;i<=maxl;i++)
        leftEmpty += "  ";
                
    cout << endl << leftEmpty << "\006 ";         // ��ʾ ���� �Ƶ����� 
    for(i=0;i<13;i++)
    {   if(a[s+i]/13==0)
            cout << CardStyle[a[s+i]%13] << " ";
    }
        
    cout << endl << leftEmpty << "\003 ";        // ��ʾ ���� �Ƶ�����
    for(i=0;i<13;i++)
    {   if(a[s+i]/13==1)
            cout << CardStyle[a[s+i]%13] << " ";
    }
        
    cout << endl << leftEmpty << "\004 ";        // ��ʾ ���� �Ƶ�����
    for(i=0;i<13;i++)
    {   if(a[s+i]/13==2)
            cout << CardStyle[a[s+i]%13] << " ";
    }
        
    cout << endl << leftEmpty << "\005 ";        // ��ʾ �ݻ� �Ƶ�����
    for(i=0;i<13;i++)
    {   if(a[s+i]/13==3)
            cout << CardStyle[a[s+i]%13] << " ";
    }
    cout << endl;
}

int main()
{   int a[52];
    
    getCard(a);
    
    rangeSort(a, 0, 12);  // �Ƶ����� a[0]~a[12] ������
    rangeSort(a, 13, 25); // �Ƶ����� a[13]~a[25]������
    rangeSort(a, 26, 38); // �Ƶ����� a[26]~a[38]������
    rangeSort(a, 39, 51); // �Ƶ����� a[39]~a[51]���ϣ�
        
    cout << endl << "���Ʒ������£�" << endl;
    cardSouthNorthShow(a, 0);  // ��ʾ �� ���� 
    cardEastWestShow(a);       // ��ʾ ���� ���� 
    cardSouthNorthShow(a, 39); // ��ʾ �� ���� 
    cout << endl;
    

}
