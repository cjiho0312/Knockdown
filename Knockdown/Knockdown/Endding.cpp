#include "Endding.h"
using namespace std;


void Endding::printEndding()
{
	EndResult = gameset.GetResult();

	if (EndResult == 0) // 비겼을 때
	{
		cout << "Draw" << endl;
	}	
	else if (EndResult == 2) // 이겼을 때
	{
		cout << "Win!" << endl;
	}	
	else if (EndResult == 1) // 졌을 때
	{
		cout << "Lose..." << endl;
	}
}
