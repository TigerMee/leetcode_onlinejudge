
#include "common.h"



class Solution {
public:
    typedef vector<vector<string> > VV;
    typedef vector<string> V;

    struct Parent {
        vector<string> parents;
        int level;
        Parent() : level(0) {}
        Parent(int l) : level(l) {}
    };

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start == end || dict.size() == 0)
            return VV();

        //unordered_set<string> added;    // ���ֵ��У������Ѿ�������·���еĵ��ʣ���ֹ����ѭ��
        queue<string> q;                // �ڵ�n������ĵ��ʣ�����һ��ת�����Ե���������ֵ��еĵ���
        map<string, Parent> parents;

        int level = 0;      // start��end�ڵ����ٸ��ڵ㣨����start��end�ڵ㱾��
        int last_count = 1; // ��һ��level�ж��ٸ��ڵ�
        int cur_count = 0;  // ��ǰlevel�ж��ٸ��ڵ�
        bool find_end = false;

        q.push(start);
        //added.insert(start);

        while(!q.empty()) {
            string s = q.front();
            q.pop();
            --last_count;

            for(int i = 0; i < s.length(); ++i) {
                for(int j = 0; j < 26; ++j) {
                    string t = s;
                    t[i] = 'a' + j;
                    if (t == s)
                        continue;

                    if(t == end) {
                        if (!find_end) {
                            parents[end] = Parent(level);
                            find_end = true;
                        }
                        parents[end].parents.push_back(s);
                        break;
                    }

                    // todo wangqiushi
                    // ����������ڵ㻥Ϊparent�����
                    if(dict.find(t) != dict.end()) {
                        if (parents.find(t) == parents.end()) {
                            parents[t] = Parent(level);
                            parents[t].parents.push_back(s);
                            q.push(t);
                            //added.insert(t);
                            ++cur_count;
                        } else if (parents[t].level == level) {
                            parents[t].parents.push_back(s);
                        }
                    }
                }
            }

            if(last_count == 0) {
                if (find_end)
                    break;
                ++level;
                last_count = cur_count;
                cur_count = 0;
            }
        }

        if (parents.size() == 0)
            return VV();
        else
            return build_path(end, parents);
    }

    VV build_path(const string& cur, map<string, Parent>& parents) {
        VV res;
        cout << cur << endl;
        if (parents.find(cur) == parents.end()) {
            V v(1, cur);
            res.push_back(v);
            return res;
        }

        for (size_t i = 0; i < parents[cur].parents.size(); i++) {
            VV vv = build_path(parents[cur].parents[i], parents);
            for (size_t j = 0; j < vv.size(); j++) {
                vv[j].push_back(cur);
                res.push_back(vv[j]);
            }
        }
        return res;
    }
};


/*
class Solution {
public:
    typedef vector<vector<string> > VV;
    typedef vector<string> V;

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        printf("start[%s], end[%s], dict.size()=[%zu]\n",
            start.c_str(), end.c_str(), dict.size());
        VV res;
        size_t min_steps = 0;
        if (start == end || dict.size() == 0)
            return res;

        for (int i = 0; i < start.length(); i++) {
            for (int j = 0; j < 26; j++) {
                string cur = start;
                cur[i] = 'a'+j;

                //if (cur[i] == start[i])
                //    continue;

                if (cur == end) {
                    V v;
                    v.push_back(start);
                    v.push_back(end);
                    res.clear();
                    res.push_back(v);
                    return res;
                }

                if (dict.find(cur) != dict.end()) {
                    // һ��ת����Ĵʣ��ڴʵ��д���
                    // �ʵ�����Ҫȥ��start��cur
                    // ��ֹ����ѭ��
                    unordered_set<string> d = dict;
                    d.erase(start);
                    d.erase(cur);
                    VV vv = findLadders(cur, end, d);

                    for (VV::iterator it = vv.begin(); it != vv.end(); ++it) {
                        if (min_steps == 0)
                            min_steps = it->size();
                        else {
                            if (it->size() < min_steps) {
                                res.clear();
                                min_steps = it->size();
                            } else if (it->size() > min_steps) {
                                continue;
                            }
                        }
                        it->insert(it->begin(), start);
                        res.push_back(*it);

                        cout << "add res:";
                        print_v(*it);
                    }
                }
            }
        }
        return res;
    }
};
*/
