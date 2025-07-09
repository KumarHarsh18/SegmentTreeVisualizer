#pragma once
#include <vector>

class SegmentTree {
private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& data, int node, int l, int r);
    void update(int node, int l, int r, int idx, int val);
    int query(int node, int l, int r, int ql, int qr);

public:
    SegmentTree(const std::vector<int>& data);
    void update(int idx, int val);
    int query(int l, int r);
    const std::vector<int>& getTree() const;
};
