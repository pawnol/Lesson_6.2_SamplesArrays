/*
Lesson 6.2 Samples Arrays
Pawelski
5/2/2021
Here are the samples for the lesson.
*/

#include <iostream>
using namespace std;

/*
Displays the board for tic tac toe. Notice how the array needs the 
second dimension in order to work!
*/
void displayBoard(string board[][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
This function accepts an array and prints out each value on a seperate
line along with its index. This particular function traverses an array,
which we will discuss tomorrow! (SIDE NOTE: this is another example of
overloading!)
*/
void print(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << i << " : " << arr[i] << "\n";
    }
    cout << "\n";
}

/*
Doubles the first element in the array. This will change the
array back in main() as it is the same array being changed.
*/
void doubleFirstNumber(int arr[])
{
    arr[0] = arr[0] * 2;
}

int main()
{
    /*
    Example #1
    This shows some of the different ways to declare
    and initialize arrays. This example also shows
    you how to assign values to an array.
    */
    int someNumbers1[5];
    someNumbers1[0] = 1;
    someNumbers1[1] = 2;
    someNumbers1[2] = 3;
    someNumbers1[3] = 4;
    someNumbers1[4] = 5;

    int someNumbers2[5] = { 1, 2, 3 };  // remaining positions get 0

    int someNumbers3[5] = { 1, 2, 3, 4, 5 };

    int someNumbers4[] = { 1, 2, 3, 4, 5 };
    int someNumbers5[] = { 1, 2, 3 };

    // more on these lines in a few!
    print(someNumbers1, 5);
    print(someNumbers2, 5);
    print(someNumbers3, 5);
    print(someNumbers4, 5);
    print(someNumbers5, 3);

    /*
    Example #2
    This example shows how to access elements within an array.
    Treat individual elements from an array like a variable!
    */
    int replacement = 6;
    someNumbers1[0] = replacement;
    someNumbers1[1] += replacement;
    someNumbers1[2] = someNumbers1[0] + someNumbers1[1];
    someNumbers1[replacement - 3] = -2;
    print(someNumbers1, 5);
    
    // This is a clunky way of finding the sum of an array.
    // We will revisit this tomorrow!
    int sum;
    sum = someNumbers1[0] + someNumbers1[1]
        + someNumbers1[2] + someNumbers1[3]
        + someNumbers1[4];
    cout << "Sum: " << sum << "\n\n";

    /*
    Example #3
    This example shows how to use a two dimensional array.
    */
    int row, column;
    string player = "X";
    string board[3][3] = { { "-", "-", "-" }, 
        { "-", "-", "-" }, { "-", "-", "-" } };
    do
    {
        cout << player << "'s Turn\n";
        cout << "Enter the row of the spot you want >> ";
        cin >> row;
        row--;
        cout << "Enter the column of the spot you want >> ";
        cin >> column;
        column--;
        board[row][column] = player;
        displayBoard(board, 3, 3);
        cout << "Enter the symbol (X/O) of the next player or 'E' to exit >> ";
        cin >> player;
        cout << "\n";
    } while (player == "X" || player == "O");

    /*
    Example #4
    In this example, we will see how to pass an array as a
    parameter to a function. You should also notice how a function
    can change values in an array. This is because arrays are passed 
    differently than variables as copying an entire array is an 
    expensive operation. We will discuss on how C++ performs 
    this operation in Lesson 6.5 - Pointers.
    */
    int exampleArray[] = { 1, 2, 3, 4, 5 };
    print(exampleArray, 5);
    doubleFirstNumber(exampleArray);
    print(exampleArray, 5);
    return 0;
}
