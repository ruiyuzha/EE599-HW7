#include "src/lib/graph.h"
#include "gtest/gtest.h"
#include <vector>

TEST(DistShould, ReturnDist) {
  map<int, set<int> >vertices = {{0, {1,2,5}},
                                 {1, {0,2,3}},
                                 {2, {0,1,3}},
                                 {3, {1,2,4,6}},
                                 {4, {3}},
                                 {5, {0}},
                                 {6, {3}}};
  
  Graph g(vertices);
  map<int, int> actual_dist;
  map<int, std::vector<int>> actual_path;

  g.BFS(0, actual_dist, actual_path);

  map<int, int> expected_dist = {{0,0},{1,1},{2,1},{3,2},{4,3},{5,1},{6,3}};

  map<int, vector<int> > expected_path = {{0, {0}},
  {1, {0,1}},
  {2, {0,2}},
  {3, {0,1,3}},
  {4, {0,1,3,4}},
  {5, {0,5}},
  {6, {0,1,3,6}}
  };
  EXPECT_EQ(expected_dist, actual_dist);
  EXPECT_EQ(expected_path, actual_path);
}

TEST(RootShould, ReturnRoot) {
  map<int, set<int> >vertices = {{7, {5,6}},
                                  {6, {3,4}},
                                  {5, {2,4}},
                                  {4, {}}, 
                                  {3, {1}},
                                  {2, {1}},
                                  {1, {0}}, 
                                  {0, {}}
                                  };

  Graph g(vertices);
  set<int> actual_root=g.findRootNode();
  set<int> expected_root={7};

  EXPECT_EQ(expected_root, actual_root);
}

TEST(TopoShould, ReturnTopo) {
  map<int, set<int> >vertices = {{7, {5,6}},
                                  {6, {3,4}},
                                  {5, {2,4}},
                                  {4, {}}, 
                                  {3, {1}},
                                  {2, {1}},
                                  {1, {0}}, 
                                  {0, {}}
                                  };

  Graph g(vertices);
  stack<int> s = g.topologicalSort();
  vector<int> actual_topo;
  while (s.empty() == false) { 
    actual_topo.push_back(s.top()); 
    s.pop(); 
  }
  vector<int> expected_topo = {7,6,5,4,3,2,1,0};

  EXPECT_EQ(expected_topo, actual_topo);
}

TEST(boolShould, Returnbool) {
  map<int, set<int> > vertices = {
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
  Graph g(vertices);
  vector<bool> actual_bool=g.isInPath();
  vector<bool> expected_bool={1,1,1,0,0,1,1,0,0};
  EXPECT_EQ(expected_bool, actual_bool);
}
