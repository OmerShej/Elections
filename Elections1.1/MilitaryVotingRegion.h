#ifndef _MILITARY_VOTINGREGION__H
#define _MILITARY_VOTINGREGION__H
#include "VotingRegion.h"




class MilitaryVotingRegion : virtual public VotingRegion
{
protected:


public:
	//constructors
	MilitaryVotingRegion(Address& i_Address);
	MilitaryVotingRegion(MilitaryVotingRegion& other) = delete;
	virtual ~MilitaryVotingRegion();
	//getters
	virtual int getType() const;
};


#endif // _MILITARY_VOTINGREGION__H