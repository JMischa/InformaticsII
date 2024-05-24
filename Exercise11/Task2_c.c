#include <stdio.h>

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}

struct Cell{
    int val;
    int x_coor;
    int y_coor;
};

void merge(struct Cell a[], int l, int r, int m){
    struct Cell b[r-l+1];
    for(int i = l; i <= m; i++){
        b[i-l] = a[i];
    }
    for(int i = m+1; i <= r; i++){
        b[r+m-i+1-l] = a[i];
    }
    int i = l;
    int j = r;
    for(int k = l; k <= r; k++){
        if(b[i-l].val < b[j-l].val){
            a[k] = b[i-l];
            i++;
        }
        else{
            a[k] = b[j-l];
            j--;
        }
    }
}

void merge_sort(struct Cell a[], int l, int r){
    if(l < r){
        int m = (l + r)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, r, m);
    }
}


int longest_path_all_directions(int x, int y, int M[x][y]){

    struct Cell cells[x*y+1];
    int counter = 0;
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            counter++;
            cells[counter].val = M[i][j];
            cells[counter].x_coor = i;
            cells[counter].y_coor = j;
        }
    }
    merge_sort(cells, 1, x*y);

    int dp[x][y];

    for(int cell = 1; cell <= x*y; cell++){
        int i = cells[cell].x_coor;
        int j = cells[cell].y_coor;

        dp[i][j] = 1;

        if(i > 0 && M[i-1][j] < M[i][j]){
            dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
        }
        if(j > 0 && M[i][j-1] < M[i][j]){
            dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
        }
        if(i + 1 < x && M[i+1][j] < M[i][j]){
            dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
        }
        if(j + 1 < y && M[i][j+1] < M[i][j]){
            dp[i][j] = max(dp[i][j], dp[i][j+1] + 1);
        }
    }
    int final_answer = 0;
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            final_answer = max(final_answer, dp[i][j]);
        }
    }
    return final_answer;
}

int main(){
    int M[4][6] = {
        {1, 2, 1, 4, 1, 8},
        {2, 1, 2, 3, 4, 7},
        {3, 2, 1, 4, 5, 6},
        {4, 3, 2, 1, 2, 7}
    };
    printf("Longest increasing subsequence in all direction is: %d", longest_path_all_directions(4,6,M));
    return 0;
}