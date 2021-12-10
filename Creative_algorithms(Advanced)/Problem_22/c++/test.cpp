#include <iostream>

int N = 8;
int m = 1000;
int p[500] = {0, 3, 6, 8, 12, 13, 14, 15};
int d[500] = {7, 4, 8, 6, 2, 2, 2, 7}; 
int g[500] = {1, 1, 1, 1, 0, 1, 1, 1};

bool ca(int a, int k){
	return p[k] <= p[a] + d[a];
}

bool cb(int b, int k){
	return (p[k] <= p[b] + d[b]) && g[k];
}

int f(int a, int b, int k){
	int c = 0;
	if(k == N-1){
		if(ca(a, k) && cb(b, k)) c = 1;
		else c = 0;
	}
	else{
		if(ca(a, k)) c+=f(k, b, k+1)%m;
		if(cb(b, k)) c+=f(a, k, k+1)%m;
		c+=f(a, b, k+1)%m;
	}

	return c;
}


int main(){
	std::cout << f(0, 0, 1) << std::endl;
	return 0;
}