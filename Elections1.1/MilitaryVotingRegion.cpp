#include "MilitaryVotingRegion.h"


//c'tor
MilitaryVotingRegion::MilitaryVotingRegion(Address& i_Address) : VotingRegion(i_Address)
{

}

//d'tor
MilitaryVotingRegion::~MilitaryVotingRegion()
{

}

//get method which helps us to recognize voting-region's type.
int MilitaryVotingRegion::getType() const
{
	return 3;
}