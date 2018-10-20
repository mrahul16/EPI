#include <string>
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"

using std::string;

string IntToString(int x) {
    bool isNeg = false;
    if(x < 0) {
        isNeg = true;
    }
    string s;
    // Use do while to take care of 0
    do {
        s += (char)('0' + abs(x % 10));
        x /= 10;
    }
    while (x);

    if(isNeg) {
        s += '-';
    }
    std::reverse(s.begin(), s.end());
    return s;
}

int StringToInt(const string &s) {
    bool isNeg = s[0] == '-';
    int len = s.size();
    int num = 0;
    int digit;
    for (int i = isNeg ? 1: 0; i < len; ++i) {
        digit = s[i] - '0';
        if(isNeg && num == (std::numeric_limits<int>::max() / 10) && digit <= 8) {
            return (-num) * 10 - digit;
        }
        num = num * 10 + digit;
    }
    return isNeg ? -num: num;
}

void Wrapper(int x, const string &s) {
    if (IntToString(x) != s) {
        throw TestFailure("Int to string conversion failed");
    }

    if (StringToInt(s) != x) {
        throw TestFailure("String to int conversion failed");
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"x", "s"};
    return GenericTestMain(args, "string_integer_interconversion.cc",
                           "string_integer_interconversion.tsv", &Wrapper,
                           DefaultComparator{}, param_names);
}
