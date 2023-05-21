#include <stdio.h>
#include <stdlib.h>
#include "timer.h"


int SIZE_ARR = 1000000;
int N_TEST   = 5;
char FILE_NAME[20] = "test_rmq_n_logn.txt";


int min(int a, int b)
{

    if (a < b) return a;
    return b;

}


void buildLogs(int* logs, int n)
{

    int q = 1;
    int d = 0;

    

    for (int i = 1; i <= n; i++)
    {

        while (q <= i)
        {

            q <<= 1;
            d++;

        }

        q >>= 1;
        d--;

        logs[i] = d;

    }

}


void buildST(int** ST1, int* a, int n, int* logs)
{
    
    for (int j = 0; j <= logs[n]; j++)
    {
        for (int i = 1; i <= n; i++)
        {

            if (j == 0)
            {

                ST1[i][j] = a[i];

            }
            else
            {
                if (i + (1 << j) - 1 > n)
                {

                    break;

                }

                ST1[i][j] = min(ST1[i][j - 1], ST1[i + (1 << (j - 1))][j - 1]);
                 
            }

        }

    }

}


int getMin(int** ST1, int n, int* logs, int l, int r)
{

    int lo = logs[r - l + 1];

    return min(ST1[l][lo], ST1[r - (1 << lo) + 1][lo]);

}


int main()
{

    int* logs = (int*) malloc((SIZE_ARR + 1) * sizeof(int));
    buildLogs(logs, SIZE_ARR);

    int* a = (int*) malloc((SIZE_ARR + 1) * sizeof(int));

    int** ST = (int**) calloc(SIZE_ARR + 1, sizeof(int*));
    for (int i = 0; i <= SIZE_ARR; i++)
    {

        ST[i] = (int*) calloc(logs[SIZE_ARR] + 1, sizeof(int));

    }

    long time = 0;
    

    for (int i = 0; i < N_TEST; i++)
    {
        
        for (int j = 1; j <= SIZE_ARR; j++)
        {

            a[j] = random() % 1000;

        }

 
        buildST(ST, a, SIZE_ARR, logs); 
        
        time_start();

        for (int j = 0; j < SIZE_ARR; j++)
        {


            int l = rand() % (SIZE_ARR - 10) + 1;
            l++;
            int len = rand() % (SIZE_ARR - l - 2);
            int r = l + len;
            //printf("mi l = %d r = %d\n", l, r);
            long long min =  getMin(ST, SIZE_ARR, logs, l, r);

        }

        time += time_stop();
    
    }


    FILE* fp = fopen(FILE_NAME, "w");
    fprintf(fp, "Время работы: %ld мс", time / N_TEST);


    fclose(fp);
    free(a);

    for (int i = 0; i <= SIZE_ARR; i++)
    {

        free(ST[i]);

    }

    free(ST);

    
}


/*

int main()
{
    int* logs = (int*) malloc(11 * sizeof(int));

    buildLogs(logs, 10);

    int a[11] = {0, 1, 2, 10, 8, 11, 9, 9, 10, 12, 5};

    int** ST = (int**) calloc(11, sizeof(int*));

    for (int i = 0; i <= 10; i++)
    {

        ST[i] = (int*) calloc(logs[10] + 1, sizeof(int));

    }

    buildST(ST, a, 10, logs);

    printf("%d\n", getMin(ST, 10, logs, 1, 2));
    printf("%d\n", getMin(ST, 10, logs, 1, 1));
    printf("%d\n", getMin(ST, 10, logs, 4, 6));
    printf("%d\n", getMin(ST, 10, logs, 8, 10));
    printf("%d\n", getMin(ST, 10, logs, 10, 10));


}


*/