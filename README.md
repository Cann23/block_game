# block_game

This is a block sudoku game. 
In this game, the user tries to place block to the main grid to earn points.

Moreover, the grid helps the user in some case:

1 - If the entire row is full (all ones) , then the grid resets all ones there.

2 - If the entire column is full (all ones) , then the grid resets all ones there.

3 - If the 3*3 box is full (all ones) , then the grid resets all ones there. 

# Game Scenario Summary

Initially, there is a 9*9 grid. All blocks are zero in the beginning.

Two different options can be used to create the shapes.
One for easy mode and the other one for hard mode.
In easy mode the user can create shape from input console.
However, the shape occurs randomly in the hard mode.

The user chooses x and y values to put the shape. According to these values, the user may place successfully or unsuccessfully. There are some situations that may arise for this placement:

- When the user places a shape successfully, the user gets 50 points.
- If one or more of the 3 above-mentioned situations occur, the user gets 100 points.
- If the user tries to place it where the user can't, the user loses 25 points.
            
