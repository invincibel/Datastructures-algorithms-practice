#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
void printGraph(vector<int> v[],int a)
{
	for(int i=0;i<a;++i)
	{
		cout<<"for "<<i<<"\n";
		for(auto x: v[i])
			cout<<"-> "<<x;
		cout<<"\n";
	}
}
int main()
{
	int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V); 
    return 0; 
}