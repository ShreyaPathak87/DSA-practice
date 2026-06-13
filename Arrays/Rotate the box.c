/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize,
                    int* returnSize, int** returnColumnSizes) {
    
    int m = boxGridSize;
    int n = boxGridColSize[0];
    for (int i = 0; i < m; i++) {
        int write = n - 1;

        for (int j = n - 1; j >= 0; j--) {
            if (boxGrid[i][j] == '*') {
                write = j - 1;
            }
            else if (boxGrid[i][j] == '#') {
                boxGrid[i][j] = '.';
                boxGrid[i][write] = '#';
                write--;
            }
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    char** result = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
        result[i] = (char*)malloc(m * sizeof(char));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][m - 1 - i] = boxGrid[i][j];
        }
    }

    return result;
}