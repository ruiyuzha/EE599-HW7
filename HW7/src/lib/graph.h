#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <queue>
using namespace std;

class Graph{
  public:
    Graph(map<int, set<int> > &vertices):v_(vertices) {}
    map<int, set<int> > v_;
    
    void BFS(int root, map<int, int> &distance, map<int, vector<int> > &path);
    set<int> findRootNode();
    void topologicalSortUtil(int root, std::map<int, int> &marks, stack<int>& s);
    stack<int> topologicalSort();
    vector<bool> isInPath();
};