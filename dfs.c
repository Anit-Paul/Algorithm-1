#include<stdio.h>
#define max 100
int adj[max][max];
char color[max];
int parent[max],d[max],f[max],time=0;
void set_adj(int i,int j){
    adj[i][j]++;
}
void visit(int start,int vertex){
    d[start]=time++;
    color[start]='g';
    for(int i=0;i<vertex;i++){
        if(color[i]=='w' && adj[start][i]==1){
            parent[i]=start;
            visit(i,vertex);
        }
    }
    f[start]=time++;
    color[start]='b';
}
void dfs(int vertex){
    time=0;
    for(int i=0;i<vertex;i++){
        if(color[i]=='w'){
            visit(i,vertex);
        }
    }
}
int main(){
    int vertex,edge;
    printf("no of vertex : ");
    scanf("%d",& vertex);
     printf("no of edges: ");
    scanf("%d",& edge);
    for(int i=0;i<vertex;i++){
        color[i]='w';
    }
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            adj[i][j]=0;
        }
    }
    int u,v;
    for(int i=0;i<edge;i++){
        printf("--------------------------------------\n");
        printf("u : ");
        scanf("%d", & u);
        printf("v : ");
        scanf("%d", & v);
        set_adj(u-1,v-1);
    }
    /*for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }*/
    dfs(vertex);
    for(int i=0;i<vertex;i++){
        printf("parent : %d\t",parent[i]+1);
        printf("time 1 : %d\t",d[i]+1);
        printf("time 2 : %d\t",f[i]+1);
        printf("color : %c\n",color[i]);
    }
}