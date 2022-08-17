# [Javier Lopez: Tetris tutorial in C++ platform independent](https://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/)

***!! Personal paraphrases/interpretation below !!***

## Linux Platform

Installing **libsdl-gfx1.2-dev** and **libsdl1.2-dev**:  
`$ sudo pacman -S sdl2 sdl2_gfx sdl12-compat sdl_ttf sdl2_ttf`  
- *compat* - SDL 1.2 runtime compatibility lib using SDL 2.0  
- *ttf*    - using TrueType fonts in SDL applications

# Keys
| ESC               | Quit the game                       |
|-------------------|-------------------------------------|
| z                 | Rotate piece                        |
| x                 | Drop piece                          |
| Left, Right, Down | I will not offend your intelligence |

# Introduction

## What will I learn from this?
- How to store pieces and board using matrices (*multimensional arrays*)
- How to solve the rotation problem in Tetris, with an intelligent hack
- How to check collisions between the pieces and the board.
- How the main loop of a Tetris game works.

## License
Crediting to Javier Lopez.

# Step 1: The pieces `file Pieces.h`
Creating class to ***store*** all 7 pieces: square, I, L, L-mirrored, N, N-mirrored and T.

These pieces are defined using matrix of 5x5 (not 4x4 so it can hold all piece variants) cells:  
- 0 means *no block*
- 1 means *normal block*
- 2 means *pivot block* - a rotation point

For example, an N piece:
``` c++
{0, 0, 0, 0, 0},
{0, 0, 0, 1, 0},
{0, 0, 2, 1, 0},
{0, 0, 1, 0, 0},
{0, 0, 0, 0, 0}
```

Up next is ***piece rotation***, aside from using complex rotation algebra, store 4 variants of the same piece, each as a rotation.
``` c++
{0, 0, 0, 0, 0},	{0, 0, 0, 0, 0},	{0, 0, 0, 0, 0},	{0, 0, 0, 0, 0},
{0, 0, 0, 1, 0},	{0, 1, 1, 0, 0},	{0, 0, 1, 0, 0},	{0, 0, 0, 0, 0},
{0, 0, 2, 1, 0},	{0, 0, 2, 1, 0},	{0, 1, 2, 0, 0},	{0, 1, 2, 0, 0},
{0, 0, 1, 0, 0},	{0, 0, 0, 0, 0},	{0, 1, 0, 0, 0},	{0, 0, 1, 1, 0},
{0, 0, 0, 0, 0} 	{0, 0, 0, 0, 0}		{0, 0, 0, 0, 0},	{0, 0, 0, 0, 0},
```

Be careful when 'showing the block', the pieces should:  
- appear first with their respective piece 1, 2, not with the 0s of the matrix
- '2' block to be centered
- shown their block rows one by one

![Good and Wrong initial position](./media/wrong_and_good_tetris_positions.png)

This translation requires two numbers, for horizontal and vertical. These will be in `Game();` class when creating the piece.  
The array that stores these displacements:  
```c++
Square {
	{-2, -3},
	{-2, -3},
	{-2, -3},
	{-2, -3}
}
// etc.
```

We can now create our Pieces class, this file is called `Pieces.h`:
``` cpp
#ifndef _PIECES_
#define _PIECES_

class Pieces {
public:
	int GetBlockType (int pPiece, int pRotation, int pX, int pY);
	int GetXInitialPosition (int pPiece, int pRotation);
	int GetYInitialPosition (int pPiece, int pRotation);
};

#endif // _PIECES_

/*
 * The methods' implementation is in Pieces.cpp
 *
 * Parameters:
 *	- pPiece: piece to draw
 *	- pRotation: 1 of the 4 possible rotations
 *	- pX: horizontal position in blocks
 *	- pY: vertical position in blocks
**/
```


# Step 2: The board
How to store the pieces in the board and check for collisions.

This class stores a bidimesional array of NxN blocks that are initialized to POS\_FREE. The pieces will be stored by filling these blocks when they fall down updating the block to POS\_FILLED.  
In this class we need to implement methods in order to store a piece, check if a movement is possible, delete lines, etc. Our board is going to be very flexible, we will be able to choose the amount of horizontal and vertical blocks and the size of each block.

`Board.h` for declarations and `Board.cpp` for implementations:
- **InitBoard** method is a nested loop that initializes all the board blocks to POS\_FREE.
- **StorePiece** method to store a piece in the board by filling the appropriate blocks as POS\_FILLED. There's a nested loop that iterates through the piece matrix and store the blocks in the board.
- **IsGameOver** checks if there are blocks in the first row, meaning the game is over.
- **DeleteLine** method erases a line and moves all the blocks of upper position one row down. It starts from the line that has to be removed, adn then iterating through the board in a nested loop, moves all the blocks of the uper lines one row down.
- **DeletePossibleLine** removes all the lines that should be erased from the board. It works by first checking which lines should be removed (ones that have all their horizontal blocks filled). Then, it calls the **DeleteLine** method to do its job.
- **IsFreeBlock** is a trivial method that checks out if a board block is filled or not.

Aside from *blocks*, in order to draw them to the screen, we also need to specify the position in pixels, hence needing two methods **GetXPosInPixels** and **GetYPosInPixels** to obtain the horizontal and vertical position of a given block.

**IsPossibleMovement** is the last and most complex method of `class Board`, which will be used later in the main loop to check if the movement of a piece is possible or not.  
It compares all the blocks of a piece with the blocks already stored in the board and with the board limits. That comparision is made by iterating through the piece matrix and comparing with the appropriate 5x5 area in the board. If there's a collision meaning the movement is not possible, so it returns false, else returing true.


# Step 3: The game
