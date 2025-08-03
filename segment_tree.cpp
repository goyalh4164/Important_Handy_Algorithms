#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
	vector<int> tree;
	int n;

public:
	SegmentTree(int _n) {
		n = _n;
		tree.resize(4 * n);
	}

	void build(vector<int>& a) {
		build(0, 0, n - 1, a);
	}

	int query(int l, int r) {
		return query(0, 0, n - 1, l, r);
	}

	void update(int idx, int val) {
		update(0, 0, n - 1, idx, val);
	}

private:
	void build(int node, int l, int r, vector<int>& a) {
		if (l == r) {
			tree[node] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(2 * node + 1, l, mid, a);
		build(2 * node + 2, mid + 1, r, a);
		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}

	int query(int node, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) return 0;       // no overlap
		if (ql <= l && r <= qr) return tree[node]; // full overlap
		int mid = (l + r) / 2;
		return query(2 * node + 1, l, mid, ql, qr) +
		       query(2 * node + 2, mid + 1, r, ql, qr);
	}

	void update(int node, int l, int r, int idx, int val) {
		if (l == r) {
			tree[node] = val;
			return;
		}
		int mid = (l + r) / 2;
		if (idx <= mid)
			update(2 * node + 1, l, mid, idx, val);
		else
			update(2 * node + 2, mid + 1, r, idx, val);
		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}
};

// Sample usage
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = v.size();

	SegmentTree st(n);
	st.build(v);

	cout << st.query(0, 4) << '\n';  // Output: 1+2+3+4+5 = 15
	st.update(4, 10);
	cout << st.query(2, 6) << '\n';  // Output: 3+4+10+6 = 23
	st.update(2, 20);
	cout << st.query(0, 4) << '\n';  // Output: 1+2+20+4+10 = 37

	return 0;
}
