#include "Endding.h"
using namespace std;


void Endding::printEndding()
{
	EndResult = gameset.GetResult();

	if (EndResult == 0) // ����� ��
	{
		cout << "Draw" << endl;
	}	
	else if (EndResult == 2) // �̰��� ��
	{
		cout << "Win!" << endl;
	}	
	else if (EndResult == 1) // ���� ��
	{
		cout << "Lose..." << endl;
	}
}
