class DSU {
   vector<int> parent;
   vector<int> size;

public:
   DSU (int sz) {
      for (int i = 0; i < sz; i++) {
         parent.push_back(i);
         size.push_back(1);
      }
   }

   int findParent(int node) {
      if (parent[node] == node) {
         return node;
      }

      return parent[node] = findParent(parent[node]);
   }

   void unionBySize(int u, int v) {
      int pu = findParent(u);
      int pv = findParent(v);

      if (pu == pv) {
         return;
      }

      if (size[pu] >= size[pv]) {
         parent[pv] = pu;
         size[pu] += size[pv];
      }
      else if (size[pv] > size[pu]) {
         parent[pu] = pv;
         size[pv] += size[pu];
      }
   }
};
