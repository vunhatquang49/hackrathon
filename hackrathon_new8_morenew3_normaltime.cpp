#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
using namespace std;

vector<int> DSatTur(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);
    vector<pair<int, int>> node_degrees(n);
    for (int i = 0; i < n; i++) {
        node_degrees[i] = {adj[i].size(), i};
    }
    sort(node_degrees.rbegin(), node_degrees.rend());
    vector<int> sorted_nodes(n);
    for (int i = 0; i < n; i++) {
        sorted_nodes[i] = node_degrees[i].second;
    }
    color[sorted_nodes[0]] = 0;
    int max_color = 0;
    vector<vector<int>> neighbor_colors(n, vector<int>(n, 0));

    for (int i = 1; i < n; i++) {
        int max_saturation = -1;
        int chosen_node = -1;

        for (int j = 0; j < n; j++) {
            int node = sorted_nodes[j];
            if (color[node] == -1) {
                int saturation = 0;
                for (auto neighbor : adj[node]) {
                    if (color[neighbor] != -1) {
                        neighbor_colors[color[neighbor]][node]++;
                        saturation += (neighbor_colors[color[neighbor]][node] == 1);
                    }
                }
                if (saturation > max_saturation) {
                    max_saturation = saturation;
                    chosen_node = node;
                }
            }
        }

        vector<int> used_colors(n, 0);
        for (auto v : adj[chosen_node]) {
            if (color[v] != -1) {
                used_colors[color[v]] = 1;
            }
        }

        int j = 0;
        while (used_colors[j]) {
            j++;
        }
        color[chosen_node] = j;
        max_color = max(max_color, j);
    }

    return color;
}

int main()
{
    ofstream output_file("output_hackrathon.txt");
    ifstream input_file("input.txt");
    int n, m;
    input_file >> n >> m;
    clock_t start_time = clock();

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        input_file >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> color = DSatTur(adj);
    int max_color = *max_element(color.begin(), color.end());

    output_file << max_color + 1 << endl;
    for (int i = 0; i < n; i++)
    {
        output_file << color[i] + 1 << endl;
    }
    input_file.close();
    output_file.close();
    clock_t end_time = clock();
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    system(".\\check_valid_coloring input.txt output_hackrathon.txt");
    return 0;
}