#include <graphics.h>
#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Point {
private:
    float x, y;

public:
    Point(float x = 0, float y = 0) : x(x), y(y) {}

    Point operator*(float scaleFactor) {
        return Point(x * scaleFactor, y * scaleFactor);
    }

    Point operator+(Point p) {
        return Point(x + p.x, y + p.y);
    }

    Point operator^(float angle) {
        float rad = angle * PI / 180.0;
        return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }

    float getX() const { return x; }
    float getY() const { return y; }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

void drawRectangle(Point p1, Point p2, Point p3, Point p4, int color = WHITE) {
    setcolor(color);
    line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    line(p2.getX(), p2.getY(), p3.getX(), p3.getY());
    line(p3.getX(), p3.getY(), p4.getX(), p4.getY());
    line(p4.getX(), p4.getY(), p1.getX(), p1.getY());
}

int main() {
    int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);

    Point p1(100, 100), p2(200, 100), p3(200, 150), p4(100, 150);

    cout << "Original Rectangle:\n";
    p1.display(); p2.display(); p3.display(); p4.display();
    drawRectangle(p1, p2, p3, p4, WHITE);

    float scaleFactor = 1.5;
    cout << "\nScaling by a factor of " << scaleFactor << ":\n";

    Point p1_scaled = p1 * scaleFactor;
    Point p2_scaled = p2 * scaleFactor;
    Point p3_scaled = p3 * scaleFactor;
    Point p4_scaled = p4 * scaleFactor;

    drawRectangle(p1_scaled, p2_scaled, p3_scaled, p4_scaled, GREEN);

    float tx = 50, ty = 50;
    cout << "\nTranslating by (" << tx << ", " << ty << "):\n";

    Point p1_translated = p1 + Point(tx, ty);
    Point p2_translated = p2 + Point(tx, ty);
    Point p3_translated = p3 + Point(tx, ty);
    Point p4_translated = p4 + Point(tx, ty);

    drawRectangle(p1_translated, p2_translated, p3_translated, p4_translated, YELLOW);

    float angle = 45;  
    cout << "\nRotating by " << angle << " degrees:\n";

    Point p1_rotated = p1 ^ angle;
    Point p2_rotated = p2 ^ angle;
    Point p3_rotated = p3 ^ angle;
    Point p4_rotated = p4 ^ angle;

    drawRectangle(p1_rotated, p2_rotated, p3_rotated, p4_rotated, RED);

    getch();
    closegraph();

    return 0;
}
