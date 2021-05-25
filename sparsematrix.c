#include <stdio.h>

void main() {
    int a[5][5], rows, columns, i, j;

    printf("Enter order of the matrix (should be less than 5x5): \n");
    scanf("%d%d", &rows, &columns);
    if((rows <= 0 || rows > 5) || (columns <=0 || columns > 5)) {
        printf("Invalid matrix order.\n");
    } else {
    printf("Enter the elements: \n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The 3-tuple representation is: \n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            if(a[i][j] != 0) {
                printf("%d %d %d\n", (i + 1), (j + 1), a[i][j]);
            }
        }
    }
    }
}