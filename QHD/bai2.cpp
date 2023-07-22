// traveling person 2

#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n; 
int a[100][100]; 

vector<int> path; 
vector<bool> visited; 
int minCost = INF; 

void TravelingSalesmanProblem(int currentCity, int totalCost, int numVisited) {
    if (numVisited == n) {
        totalCost += a[currentCity][0];
        
        minCost = min(minCost, totalCost);
        return;
    }
    
    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);
            
            int newCost = totalCost + a[currentCity][i];
            
            if (newCost >= minCost) {
                visited[i] = false;
                path.pop_back();
                continue;
            }
            
            TravelingSalesmanProblem(i, newCost, numVisited + 1);
            
            visited[i] = false;
            path.pop_back();
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    visited.resize(n, false);
    visited[0] = true;
    
    path.push_back(0);
    
    TravelingSalesmanProblem(0, 0, 1);
    
    cout <<  minCost << endl;
    
    return 0;
}
