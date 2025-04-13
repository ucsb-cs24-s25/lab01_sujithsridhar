#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib> 
#include <chrono>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> newVector;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                for (int k = 0; k < nums.size(); k++) {
                    if (i != j && j != k && i != k && (nums.at(i) + nums.at(j)
                    + nums.at(k)) == 0) {
                        vector<int> tempVector;
                        tempVector.push_back(nums.at(i));
                        tempVector.push_back(nums.at(j));
                        tempVector.push_back(nums.at(k));
                        sort(tempVector.begin(), tempVector.end());
                        newVector.insert(tempVector);
                    }
                }
            }
        }
        vector<vector<int>> result(newVector.begin(), newVector.end());
        return result;
    }
};

int main() {
    Solution sol;
    for (int n = 100; n < 4000; n *= 2) {
        vector<int> nums;
        while (nums.size() < n) {
            int num1 = rand() % 21 - 10;
            int num2 = rand() % 21 - 10;
            int num3 = -(num1 + num2);
            nums.push_back(num1);
            nums.push_back(num2);
            nums.push_back(num3);
            while (nums.size() < n) {
                int newNum = rand() % 21 - 10;
                nums.push_back(newNum);
            }
        }

        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = sol.threeSum(nums);
        auto end = chrono::high_resolution_clock::now();
        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
        cout << "Time for n = " << n << ": " << time_ms << " ms" << endl;
    }
    
    
    return 0;
}