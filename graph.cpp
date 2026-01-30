#include <iostream>
using namespace std;

class AdjacencyMatrix {
private:
    int n;
    int **adj;

public:
    AdjacencyMatrix(int n) {
        this->n = n;
        adj = new int*[n];

        for (int i = 0; i < n; i++) {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void add_edge(int origin, int destination, int weight) {
        if (origin > n || destination > n || origin <= 0 || destination <= 0) {
            cout << "Invalid edge!" << endl;
            return;
        }
        adj[origin - 1][destination - 1] = weight;
        adj[destination -1][origin -1] = weight;
    }

    void delete_edge(int origin, int destination) {
        if (origin > n || destination > n || origin <= 0 || destination <= 0) {
            cout << "Invalid edge!" << endl;
            return;
        }
        adj[origin - 1][destination - 1] = 0;
    }

    void display() {
        cout << "\nAdjacency Matrix (Weighted):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~AdjacencyMatrix() {
        for (int i = 0; i < n; i++)
            delete[] adj[i];
        delete[] adj;
    }
};

int main() {
    int nodes, edges;
    int origin, destination, weight;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    AdjacencyMatrix am(nodes);

    for (int i = 0; i < edges; i++) {
        cout << "\nEdge " << i + 1 << endl;
        cout << "Enter origin, destination, weight (-1 -1 -1 to exit): ";
        cin >> origin >> destination >> weight;

        if (origin == -1 && destination == -1 && weight == -1)
            break;

        am.add_edge(origin, destination, weight);
    }

    am.display();

    am.delete_edge(1, 2);
    cout << "\nAfter deleting edge (1 → 2):";
    am.display();

    return 0;
}
