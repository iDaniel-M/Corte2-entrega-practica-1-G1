#include <iostream>
using namespace std;

class Solution {
public:
    bool esPalindrome(int x) {
        // Números negativos nunca son palíndromos
        if (x < 0) return false;

        // Guardamos el número original
        long original = x;
        long reversed = 0;

        // Construimos el número invertido
        while (x > 0) {
            int digit = x % 10;        
            reversed = reversed * 10 + digit; 
            x /= 10;                  
        }

        // Si el número invertido es igual al original → palíndromo
        return original == reversed;
    }
};

int main() {
    Solution sol;

    cout << sol.isPalindrome(121) << endl;   
    cout << sol.isPalindrome(-121) << endl;  
    cout << sol.isPalindrome(10) << endl;    

    return 0;
}
