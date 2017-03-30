#pragma once

typedef unsigned long long U64;

const U64 universe = 0xffffffffffffffffULL;
const U64 empty = 0x0ULL;

#define NULL64 0ULL

U64 shift(unsigned int s) {
	return (1ULL << s);
}
//Pieces enums
enum PType { General, Lieutenant, Captain, Sargent, Soldier };
enum PTeam { Black, White };