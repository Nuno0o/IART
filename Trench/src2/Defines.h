#pragma once

typedef char Piece

//Piece: 1 byte
//Empty -   - Team           Rank
//  E   0   0   T   R5 |  R4   R3   R2   R1
//Team:  Team    T
//       White   0
//       Black   1
//Rank:  Rank    R5   R4   R3   R2   R1
//       Soldier 0    0    0    0    1
//       Sarg    0    0    0    1    0
//       Cap     0    0    1    0    0
//       Li      0    1    0    0    0
//       Gen     1    0    0    0    0

#define White 0x00
#define Black 0x20
#define Soldier  0x01
#define Seargent 0x02
#define Captain 0x04
#define Lieutenant 0x08
#define General 0x10
#define Empty 0x80
