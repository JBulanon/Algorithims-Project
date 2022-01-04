//
//  main.cpp
//  Shortest Path
//
//  Created by Joe Bulanon on 4/18/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <regex>

bool digit_match(std::string s)
{
    std::regex e("[-+]?([0-9]*\.[0-9]+|[0-9]+)");
    
    if (std::regex_match(s,e))
        return  true;
    return false;
}

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(std::vector<int> dist, std::vector<bool> sptSet, int V)
{
    // Initialize min value
    int min = INT_MAX, min_index = -1;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  
// Function to print shortest
// path from source to j
// using parent array
void printPath(std::vector<int> parent, int j)
{
      
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
  
    printPath(parent, parent[j]);
  
    printf("%d ", j);
    
    std::cout << std::endl;
}
  
// A utility function to print
// the constructed distance
// array
void printSolution(std::vector<int> dist, int V,
                      std::vector<int> parent, int dest)
{
    int src = 0;
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        if (i == dest)
        {
        printf("\n%d -> %d \t\t %d\t\t%d ",
                      src, i, dist[i], src);
        printPath(parent, i);
        }
    }
}
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(std::vector<std::vector<int>> graph, int src, int V, int destination)
{
    std::vector<int> dist(V); // The output array.  dist[i] will hold the shortest
    // distance from src to i
  
    std::vector<bool> sptSet(V); // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
  
    std::vector<int> parent(V);
      
        // Initialize all distances as
        // INFINITE and stpSet[] as false
        for (int i = 0; i < V; i++)
        {
            parent[0] = -1;
            dist[i] = INT_MAX;
            sptSet[i] = false;
        }
      
        // Distance of source vertex
        // from itself is always 0
        dist[src] = 0;
      
        // Find shortest path
        // for all vertices
        for (int count = 0; count < V - 1; count++)
        {
            // Pick the minimum distance
            // vertex from the set of
            // vertices not yet processed.
            // u is always equal to src
            // in first iteration.
            int u = minDistance(dist, sptSet, V);
      
            // Mark the picked vertex
            // as processed
            sptSet[u] = true;
      
            // Update dist value of the
            // adjacent vertices of the
            // picked vertex.
            for (int v = 0; v < V; v++)
      
                // Update dist[v] only if is
                // not in sptSet, there is
                // an edge from u to v, and
                // total weight of path from
                // src to v through u is smaller
                // than current value of
                // dist[v]
                if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                {
                    parent[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
        }
      
        // print the constructed
        // distance array
        printSolution(dist, V, parent, destination);
    }

int main(int argc, char* argv[])
{
    
    std::vector<std::vector<int>> Holder;
    std::vector<int> Value;
    std::string Data;
    
    int Source;
    int Destination;
    
    if (argc > 1)
        try
    {
    
        std::string FileName = argv[1];
        
        std::string characterSource = argv[2];
        
        std::string characterDestination = argv[3];
        
        std::ifstream file(FileName);
        
        if( characterSource == "A" || characterSource == "a")
        {
            Source = 0;
        }
        
        else if( characterSource == "B" || characterSource == "b")
        {
            Source = 1;
        }
        
        else if( characterSource == "C" || characterSource == "c")
        {
            Source = 2;
        }
        
        else if( characterSource == "D" || characterSource == "d")
        {
            Source = 3;
        }
        
        else if( characterSource == "E" || characterSource == "e")
        {
            Source = 4;
        }
        
        else if( characterSource == "F" || characterSource == "f")
        {
            Source = 5;
        }
        
        else if( characterSource == "G" || characterSource == "g")
        {
            Source = 6;
        }
        
        else if( characterSource == "H" || characterSource == "h")
        {
            Source = 7;
        }
        
        else if( characterSource == "I" || characterSource == "i")
        {
            Source = 8;
        }
        
        else if( characterSource == "J" || characterSource == "j")
        {
            Source = 9;
        }
        
        else if( characterSource == "K" || characterSource == "k")
        {
            Source = 10;
        }
        
        else if( characterSource == "L" || characterSource == "l")
        {
            Source = 11;
        }
        
        else
        {
            std::cout << "Error with Source Character" << std::endl;
        }
        
        if( characterDestination == "A" || characterDestination == "a")
        {
            Source = 0;
        }
        
        else if( characterDestination == "B" || characterDestination == "b")
        {
            Source = 1;
        }
        
        else if( characterDestination == "C" || characterDestination == "c")
        {
            Source = 2;
        }
        
        else if( characterDestination == "D" || characterDestination == "d")
        {
            Source = 3;
        }
        
        else if( characterDestination == "E" || characterDestination == "e")
        {
            Source = 4;
        }
        
        else if( characterDestination == "F" || characterDestination == "f")
        {
            Source = 5;
        }
        
        else if( characterDestination == "G" || characterDestination == "g")
        {
            Source = 6;
        }
        
        else if( characterDestination == "H" || characterDestination == "h")
        {
            Source = 7;
        }
        
        else if( characterDestination == "I" || characterDestination == "i")
        {
            Source = 8;
        }
        
        else if( characterDestination == "J" || characterDestination == "j")
        {
            Source = 9;
        }
        
        else if( characterDestination == "K" || characterDestination == "k")
        {
            Source = 10;
        }
        
        else if( characterDestination == "L" || characterDestination == "l")
        {
            Source = 11;
        }
    
    if (file.is_open())
    {
        getline(file, Data);
        
        while (getline(file, Data))
        {
            auto content = split(Data, " ");
            content.erase(content.begin());
            
            for(auto str: content)
            {
                if (digit_match(str))
                {
                if (str[0] == '-')
                {
                    Value.push_back(0);
                    
                }
                
                else
                {
                    int num = std::stoi(str);
                    Value.push_back(num);
                }
                }
            }
            
            Holder.push_back(Value);
        }
        
        int V = Holder.size();
        
        dijkstra(Holder, Source,V, 1);
    }
    
    
    
    }
    
    catch (std::exception e)
                {
                    std::cout << "FATAL Error: " << e.what() << std::endl;
                    return -1;
                }
    
    
        return 0;
    }

