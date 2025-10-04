##include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // valor -> índice
        for (int i = 0; i < nums.size(); i++) {
            int complemento = target - nums[i];
            if (seen.find(complemento) != seen.end()) {
                return {seen[complemento], i};
            }
            seen[nums[i]] = i;
        }
        return {}; // siempre existe solución según el enunciado
    }
};

int main() {
    int n, target;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> nums[i];
    }

    cout << "Ingrese el valor objetivo (target): ";
    cin >> target;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices encontrados: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}