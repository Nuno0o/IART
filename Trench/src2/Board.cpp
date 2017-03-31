#include "Piece.h"
Board::Board(){
	this->board =
	{
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK|SRG    ,BLACK|CPT    ,BLACK|LIT    ,BLACK|GEN    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK|SLD    ,BLACK|SRG    ,BLACK|CPT    ,BLACK|LIT    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK|SLD    ,BLACK|SLD    ,BLACK|SRG    ,BLACK|CPT    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK|SLD    ,BLACK|SLD    ,BLACK|SLD    ,BLACK|SRG    },
		{WHITE|SRG    ,WHITE|SLD    ,WHITE|SLD    ,WHITE|SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE|CPT    ,WHITE|SRG    ,WHITE|SLD    ,WHITE|SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE|LIT    ,WHITE|CPT    ,WHITE|SRG    ,WHITE|SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE|GEN    ,WHITE|LIT    ,WHITE|CPT    ,WHITE|SRG    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        }
	}
}