#include <iostream>
#include <cmath>

typedef struct
{
	int x;
	int y;
} xy_t;

xy_t xy[10] = {
	{10, 1000},
	{20, 1000},
	{30, 1000},
	{40, 1000},
	{5000, 5000},
	{1000, 60},
	{1000, 70},
	{1000, 80},
	{1000, 90},
	{7000, 7000}
};

int path[10];
const int cnt = 1;
long gdistance = 987654321;

double distance(xy_t a, xy_t b){
	//return std::ceil(std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2)));
	return std::ceil(std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2)));
}

void solve(int idx, int c){
	if(c > cnt){
		return;
	}

	if(idx == 10){

		int prev = -1;
		int i = 0;
		double dist = 0;
		for(i = 0; i < 10; i++){
			double internalDist = 0;
			if(path[i] == 1){
				if(prev == -1){
					internalDist = distance({0, 0}, xy[i]);
					prev = i;
				}
				else{
					internalDist = distance(xy[prev], xy[i]);
					prev = i;
				}
			}

			if(internalDist > dist){
				dist = internalDist;
			}
		}

		double dist2 = 0;
		if(prev == -1){
			dist2 = distance({0, 0}, {10000, 10000});
		}
		else{
			dist2 = distance(xy[prev], {10000, 10000});
		}
		//std::cout << "dist2 : " << dist2 << std::endl;
		if(dist2 > dist){
			dist = dist2;
		}

		if(gdistance > dist){
			gdistance = dist;
		}

		return;
	}

	path[idx] = 1;
	solve(idx+1, c+1);
	path[idx] = 0;
	solve(idx+1, c);
}

int main(){
	solve(0, 0);
    if((int)(gdistance/10) < (double)gdistance/10){
        gdistance = (int)(gdistance/10) + 1;
    }
	std::cout << gdistance << std::endl;

	return 0;
}