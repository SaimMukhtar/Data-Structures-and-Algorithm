#include <iostream>
using namespace std;

class Point 
{
    int x, y;

public:

    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Getter  
    int getX() const
    { 
        return x;
    }
    int getY() const 
    { 
        return y;
    }
    //Setter
    void setX(int X)
    {
        x = X;
    }
    void setY(int Y) 
    { 
        y = Y; 
    }

    // Set both coordinates 
    void setCoordinates(int X, int Y) {
        x = X;
        y = Y;
    }

    // Distance between points
    int distance(const Point& otherPoint) const 
    {
        int dx = x - otherPoint.getX();
        int dy = y - otherPoint.getY();
        return dx * dx + dy * dy;
    }
};

int main() 
{
    int x1, y1;
    cout << "Enter coordinates for Point 1 (x y): ";
    cin >> x1 >> y1;

    int x2, y2;
    cout << "Enter coordinates for Point 2 (x y): ";
    cin >> x2 >> y2;

    Point point1(x1, y1);
    Point point2(x2, y2);
    
    int distanceBetweenPoints = point1.distance(point2);
    cout << "Squared Distance between Point 1 and Point 2: " << distanceBetweenPoints << endl;

    return 0;
}