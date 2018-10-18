#include <vector>
#include "test_framework/generic_test.h"

using std::vector;
using std::max;

bool CanReachEnd(const vector<int> &max_advance_steps) {
    // NOTE: Note the value of high and the second condition in for.
    int maxPos = 0;
    unsigned int high = max_advance_steps.size() - 1;
    for(int i = 0; i <= high && i <= maxPos; i++) {
        maxPos = max(i + max_advance_steps[i], maxPos);
        if(maxPos >= high) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"max_advance_steps"};
    return GenericTestMain(args, "advance_by_offsets.cc",
                           "advance_by_offsets.tsv", &CanReachEnd,
                           DefaultComparator{}, param_names);
}
