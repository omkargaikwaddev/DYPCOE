#include <graphics.h>
#include <conio.h>

void drawPolygon() {
    // Define the concave polygon points
    int points[] = {200, 150, 250, 100, 300, 150, 250, 200, 300, 250, 200, 250, 150, 200, 200, 150, 0};
    
    // Draw the polygon
    drawpoly(8, points);
}

void scanFill(int x, int y, int fillColor, int borderColor) {
    int currentColor = getpixel(x, y);
    if (currentColor == borderColor || currentColor == fillColor) {
        return; // Stop if we hit the border or already filled
    }
    
    putpixel(x, y, fillColor); // Fill the pixel

    // Recursively fill neighboring pixels
    scanFill(x + 1, y, fillColor, borderColor);
    scanFill(x - 1, y, fillColor, borderColor);
    scanFill(x, y + 1, fillColor, borderColor);
    scanFill(x, y - 1, fillColor, borderColor);
}

int main() {
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw the polygon
    drawPolygon();

    // Fill the polygon starting from a point inside it
    scanFill(250, 150, YELLOW, WHITE);

    getch();
    closegraph();
    return 0;
}
