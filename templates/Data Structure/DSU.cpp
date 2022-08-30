void make_set(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    // Path compression
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        // Union by size
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}
