#include<iostream>
using namespace std;
const int N = 10;

/*
	Agar aap x,y par khade ho to knight ke 8 moves kya honge?
	x+dx[i],y+dy[i]  where i goes from 0 to 7 index
	in dx and dy array.
*/


int dx[] {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] {2, -2, 2, -2, 1, -1, 1, -1};
int n;
int grid[N][N] {0};
int Total_Boxes = 0;

//Take Input Seperately
void Input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				Total_Boxes++;
			}
		}
	}
}

/*
	F(0,0): It returns me the maximum boxes the
	knight can travel from 0,0 without visiting a
	box again in the current path.


	Now I don't want to return anything.
	Har path me can kitna travel kar paaya usko
	calculate karo and ek global maximum
	rakho jo ye batata hain ki across all the
	paths knight maximum kitne boxes ko travel
	kar paaya.

	F(0,0,count): Count hume ye batata hain
	ki current raste me aapne kine boxes
	knight se visit kar liye hain.

	global maximum ke liye :
	ans;


*/


int ans = -1;//This variable stores the maximum boxes the knight was able to travel across all the paths.

void F(int x, int y, int count) {

	ans = max(ans, count);


	/*
		Currently I am x,y co-ordinates and I am
		trying to solve for the state: F(x,y,count).

		There are 8 new paths from this x,y co-ordinate:
		Main har path ke liye recursion call karna chahta hu:
		ye ya toh main manually karlu ya for loop se.
	*/

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		//Check if this current nx,ny co-ordinate is valid or not.

		/*
			How to check this:
			1. Matrix ke ander hona chahiye.
			2. Current path me visited nahi hona chahiye.

		*/

		if (nx >= 0 and nx<N and ny >= 0 and ny < N and grid[nx][ny] == 1) {

			//Now I am going to this new box, hence this box beccomes part
			// of the current path so make this box unavailable for the
			//future iteration in the current path only.
			grid[nx][ny] = 0;
			F(nx, ny, count + 1);


			//If I am standing at this line that means:
			//Recursion has already calculated the answer for
			//nx,ny co-ordinates that means Now this box
			//should be available for future and then we
			//reverse the work done.

			grid[nx][ny] = 1;//backtracking

		}


	}




}



int main() {
	cin >> n;
	Input();

	grid[0][0] = 0;//Why make this box zero initially ?
	//Because this box is common in all the paths and I don't
	//want to revisit it again.

	/*
		Agar grid[x][y]=1 hain toh aap x,y par jaasakte ho
		varna agar 0 hain to aap nahi jaasakte.

		Insead of maintaining a new visisted array i am doing
		the visisted vaala task in the input array itself.
	*/

	F(0, 0, 1);

	cout << Total_Boxes - ans << endl;

}

















