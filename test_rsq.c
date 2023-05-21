#include <stdio.h>
#include <stdlib.h>
#include "timer.h"


//#define SEG_TREE
#define FEN_TREE


#ifdef SEG_TREE
 
    #include "seg_tree.h"

    int SIZE_TREE = 4194304;

    #define buildTree(a, tree) buildTree(a, tree, 1, 1, SIZE_ARR)
    #define getSum(tree, l, r) getSum(tree, 1, 1, SIZE_ARR, l, r)
    #define setTree(tree, x, idx, a) setTree(tree, 1, x, idx, 1, SIZE_ARR)

    char FILE_NAME[20] = "test_segment_tree.txt";

#endif


#ifdef FEN_TREE

    #include "fen_tree.h"

    int SIZE_TREE = 1000000;
    
    #define buildTree(a, tree) buildTree(a, tree, SIZE_ARR)
    #define setTree(tree, x, idx, a) setTree(tree, idx, x, a, SIZE_ARR)

    char FILE_NAME[20] = "test_fenvik_tree.txt";

#endif


const int SIZE_ARR = 1000000;
const int N_TEST   = 5;


int main()
{

    long long* tree = (long long*) calloc(SIZE_TREE, sizeof(long long));
    long long* a    = (long long*) calloc(SIZE_ARR + 10, sizeof(long long));

    long time = 0;
    

    for (int i = 0; i < N_TEST; i++)
    {
        
        for (int j = 0; j <= SIZE_ARR; j++)
        {

            a[j] = random() % 1000;

        }

 
        buildTree(a, tree); 
        
        time_start();

        for (int j = 0; j < SIZE_ARR; j++)
        {

            char op = random() % 2;
            if (op)
            {

                int l = rand() % (SIZE_ARR - 10);
                l++;
                int len = rand() % (SIZE_ARR - l - 2);
                int r = l + len;
                //printf("susum\n");
                long long sum =  getSum(tree, l, r);

            }
            else
            {

                int x = rand() % 1000;
                int idx = rand() % SIZE_ARR;
                //printf("seset\n");
                setTree(tree, x, idx, a);

            }

        }

        time += time_stop();
    
    }


    FILE* fp = fopen(FILE_NAME, "w");
    fprintf(fp, "Время работы: %ld мс", time / N_TEST);


    fclose(fp);
    free(a);
    free(tree);
}