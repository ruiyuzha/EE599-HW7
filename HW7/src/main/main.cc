#include "src/lib/graph.h"
#include <iostream>
#include <map>
#include <vector>

int main() {
  map<int, set<int> >vertices = {{0, {1,2,5}},
                                 {1, {0,2,3}},
                                 {2, {0,1,3}},
                                 {3, {1,2,4,6}},
                                 {4, {3}},
                                 {5, {0}},
                                 {6, {3}}};
  
  Graph g(vertices);
  map<int, int> distance;
  map<int, vector<int> > path;

  g.BFS(0, distance, path);

  cout << "Shortest distances: " << endl;
  for (auto it = distance.begin(); it != distance.end(); it++){
      cout << "(" << it->first <<", " << it->second << ") ";
  }
  cout << endl;

  cout << "Shortest paths: " << endl;
  for (int i = 0; i < path.size(); i++){
      cout << "(" << i << ", ";
      for (auto it = path[i].begin(); it != path[i].end(); it++){
          cout << *it << " ";
      }
      cout << ")";
  }
  cout << endl;

  //Question 4
  map<int, set<int> >vertices1 = {{7, {5,6}},
                                  {6, {3,4}},
                                  {5, {2,4}},
                                  {4, {}}, 
                                  {3, {1}},
                                  {2, {1}},
                                  {1, {0}}, 
                                  {0, {}}
                                  };

  Graph g1(vertices1);
  set<int> res=g1.findRootNode();
  for (auto &n: res){
      cout << "Root Node: " << n << endl;
  }

  stack<int> s = g1.topologicalSort();
  cout<<"Topological Sort: ";
  while (s.empty() == false) { 
    cout << s.top() << " "; 
    s.pop(); 
  }
  cout<<endl;

  //Question 5
  map<int, set<int> > vertices2 = {
      {0, {1,4,5}},
      {1, {0,2,3}},
      {2, {1,3,8}},
      {3, {1,2}},
      {4, {0}},
      {5, {0,6}},
      {6, {5,7,8}},
      {7, {6,8}},
      {8, {2,6,7}}
  };
  Graph g2(vertices2);
  vector<bool> result=g2.isInPath();
  for(int i = 0; i<(int)result.size();i++){
      if(result[i]){
          cout<<"true ";
      }
      else{
          cout<<"false ";
      }
  }
  cout<<endl;
  return EXIT_SUCCESS;
}