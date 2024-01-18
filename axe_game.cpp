#include "raylib.h"
int main()
{
    //You can initialise and fill at the same time in C++
    int hello {203};
    bool equal{ 4==6};

    int circle_x{200};
    int circle_y{200};

    int circle_radius{25};

    //circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};


    int width{800};
    int height{450};

    //Width, height, title
    InitWindow(width, height, "Stephen's Window");
    //Make the frame move at 60 fps per seconds
    SetTargetFPS(60);

    //AXE COORDINATES
    int axe_x{400};
    int axe_y{0};
    int axe_lenght{50};
    //Axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_lenght};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_lenght};



    int direction{10};


    bool collision_with_axe= 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);


    while(WindowShouldClose() == false){
        BeginDrawing();
        
        //Clear the background to avoid flickering
        ClearBackground(RED);
        if(collision_with_axe){
            DrawText("Game Over!", 400,200,20, PURPLE);
        }
        else{

            //Update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_lenght;
            u_axe_y = axe_y;
            u_axe_y = axe_y + axe_lenght;
            //Update collision detection :
            collision_with_axe= 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);
                        


            DrawCircle(circle_x,circle_y,circle_radius,BLUE);
            DrawRectangle(axe_x,axe_y, axe_lenght, axe_lenght, GREEN);

            //move the axe
            axe_y+=direction;
            if(axe_y > height || axe_y < 0){
                direction = -direction;
            }

            //Key_d means if the button D is pressed
            if(IsKeyDown(KEY_D) && circle_x < width){
                //Move the circle
                circle_x = circle_x + 10;
            }
            if(IsKeyDown(KEY_A) && circle_x > 0){
                //Move the circle
                circle_x = circle_x - 10;
            }

        }
        EndDrawing();

    }
}
