//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// 计算两个字符串的最长公共子序列
//int longestCommonSubsequence(const string& str1, const string& str2) {
//    int m = str1.length();
//    int n = str2.length();
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (str1[i - 1] == str2[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//            }
//            else {
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//            }
//        }
//    }
//
//    return dp[m][n];
//}
//
//int main() {
//
//    string lines[5];
//    for (int i = 0; i < 5; i++) 
//    {
//        getline(cin, lines[i]);
//    }
//
//
//    for (int i = 0; i < 5; i++) 
//    {
//        lines[i].erase(remove_if(lines[i].begin(), lines[i].end(), ::isspace), lines[i].end());
//    }
//
//
//    string member1 = "Pegasus";
//    string member2 = "Hitass_SY";
//    string member3 = "Nekopass";
//
//
//    string signature = "ass";
//    
//
//  
//    int count = 0;
//    for (int i = 0; i < 5; i++) {
//        string line = lines[i];
//        transform(line.begin(), line.end(), line.begin(), ::tolower); 
//        int found = line.find(signature);
//        while (found != string::npos) {
//            count++;
//            found = line.find(signature, found + 1);
//        }
//    }
//
//    // 输出结果
//    cout << count << endl;
//
//    return 0;
//}
