#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

vector<int> PlusOne(vector<int> A) {
    unsigned int len = A.size();
    A[len - 1]++;
    for(int i = len - 1; i > 0; i--) {
        if(A[i] == 10) {
            A[i] = 0;
            A[i - 1]++;
        }
        else {
            return A;
        }
    }
    if(A[0] == 10) {
        A[0] = 0;
        A.insert(A.begin(), 1);
    }
    return A;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"A"};
    return GenericTestMain(args, "int_as_array_increment.cc",
                           "int_as_array_increment.tsv", &PlusOne,
                           DefaultComparator{}, param_names);
}
