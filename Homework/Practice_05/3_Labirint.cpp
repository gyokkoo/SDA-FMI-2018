/*
Намерете дължината на най-кратъкия път през лабиринт.
Лабиринта е описан с карта-матрица състояща се от нули и единици.
Нулата представлява клетка в лабиринта в която може да се влезне, а единицата е препятствие(стена).
Започвайки от клетката в горния ляв ъгъл, която има координата (0,0) трябва да се придвижите
възможно най-бързо(с най-малко ходове) до клетката (x_i, y_i), като позволените ходове са:
нагоре с една позиция, надолу с една позиция, наляво с една позиция и надясно с една позииция.
Ако дадена клетка има стойност 1, то нямате право да влизате или преминавате през нея.

Input Format
На първия ред са дадени три числа: M N K
М - брой редове на матрицата
N - брой колони на матрицата
K - брой заявки
На всеки от следващите M реда се задава всеки от редовете на матрицата, като 0 съответства на празна клетка
през която може да се придвижвате, а 1 съотвества на заета клетка(препятствие).
На всеки от следващите K реда ще получите двойка X_i Y_i, която съотвества на клетката до която трябва да се придвижите
с възможно най-малко стъпки.

Constraints
1 <= М <= 5000
1 <= N <= 5000
0 <= X_i < M
0 <= Y_i < N
1 <= K <= M * N

Output Format
За всяка заявка на нов ред изведете минималния брой стъпки, за които може да се придвижите от (0, 0) до съответната клетка.
Ако няма път от началната клетка до търсения изход то върнете -1.

Sample Input 0
5 5 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 0
0 0 0 0 0
4 0
4 4
Sample Output 0
12
8
 */

#include <iostream>
#include <queue>

const int OBSTACLE_CELL_NUMBER = 1;

class Cell
{
public:
    int row;
    int col;
    int distance;

    Cell(int row, int col, int distance)
    {
        this->row = row;
        this->col = col;
        this->distance = distance;
    }
};

void deleteMatrix(bool** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int getMinDistance(bool** matrix, int N, int M, int targetRow, int targetCol)
{
    bool** isCellVisited = new bool*[N];
    for (int i = 0; i < N; i++)
    {
        isCellVisited[i] = new bool[M];
        for (int j = 0; j < M; j++)
        {
            isCellVisited[i][j] = matrix[i][j];
        }
    }

    std::queue<Cell> cellsQueue;
    cellsQueue.push(Cell(0, 0, 0));
    while (!cellsQueue.empty())
    {
        Cell current = cellsQueue.front();
        cellsQueue.pop();

        int row = current.row;
        int col = current.col;
        int distance = current.distance;

        if (current.row == targetRow && current.col == targetCol)
        {
            return current.distance;
        }

        if (row - 1 >= 0 && !isCellVisited[row - 1][col])
        {
            cellsQueue.push(Cell(row - 1, col, distance + 1));
            isCellVisited[row - 1][col] = true;
        }

        if (row + 1 < N && !isCellVisited[row + 1][col])
        {
            cellsQueue.push(Cell(row + 1, col, distance + 1));
            isCellVisited[row + 1][col] = true;
        }

        if (col - 1 >= 0 && !isCellVisited[row][col - 1])
        {
            cellsQueue.push(Cell(row, col - 1, distance + 1));
            isCellVisited[row][col - 1] = true;
        }

        if (col + 1 < M && !isCellVisited[row][col + 1])
        {
            cellsQueue.push(Cell(row, col + 1, distance + 1));
            isCellVisited[row][col + 1] = true;
        }
    }

//    deleteMatrix(matrix, N);
    return -1;
}

int main()
{
    int M = 0;
    int N = 0;
    int K = 0;

    std::cin >> M >> N >> K;

    bool** matrix = new bool*[M];
    for (int i = 0; i < M; i++)
    {
        matrix[i] = new bool[N];
        for (int j = 0; j < N; j++)
        {
            int number = 0;
            std::cin >> number;
            matrix[i][j] = number == OBSTACLE_CELL_NUMBER;
        }
    }

    for (int i = 0; i < K; i++)
    {
        int targetRow = 0;
        int targetCol = 0;
        std::cin >> targetRow >> targetCol;

        int distance = getMinDistance(matrix, N, M, targetRow, targetCol);
        std::cout << distance << "\n";
    }

    deleteMatrix(matrix, M);

    return 0;
}