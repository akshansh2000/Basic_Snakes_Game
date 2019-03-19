# Basic Snakes Game
The world famous Snakes game, implemented in C++ using basic libraries

## The Working
The main function consists of 3 functions, Draw(), Input(), and Logic(), called infinitely, until a boolean variable (gameover) becomes false.

### The Draw() Function
When called, this function clears the screen, draws the grid boundaries using hashtags, and prints the fruit and snake at the stored locations (explained ahead). It also shows the current user score.

### The Input() Function
It waits for the user to hit a key on the keyboard, and performs the corresponding task. The movement keys are set to W, A, S, and D, while T is set to terminate the program. Any other key is ignored.

Note: Please make sure to disable the caps lock

### The Logic() Function
It stores the coordinates for snake's head and every element of its tail. This is the function which makes sure that the fruit's location is changed everytime the snake's head conincides with it, and that the length of the snake's tail is increased by 1. Also, it modifies and takes care of the coordinates of each element of the tail, and stores them in an array which is used by the Draw() function further. This also makes sure that the snake does not exit the grid.
