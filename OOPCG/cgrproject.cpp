#include <graphics.h> 
#include <conio.h> 
#include <iostream> 

using namespace std;

// Function to draw Olympic rings
void drawOlympicRings() {
    // Colors for the Olympic rings
    int colors[] = {BLUE, YELLOW, BLACK, GREEN, RED};
    int x[] = {300, 400, 520, 620, 740};  // X-coordinates for each ring
    int y[] = {300, 400, 300, 400, 300};  // Y-coordinates for each ring
    int radius_outer = 100;
    int radius_inner = 90;

    // Draw rings with colors
    for (int i = 0; i < 5; i++) {
        setcolor(colors[i]);               // Set color for each ring
        circle(x[i], y[i], radius_outer);  // Draw outer circle
        circle(x[i], y[i], radius_inner);  // Draw inner circle
    }
}

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, (char*)"");

    // Set background color to grey
    setbkcolor(DARKGRAY);
    cleardevice();

    // Draw Olympic rings
    drawOlympicRings();

    // Wait for user input before closing
    getch();

    // Close graphics mode
    closegraph();

    return 0;
}

