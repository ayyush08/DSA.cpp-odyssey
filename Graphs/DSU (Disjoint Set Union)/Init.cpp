
    #include <bits/stdc++.h>
    using namespace std;

    struct DSU
    {
        vector<int> parent; // Method 1 (Union by Parent)
        vector<int> size;   // Method 2 (Union by Size)
        vector<int> rank;   // Method 3 (Union by Rank)
        void init(int n)
        { // initialize DSU with n elements
            parent.assign(n, 0);
            iota(parent.begin(), parent.end(), 0); // assign sequentially from 0 to n-1
            size.assign(n, 1);                     // initialize size of each set to 1
            rank.assign(n, 0);                     // initialize rank of each set to 0
        }
        int find(int v)
        { // find leader of any node
            if (parent[v] != v)
                return find(parent[v]); // recursive search for the root of the set with complexity O(N)
            // or
            return parent[v] = find(parent[v]); // path compression (reduces complexity to O(N*log(N)))
        }
        void merge(int a, int b)
        { // merge two sets
            a = find(a);
            b = find(b);
            if (a != b)
            {
                // parent[b] = a; 1. Method 1: make a the parent of b
                // if(size[a] < size[b])  swap(a, b); //2. Method 2: make parent of bigger size
                // 2. Method 2: make parent of bigger size
                // if(size[a]<size[b]) swap(a, b);
                // parent[b] = a; //make a the parent of b
                // size[a] += size[b]; //update size of the new parent
                if (rank[a] < rank[b])
                    swap(a, b); // 3. Method 3: union by rank
                parent[b] = a;  // make a the parent of b
                if (rank[a] == rank[b])
                    rank[a]++; // increase rank if they were
            }
        }
    }; // DSU class definition

    int main()
    {
        DSU dsu;
        int n = 10; // Example size
        dsu.init(n); // Initialize DSU with 10 elements

        // Example merges
        dsu.merge(1, 2);
        dsu.merge(2, 3);
        dsu.merge(4, 5);

        // Find leaders
        cout << "Leader of 1: " << dsu.find(1) << endl; // Should print the leader of the set containing 1
        cout << "Leader of 4: " << dsu.find(4) << endl; // Should print the leader of the set containing 4

        return 0;
    }