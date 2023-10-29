#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
using namespace std;

void getCard(int a[])   // 约定 0-12表示黑桃 2~A; 约定 13-25表示红桃 2~A; 约定 26-38表示方块 2~A; 约定 39-51表示草花 2~A;
{   int num = 0, j, x;  // 产生 0~51 随机数，放入 a[52] 数组中 
    bool flag;          // a[0]~a[12] 北的牌； a[13]~a[25] 西的牌；a[26]~a[38] 东的牌；a[39]~a[51] 南的牌
        
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

void rangeSort(int a[], int s, int p) // 对四人牌的区间排序 a[0]~a[12]（北）； a[13]~a[25]（西）；a[26]~a[38]（东）；a[39]~a[51]（南）
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

string getLineCard(int a[], char type, int s, int p)  //  形成某一花色的字符串 
{   int i;
    string CardStyle[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string str = "  ";
    str[0] = type;
        
    for(i=0;i<13;i++)
        if(a[s+i]/13 == p)
            str += CardStyle[a[s+i]%13]+" ";
        
    return str;
}

string getBlank(int x)  // 补齐空格数 
{   string str="";
    for(int i=0;i<x;i++)
        str += " ";
    return str;
}

int countMaxLeft(int a[])  // 计算 西 最长花色 
{   int i, maxlen=0;
    int count[4] = {0};
        
    for(i=0;i<13;i++)
        count[a[13+i]/13] ++;
        
    for(i=0;i<4;i++)
        if(count[i]>maxlen)
            maxlen = count[i];
                
    return maxlen+1 ;
}

void cardEastWestShow(int a[])  // 显示 西东 的牌 
{
    int i, maxl = 0;
    (void)i;
    string oneLine;
       
    maxl = 2*countMaxLeft(a)+1;
    cout << getBlank(maxl+1) << "┌───────┐"  << endl;
    oneLine = getLineCard(a, '\006', 13, 0);
    cout << " " << oneLine << getBlank(maxl-(int)oneLine.length());
    oneLine = getLineCard(a, '\006', 26, 0);
    cout << "│    North     │" << oneLine << endl;            // 显示 黑桃 牌的数据 
        
    oneLine = getLineCard(a, '\003', 13, 1);
    cout << " " << oneLine << getBlank(maxl- (int)oneLine.length());
    oneLine = getLineCard(a, '\003', 26, 1);
    cout << "│West      East│" << oneLine << endl;           // 显示 红桃 牌的数据 
        
    oneLine = getLineCard(a, '\004', 13, 2);
    cout << " " << oneLine << getBlank(maxl- (int)oneLine.length());
    oneLine = getLineCard(a, '\004', 26, 2);
    cout << "│              │" << oneLine << endl;           // 显示 方块 牌的数据 
        
    oneLine = getLineCard(a, '\005', 13, 3);
    cout << " " << oneLine << getBlank(maxl- (int)oneLine.length());
    oneLine = getLineCard(a, '\005', 26, 3);
    cout << "│    South     │" << oneLine << endl;           // 显示 草花 牌的数据 
        
    cout << getBlank(maxl+1) << "└───────┘" ;
}
    
void cardSouthNorthShow(int a[], int s)  // 显示 北和南 的牌 
{   int i, maxl=0;
    string CardStyle[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string leftEmpty = "  ";
        
    maxl = countMaxLeft(a);  // 计算 西 最大的显示距离 
    for(i=0;i<=maxl;i++)
        leftEmpty += "  ";
                
    cout << endl << leftEmpty << "\006 ";         // 显示 黑桃 牌的数据 
    for(i=0;i<13;i++)
    {   if(a[s+i]/13==0)
            cout << CardStyle[a[s+i]%13] << " ";
    }
        
    cout << endl << leftEmpty << "\003 ";        // 显示 红桃 牌的数据
    for(i=0;i<13;i++)
    {   if(a[s+i]/13==1)
            cout << CardStyle[a[s+i]%13] << " ";
    }
        
    cout << endl << leftEmpty << "\004 ";        // 显示 方块 牌的数据
    for(i=0;i<13;i++)
    {   if(a[s+i]/13==2)
            cout << CardStyle[a[s+i]%13] << " ";
    }
        
    cout << endl << leftEmpty << "\005 ";        // 显示 草花 牌的数据
    for(i=0;i<13;i++)
    {   if(a[s+i]/13==3)
            cout << CardStyle[a[s+i]%13] << " ";
    }
    cout << endl;
}

int main()
{   int a[52];
    
    getCard(a);
    
    rangeSort(a, 0, 12);  // 牌的排序 a[0]~a[12] （北）
    rangeSort(a, 13, 25); // 牌的排序 a[13]~a[25]（西）
    rangeSort(a, 26, 38); // 牌的排序 a[26]~a[38]（东）
    rangeSort(a, 39, 51); // 牌的排序 a[39]~a[51]（南）
        
    cout << endl << "桥牌发牌如下：" << endl;
    cardSouthNorthShow(a, 0);  // 显示 北 的牌 
    cardEastWestShow(a);       // 显示 西东 的牌 
    cardSouthNorthShow(a, 39); // 显示 南 的牌 
    cout << endl;
    

}
