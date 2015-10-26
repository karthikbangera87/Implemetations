#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::ctime;

int rolldice();

int main()
{
	enum Status {WIN,LOSS,CONTINUE};

	Status gamestatus;

	int myPoint;

	srand(time(0));

	int sumofdice=rolldice();

	switch(sumofdice)
	{
		case 7:
		case 11:
			gamestatus=WIN;
			break;

		case 2:
		case 3:
		case 12:
			gamestatus=LOSS;
			break;

		default:
			gamestatus=CONTINUE;
			myPoint=sumofdice;
			cout << "Point:"<<myPoint<<endl;
			break;
	}

	while (gamestatus==CONTINUE)
	{
		sumofdice=rolldice();

		if(sumofdice==myPoint)
			gamestatus=WIN;
		else if(sumofdice==7)
			gamestatus=LOSS;


	}

	if(gamestatus==WIN)
		cout<< "Player wins"<<endl;
	else
		cout<<"Player loses, House Wins"<<endl;
}

int rolldice()
{

	int dice1 = 1+rand() %6;
	int dice2 = 1+rand()%6;

	int sum=dice1+dice2;

	cout<<"Player rolls:"<<dice1 <<" + "<<dice2<<" = "<<sum<<endl;
	return sum;

}
