//Prints true if the Given graph is "Bipartite"
//Bipartite graph : bipartite graph (or bigraph) is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V. Vertex sets U and V are usually called the parts of the graph. Equivalently, a bipartite graph is a graph that does not contain any odd-length cycles.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> graph = {
        {1},
        {0},
        {4},
        {4},
        {2, 3}}; //The graph is in the form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

    int level[graph.size()];
    for (int i = 0; i < graph.size(); i++)
    {
        level[i] = -1;
    }
    int queue[graph.size()], start = -1, end = -1, index;
    level[0] = 0;
    start = end = 0;
    end++;
    queue[start] = 0;
    int cont = 1;
    while (cont)
    {
        while (start < end && start != -1)
        {
            index = queue[start];
            start++;
            for (int i = 0; i < graph[index].size(); i++)
            {
                if (level[graph[index][i]] == -1)
                {
                    queue[end] = graph[index][i];
                    end++;
                    level[graph[index][i]] = level[index] + 1;
                }
                else if (level[index] == level[graph[index][i]])
                {
                    cout << 'f' << endl;
                }
            }
        }
        cont = 0;
        for (int i = 0; i < graph.size(); i++)
        {
            if (level[i] == -1)
            {
                queue[end] = i;
                end++;
                cont = 1;
                level[i] = 0;
                break;
            }
        }
    }

    cout << "true" << endl;

    for (int i = 0; i < graph.size(); i++)
    {
        cout << level[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << ", ";
        }
        cout << endl;
    }
}
