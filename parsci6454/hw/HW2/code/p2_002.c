#include<stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include <time.h>
/*
    CSCI6454 UNO - Fall 2020
    HW2 - Question 1
    Daniel Murphy

    
*/


int rando(){
//     int i, n;
//    time_t t;
   
//    n = 5;
   
//    /* Intializes random number generator */
//    srand((unsigned) time(&t));

//    /* Print 5 random numbers from 0 to 49 */
//    for( i = 0 ; i < n ; i++ ) {
//       printf("%d\n", rand() % 50);
//    }
srand(0);

   return rand() % 50;
   
//    return(0);
}

void multiply(int m1, int m2, int mat1[][m2], 
            int n1, int n2, int mat2[][n2]) 
{ 
    int x, i, j; 
    int res[m1][n2]; 
    for (i = 0; i < m1; i++) 
    { 
        for (j = 0; j < n2; j++) 
        { 
            res[i][j] = 0; 
            for (x = 0; x < m2; x++) 
            { 
                *(*(res + i) + j) += *(*(mat1 + i) + x) * 
                                    *(*(mat2 + x) + j); 
            } 
        } 
    } 
    for (i = 0; i < m1; i++) 
    { 
        for (j = 0; j < n2; j++) 
        { 
            printf("%d ", *(*(res + i) + j)); 
        } 
        printf("\n"); 
    } 
} 
  
// Driver code 
int main() 
{ 




    // int mat1[][2] = { { 2, 4 }, { 3, 4 } }; 
    // int mat2[][2] = { { 1, 2 }, { 1, 3 } }; 
    // int m1 = 2, m2 = 2, n1 = 2, n2 = 2; 
    int mat1[][3] = { {1,2}, {3,4}, {5,6} };
    int mat2[][2] = { {7,8}, {9,10} };
    int m1 = 3, m2   = 2, n1 = 2, n2 = 2;


    // int MatA[][3] = { {1,3,5},{2,4,6} };
    // int MatB[][2] = { {7,9}, {8,10} };
    // int MatA[][2] = { {1,4},{2,5},{3,6} };
    // int MatB[][3] = { {10,20,30}, {11,21,31} };
    // int m1 = 3, m2   = 2, n1 = 2, n2 = 2;

    srand(time(NULL));

    int MatA[1000][1000];
    int MatB[1000][1000];

    int r = 1000, c = 1000;
    int *arr = (int *)malloc(r*c*sizeof(int));
    int i1, i2;
    for (i1 = 0; i1 < 1000; i1++){
        for (i2 = 0; i2 < 1000; i2++){
            MatA[i1][i2] = rand() % 50;
            MatB[i1][i2] = rand() % 50;
        }
    }
    


    int sizeA = sizeof MatA / sizeof MatA[0];

    printf("the size of the matrix is: %d", sizeA);

    int sizeB = sizeof MatB / sizeof MatB[0];

    printf("the size of the matrix is: %d", sizeB);

    int AN = sizeof MatA[0] / 4; //assumes an int
    int AM = sizeof MatA / sizeof MatA[0];
    int BN = sizeof MatB[0] / 4; //assumes an int
    int BM = sizeof MatB / sizeof MatB[0];

    // printf("N is: %d\n\n\n", NA);

    // multiply( sizeA, sizeB, MatA, NA, NB, MatB);

    int MatC[1000][1000];
    memset(MatC, 0, sizeof MatC);

    printf("\n------------------------------------\n");

    int i, e, d;
    for(i=0; i < AN; i++){
        for(e=0; e< BM; e++){
            for(d=0; d< BN; d++){
                MatC[e][i] += MatA[d][i] * MatB[e][d];
                // printf("%d * %d\t", MatA[d][i], MatB[e][d]);
            }
            // printf("\t\t");
        }
        // printf("\n");
    }



    for(i = 0; i < AN; i++){
        for(e = 0; e< BM; e++){
            // printf("%d\t", MatC[e][i]);
        }
        // printf("\n");
    }





    // int ax = sizeof MatA / sizeof MatA[0];


    // multiply(m1, m2, mat1, n1, n2, mat2); 

    // rando();
    return 0; 
} 