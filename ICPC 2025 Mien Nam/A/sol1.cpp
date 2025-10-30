#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const long long MOD = 1000000007;

// Function to find divisors of a number
std::vector<long long> findDivisors(long long n) {
    std::vector<long long> divisors;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

// Function to compute modular inverse using Fermat's Little Theorem
long long modInverse(long long a, long long m) {
    return pow(a, m - 2, m);  // Using Fermat's Little Theorem: a^(m-2) % m
}

// Function to compute expected value after k refinements
long long computeExpectedEssence(long long n, int k) {
    long long current = n;
    for (int step = 0; step < k; ++step) {
        // Find divisors of the current value
        std::vector<long long> divisors = findDivisors(current);
        long long sum = 0;
        long long count = divisors.size();
        
        // Calculate the sum of divisors
        for (long long d : divisors) {
            sum = (sum + d) % MOD;
        }

        // Compute the expected value (sum / count) % MOD
        long long invCount = modInverse(count, MOD);  // Inverse of count mod MOD
        current = (sum * invCount) % MOD;
    }
    return current;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    // Compute the expected Essence Value after k steps
    long long expectedValue = computeExpectedEssence(n, k);

    // Output the result modulo 10^9 + 7
    std::cout << expectedValue << std::endl;

    return 0;
}
