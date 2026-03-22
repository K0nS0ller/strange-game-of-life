                                             m""         ""#      "      m""        
  mmmm   mmm   mmmmm   mmm           mmm   mm#mm           #    mmm    mm#mm   mmm  
 #" "#  "   #  # # #  #"  #         #" "#    #             #      #      #    #"  # 
 #   #  m"""#  # # #  #""""         #   #    #             #      #      #    #"""" 
 "#m"#  "mm"#  # # #  "#mm"         "#m#"    #             "mm  mm#mm    #    "#mm" 
  m  #                                                                              
   ""         

# how to compile?
you can compile it with that command:
```sh
gcc life.c -o life
```
then just launch binary file:
```sh
./life
```

# how to change field size?
on lines 9 and 10, you can see:
```c
#define ROW 100
#define COLUMN 100
```
just change it, then compile again

# how to change frametime?
type your frametime on string 12 (in microseconds)

# how to change rules?
You can see rules of game on lines 85-88:

```c
if(grid[row][column].alive_around <= 3){
    grid[row][column].alive = true;
}
else grid[row][column].alive = false;
```
Just type your rules instead. for example, this is the original conway's rules:

```c
if (grid[row][column].alive) {
    if (grid[row][column].alive_around != 2 && grid[row][column].alive_around != 3) grid[row][column].alive = false;
} else {
    if (grid[row][column].alive_around == 3) grid[row][column].alive = true;
}
```

