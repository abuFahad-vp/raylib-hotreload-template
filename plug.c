#include "raylib.h"
#include "plug.h"
#include <stdio.h>

void update(void) {
    BeginDrawing();
        ClearBackground(BLUE);
        DrawLineBezier((Vector2){12,12}, (Vector2){GetMousePosition().x,GetMousePosition().y}, 3, RED);
    EndDrawing();
}

