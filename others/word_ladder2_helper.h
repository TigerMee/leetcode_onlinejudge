
#include "common.h"

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (dict.find(start) == dict.end()) {
            dict.insert(start);
        }
        if (dict.find(end) == dict.end()) {
            dict.insert(end);
        }

        queue<string> q;
        unordered_map<string, pair<int, vector<string> > > dep_map;
        dep_map[start] = pair<int, vector<string> >(1, vector<string>());
        q.push(start);

        int depth = 1;
        int len = start.length();           // word length
        int min_depth = dict.size() + 2;    // 2 for start and end words
        while (!q.empty() && min_depth > depth) {
            string cur = q.front();
            q.pop();

            depth = dep_map[cur].first;
            for (int i=0; i<len; ++i)       // check word(s)
            {
                string adj = cur;
                for (char a='a'; a<='z'; ++a) {
                    if (a==cur[i]) continue;

                    adj[i] = a;
                    if (adj == end) {
                        min_depth = depth+1;
                    }

                    if (dict.find(adj) != dict.end())
                    {
                        unordered_map<string, pair<int, vector<string> > > ::iterator it = dep_map.find(adj);
                        if(it == dep_map.end()) {
                            pair<int, vector<string> > value(depth + 1, vector<string>());
                            value.second.push_back(cur);
                            dep_map[adj] = value;
                            q.push(adj);
                        } else if ((it->second).first == depth+1) {
                            it->second.second.push_back(cur);
                        }
                    }
                }
            }
        }   // end while

        vector<vector<string> > result;
        if (min_depth == dict.size() + 2) {     // only for start and end words
            return result;
        }

        vector<string> stack;
        vector<string> sequence;
        stack.push_back(end);
        while(!stack.empty()) {
            string top = stack.back();
            stack.pop_back();
            sequence.push_back(top);
            vector<string> &sons = dep_map[top].second;
            for(int i=0; i<sons.size(); ++i) {
                stack.push_back(sons[i]);
            }

            if (sons.size()==0) {
                int index = result.size();
                result.push_back(vector<string>());
                for (int i=sequence.size()-1; i>=0; --i) {
                    result[index].push_back(sequence[i]);   // save result
                }
                top = sequence.back();
                sequence.pop_back();
                while(!sequence.empty())
                {
                    string father = sequence.back();
                    vector<string> brothers = dep_map[father].second;
                    if (top != brothers[0]) {
                        break;
                    }
                    sequence.pop_back();
                    top = father;
                }
            }
        }
        return result;
    }
};
