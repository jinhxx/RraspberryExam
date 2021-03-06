#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	int fndPin[8] = {9, 11, 0, 5, 6, 13, 19, 26};
	int fndData[10][8] ={
		// A, B, C, D, E, F, G, DP
		{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW}, 	// 0
		{LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW}, 		// 1
		{HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW}, 		// 2
		{HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW}, 		// 3
		{LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW}, 		// 4
		{HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW}, 		// 5
		{HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, 	// 6
		{HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW}, 		// 7
		{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, 	// 8
		{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW}, 	// 9
		//{HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW}, 	// .
	};
	
	// wiringPi setup
	wiringPiSetupGpio();
	
	// Pin mod setup
	for (i=0; i<8; i++)
		pinMode(fndPin[i], OUTPUT);
	
	// digitalWrite 
	for (i=0; i<10; i++)
	{
		for (j=0; j<8; j++)
		{
			digitalWrite(fndPin[j], fndData[i][j]);
		}
		delay(1000);
	}
	return 0;
}
