
#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>
#include "common.h"

using namespace std;

#define ARR_SIZE(T) (sizeof(T)/sizeof(T[0]))

template <class T>
void print_v(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << ",";
    cout << endl;
}

template <class T>
void print_vv(const vector<vector<T> >& vv) {
    for (size_t i = 0; i < vv.size(); i++) {
        print_v(vv[i]);
    }
}

template <class T>
vector<T> arr_to_vector(T *arr, size_t size) {
    size_t i = 0;
    vector<T> v;
    while (i < size) {
        v.push_back(*arr);
        arr++;
        i++;
    }
    return v;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// arr中的第一个元素必须是INT_MIN
TreeNode* build_tree(int idx, int *arr, int arr_size) {
    if (idx >= arr_size || arr[idx] == INT_MIN) {
        return NULL;
    }

    TreeNode *t = new TreeNode(arr[idx]);
    t->left = build_tree(idx * 2, arr, arr_size);
    t->right = build_tree(idx * 2 + 1, arr, arr_size);
    return t;
}

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
// arr中的第一个元素必须是INT_MIN
TreeLinkNode* build_link_tree(int idx, int *arr, int arr_size) {
    if (idx >= arr_size || arr[idx] == INT_MIN) {
        return NULL;
    }

    TreeLinkNode *t = new TreeLinkNode(arr[idx]);
    t->left = build_link_tree(idx * 2, arr, arr_size);
    t->right = build_link_tree(idx * 2 + 1, arr, arr_size);
    return t;
}

#endif // _HELPER_H_
