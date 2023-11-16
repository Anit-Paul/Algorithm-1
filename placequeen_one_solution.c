#include<stdio.h>
#include<stdbool.h>
#define n 4
int board[n],col[n];
int ld[2*n-1],rd[2*n-1];
bool place_queen(int i){
    for(int j=1;j<=n;j++){
        if(col[j]==0 && ld[i+n-j]==0 && rd[i+j-1]==0){
            board[i]=j;
            col[j]=1;
            ld[i+n-j]=1;
            rd[i+j-1]=1;
            if(i==n){
                return true;
            }
            else if(place_queen(i+1)==true){
                return true;
            }
             board[i]=0;
            col[j]=0;
            ld[i+n-j]=0;
            rd[i+j-1]=0;
        }
    }
    return false;
}
int main(){
    for(int i=1;i<=n;i++){
        col[i]=0;
        board[i]=0;
    }
    for(int i=1;i<=2*n-1;i++){
        ld[i]=0;
        rd[i]=0;
    }
    place_queen(1);
    for(int i=1;i<=n;i++){
        printf("%d\t",board[i]);
    }
}
/*#include<stdio.h>
#include<stdbool.h>
#define n 4
int board[n], col[n];
int ld[2*n-1], rd[2*n-1];

bool place_queen(int i) {
    for (int j = 1; j <= n; j++) {
        if (col[j] == 0 && ld[i + n - 1] == 0 && rd[i + j - 1] == 0) {
            board[i] = j;
            col[j] = 1;
            ld[i + n - j] = 1;
            rd[i + j - 1] = 1;
            
            if (i == n) {
                return true;
            } else if (place_queen(i + 1) == true) {
                return true;
            }

            board[i] = 0;
            col[j] = 0;
            ld[i + n - j] = 0;
            rd[i + j - 1] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 1; i <= n; i++) {
        col[i] = 0;
        board[i] = 0;
    }

    for (int i = 1; i <= 2 * n - 1; i++) {
        ld[i] = 0;
        rd[i] = 0;
    }

    place_queen(1);

    for (int i = 1; i <= n; i++) {
        printf("%d\t", board[i]);
    }

    return 0;
}
*/