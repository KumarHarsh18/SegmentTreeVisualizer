#include "SegmentTree.hpp"

SegmentTree::SegmentTree(const std::vector<int>& data) {
    n = data.size();
    tree.resize(4 * n);
    build(data, 1, 0, n - 1);
}

void SegmentTree::build(const std::vector<int>& data, int node, int l, int r) {
    if (l == r) {
        tree[node] = data[l];
    } else {
        int mid = (l + r) / 2;
        build(data, 2 * node, l, mid);
        build(data, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void SegmentTree::update(int idx, int val) {
    update(1, 0, n - 1, idx, val);
}

void SegmentTree::update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] = val;
    } else {
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int SegmentTree::query(int l, int r) {
    return query(1, 0, n - 1, l, r);
}

int SegmentTree::query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return tree[node];
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) +
           query(2 * node + 1, mid + 1, r, ql, qr);
}

const std::vector<int>& SegmentTree::getTree() const {
    return tree;
}
