/*
 *  Authors:  Christopher Gillis,  Alexander Jackson
 *  Created on:  February 11, 2015
 */

#include "Bitboard.h"

// Function that will return whether the given index is occupied in the board passed in.
// Occupancy will be determined by bitshifting the index to the 1's place and then using the
// bitwise AND operation on integer 1.
int occupied(int x, int y, bitboard board)
{
    int shift = ((y * 8) + x);

    board = board >> shift;

    return (board & 1);
} // occupied(int, int, bitboard)

// Function that will bitshift integer 1 to the given index.
bitboard putPiece(int x, int y)
{
    int shift = ((y * 8) + x);

    bitboard board = 1;

    board = board << shift;

    return board;
}

// Function that will return an initialized bitboard based on the type of board passed in.
bitboard initializeBoard(enum Board_Types type)
{
    // Variable to hold bitboard to be returned.
    bitboard board = 0;
    int i, j;

    switch(type)
    {
    case WHITE:
        // Put pieces in the bottom 2 rows.
        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 8; j++)
            {
                board += putPiece(j, i);
            }
        }
        break;
    case BLACK:
        // Put pieces in the top 2 rows.
        for(i = 7; i > 5; i--)
        {
            for(j = 0; j < 8; j++)
            {
                board += putPiece(j, i);
            }
        }
        break;
    case PAWNS:
        // Put pawns in the 1st and 6th rows.
        for(i = 1; i < 8; i += 5)
        {
            for(j = 0; j < 8; j++)
            {
                board += putPiece(j, i);
            }
        }
        break;
    case ROOKS:
        // Put rooks in the corners of the board.
        for(i = 0; i < 8; i += 7)
        {
            for(j = 0; j < 8; j += 7)
            {
                board += putPiece(j, i);
            }
        }
        break;
    case KNIGHTS:
        // Put knights next to the rooks.
        for(i = 0; i < 8; i += 7)
        {
            for(j = 1; j < 7; j += 5)
            {
                board += putPiece(j, i);
            }
        }
        break;
    case BISHOPS:
        // Put bishops next to the knights.
        for(i = 0; i < 8; i += 7)
        {
            for(j = 2; j < 6; j += 3)
            {
                board += putPiece(j, i);
            }
        }
        break;
    case QUEENS:
        // Put queens on board.
        for(i = 0; i < 8; i += 7)
        {
            board += putPiece(3, i);
        }
        break;
    case KINGS:
        // Put kings on board.
        for(i = 0; i < 8; i += 7)
        {
            board += putPiece(4, i);
        }
        break;
    default:
        return 0;
        break;
    }

    return board;
} // initializeBoard(enum Board_Type)
