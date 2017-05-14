#include "Algorithms.h"
#include <stdio.h>
#include <stdlib.h>
Board Algorithms::negamaxWithoutABP(Board & b, int depth, Team team) {
	if (depth < 1) {
		throw "Depth must be > 1";
	}
	//Get all child nodes
	std::vector<Move> moves = b.getAllMoves(team);
	std::vector<Board> boards = b.getAllBoards(b, moves);
	//Best choice
	std::vector<SHeur> allHeurs;
	//Try all moves
	for (int i = 0; i < moves.size(); i++) {
		SHeur next = negamaxWithoutABPAux(boards[i], depth - 1, team);
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

SHeur Algorithms::negamaxWithoutABPAux(Board & b, int depth, Team team) {
	//If at bottom of search tree
	Team end = b.getGameEnded();
	if (end != None) {
		return team * end * 1000000;
	}
	if (depth == 0 ) {
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
	std::vector<Move> moves = b.getAllMoves(nextTeam);
	std::vector<Board> boards = b.getAllBoards(b, moves);
	for (int i = 0; i < moves.size(); i++) {
		SHeur next = -negamaxWithoutABPAux(b,depth-1,nextTeam);
		if (next > best) {
			best = next;
		}
	}
	return best;
}

Board Algorithms::negamaxWithABP(Board & b, int depth, Team team) {
	if (depth < 1) {
		throw "Depth must be > 1";
	}
	//Get all child nodes
	std::vector<Move> moves = b.getAllMoves(team);
	std::vector<Board> boards = b.getAllBoards(b, moves);
	//Best choice
	std::vector<SHeur> allHeurs;
	//Try all moves
	for (int i = 0; i < moves.size(); i++) {
		SHeur next = negamaxWithABPAux(boards[i], depth - 1, team, -10000000000,10000000000);
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

SHeur Algorithms::negamaxWithABPAux(Board & b, int depth, Team team,int alpha, int beta) {
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
	std::vector<Move> moves = b.getAllMoves(nextTeam);
	std::vector<Board> boards = b.getAllBoards(b, moves);
	for (int i = 0; i < moves.size(); i++) {
		SHeur next = -negamaxWithABPAux(b, depth - 1, nextTeam,-beta,-alpha);
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
