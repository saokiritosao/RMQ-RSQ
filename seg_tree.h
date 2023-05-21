#ifndef SEG_TREE_H
#define SEG_TREE_H

void buildTree(long long* a, long long* tree, int i, int t_l, int t_r);
void setTree(long long* tree, int i, int x, int idx, int l, int r);
long long getSum(long long* tree, int i, int t_l, int t_r, int l, int r);
int max(int a, int b);
int min(int a, int b);

#endif //seg_tree.h