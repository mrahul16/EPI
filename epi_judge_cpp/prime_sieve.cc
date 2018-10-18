#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
    vector<bool> isPrime(static_cast<unsigned int>(n + 1), true);
    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i; j <= n; j += i) {
                isPrime[j] = false;
            }
            primes.push_back(i);
        }
    }
    return primes;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"n"};
    return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                           &GeneratePrimes, DefaultComparator{}, param_names);
}
