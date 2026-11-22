# THIS PROJECT IS FOR ALGORITHM LAB
# University Campus Shortest Path Finder

# Introduction

This project is designed to find the shortest path between any two locations in a university campus using Dijkstra's Algorithm. It uses an undirected weighted graph to represent the campus, where locations are vertices and roads are edges with distance values.

# Algorithm: Dijkstra's Algorithm

Dijkstra's Algorithm is used to find the shortest path between a source location and a destination location in a weighted graph with non-negative edge weights.

At first, the algorithm assigns a distance of zero to the source location and infinity to all other locations. Then it repeatedly selects the unvisited location with the smallest known distance and checks its neighboring locations. If a shorter path is found through the current location, the distance is updated.

This process continues until the shortest distances are determined. Finally, the algorithm uses the recorded previous locations to reconstruct the shortest path from the source to the destination.

# Graph Representation

The campus is represented as an undirected weighted graph.

- Vertices: Represent different campus locations.
- Edges: Represent roads connecting two locations.
- Weights: Represent the distance between connected locations.

# Output

The program displays the shortest path between the given source and destination, along with the minimum total distance.

# Conclusion

This project demonstrates the practical application of Dijkstra's Algorithm for solving shortest path problems in a weighted graph.
