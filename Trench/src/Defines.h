#pragma once

typedef unsigned long long U64;

const U64 universe = 0xffffffffffffffffULL;
const U64 empty = 0x0ULL;

U64 shift(unsigned int s) {
	return (1ULL << s);
}