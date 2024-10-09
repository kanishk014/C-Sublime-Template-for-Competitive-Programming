struct segtree {
   vector<long long> segarr;
   int size;

   segtree(int n) {
      size = 1;
      while (size < n) {
         size = size * 2;
      }

     // set size upto closest power of 2.
      segarr.resize(2 * size, 0LL);
   }

   void build(vector<int> &arr, int x, int lx, int rx) {
      if (lx + 1 == rx) {
         if (lx < arr.size())
            segarr[x] = arr[lx];

         return;
      }

      int mid = (lx + rx) / 2;
      build(arr, 2 * x + 1, lx, mid);
      build(arr, 2 * x + 2, mid, rx);
      segarr[x] = segarr[2 * x + 1] + segarr[2 * x + 2];
   }

   void build(vector<int> &arr) {
      build(arr, 0, 0, size);
   }

   void set(int ind, int val, int x, int lx, int rx) {
      if (rx - lx == 1) {
         segarr[x] = val;
         return;
      }

      int mid = (lx + rx) / 2;
      if (ind < mid) {
         set(ind, val, 2 * x + 1, lx, mid);
      }
      else {
         set(ind, val, 2 * x + 2, mid, rx);
      }

      segarr[x] = segarr[2 * x + 1] + segarr[2 * x + 2];
   }

   void set(int ind, int val) {
      set(ind, val, 0, 0, size);
   }

   long long get(int x, int lx, int rx, int l, int r) {
      if (lx >= r or rx <= l) return 0;
      if (lx >= l and rx <= r) return segarr[x];

      int mid = (lx + rx) / 2;
      long long left = get(2 * x + 1, lx, mid, l, r);
      long long right = get(2 * x + 2, mid, rx, l, r);
      return left + right;
   }

   long long get(int l, int r) {
      return get(0, 0, size, l, r);
   }
};
