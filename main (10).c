#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
typedef struct _lnode{
  int x;
  int w;
  struct _lnode *next;
} lnode;
void insert_edge(int x,int y,int w);
void dfs(int x,int y);
long long not_care[100000],safe[100000];
lnode *table[100000]={0};

int main(){
  int n,x,y,i;
  scanf("%d",&n);
  for(i=0;i<n-1;i++){
    scanf("%d%d",&x,&y);
    insert_edge(x-1,y-1,0);
  }
  dfs(0,-1);
  printf("%lld",safe[0]*2%MOD);
  return 0;
}
void insert_edge(int x,int y,int w){
  lnode *t=(lnode*)malloc(sizeof(lnode));
  t->x=y;
  t->w=w;
  t->next=table[x];
  table[x]=t;
  t=(lnode*)malloc(sizeof(lnode));
  t->x=x;
  t->w=w;
  t->next=table[y];
  table[y]=t;
  return;
}
void dfs(int x,int y){
  int f=0;
  long long not_safe=1;
  lnode *p;
  not_care[x]=1;
  for(p=table[x];p;p=p->next)
    if(p->x!=y){
      dfs(p->x,x);
      f=1;
      not_care[x]=(not_care[p->x]+safe[p->x])%MOD*not_care[x]%MOD;
      not_safe=not_safe*safe[p->x]%MOD;
    }
  if(!f)
    safe[x]=0;
  else
    safe[x]=(not_care[x]-not_safe+MOD)%MOD;
  return;
}
