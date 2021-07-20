#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n <= 0)
            return result;
        vector<string> s_result;

        s_result.push_back("0");
        s_result.push_back("1");

        int i, j;
        for (i = 2; i < (1 << n); i = i << 1)
        {
            for (j = i - 1; j >= 0; j--)
                s_result.push_back(s_result[j]);
            for (j = 0; j < i; j++)
                s_result[j] = "0" + s_result[j];
            for (j = i; j < 2 * i; j++)
                s_result[j] = "1" + s_result[j];
        }
        
        // Convert binary strings to decimal
        for (i = 0; i < s_result.size(); i++)
        {
            result.push_back(stoi(s_result[i], 0, 2));
            cout << result[i] << endl;
        }

        return result;
    }
};

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

int main() {
    Solution a;
    a.grayCode(3);

    return 0;
}