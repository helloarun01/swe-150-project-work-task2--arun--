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
    switch(snake.direction){
        case k_up:
            snake.head_y -= snake.speed;
            break;
        
        case k_down:
            snake.head_y += snake.speed;
            break;
        
        case k_left:
            snake.head_x -= snake.speed;
            break;
        
        case k_right:
            snake.head_x += snake.speed;
            break;

    }
    
    snake.head_x = fmod(snake.head_x + snake.grid_width, snake.grid_width );
    snake.head_y = fmod(snake.head_y + snake.grid_height , snake.grid_height);

}



void update_body(SDL_Point current_head_cell, SDL_Point prev_head_cell){
    snake.body[snake.body_length] = prev_head_cell;
    snake.body_length ++;

    if(!snake.growing){
        for(int i=1; i< snake.body_length; i++){
            snake.body[i-1] = snake.body[i];
        }
        snake.body_length --;
    }
    else{
        snake.growing = false;
        snake.size ++;
        snake.speed -= 0.01f;
    }

    for(int i =0; i< snake.body_length; i++){
        if(current_head_cell.x == snake.body[i].x && current_head_cell.y == snake.body[i].y){
            snake.alive= false;
        }
    }


}



void snake_update(){

}



void grow_body(){
    snake.growing = true;

}



bool snake_cell(int s, int y){

}


void place_food(){

    int x, y;
    while(true){
        x = rand() % snake.grid_width;
        y = rand() % snake.grid_height;

        if(!snake_cell(x,y)){
            food.x = x;
            food.y = y;
            return ;
        }
    }

}





void render(SDL_Renderer * sdl_renderer, const int screen_width, const int screen_height, const int grid_width, const int grid_height){
    SDL_Rect block;

    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;
    block.x = food.x * block.w;
    block.y = food.y * block.h;

    SDL_SetRenderDrawColor(sdl_renderer, 16,21,30,255);
    SDL_RenderClear(sdl_renderer);





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