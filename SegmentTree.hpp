// include/SegmentTree.hpp
#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>

class SegmentTree {
private:
    std::vector<int> tree;
    std::vector<int> data;
    int size;

    void build(int node, int l, int r);
    int query(int node, int l, int r, int ql, int qr);
    void update(int node, int l, int r, int idx, int val);

public:
    SegmentTree(const std::vector<int> &input);
    int query(int l, int r);
    void update(int idx, int val);
    const std::vector<int>& getTree() const;
};

#endif

