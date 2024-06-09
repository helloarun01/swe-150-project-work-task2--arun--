#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<SDL2/SDL.h>






enum Direction {k_up, k_down, k_left, k_right};

struct Snake{
    enum Direction direction;
    float speed;
    int size;
    bool alive;
    float head_x;
    float head_y;
    SDL_Point body[1024];     // I fixed the snake body
    int body_length;
    int growing;
    int grid_width;
    int grid_height;

};



struct Snake snake;
SDL_Point food;
int score = 0;






void update_head(){

}



void update_body(){

}



void snake_update(){

}



void grow_body(){

}



bool snake_cell(int s, int y){

}


void place_food(){

}





void render(SDL_Renderer * sdl_renderer, const int screen_width, const int screen_height, const int grid_width, const int grid_height){
    SDL_Rect block;

    
}







int main(int argc, char* argv[]){

const int frame_per_second = 60;
const int ms_per_frame = 1000/ frame_per_second;
const int screen_width = 640;
const int screen_height = 640;
const int grid_width =32;
const int grid_height =32;




snake.grid_width = grid_width;
snake.grid_height = grid_height;
snake.head_x = grid_width / 2;
snake.head_y = grid_height /2;
snake.direction = k_up;
snake.speed = 0.1f;
snake.alive = true;
snake.body_length = 0;
snake.growing = false;



if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("error : sdl failed to initialize\n sdl error:'%s'",SDL_GetError());
    return 1;
}


SDL_Window *sdl_window = SDL_CreateWindow("snake game",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            screen_width,
                                            screen_height,
                                            SDL_WINDOW_SHOWN);




if(sdl_window == NULL){
    printf("error: window could not create\n sdl_error:'%s'", SDL_GetError());
    return 1;
}


SDL_Renderer *sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
if(sdl_renderer == NULL){
    printf("error: renderer could not create\n  sdl_error: '%s'", SDL_GetError());
    return 1;
}






return 0;
}