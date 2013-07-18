/* 
 * File:   BitManipulation.h
 * Author: Daniela
 *
 * Created on May 7, 2013, 10:23 AM
 */

#ifndef BITMANIPULATION_H
#define	BITMANIPULATION_H

/**
 * Test if the bit from the received byte, in the selected position, is on (1) or off (0).
 * 
 * @param byteToTest Byte that will be tested.
 * @param position Position to test the bit.
 * 
 * @return true if is on, false in other case.
 */
bool isOn(char byteToTest, int position);

/**
 * Turn on a bit (Set to 1) inside the received byte in the selected position. 
 * 
 * @param byteToChange Byte that will be changed.
 * @param position Position to change the bit.
 * 
 * @return Byte with a bit changed in the selected position.
 */
char setOn(char byteToChange, int position);

/**
 * Turn off a bit (Set to 0) inside the received byte in the selected position.
 * 
 * @param byteToChange Byte that will be changed.
 * @param position Position to change the bit.
 * @return Byte with a bit changed in the selected position.
 */
char setOff(char byteToChange, int position);

/**
 * Flip the state of a bit inside the received byte in the selected position.
 * 
 * @param byteToFlip Byte that will be changed.
 * @param position Position to flip the bit.
 * 
 * @return Byte with the bit flipped in the selected position.
 */
char flipState(char byteToFlip, int position);

#endif	/* BITMANIPULATION_H */

