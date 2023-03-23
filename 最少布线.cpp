#include<stdio.h>
#include<iostream>
using namespace std;
#define N 100
#define MAX 0xFFFF   

//Prim
void Prim(int n, int m,int cost[N][N], int ID[N][2]) //n¶¥µãÊý m±ßÊý
{
    int roads[N], i = 1,sum=0, min_cost, chosen_roads = 0, visited[N] = { 0 }, id[N] = { 0 };
    roads[chosen_roads++] = 0;   
    visited[0] = 1; 
    while (i < n) 
    {
        int min0 = 0, min1 = 0;  
        min_cost = MAX;
        for (int k = 0; k < n; k++) {
            if (!visited[k])
                for (int j = 0; j < chosen_roads; j++) 
                    if (cost[roads[j]][k] < min_cost) { 
                        min0 = roads[j];
                        min1 = k;
                        min_cost = cost[roads[j]][k];
                    }
        }
        visited[min1] = 1;
        roads[chosen_roads++] = min1;
        sum += min_cost;
        for (int j = 1; j <= m; j++) {
            if ((ID[j][0] == min0 && ID[j][1] == min1) || (ID[j][0] == min1 && ID[j][1] == min0)) {
                id[j] = 1;
                break;
            }
        }
        i++;
    }
    cout << sum<< endl;
    for (i = 0; i <= m; i++)
    {
        if (id[i])
            cout << i<<" ";
    }
}

int main()
{
    int cost[N][N] = { 0 }, m, n, ID[N][2] = { 0 };
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = MAX;
    for (int i = 0; i < m; i++) {
        int id, vi, vj, w;
        cin >> id >> vi >> vj >> w;
        cost[vi][vj] = w;
        cost[vj][vi] = w;
        ID[id][0] = vi;
        ID[id][1] = vj;
    }
    Prim(n, m, cost, ID);
    return 0;
}
 