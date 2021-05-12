int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **pascal = NULL, i, j;
	
	*returnSize = numRows;
	
	pascal = (int **) malloc(sizeof(int*)*numRows);
    *returnColumnSizes = (int *) malloc (sizeof(int)*numRows);
	for (i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
		pascal[i] = (int *) malloc (sizeof(int)*(i + 1));
		pascal[i][0] = 1;
		pascal[i][i] = 1;
	}
		
	i = 2;
	while (i < numRows) {
		j = 1;
		while (j < i) {
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			j++;
		}
		i++;
	}

	return pascal;
}
