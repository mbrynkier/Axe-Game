#include "raylib.h"

int main()
{

    // Window dimensions
    int width{800};
    int heigth{450};
    InitWindow(width,heigth,"Marcos's Window");

    //circle attributes
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    //circle edges
    int l_circle_x {circle_x - circle_radius};
    int r_circle_x {circle_x + circle_radius};
    int u_circle_y {circle_y - circle_radius};
    int b_circle_y {circle_y + circle_radius};

    //rectangle attributes
    int rectangle_x{400};
    int rectangle_y{0};
    int rectangle_length{50};
    //rectangle edged
    int l_rectangle_x{rectangle_x};
    int r_rectangle_x{rectangle_x + rectangle_length};
    int u_rectangle_y{rectangle_y};
    int b_rectangle_y{rectangle_y + rectangle_length};
    //rectangle direction
    int direction{10};

    bool collision_with_rectangle{true};

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        

        //GameOver
        if (collision_with_rectangle)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            //Game logic begins
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(rectangle_x, rectangle_y, rectangle_length, rectangle_length, RED);

            //Move the axe
            rectangle_y += direction;
            if (rectangle_y > heigth || rectangle_y < 0)
            {
                direction = -direction;
            }
            

            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

            if (IsKeyDown(KEY_S) && circle_y < heigth)
            {
                circle_y += 10;
            }
            
            if (IsKeyDown(KEY_W) && circle_y > 0)
            {
                circle_y -= 10;
            }
            //Game logic ends
        }
        


        
        EndDrawing();
    }
    
}