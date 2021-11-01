//
// Created by tyoun on 10/30/2021.
//

#include <catch2/catch.hpp>
#include <cstdio>


typedef unsigned char* byte_pointer;

//prints any data in hexadecimal
void show_bytes(byte_pointer start, size_t len) {
    int i;
    for( int i = 0; i < len; ++i)
        printf(" %.2x", start[i]);

    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

// bitwise function to test if a value is odd
int even( const int value)
{
    return ((value & 1) == 0);
}

TEST_CASE("show int bytes") {

    test_show_bytes(12'345);
    // ok but i'm not a hex guy
}

TEST_CASE("show binary in hex") {
    int sixty_four = 0x64;
    printf("%x\n",sixty_four);

    // numeric representation is the same number
    int number = 0xAF;
    printf("Number is %X %d %o\n", number, number, number);

    int c1, c2;
    c1 = 0x45; // 01000101
    c2 = 0x71; // 01110001
    printf("Result of %x & %x = %x\n", c1, c2, c1 & c2); // 01000001
}

TEST_CASE("other binary operators operators") {

    int i1 = 4;
    int i2 = 1;

    printf("Result of %x & %x = %d\n", i1, i2, i1 & i2);
}

TEST_CASE("testing even numbers") {
    REQUIRE(even(2));
    REQUIRE_FALSE(even(3));
}

// Communications Status Value
// Name             Description
// ERROR            True if any error is set.
// FRAMING_ERROR    A framing error
// PARITY_ERROR     Character had the wrong parity
// CARRIER_LOST     THe carrier signal went down
// CHANNEL_DOWN     Power was lost on the commuication device

// Bit assignments
// 0    ERROR
// 1    FRAMING_ERROR
// 2    PARITY_ERROR
// 3    CARRIER_LOST
// 4    CHANNEL_DOWN

// Bit numbers  setting 4 and 1 bit.
// 7 6 5 4 3 2 1 0
// 0 0 0 1 0 0 1 0

// Bit | Binary value | Hex constant
//  7    10000000        0x80
//  6    01000000        0x40
//  5    00100000        0x20
//  4    00010000        0x10
//  3    00001000        0x08
//  2    00000100        0x04
//  1    00000010        0x02
//  0    00000001        0x01

//// true if any error is set
//const int ERROR = 0x01;
//
//// Framing error occured for this character
//const int FRAMING_ERROR = 0x02;
//
//// character had the wrong parity
//const int PARITY_ERROR = 0x04;
//
//// Carrier signal went down
//const int CARRIER_LOST = 0x08;
//
//// Power was lost on the communicaton device
//const int CHANNEL_DOWN = 0x10;

// a better way to represent what's going on

const int ERROR         = (1 << 0);
const int FRAMING_ERROR = (1 << 1);
const int PARITY_ERROR  = (1 << 2);
const int CARRIER_LOST  = (1 << 3);
const int CHANNEL_DOWN  = (1 << 4);


char flags = 0;         // start all the flags at 0

TEST_CASE("ORing channel bit sets it to be channel down ") {
    char flags = 0;         // start all the flags at 0

    flags |= CHANNEL_DOWN;  // channel just died
    REQUIRE((flags & ERROR) == 0);

   /* if((flags & ERROR) != 0)
        // error flag is set
    else
        // printt f no error detected */
}
// clearing a bit
// PARITY_ERROR         00000100
// ~PARITY_ERROR        11111011
// flags                00000101
// flags & ~PARITY_ERRO 00000001

// in c this would be flags
// flags &= ~PARITY_ERROR;      // who cares about parity

TEST_CASE("HIGH_SPEED flag works but the DIRECT_CONNECT flag does not... why?"){

    const int HIGH_SPEED = (1 << 7); // modem is running fast
    const int DIRECT_CONNECT = (1 << 8);
    char flags = 0 ;

    flags |= HIGH_SPEED;          // running fast
    flags |= DIRECT_CONNECT;      // because we are wired together

    REQUIRE((flags & HIGH_SPEED) != 0);
    REQUIRE((flags & DIRECT_CONNECT) !=0);
}

// processor instructions
// understanding bitshift operations
void test_shifting() {
    int some_number = 100;
    int result ;

    // multiply by 2;
    result = some_number * 2; // 200

    result = some_number << 1; // * 2;  // 200
    result = some_number << 2; // * 4;  // 400
    result = some_number << 3; // * 8;  // 800
    result = some_number << 4; // * 16; // 1600

}