
#include "raylib.h"
#include "plug.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

update_t update = NULL;
void *handle;

void hot_reload() {

    char *error;

    if (handle) {
        dlclose(handle);
    }

    handle = dlopen("./libplug.so",RTLD_NOW);

    if(!handle) {
        fprintf(stderr,"%s\n",dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    update = (update_t)dlsym(handle,"update");
    
    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

}

int main() {
    int screen_width  = 1020;
    int screen_height = 600;

    InitWindow(screen_width, screen_height, "hotApp");

    SetTargetFPS(60);
    hot_reload();
    while(!WindowShouldClose()) {
        if (IsKeyPressed(KEY_R)) {
            hot_reload();
        }
        (*update)();
    }

    dlclose(handle);

    CloseWindow();
}
