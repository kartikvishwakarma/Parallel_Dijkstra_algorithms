#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <fstream>

using namespace std;

const int size = int(1e5);

int main(){
	srand(time(0));
	
	ofstream file;
	file.open("data.txt", ios::app);
	for(int i=0; i<size-1; i++){
		for(int j=0; j< 100; j++)
		file << to_string(i) << ' ' << to_string(j+i+1) << ' ' << to_string(rand()%size) << '\n';

	}
}
