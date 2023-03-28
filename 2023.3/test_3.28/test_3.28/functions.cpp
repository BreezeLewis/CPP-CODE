#define _CRT_SECURE_NO_WARNINGS

int* Array(int n)
{
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    return a;
}
int** Reshape(int* vec, int row, int col)
{

    int** a = new int* [row];
    for (int i = 0; i < row; i++)
        a[i] = new int[col];
    int len = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a[i][j] = vec[len++];
    //delete[] vec;
    return a;
}
void FreeArray(int* a)
{
    delete[] a;
}
void FreeMatrix(int** a, int row)
{
    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete[] a;
}
