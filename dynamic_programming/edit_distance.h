
#include "common.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word1.length() == 0) {
            return word2.length();
        }
        if (word2.length() == 0) {
            return word1.length();
        }

        int** matrix = new int*[word1.length()];
        for (int i = 0; i < word1.length(); i++) {
            matrix[i] = new int[word2.length()];
        }

        matrix[0][0] = (word1[0] == word2[0]) ? 0 : 1;
        for (int i = 1; i < word1.length(); i++) {
            matrix[i][0] = (word1[i] == word2[0] ? i : matrix[i-1][0] + 1);
        }
        for (int j = 1; j < word2.length(); j++) {
            matrix[0][j] = (word1[0] == word2[j] ? j : matrix[0][j-1] + 1);
        }

        for (int i = 1; i < word1.length(); i++) {
            for (int j = 1; j < word2.length(); j++) {
                if (word1[i] == word2[j]) {
                    matrix[i][j] = matrix[i-1][j-1];
                } else {
                    matrix[i][j] = min(matrix[i-1][j-1],
                                        min(matrix[i-1][j], matrix[i][j-1])) + 1;

                }
            }
        }
        return matrix[word1.length()-1][word2.length()-1];
    }
};
