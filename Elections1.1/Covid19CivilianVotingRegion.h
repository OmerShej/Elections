#ifndef __COVID19_CIVILIAN_VOTINGREGION__H
#define __COVID19_CIVILIAN_VOTINGREGION__H
#include "VotingRegion.h"

class Covid19CivilianVotingRegion : virtual public VotingRegion
{

protected:


public:
	//constructors
	Covid19CivilianVotingRegion(Address& i_Address);
	Covid19CivilianVotingRegion(Covid19CivilianVotingRegion& other) = delete; 
	virtual ~Covid19CivilianVotingRegion();
	//getters
	virtual int getType() const;
		
	

};

#endif // !__COVID19_CIVILIAN_VOTINGREGION__H