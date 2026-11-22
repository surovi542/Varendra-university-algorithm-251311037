#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, vector<pair<string, int>>> graph;

    // Creating the campus graph
    graph["Main Gate"].push_back({"CSE", 100});
    graph["CSE"].push_back({"Main Gate", 100});

    graph["Main Gate"].push_back({"BBA", 150});
    graph["BBA"].push_back({"Main Gate", 150});

    graph["CSE"].push_back({"EEE", 80});
    graph["EEE"].push_back({"CSE", 80});

    graph["CSE"].push_back({"Library", 120});
    graph["Library"].push_back({"CSE", 120});

    graph["EEE"].push_back({"Library", 90});
    graph["Library"].push_back({"EEE", 90});

    graph["BBA"].push_back({"Cafeteria", 70});
    graph["Cafeteria"].push_back({"BBA", 70});

    graph["Cafeteria"].push_back({"Library", 90});
    graph["Library"].push_back({"Cafeteria", 90});

    graph["Library"].push_back({"Administration", 60});
    graph["Administration"].push_back({"Library", 60});

    graph["EEE"].push_back({"Science Building", 100});
    graph["Science Building"].push_back({"EEE", 100});

    graph["Science Building"].push_back({"Administration", 110});
    graph["Administration"].push_back({"Science Building", 110});

    string source, destination;

    cout << "Enter Source: ";
    getline(cin, source);

    cout << "Enter Destination: ";
    getline(cin, destination);

    // Checking the entered locations
    if (graph.find(source) == graph.end() ||
        graph.find(destination) == graph.end())
    {
        cout << "Location not found!" << endl;
        return 0;
    }

    map<string, int> dist;
    map<string, bool> visited;
    map<string, string> parent;

    // Initializing distances
    for (auto location : graph)
    {
        dist[location.first] = INT_MAX;
        visited[location.first] = false;
    }

    dist[source] = 0;

    // Dijkstra's algorithm
    for (int i = 0; i < graph.size(); i++)
    {
        string u;
        int minimum = INT_MAX;

        // Finding the nearest unvisited location
        for (auto location : graph)
        {
            string name = location.first;

            if (visited[name] == false && dist[name] < minimum)
            {
                minimum = dist[name];
                u = name;
            }
        }

        visited[u] = true;

        // Updating neighboring locations
        for (auto neighbor : graph[u])
        {
            string v = neighbor.first;
            int weight = neighbor.second;

            if (visited[v] == false && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Finding the shortest path
    vector<string> path;
    string current = destination;

    while (current != source)
    {
        path.push_back(current);
        current = parent[current];
    }

    path.push_back(source);
    reverse(path.begin(), path.end());

    cout << "\nShortest Path: ";

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
        {
            cout << " -> ";
        }
    }

    cout << "\nMinimum Distance: " << dist[destination] << " meters" << endl;

    return 0;
}