
// Solution: binary search
class Solution {
 public:
     int findPos(int a[], int left, int right)
     {
         if (left > right)
             return -1;

         int mid = left + (right - left) / 2;

         if (a[left] <= a[mid])
         {
             int pos = findPos(a, mid + 1, right);

             if (pos == -1)
                 return left;
             else
                 return a[left] < a[pos] ? left : pos;
         }
         else
         {
             int pos = findPos(a, left, mid - 1);

             if (pos == -1)
                 return mid;
             else
                 return a[pos] < a[mid] ? pos : mid;
         }
     }

     int bsearch(int a[], int left, int right, int key)
     {
         if (left > right)
             return -1;

         int mid = left + (right - left) / 2;

         if (a[mid] == key)
             return mid;
         else if (a[mid] < key)
             return bsearch(a, mid + 1, right, key);
         else
             return bsearch(a, left, mid - 1, key);
     }

     int search(int A[], int n, int target) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         int pos = findPos(A, 0, n - 1);

         int index = bsearch(A, 0, pos - 1, target);
         if (index != -1)
             return index;

         return bsearch(A, pos, n - 1, target);
     }
 };


// Solution: linear
class Solution2 {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
            return -1;

        if (A[0] > target) {
            // search from end
            for (int i = n-1; i >= 0; i--) {
                if (A[i] == target)
                    return i;
                if (A[i] < target)
                    return -1;
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (A[i] == target)
                    return i;
                if (A[i] > target)
                    return -1;
            }
        }
        return -1;
    }
};
