#include "Algorithms.h"
#include <stdio.h>
#include <stdlib.h>

Board Algorithms::negamax(Board & b, int depth, Team team,bool alphabeta) {
	if (depth < 1) {
		throw "Depth must be > 1";
	}
	//Get all child nodes
	std::list<Move> moves = b.getAllMoves(team);
	std::vector<Board> boards = b.getAllBoards(b, moves);
	//Best choice
	std::vector<SHeur> allHeurs;
    Team nextTeam;
	if (team == Black) {
		nextTeam = White;
	}
	else nextTeam = Black;
	//Try all moves
	for (int i = 0;i < boards.size();i++) {
        SHeur next;
        if(alphabeta){
            next = -negamaxWithABP(boards[i], depth - 1, nextTeam,-1000000000,1000000000);
        }
		else
            next = -negamaxWithoutABP(boards[i], depth - 1, nextTeam);
		allHeurs.push_back(next);
	}
	std::vector<int> bestIndexes;
	SHeur bestIndexValue = -10000000;
	for (int i = 0; i < allHeurs.size(); i++) {
		if (allHeurs[i] > bestIndexValue) {
			bestIndexValue = allHeurs[i];
			bestIndexes.clear();
			bestIndexes.push_back(i);
		}
		else if (allHeurs[i] == bestIndexValue) {
			bestIndexes.push_back(i);
		}
	}
	return boards[bestIndexes[rand() % bestIndexes.size()]];
}

SHeur Algorithms::negamaxWithoutABP(Board & b, int depth, Team team) {
	//If at bottom of search tree
	Team end = b.getGameEnded();
	if (end != None) {
		return team * end * 1000000;
	}
	if (depth == 0 ) {
		return team * b.calculateScore();
	}
	//Check which is the next team
	Team nextTeam;
	if (team == Black) {
		nextTeam = White;
	}
	else nextTeam = Black;
	//Best choice
	SHeur best = -100000000000;
	//Try all moves
	std::list<Move> moves = b.getAllMoves(team);
	for (auto it = moves.begin(); it != moves.end();it++) {
        Board b2 = b.movePiece(*it);
		SHeur next = -negamaxWithoutABP(b2,depth-1,nextTeam);
		if (next > best) {
			best = next;
		}
	}
	return best;
}

SHeur Algorithms::negamaxWithABP(Board & b, int depth, Team team,int alpha, int beta) {
	//If at bottom of search tree
	Team end = b.getGameEnded();
	if (end != None) {
		return team * end * 1000000;
	}
	if (depth == 0) {
		return team*b.calculateScore();
	}
	//Check which is the next team
	Team nextTeam;
	if (team == Black) {
		nextTeam = White;
	}
	else nextTeam = Black;
	//Best choice
	SHeur best = -100000000000;
	//Try all moves
	std::list<Move> moves = b.getAllMoves(team);
	for (auto it = moves.begin(); it != moves.end();it++) {
        Board b2 = b.movePiece(*it);
		SHeur next = -negamaxWithABP(b2, depth - 1, nextTeam,-beta,-alpha);
		if (next > best) {
			best = next;
		}
		if (next > alpha) {
			alpha = next;
		}
		if (alpha >= beta) {
			return alpha;
		}
	}
	return best;
}
