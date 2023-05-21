#include <stdio.h>
#include <stdlib.h>
#include "fen_tree.h"

void modify(long long* tree, int i, int x, int n)
{

    while (i < n)
    {

        tree[i] += x;
        i = i | (i + 1);

    }    

}


void setTree(long long* tree, int i, int x, long long* a, int n)
{

    long long delta = x - a[i];
    a[i] = x;
    modify(tree, i, delta, n);

}


void buildTree(long long* a, long long* tree, int n)
{

    for (int i = 0; i < n; i++)
    {

        modify(tree, i, a[i], n);

    }

}


long long getSum(long long* tree, int l, int r)
{

    long long sum = 0;
    long long s1 = 0;
    long long s2 = 0;
    l--;
    while (l >= 0)
    {
        //printf("qq s = %d\n", l);
        s1 += tree[l];
        l  = (l & (l + 1)) - 1;

    }

    while (r >= 0)
    {

        s2 += tree[r];
        r = (r & (r + 1)) - 1;

    }

    sum = s2 - s1;

    return sum;

}


/*int main()
{

    //long long* tree = (long long*) calloc(10, sizeof(long long));
    long long tree[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long long a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    buildTree(a, tree, 10);
    printf("ds\n");
    printf("sum = %lld\n", getSum(tree, 2, 4));
    printf("sum = %lld\n", getSum(tree, 0, 3));
    printf("sum = %lld\n", getSum(tree, 8, 9));
    printf("sum = %lld\n", getSum(tree, 2, 4));


}*/