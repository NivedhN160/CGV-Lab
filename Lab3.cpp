#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace chrono;

// DDA Line Drawing Algorithm
void DDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    cout << "\nDDA Points:\n";

    for (int i = 0; i <= steps; i++)
    {
        cout << "(" << round(x) << ", " << round(y) << ") ";
        x += xIncrement;
        y += yIncrement;
    }
}

// Bresenham Line Drawing Algorithm
void Bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    cout << "\n\nBresenham Points:\n";

    while (true)
    {
        cout << "(" << x1 << ", " << y1 << ") ";

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

int main()
{
    int x1, y1, x2, y2;

    cout << "Enter starting point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter ending point (x2 y2): ";
    cin >> x2 >> y2;

    // Measure DDA execution time
    auto start1 = high_resolution_clock::now();

    DDA(x1, y1, x2, y2);

    auto end1 = high_resolution_clock::now();

    // Measure Bresenham execution time
    auto start2 = high_resolution_clock::now();

    Bresenham(x1, y1, x2, y2);

    auto end2 = high_resolution_clock::now();

    auto timeDDA =
        duration_cast<nanoseconds>(end1 - start1).count();

    auto timeBresenham =
        duration_cast<nanoseconds>(end2 - start2).count();

    cout << "\n\nPerformance Comparison";
    cout << "\n----------------------";
    cout << "\nDDA Time        : " << timeDDA << " nanoseconds";
    cout << "\nBresenham Time  : " << timeBresenham << " nanoseconds";

    if (timeDDA < timeBresenham)
        cout << "\n\nDDA is faster for this execution.";

    else if (timeBresenham < timeDDA)
        cout << "\n\nBresenham is faster for this execution.";

    else
        cout << "\n\nBoth have approximately the same execution time.";

    return 0;
}