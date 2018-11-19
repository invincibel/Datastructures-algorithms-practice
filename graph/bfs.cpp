#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
/*void printGraph(vector<int> v[],int a)
{
	for(int i=0;i<a;++i)
	{
		cout<<"for "<<i<<"\n";
		for(auto x: v[i])
			cout<<"-> "<<x;
		cout<<"\n";
	}
}*/
void bfs(vector<int> v[],int a,int V)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	list<int>queue;
	visited[a]=true;
	queue.push_back(a);
	vector<int>::iterator i;
	while(!queue.empty())
		{
			a=queue.front();
			cout<<a<<" ";
			queue.pop_front();
			for(i=v[a].begin();i!=v[a].end();++i)
			{
				if(!visited[*i])
				{
					visited[*i]=true;
					queue.push_back(*i);
				}
			}
		}
		cout<<"\n";
}
int main()
{
	int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 2, 0); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 3); 
   // printGraph(adj, V);
    bfs(adj,2,V);
    return 0; 
}