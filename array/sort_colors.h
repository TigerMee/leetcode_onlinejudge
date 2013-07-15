
#include "common.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int RED = 0;
        const int WHITE = 1;
        const int BLUE = 2;

        int red = -1;
        int white = -1;
        int blue = -1;

        for (int i = 0; i < n; i++) {
            int p1;
            switch (A[i]) {
                case RED:
                    if (blue != -1) {
                        if (white != -1) {
                            p1 = white + 1;
                        } else {
                            p1 = red + 1;   // red maybe is -1.
                        }
                        swap(A, p1, i);
                        blue++;

                        if (white != -1) {
                            swap(A, red + 1, p1);
                            white++;
                        }
                    } else if (white != -1) {
                        swap(A, red + 1, i);
                        white++;
                    }
                    red++;
                    break;
                case WHITE:
                    if (blue != -1) {
                        if (white != -1) {
                            p1 = white + 1;
                        } else {
                            p1 = red + 1;
                        }
                        swap(A, p1, i);
                        blue++;
                    }
                    if (white == -1) {
                        white = red;
                    }
                    white++;
                    break;
                case BLUE:
                    if (blue == -1) {
                        blue = white != -1 ? white : red;
                    }
                    blue++;
                    break;
                default:
                    return;
            }
        }
    }

    void swap(int A[], int p1, int p2) {
        if (p1 == p2) {
            return;
        }
        int tmp = A[p1];
        A[p1] = A[p2];
        A[p2] = tmp;
        return;
    }
};
