#include "graph.h"
using namespace std;

//Question 3
//O(V+E)
void Graph::BFS(int root, map<int, int> &distance, map<int, vector<int> > &path){
  map<int, int> marks;
  queue<int> q;

  if(v_.empty()){
    return;
  }

  q.push(root);
  marks[root] = 1;
  distance[root] = 0;
  path[root] = {0};

  while (!q.empty()){
    int cur = q.front();
    q.pop();
    
    int cur_dis = distance[cur];

    for(auto &n: v_[cur]){
      if(!marks[n]){
        marks[n]=1;
        distance[n] = cur_dis+1;
        path[n]=path[cur];
        path[n].push_back(n);
        q.push(n);
      }
    }
  }
}


//Question 4
//O(V+E)
set<int> Graph::findRootNode(){
  set<int> res;
  map<int, int> mark;
  if (v_.empty()){
    return res;
  }
  vector<int> node(v_.size(), 0);
  for(auto it = v_.begin(); it!=v_.end(); it++){
    for(auto &n: it->second){
      node[n]=1;
    }
  }
  for(int i = 0; i<node.size(); i++){
    if(node[i] == 0){
      res.insert(i);
    }
  }
return res;
}

//O(V+E)
void Graph::topologicalSortUtil(int root, std::map<int, int> &marks, stack<int>& s) 
{ 
    marks[root] = 1; 
  
    for (const int child: v_[root]) 
        if (marks[child] != 1) 
            topologicalSortUtil(child, marks, s); 

    s.push(root); 
} 

stack<int> Graph::topologicalSort() 
{ 
  stack<int> s; 
  map<int, int> marks;
  
  for (int i = 0; i < v_.size(); i++) 
      if (marks[i] == false) 
          topologicalSortUtil(i, marks, s);
    
  return s;
} 



//Question 5
//O(V+E)
vector<bool> Graph::isInPath(){
  vector<bool> res(v_.size(), false);
  map<int, int> dist1;
  map<int, int> dist2;
  map<int, std::vector<int> > path;

  BFS(0, dist1, path);
  BFS(v_.size()-1, dist2, path);

  for(int i = 0; i < v_.size()-1; i++){
    int d_0_n=dist1[i];
    int d_n_i=dist2[i];
    if(d_0_n+d_n_i==dist1[v_.size()-1]){
      res[i]=true;
    }
  }
  return res;
}