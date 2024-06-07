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




int main(int argc, char* argv[]){

const int frame_per_second = 60;
const int ms_per_frame = 1000/ frame_per_second;
const int scree_width = 640;
const int scree_height = 640;
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











return 0;
}