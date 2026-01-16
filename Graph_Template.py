import math

# Global Variables

"""
3 3
1 2 3
1 3 2
2 3 1
"""

Graph = [[]]


# Functions


def print_Graph():
    print("Adjacency Matrix:\n")
    print("\t", end="")
    for i in range(1, node_no + 1):
        print(f"{i}\t", end="")

    for i in range(1, node_no + 1):
        print(f"\n{i}\t", end="")
        for j in range(1, node_no + 1):
            if Graph[i][j] == math.inf:
                print("INF\t", end="")
            else:
                print(f"{Graph[i][j]}\t", end="")
    print()


# Main

node_no, edge_no = map(int, input("Enter number of nodes and edges: ").split())
Graph = [[math.inf for _ in range(node_no + 1)] for _ in range(node_no + 1)]

print("Enter connections and cost:")
for i in range(edge_no):
    u, v, c = map(int, input().split())
    Graph[u][v] = c

print_Graph()
