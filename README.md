# HOW TO COMPILE?
** you can compile it with that command:
```sh
gcc life.c -o life
```
then just launch binary file:
```sh
./life
```

# HOW TO CHANGE FIELD SIZE?
on lines 8 and 9, you can see:
```c
#define ROW 100
#define COLUMN 100
```
just change it, then compile again

# HOW TO CHANGE RULES?
You can see rules of game on lines 102-106:
```c
if(grid[row][column].alive_around == 2){
    grid[row][column].alive = true;
} else{
    grid[row][column].alive = false;
}
```
Just type your rules instead.
