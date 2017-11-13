/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // create the tile value to be inserted in the board
    int tile_value = (d * d);

    // Create a variable to check whether the board is even or not
    int is_even = tile_value % 2;

    //Iterate over the board to insert the tile value
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            tile_value--;

            if (is_even == 0 && tile_value == 2 )
            {
                board[i][j] = 1;
            }
            else if (is_even == 0 && tile_value == 1 )
            {
                board[i][j] = 2;
            }
            else
            {
                board[i][j] = tile_value;
            }

        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // Iterate over the board and print the tile value
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                //In place of 0 print underscore and also extra space to
                // aid visibility of double digits ints
                printf("%2c ", (char)(95));
            }
            else
            {
                // Print tile values but with extra space to aid
                // visibility of double digits of ints
                printf("%2i ", board[i][j]);
            }
        }

        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // Iterate over the board to see if a tile is moveable or not
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // If the tile is found
            if (board[i][j] == tile)
            {
                // If tile next to the given tile is 0 and
                // the next jth item is within scope
                if (board[i][j + 1] == 0 && j + 1 < d)
                 {
                    // Set the tile with value zero to the tile given
                    board[i][j + 1] = tile;

                    // Set the current tile value to zero
                    board[i][j] = 0;
                 }
                // If tile before the given tile is 0 and
                // the previous jth item (j-1) is within scope
                else if (board[i][j - 1] == 0 && j - 1 >= 0)
                 {
                    // Set the tile with value zero to the tile given
                    board[i][j - 1] = tile;

                    // Set the current tile value to zero
                    board[i][j] = 0;
                 }
                // If tile above the given tile is 0 and
                else if (board[i + 1][j] == 0 && i + 1 < d)
                 {
                    board[i + 1][j] = tile;
                    board[i][j] = 0;
                 }
                 // If the tile below the tile is 0
                else if (board[i - 1][j] == 0 && i - 1 >= 0)
                 {
                    board[i - 1][j] = tile;
                    board[i][j] = 0;
                 }
                 // An illegal
                 else
                 {
                    return false;
                 }
                 // Return if move is valid
                 return true;
            }
        }
    }
    // Return flase if the tile is not found
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // Declare and assign initial value of 1 to it
    int winning_tile = 1;

    // Iterate over the board
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // If the current tile value is same as the winning_tile
            if (board[i][j] == winning_tile)
            {
                // increase the winning_tile
                winning_tile++;
            }
            // If the last tile is 0
            else if (winning_tile == d*d && board[i][j] == 0)
            {
                return true;
            }
            // Return false if any tile not equal to winning_tile order
            else
            {
                return false;
            }
        }
    }
    return true;
}
