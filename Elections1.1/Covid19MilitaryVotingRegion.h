#ifndef __COVID19_MILITARY_VOTINGREGION__H
#define __COVID19_MILITARY_VOTINGREGION__H
#include "VotingRegion.h"
#include "Covid19CivilianVotingRegion.h"
#include "MilitaryVotingRegion.h"

class Covid19MilitaryVotingRegion : virtual public MilitaryVotingRegion ,virtual public Covid19CivilianVotingRegion
{
protected:



public:
	//constructors
	Covid19MilitaryVotingRegion(Address& i_Address);
	Covid19MilitaryVotingRegion(Covid19MilitaryVotingRegion& other) = delete;
	virtual ~Covid19MilitaryVotingRegion();
	//getters
	virtual int getType() const;
};


#endif // __COVID19_MILITARY_VOTINGREGION__H