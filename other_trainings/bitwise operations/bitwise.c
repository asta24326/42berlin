#include <stdio.h>


int	main(void)
{
	int	a;
	int	b;
	int	result;

	// Bitwise AND (&)
	// compares bits and returns 1, only if both are 1, otherwise 0
	a = 12; // 1100 in binary
	b = 10; // 1010 in binary
	result = a & b; // 1000 in binary = 8
	printf("%d\n", result); // Output: 8


	// Bitwise OR (|)
	// compares bits and returns 1 if any of bits is 1, and 0 if both are 0s
	a = 12; // 1100
	b = 10; // 1010
	result = a | b; // 1110 in binary = 14
	printf("%d\n", result); // Output: 14


	// Bitwise XOR (^) - exception
	// returns 1 if bits are different
	a = 12; // 1100
	b = 10; // 1010
	result = a ^ b; // 0110 in binary = 6
	printf("%d\n", result); // Output: 6

	// Bitwise NOT (~)
	// inverts all bits
	a = 12; // 00001100
	result = ~a; // 11110011 = -13 (in additional code)
	printf("%d\n", result); // Output: -13


	// Bitwise Left Shift (<<)
	// moves all beats to the left for specified length, setting to zero opened bits
	a = 12; // 00001100
	result = a << 2; // 00110000 = 48
	printf("%d\n", result); // Output: 48

	// Bitwise Right Shift (>>)
	// moves all beats to the right for specified length, setting to zero opened bits
	a = 12; // 00001100
	result = a >> 2; // 00000011 = 3
	printf("%d\n", result); // Output: 3


	return (0);
}