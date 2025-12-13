#include <iostream>
using namespace std;

int main()
{
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    int **arr = new int *[rows];
    int *colSize = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        int cols;
        cout << "Enter the number of columns: " << endl;

        cin >> cols;
        colSize[i] = cols;

        arr[i] = new int[cols];

        cout << "Enter the elements of row: " << endl;

        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The jagged array is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        int size = colSize[i];
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] colSize;

    return 0;
}