#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

#include"city.h"

void Dijkstra(int i);

int main(){  
  int n,m;
  std::vector<Road>roads;
  std::vector<Node>nodes;
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++){
    Node node_load(i);
    nodes.push_back(node_load);
  }
  for(int i=0; i<m; i++){
    int node1,node2,dis;
    scanf("%d%d%d", &node1, &node2, &dis);
    Road road_load(node1-1, node2-1, dis);
    roads.push_back(road_load);
    nodes[node1-1].Connect(node2-1,dis);
    nodes[node2-1].Connect(node1-1,dis);
  }
  
  int shortcut[200];
  for(int i=0; i<200; i++)
      shortcut[i] = 0x3f3f3f;


  for(int no = 0; no < m; no++){
    int no1 = roads[no].node1;
    int no2 = roads[no].node2;

    bool exist[n];
    memset(exist,0,sizeof(exist));
    std::queue<Node>temp;
    temp.push(nodes[no1]);exist[no1] = true;
    do{
      Node head = temp.front();
      temp.pop();
      exist[head.id] = false;
      for(int i=0; i < static_cast<int>(head.neighbor.size()); i++){

        if( no1 == i && no2 == head.id)
          break;

        if( no2 == i && no1 == head.id)
          break;

        if(shortcut[head.neighbor[i]] >
            shortcut[head.id] + head.distance[i]){

          shortcut[head.neighbor[i]] = 
            shortcut[head.id] + head.distance[i];

          shortcut[head.neighbor[i]] = 
            shortcut[head.id] + head.distance[i];


          if(!exist[head.neighbor[i]])
          {
            temp.push(nodes[head.neighbor[i]]);
            exist[head.neighbor[i]] = true;
          }
        } 
      }
      while(!temp.empty());

    }
  }
  return 0;
}
