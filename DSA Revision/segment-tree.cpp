const int maxN = 1e5 + 10;
vector<int> seg(maxN);

void build(int ind, int l, int r, vector<int> &arr) {
   if (l > r) return;

   if (l == r) {
      seg[ind] = arr[l];
      return;
   }

   int mid = l + (r - l) / 2;

   build(2 * ind + 1, l, mid, arr);
   build(2 * ind + 2, mid + 1, r, arr);
   seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r) {
   if (l > high or r < low) return INT_MIN;
   if (l <= low and high <= r) {
      return seg[ind];
   }

   int mid = low + (high - low) / 2;
   int left = query(2 * ind + 1, low, mid, l, r);
   int right = query(2 * ind + 2, mid + 1, high, l, r);

   return max(left, right);
}
