#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// 类信息结构体
struct ClassInfo {
    string parentName;
    unordered_set<string> pureVirtualFunctions;
    unordered_map<string, string> implementedFunctions;  // 函数名称 -> 实现的类名
};

// 类名到类信息的映射
unordered_map<string, ClassInfo> classes;

// 检查函数调用状态的辅助函数
string checkFunctionCall(const string& className, const string& functionName) {
    if (classes.find(className) == classes.end()) {
        return "NO_SUCH_CLASS";
    }

    unordered_set<string> seenPureVirtualFunctions;
    string currentClass = className;

    // 追溯继承链
    while (currentClass != "~") {
        ClassInfo& info = classes[currentClass];

        // 检查当前类是否实现了该函数
        if (info.implementedFunctions.find(functionName) != info.implementedFunctions.end()) {
            return /*"[" +*/ info.implementedFunctions[functionName] + "::" + functionName + "()";
        }

        // 记录该类声明的纯虚函数
        if (info.pureVirtualFunctions.find(functionName) != info.pureVirtualFunctions.end()) {
            seenPureVirtualFunctions.insert(functionName);
        }

        // 追溯到父类
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

    // 读取类定义
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

    // 处理查询
    for (int i = 0; i < q; ++i) {
        string className, functionName;
        cin >> className >> functionName;

        cout << checkFunctionCall(className, functionName) << endl;
    }

    return 0;
}
