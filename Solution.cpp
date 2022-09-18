
#include <vector>
using namespace std;

class Solution {
    
public:
    int numberOfWeakCharacters(vector<vector<int>>&properties) {

        static auto comparator = [](const vector<int>& x, const vector<int>& y) { return (x[0] == y[0]) ? (x[1] > y[1]) : (x[0] < y[0]); };
        //C++20: std::ranges::sort(properties, comparator);
        sort(properties.begin(), properties.end(), comparator);
        int maxDefence = properties[properties.size() - 1][1];
        int countNumberOfWeakCharacters = 0;

        for (int i = properties.size() - 2; i >= 0; --i) {
            countNumberOfWeakCharacters += (properties[i][1] < maxDefence) ? 1 : 0;
            maxDefence = max(maxDefence, properties[i][1]);
        }
        return countNumberOfWeakCharacters;
    }
};
