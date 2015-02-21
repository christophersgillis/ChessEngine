/*
 *  Authors:  Christopher Gillis,  Alexander Jackson
 *  Created on:  February 11, 2015
 *
 *  File that will define functions to extract information from bitboards.
 */

#ifndef BITBOARD_H_INCLUDED
#define BITBOARD_H_INCLUDED

#include <stdint.h> // for the int64_t data type.

typedef int64_t bitboard;

// The various boards that will hold information about the game.
enum Board_Types
{
    WHITE,
    BLACK,
    PAWNS,
    ROOKS,
    KNIGHTS,
    BISHOPS,
    QUEENS,
    KINGS
};

// Functions that will be used to access information from bitboards.
/*******************************************************************/

// Function that will return whether or not the index passed is occupied in the given bitboard.
// The indexes of the board will be assumed to go from 0-7.
int occupied(int x, int y, bitboard board);

// Function that will a bitboard containing one bit at the index passed in.
bitboard putPiece(int x, int y);

// Function that will initialize a bitboard to its starting values based on the Board_Type passed in.
bitboard initializeBoard(enum Board_Types type);

#endif // BITBOARD_H_INCLUDED
