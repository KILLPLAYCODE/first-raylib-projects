#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "First prototype");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Texture2D playerTex = LoadTexture("resources/hero.png");

    Vector2 playerPos = {400,300}; 
    Vector2 playerVel = {0,0};
    float speed = 200.0f;
    float size = 0.2f;
    bool facingRight = true;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float dt = GetFrameTime();

        playerVel.x = 0;

        if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
            playerVel.x = -1;
        }
        if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
            playerVel.x = 1;
        }

       //Update
       if(playerVel.x > 0){
        facingRight = true;
       }
       if(playerVel.x < 0){
        facingRight = false;
       }
       playerPos.x += playerVel.x * speed * dt;
        BeginDrawing();
            ClearBackground(RAYWHITE);

            Rectangle source = {
                0,
                0,
                facingRight ?
                (float)playerTex.width:
                -(float)playerTex.width,
                (float)playerTex.height
            };
            Rectangle dest = {
                playerPos.x,
                playerPos.y,
                (float)playerTex.width * size,
                (float)playerTex.height * size
            };
            Vector2 origin = {
                playerTex.width * size / 2.0f,
                playerTex.height * size / 2.0f
            };
            
            DrawTexturePro(playerTex,source,dest,origin,0.0f,WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(playerTex); //clear texture
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}