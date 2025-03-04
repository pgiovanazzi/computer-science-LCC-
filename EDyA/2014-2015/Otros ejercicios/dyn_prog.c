

#include <stdio.h>
#include <stdlib.h>


int max (int i, int j)
{
    if(i>j) return i;
    else return j;
    
}


void print_matrix(int ** arr, int n,int m)
{
    int i,j;
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("res[%d][%d] = %d\t",i,j,arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
}

int LCS(char * seq1, int n, char * seq2, int m, int ** res )
{
    int result;
    if ((n==0)||(m==0)) return 0;
    else if (res[n][m]!=-1) return res[n][m];
    else if (seq1[n]==seq2[m]) result= 1 + LCS(seq1,n-1,seq2,m-1,res);
    else result = max(LCS(seq1,n-1,seq2,m,res), LCS(seq1, n, seq2, m-1,res));
    res[n][m] = result;
    return result;
    
}



int main(int argc, const char * argv[])
{
    int ** res, i,j;
    
    char seq1[] = {'A','B','C','D','J','G'};
    int sz1=6;
    
    char seq2[] = {'A','B','D','H','J','D','G'};
    int sz2=7;
    
    res = (int **) malloc(sizeof(int *) * sz1);
    for(i=0;i<sz1;i++){
        res[i] = (int *)malloc (sizeof(int)*sz2);
        for(j=0;j<sz2;j++)
            res[i][j]=-1;
    }
    
   // print_matrix(res, sz1, sz2);
    
    printf("LCS = %d \n\n",LCS(seq1,sz1-1,seq2,sz2-1,res));

   // print_matrix(res, sz1, sz2);

    return 0;
}

