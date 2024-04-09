#include "iostream"
using namespace std;

class Solution {
public:
    int t;
    void setter(int t);
    int getter();
};

void Solution::setter(int t) { this->t = t; }

int Solution::getter() { return this->t; }

int main() {
    int t;
    cin >> t;
    Solution sol;
    sol.setter(t);
    cout << sol.getter() << "\n";
}