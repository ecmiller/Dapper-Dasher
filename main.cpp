#include "raylib.h"

int main()
{
    // Window dimensions
    const int window_width{640};
    const int window_height{480};

    // Rectangle dimensions
    const int width{50};
    const int height{80};

    int posY{window_height - height};

    bool isInAir{false};

    int velocity{0};
    // Acceleration due to gravity ((pixels / frame) / frame)
    const int gravity{1};
    const int jumpVelocity{-20};

    // Initialize the window
    InitWindow(window_width, window_height, "Dapper Dasher");

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // Ground check
        if(posY >= window_height - height)
        {
            // Rectangle is on the ground
            isInAir = false;
            // Reset velocity
            velocity = 0;
        }
        else 
        {
            // Rectangle is in the air
            isInAir = true;
            // Apply gravity
            velocity += gravity;
        }

        // Detect jump input (space key) while grounded
        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            // Apply jump velocity
            velocity += jumpVelocity;
        }

        // Update position
        posY += velocity;

        // Render the Player (rectangle)
        DrawRectangle(window_width/2, posY, width, height, BLUE);
        
        // Stop drawing
        EndDrawing();
    }
    CloseWindow();
} 