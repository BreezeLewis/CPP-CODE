#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// ����Ϣ�ṹ��
struct ClassInfo {
    string parentName;
    unordered_set<string> pureVirtualFunctions;
    unordered_map<string, string> implementedFunctions;  // �������� -> ʵ�ֵ�����
};

// ����������Ϣ��ӳ��
unordered_map<string, ClassInfo> classes;

// ��麯������״̬�ĸ�������
string checkFunctionCall(const string& className, const string& functionName) {
    if (classes.find(className) == classes.end()) {
        return "NO_SUCH_CLASS";
    }

    unordered_set<string> seenPureVirtualFunctions;
    string currentClass = className;

    // ׷�ݼ̳���
    while (currentClass != "~") {
        ClassInfo& info = classes[currentClass];

        // ��鵱ǰ���Ƿ�ʵ���˸ú���
        if (info.implementedFunctions.find(functionName) != info.implementedFunctions.end()) {
            return /*"[" +*/ info.implementedFunctions[functionName] + "::" + functionName + "()";
        }

        // ��¼���������Ĵ��麯��
        if (info.pureVirtualFunctions.find(functionName) != info.pureVirtualFunctions.end()) {
            seenPureVirtualFunctions.insert(functionName);
        }

        // ׷�ݵ�����
        currentClass = info.parentName;
    }

    if (seenPureVirtualFunctions.find(functionName) != seenPureVirtualFunctions.end()) {
        return "FUNCTION_IS_VIRTUAL";
    }
    else {
        return "NO_MEMBER_FOUND";
    }
}

int main() {
    int k;
    cin >> k;

    // ��ȡ�ඨ��
    for (int i = 0; i < k; ++i) {
        string className, parentName;
        int n;
        cin >> className >> parentName >> n;

        ClassInfo info;
        info.parentName = parentName;

        for (int j = 0; j < n; ++j) {
            string oper, functionName;
            cin >> oper >> functionName;
            if (oper == "defn") {
                info.pureVirtualFunctions.insert(functionName);
            }
            else if (oper == "impl") {
                info.implementedFunctions[functionName] = className;
            }
        }

        classes[className] = info;
    }

    int q;
    cin >> q;

    // �����ѯ
    for (int i = 0; i < q; ++i) {
        string className, functionName;
        cin >> className >> functionName;

        cout << checkFunctionCall(className, functionName) << endl;
    }

    return 0;
}
