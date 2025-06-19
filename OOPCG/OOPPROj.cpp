#include <graphics.h>
#include <conio.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Set background color to white
    setbkcolor(WHITE);
    cleardevice();

    // Static x-coordinates for each ring
    int xCoords[] = {100, 220, 340, 160, 280};
    int baseY = 130;            // Base y-coordinate
    int amplitude = 20;         // Amplitude for vertical motion
    int radius = 70;            // Increased radius for larger circles

    // Colors for each ring
    int colors[] = {BLUE, YELLOW, BLACK, GREEN, RED};

    // Initial angles for sine wave motion of each ring
    float angles[] = {0, 45, 90, 135, 180};  // Start angle for each ring

    while (!kbhit()) {  // Run until a key is pressed
        cleardevice();  // Clear screen for animation effect

        for (int i = 0; i < 5; i++) {
            setcolor(colors[i]);  // Set color for each ring

            // Calculate new y position based on vertical sine wave motion
            int y = baseY + amplitude * sin(angles[i] * M_PI / 180.0);

            // Draw the ring at the new y position, keeping x position static
            circle(xCoords[i], y, radius);

            // Update angle to create continuous up-and-down motion
            angles[i] += 5;  // Adjust this value to control speed of motion
            if (angles[i] >= 360) angles[i] -= 360;  // Keep angle within bounds
        }

        delay(50);  // Delay to control animation speed
    }
    closegraph();
    return 0;
}

