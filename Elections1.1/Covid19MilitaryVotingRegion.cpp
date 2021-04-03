#include "Covid19MilitaryVotingRegion.h"


//c'tor
Covid19MilitaryVotingRegion::Covid19MilitaryVotingRegion(Address& i_Address) : MilitaryVotingRegion(i_Address) , Covid19CivilianVotingRegion(i_Address), VotingRegion(i_Address)
{
	
}

//d'tor
Covid19MilitaryVotingRegion::~Covid19MilitaryVotingRegion()
{

}

//get method which helps us to recognize voting-region's type.
int Covid19MilitaryVotingRegion::getType() const
{
	return 4;
}