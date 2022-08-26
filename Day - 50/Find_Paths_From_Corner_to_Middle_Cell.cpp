// C++ program for the above approach
#include<bits/stdc++.h>
using namespace std;

void printPath(vector<vector<int>>&maze, int i, int j, string ans){


	// If we reach the center cell
	if (i == maze.size()/2 && j==maze.size()/2){

		// Make the final answer, Print the
		// final answer and Return
		ans += "(";
		ans += to_string(i);
		ans += ", ";
		ans += to_string(j);
		ans += ") -> MID";
		cout<<ans<<endl;
		return;
	}
		
	// If the element at the current position
	// in maze is 0, simply Return as it has
	// been visited before.
	if (maze[i][j]==0){
		return;
	}
	
	// If element is non-zero, then note
	// the element in variable 'k'
	int k = maze[i][j];
	
	// Mark the cell visited by making the
	// element 0. Don't worry, the element
	// is safe in 'k'
	maze[i][j]=0;
	
	// Make recursive calls in all 4
	// directions pro-actively i.e. if the next
	// cell lies in maze or not. Right call
	ans += "(";
	ans += to_string(i);
	ans += ", ";
	ans += to_string(j);
	ans += ") -> ";

	if (j+k<maze.size()){
		printPath(maze, i, j+k, ans);
	}

	// down call
	if (i+k<maze.size()){
		printPath(maze, i+k, j,ans);
	}

	// left call
	if (j-k>0){
		printPath(maze, i, j-k, ans);
	}

	// up call
	if (i-k>0){
		printPath(maze, i-k, j, ans);
	}
	
	// Unmark the visited cell by substituting
	// its original value from 'k'
	maze[i][j] = k;

}

int main () {

	// Creating the maze
	vector<vector<int>>maze = {
		{ 3, 5, 4, 4, 7, 3, 4, 6, 3 },
		{ 6, 7, 5, 6, 6, 2, 6, 6, 2 },
		{ 3, 3, 4, 3, 2, 5, 4, 7, 2 },
		{ 6, 5, 5, 1, 2, 3, 6, 5, 6 },
		{ 3, 3, 4, 3, 0, 1, 4, 3, 4 },
		{ 3, 5, 4, 3, 2, 2, 3, 3, 5 },
		{ 3, 5, 4, 3, 2, 6, 4, 4, 3 },
		{ 3, 5, 1, 3, 7, 5, 3, 6, 4 },
		{ 6, 2, 4, 3, 4, 5, 4, 5, 1 }
	};
	
	// Calling the printPath function
	printPath(maze,0,0,"");
}

// This code is contributed by shinjanpatra
