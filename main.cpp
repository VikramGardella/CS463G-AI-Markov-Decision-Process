#include <iostream>
#include <cstdlib>

using namespace std;

/*
Prob of successful move: 0.7
Prob of going in opposite direction: 0.2
Prob of staying: 0.1
gamma1 = 1.00
gamma2 = 0.95

sum of going a direction = prob of success*reward of success +
prob of stay*reward of stay + prob of going back*reward of going back

(s is a spot, s' is spot a will should move to, s" is spot a will lead
to if it goes in the opposite direction)
V*(s) = r(s) + gamma*[0.7*r(s') + 0.2*r(s") + 0.1*r(s)]
*/

int main(){
//declaring values
	double grida[6][6];
	double gridb[6][6];
	char gridc[6][6];
	double gridd[6][6];
	int numIt = 1;
	double gammaone = 1.00;
	double gammatwo = 0.95;

	//"building" each grid
	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++){
			grida[i][j] = 0.0;
			gridb[i][j] = 0.0;
			gridc[i][j] = 'o';
			gridd[i][j] = 0.0;
		}


//establishing blocked spaces by giving them the arbitrary value of -1
	grida[2][0] = -1;
	grida[2][1] = -1;
	grida[3][1] = -1;
	grida[4][1] = -1;
	grida[1][4] = -1;
	grida[2][4] = -1;
	grida[3][4] = -1;
	grida[4][4] = -1;

//establishing spaces with values
	grida[3][0] = 100.0;
	grida[1][3] = 10.0;
	grida[4][2] = 5.0;
	grida[3][5] = 20.0;


//printing out initial grids
	cout << "Grid A (original/actual values):" << endl;
	for(int i=0; i<6; i++){
		for(int j=0; j<6;j++)
			cout << grida[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	cout << "Grid B:" << endl;
	for(int i=0; i<6; i++){
		for(int j=0; j<6;j++)
			cout << gridb[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	cout << "Grid C:" << endl;
	for(int i=0; i<6; i++){
		for(int j=0; j<6;j++)
			cout << gridc[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	cout << "Grid D:" << endl;
	for(int i=0; i<6; i++){
		for(int j=0; j<6;j++)
			cout << gridd[i][j] << " ";
		cout << endl;
	}
	cout << endl;

//V*(s) = r(s) + gamma*[0.7*r(s') + 0.2*r(s") + 0.1*r(s)]
//run iterations here and update grid values:
//Set gridb = grida first:
	for(int a=0; a<6; a++){
		for(int b=0; b<6; b++){
			gridb[a][b] = grida[a][b];
			cout << gridb[a][b] << " ";
		}
		cout << endl;
	}
//outermost loop deals with iterations, middle and inner loops deal with
//going through coordinates of elements in the 2D grids.
	for(int z=0; z<7; z++){
		cout << "Iteration #" << numIt << " utilities:" << endl << endl;
		for(int i=0; i<6; i++){
			for(int j=0; j<6; j++){
				if(gridb[i][j]>=0){//because -1 is a blocked square
					double up = 0, down = 0, left = 0, right = 0, maxa;
					char dir = 'o';

//action is attempting to move up:
					if((i-1)>=0 && gridb[i-1][j]>0)//for sum if you go up
						up = (0.7*gridb[i-1][j]);
					if((i+1)<6 && grida[i+1][j]>0)//for sum if you go down by accident
						up += (0.2*gridb[i+1][j]);
				//for sum if you stay when trying to go up
					up += (0.1*gridb[i][j]);

//action is attempting to move down
					if((i+1)<6 && gridb[i+1][j]>0)//for sum if you go down
						down = (0.7*gridb[i+1][j]);
					if((i-1)>=0 && gridb[i-1][j]>0)//for sum if you go up by accident
						down += (0.2*gridb[i-1][j]);
				//for sum if you stay when trying to go down
					down += (0.1*gridb[i][j]);

//action is attempting to move left
					if((j-1)>=0 && gridb[i][j-1]>0)//for sum if you go left
						left = (0.7*gridb[i][j-1]);
					if((j+1)<6 && gridb[i][j+1]>0)//for sum if you go right by accident
						left += (0.2*gridb[i][j+1]);
				//for sum if you stay when trying to go left
					left += (0.1*gridb[i][j]);

//action is attempting to move right
					if((j+1)<6 && gridb[i][j+1]>0)//for sum if you go right successfully
						right = (0.7*gridb[i][j+1]);
					if((j-1)>=0 && gridb[i][j-1]>0)//for sum if you go left by accident
						right += (0.2*gridb[i][j-1]);
				//for sum if you stay when trying to go left
					right += (0.1*gridb[i][j]);

					if(up<0.000001)
						up = 0.0;
					if(down<0.000001)
						down = 0.0;
					if(left<0.000001)
						left = 0.0;
					if(right<0.000001)
						right = 0.0;

//				cout << "up is: " << up << endl;
//				cout << "down is: " << down << endl;
//				cout << "left is: " << left << endl;
//				cout << "right is: " << right << endl;
					maxa = up;
					dir = '^';
					if(down>maxa){
						maxa = down;
						dir = 'v';
					}
					if(left>maxa){
						maxa = left;
						dir = '<';
					}
					if(right>maxa){
						maxa = right;
						dir = '>';
					}
//round maxa
//				cout << "maxa is: " << maxa << endl;
					int temp = (int)(maxa*10);
					maxa = temp/10.0;
					gridd[i][j] = grida[i][j] + gammaone*maxa;
					gridc[i][j] = dir;
				}//end if nested in nested for loop
				else
					gridd[i][j] = -1;
				if(gridd[i][j]>=0)
					cout << gridd[i][j] << " ";
				else
					cout << "[] ";
			
			}//end inner for loop
			cout << endl;
		}//end middle for loop

		cout << endl;
		cout << "Iteration #" << numIt << " direction graph:" << endl << endl;
		for(int g=0; g<6; g++){
			for(int h=0; h<6; h++)
				cout << gridc[g][h] << " ";
			cout << endl;
		}
		cout << endl << endl;
		numIt++;
//		gridb = gridd;
		for(int u=0; u<6; u++)
			for(int v=0; v<6; v++)
				gridb[u][v] = gridd[u][v];
	}//end outermost for loop
}//end of main function
