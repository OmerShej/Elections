#include "Covid19CivilianVotingRegion.h"


//c'tor
Covid19CivilianVotingRegion::Covid19CivilianVotingRegion(Address& i_Address) : VotingRegion(i_Address)
{
	
}

//d'tor
Covid19CivilianVotingRegion::~Covid19CivilianVotingRegion()
{

}

//get method which helps us to recognize voting-region's type.
int Covid19CivilianVotingRegion::getType() const
{
	return 2;
}