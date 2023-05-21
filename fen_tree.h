#ifndef FEN_TREE_H
#define FEN_TREE_H

void modify(long long* tree, int i, int x, int n);
void setTree(long long* tree, int i, int x, long long* a, int n);
void buildTree(long long* a, long long* tree, int n);
long long getSum(long long* tree, int l, int r);

#endif //fen_tree.h