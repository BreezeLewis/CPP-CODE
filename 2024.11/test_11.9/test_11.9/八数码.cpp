//广度优先搜索--标志位采用set二分查找
//内存：10752kB    时间：533ms

#include<iostream>
#include<cstring>
#include<cstdio>//sprintf()头文件
#include<cstdlib>//atoi()头文件
#include<set>//STL容器
using namespace std;

int goalStatus;
const int MAXS = 400000;
char result[MAXS];
struct Node
{
    int status;
    int father;
    char move;
    Node(int s, int f, char m) :status(s), father(f), move(m) {}
    Node() {}
};
Node myQueue[MAXS];
int qhead = 0;
int qtail = 1;
char moves[] = "udrl";

void IntStatusToStrStatus(int n, char* strStatus)
{//字符串格式化命令，按十进制转换成9位的字符串，可在前面添加0凑足
    sprintf(strStatus, "%09d", n);//需要保留前导0
}

int NewStatus(int status, char cMove)
{//求从状态status经过cMove移动后的新状态；若不可行则返回-1
    char tmp[20];
    int zeroPos;
    IntStatusToStrStatus(status, tmp);//转换成字符串形式进行移动
    for (int i = 0; i < 9; ++i)
        if (tmp[i] == '0') { zeroPos = i; break; }
    switch (cMove)
    {
    case'u':
        if (zeroPos - 3 < 0)return -1;
        else {
            tmp[zeroPos] = tmp[zeroPos - 3];
            tmp[zeroPos - 3] = '0';
        }
        break;
    case'd':
        if (zeroPos + 3 > 8)return -1;
        else {
            tmp[zeroPos] = tmp[zeroPos + 3];
            tmp[zeroPos + 3] = '0';
        }
        break;
    case'l':
        if (zeroPos % 3 == 0)return -1;
        else {
            tmp[zeroPos] = tmp[zeroPos - 1];
            tmp[zeroPos - 1] = '0';
        }
        break;
    case'r':
        if (zeroPos % 3 == 2)return -1;
        else {
            tmp[zeroPos] = tmp[zeroPos + 1];
            tmp[zeroPos + 1] = '0';
        }
        break;
    }
    return atoi(tmp);//再将字符串还原为整数状态返回
}

bool Bfs(int status)
{//从初始状态status到目标的路径，找不到则返回false
    int newStatus;
    set<int>expanded;//存放标记位
    expanded.insert(status);
    myQueue[qhead] = Node(status, -1, 0);//初始化队列头节点(起始节点)
    while (qhead != qtail)//队列不为空
    {
        status = myQueue[qhead].status;
        if (status == goalStatus)return true;

        for (int i = 0; i < 4; i++)
        {
            newStatus = NewStatus(status, moves[i]);
            if (newStatus == -1)continue;
            if (expanded.find(newStatus) != expanded.end())continue;//set中若没找到则返回end
            expanded.insert(newStatus);
            myQueue[qtail++] = Node(newStatus, qhead, moves[i]);
        }
        qhead++;
    }
    return false;
}

int main()
{
    goalStatus = atoi("123456780");
    char line1[50];  char line2[20];
    while (cin.getline(line1, 48))
    {
        int i, j;
        //将原始输入转变成数字字符串
        for (i = 0, j = 0; line1[i]; i++)
        {
            if (line1[i] != ' ') {
                if (line1[i] == 'x')line2[j++] = '0';
                else line2[j++] = line1[i];
            }
        }
        line2[j] = 0;
        if (Bfs(atoi(line2)))
        {
            int moves = 0;
            int pos = qhead;
            do {
                result[moves++] = myQueue[pos].move;
                pos = myQueue[pos].father;
            } while (pos);//pos=0说明已经退回初始状态
            for (int i = moves - 1; i >= 0; i--)cout << result[i];
        }
        else cout << "unsolvable" << endl;
    }
    return 0;
}

