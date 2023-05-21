#include <stdio.h>
#include <stdlib.h>
#include "seg_tree.h"


int max(int a, int b)
{

    if (a > b) return a;
    return b;

}

int min(int a, int b)
{

    if (a < b) return a;
    return b;

}


void buildTree(long long* a, long long* tree, int i, int t_l, int t_r)
{

    if (t_l == t_r)
    {
        long long int l = a[t_l];
        tree[i] = a[t_l];
        return;

    }

    int mid = (t_l + t_r) / 2;
    buildTree(a, tree, 2 * i, t_l, mid);
    buildTree(a, tree, 2 * i + 1, mid + 1, t_r);
    tree[i] = tree[2 * i] + tree[2 * i + 1];

}


void setTree(long long* tree, int i, int x, int idx, int l, int r)
{

    if (l == r)
    {

        tree[i] = x;
        return;

    }

    int mid = (l + r) / 2;

    if (idx <= mid)
    {

        setTree(tree, 2 * i, x, idx, l, mid);

    }
    else
    {

        setTree(tree, 2 * i + 1, x, idx, mid + 1, r);

    }

    tree[i] = tree[2 * i] + tree[2 * i + 1];
    
    return;

}

long long getSum(long long* tree, int i, int t_l, int t_r, int l, int r)
{
    //printf("tuta i = %d t_l = %d t_r = %d l = %d r = %d\n", i, t_l, t_r, l, r);
    if (l > r)
    {

        return 0;

    }

    if (t_l == l && t_r == r)
    {

        return tree[i];

    }

    int mid = (t_l + t_r) / 2;
    return getSum(tree, 2 * i, t_l, mid, l, min(mid, r)) + 
           getSum(tree, 2 * i + 1, mid + 1, t_r, max(l, mid + 1), r);

}

/*int main()
{

    long long* tree = (long long*) calloc(262144, sizeof(long long));

    int n = 0;
    int m = 0;
    int c = 0;
    int j = 0;
    int k = 0;
    int p = 1;
    scanf("%d", &n);

    while (p < n)
    {

        p <<= 1;

    }

    long long* a = (long long*) calloc(p, sizeof(long long));

    for (int i = 1; i <= n; i++)
    {

        scanf("%lld", &a[i]);
        k = a[i];
        if (i % 2 == 0)
        {

            a[i] = -a[i];

        }

    }*/

    //long long a[10] = {0, 3, -5, 6, 2, -1, 9, 12, -4};

    /*for (int i = 0; i < n * 3; i++)
    {

        printf("%lld ", tree[i]);

    }
    printf("\n");

    buildTree(a, tree, 1, 1, p);*/

    /*for (int i = 0; i < n * 3; i++)
    {

        printf("%lld ", tree[i]);

    }
    printf("\n");*/


    /*scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {

        scanf("%d %d %d", &c, &j, &k);
        if (c == 0)
        {
            if (j % 2 == 0)
            {

                k = -k;

            }
            setTree(tree, 1, k, j, 1, p);

        }
        else
        {
            long long int res = getSum(tree, 1, 1, p, j, k);
            
            if (j % 2 == 0) res = -res;
            
            printf("%lld\n", res);
            
        }

    }*/
    
    

    //printf("%lld\n", getSum(tree, 1, 1, 8, 2, 5));
    //printf("%lld\n", getSum(tree, 1, 1, 8, 2, 2));
    //printf("%lld\n", getSum(tree, 1, 1, 8, 1, 8));
    //printf("%lld\n", getSum(tree, 1, 1, 8, 6, 8));
    //setTree(tree, 1, 4, 7, 1, 8);
    //printf("%lld\n", getSum(tree, 1, 1, 8, 6, 8));


    //free(tree);
    //free(a);
    
    
//}