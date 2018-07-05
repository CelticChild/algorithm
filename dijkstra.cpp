#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
int read(){
    char tmp=getchar();
    while (tmp<'0' || tmp>'9') tmp=getchar();
    int ret=0;
    while (tmp>='0' && tmp<='9'){
        ret=(ret<<3)+(ret<<1)+tmp-'0';
        tmp=getchar();
    }
    return ret;
}
struct edge{
    int to, cost;
};
int V, E; //頂點數、邊數
vector<edge> G[105];
int d[105];
bool vis[105];
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > Q;
    for(int i=0;i<V;i++){
		d[i]=INF;
		vis[i]=false;
	}
    d[s]=0;
    Q.push(make_pair(0, s));
    while(1){
    	while(!Q.empty() && vis[Q.top().second]) Q.pop();
    	if(Q.empty()) return;
    	int x=Q.top().second;
        vis[x]=true;
        for(edge &e : G[x]){
            if(d[e.to]>d[x]+e.cost){
                d[e.to]=d[x]+e.cost;
                Q.push(make_pair(d[e.to], e.to));
            }
        }
    }
}
int main(){
    int from, to, cost;
    V=read();
    E=read();
    for(int i = 0; i < E; i++){
        from=read();
        to=read();
        cost=read();
        G[from].push_back((edge){to, cost});
        //G[to].push_back((edge){from, cost}); //無向圖
    }
    dijkstra(0);
    for(int i = 0; i < V; i++) 
    	printf("d[%d] = %d\n", i, d[i]); //各點距離
    return 0;
}
