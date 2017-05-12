#pragma once

//Piece: 1 byte
//Empty    Team            Rank
//  E    T2   T1   R5 |  R4   R3   R2   R1
//Team:  Team    T2   T1
//       White   0    1
//       Black   1    0
//Rank:  Rank    R5   R4   R3   R2   R1
//       Soldier 0    0    0    0    1
//       Sarg    0    0    0    1    0
//       Cap     0    0    1    0    0
//       Li      0    1    0    0    0
//       Gen     1    0    0    0    0

typedef unsigned char Piece;

#define WHITE 0x20
#define BLACK 0x40
#define SLD   0x01
#define SRG   0x02
#define CPT   0x04
#define LIT   0x08
#define GEN   0x10
#define EMPTY 0x80