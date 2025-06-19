#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Draw the rings
    setcolor(BLUE);
    circle(100, 100, 50);
    setcolor(YELLOW);
    circle(220, 100, 50);
    setcolor(BLACK);
    circle(340, 100, 50);
    setcolor(GREEN);
    circle(160, 160, 50);
    setcolor(RED);
    circle(280, 160, 50);

    getch();
    closegraph();
    return 0;
}
