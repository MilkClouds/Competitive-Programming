#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<char> > dubu;
vector<vector<int> > cost,capacity,flow,adj;

int dubu_cost[6][6]={
    {10,8,7,5,0,1},
    {8,6,4,3,0,1},
    {7,4,3,2,0,1},
    {5,3,2,2,0,1},
    {0,0,0,0,0,0},
    {1,1,1,1,0,0}
};

int n,m,src,sink;
int cal_node(int a, int b){
    return a*m+b+1;
}

int xshift[4]={0,0,1,-1};
int yshift[4]={1,-1,0,0};

int main(){

    scanf("%d %d",&n,&m);

    dubu = vector<vector<char> >(n+1,vector<char>(m+1));

    for(int i=0;i<n;i++){
        scanf("%s",&dubu[i][0]);
    }

    src=0; sink=n*m+1;
    adj = vector<vector<int> >(sink+1);
    cost = capacity = flow = vector<vector<int> >(sink+1,vector<int>(sink+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if((i+j)%2) continue;

            int A = cal_node(i,j);
            adj[src].push_back(A);
            adj[A].push_back(src); capacity[src][A]=1;

            for(int k=0;k<4;k++){
                int x=i+xshift[k];
                int y=j+yshift[k];
                
                if(!(0<=x&&x<n&&0<=y&&y<m)) continue;
                
                int B = cal_node(x,y);
                adj[A].push_back(B);
                adj[B].push_back(A); capacity[A][B]=1;
                cost[A][B] = dubu_cost[dubu[i][j]-'A'][dubu[x][y]-'A'];
                cost[B][A] = -cost[A][B];

                adj[B].push_back(sink);
                adj[sink].push_back(B); capacity[B][sink]=1;
            }
        }
    }
    
    int result=0;
    vector<int> parent,dist;
    vector<bool> inQueue;

    while(1){
        
        queue<int> q;
        q.push(src);

        parent = vector<int>(sink+1,-1);
        parent[src] = src;

        dist = vector<int>(sink+1,-1e9);
        dist[src]=0;

        inQueue = vector<bool>(sink+1,false);

        while(!q.empty()){
            int here = q.front(); q.pop();
            inQueue[here]=false;

            for(int i=0;i<adj[here].size();i++){
                int next = adj[here][i];
                if(capacity[here][next]-flow[here][next]>0 && dist[next]<dist[here]+cost[here][next]){
                    dist[next] = dist[here]+cost[here][next];
                    parent[next] = here;
                    if(!inQueue[next]){
                        q.push(next);
                        inQueue[next]=true;
                    }
                }
            }
        }

        if(parent[sink]==-1) break;
        if(dist[sink]<0) break;

        for(int p=sink;p!=src;p=parent[p]){
            flow[parent[p]][p]++;
            flow[p][parent[p]]--;
        }
        result+=dist[sink];
    }

    printf("%d\n", result);

    return 0;
}
