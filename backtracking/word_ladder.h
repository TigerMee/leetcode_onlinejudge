
#include "common.h"

class Solution {
public:
    /*
     * ���ⷽ������start��ʼ��BFS��end
     * NOTE��
     * �������ص���unordered_set��ʹ�á�unordered_set::find��ʱ�临�Ӷ���O(1)��
     * ��BFS�У����ҵ�ǰ�ڵ���������ڽڵ�ʱ�����Ǳ���dict�����е�û��visited�Ľڵ㣬Ȼ��������ߵ�distance�Ƿ���1��
     * ����ͨ������ǰ�ڵ��ֵ��string����ÿ���޸�һ���ַ����ж��Ƿ���dict��O(1)�������ȼ���distance�ķ�ʽ����
     * ʹ��unordered_set�洢�Ѿ��������Ľڵ�
     */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> added;    // ���ֵ��У������Ѿ�������·���еĵ��ʣ���ֹ����ѭ��
        queue<string> q;                // �ڵ�n������ĵ��ʣ�����һ��ת�����Ե���������ֵ��еĵ���

        int level = 0;      // start��end�ڵ����ٸ��ڵ㣨����start��end�ڵ㱾��
        int last_count = 1; // ��һ��level�ж��ٸ��ڵ�
        int cur_count = 0;  // ��ǰlevel�ж��ٸ��ڵ�

        q.push(start);
        added.insert(start);

        while(!q.empty()) {
            string s = q.front();
            q.pop();
            --last_count;

            for(int i = 0; i < s.length(); ++i) {
                for(int j = 0; j < 26; ++j) {
                    string t = s;
                    t[i] = 'a' + j;
                    if(t != s) {
                        if(t == end) return level + 2;
                        if(dict.find(t) != dict.end() && added.find(t) == added.end()) {
                            q.push(t);
                            added.insert(t);
                            ++cur_count;
                        }
                    }
                }
            }

            if(last_count == 0) {
                ++level;
                last_count = cur_count;
                cur_count = 0;
            }
        }

        return 0;
    }

    /*
    class Node {
    public:
        int num;
        string str;
        bool visited;
        vector<int> edges;
        int parent;

        Node (int n, string s)
            : num(n), str(s), visited(false), parent(-1)
        {
            edges.clear();
        }
        void connect(Node *n) {
            edges.push_back(n->num);
            n->edges.push_back(num);
        }
    };


    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start == end || dict.size() == 0) {
            return 0;
        }

        vector<Node*> g;

        Node *begin_n = NULL;
        if (dict.find(start) == dict.end()) {
            begin_n = new Node(g.size(), start);
            g.push_back(begin_n);
        }
        if (dict.find(end) == dict.end()) {
            Node *end_n = new Node(g.size(), end);
            g.push_back(end_n);
        }

        for (unordered_set<string>::iterator it = dict.begin();
            it != dict.end(); ++it) {
            Node *n = new Node(g.size(), *it);

            if (begin_n == NULL && n->str == start) {
                begin_n = n;
            }
            for (int j = 0; j < g.size(); j++) {
                if (canChange(n->str, g[j]->str)) {
                    g[j]->connect(n);
                }
            }
            g.push_back(n);
        }

        // BFS g
        queue<Node*> q;
        q.push(begin_n);
        begin_n->visited = true;
        while (!q.empty()) {
            Node *n = q.front();
            q.pop();
            for (int i = 0; i < n->edges.size(); i++) {
                Node *target = g[n->edges[i]];
                if (!target->visited) {
                    target->visited = true;
                    target->parent = n->num;
                    q.push(target);

                    if (target->str == end) {
                        int step = 1;
                        Node *tmp = target;
                        while (tmp->parent != -1) {
                            ++step;
                            tmp = g[tmp->parent];
                        }
                        return step;
                    }

                }
            }
        }

        return 0;
    }

    bool canChange(const string &str1, const string &str2) {
        if (str1.length() != str2.length()) {
            return false;
        }

        int dist = 0;
        for (size_t i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) ++dist;
            if (dist > 1) return false;
        }

        return dist == 1;
    }
    */
};
