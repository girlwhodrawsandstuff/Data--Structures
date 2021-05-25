#include <stdio.h>

void main() {
    int a[5][5], rows, columns, i, j;

    printf("Enter order of the matrix (should be less than 5x5): \n");
    scanf("%d%d", &rows, &columns);
    printf("Enter the elements: \n");

    for(i = 0; i < rows; i++) {
        for(j = 0; j < rows; j++) {
            scanf("%d", a[i][j]);
        }
    }
}