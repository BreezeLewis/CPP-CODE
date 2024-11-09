//�����������--��־λ����set���ֲ���
//�ڴ棺10752kB    ʱ�䣺533ms

#include<iostream>
#include<cstring>
#include<cstdio>//sprintf()ͷ�ļ�
#include<cstdlib>//atoi()ͷ�ļ�
#include<set>//STL����
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
{//�ַ�����ʽ�������ʮ����ת����9λ���ַ���������ǰ�����0����
    sprintf(strStatus, "%09d", n);//��Ҫ����ǰ��0
}

int NewStatus(int status, char cMove)
{//���״̬status����cMove�ƶ������״̬�����������򷵻�-1
    char tmp[20];
    int zeroPos;
    IntStatusToStrStatus(status, tmp);//ת�����ַ�����ʽ�����ƶ�
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
    return atoi(tmp);//�ٽ��ַ�����ԭΪ����״̬����
}

bool Bfs(int status)
{//�ӳ�ʼ״̬status��Ŀ���·�����Ҳ����򷵻�false
    int newStatus;
    set<int>expanded;//��ű��λ
    expanded.insert(status);
    myQueue[qhead] = Node(status, -1, 0);//��ʼ������ͷ�ڵ�(��ʼ�ڵ�)
    while (qhead != qtail)//���в�Ϊ��
    {
        status = myQueue[qhead].status;
        if (status == goalStatus)return true;

        for (int i = 0; i < 4; i++)
        {
            newStatus = NewStatus(status, moves[i]);
            if (newStatus == -1)continue;
            if (expanded.find(newStatus) != expanded.end())continue;//set����û�ҵ��򷵻�end
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
        //��ԭʼ����ת��������ַ���
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
            } while (pos);//pos=0˵���Ѿ��˻س�ʼ״̬
            for (int i = moves - 1; i >= 0; i--)cout << result[i];
        }
        else cout << "unsolvable" << endl;
    }
    return 0;
}

