#include <iostream>
using namespace std;

bool isPowerOfTwo(long long N) {
    if (N <= 0) {
        return false;
    }
    while (N % 2 == 0) {
        N /= 2;
    }
    return N == 1;
}

int main() {
    long long N;
    cin >> N;
    if (isPowerOfTwo(N)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
