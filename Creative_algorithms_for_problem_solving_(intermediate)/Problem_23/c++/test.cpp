#include <iostream>

const int H = 3;
const int W = 4;
int cnt = 0;

void solve(int h, int w)
{
	if(h > H || w > W+1){
		return;
	}

	if(h == H && w == W+1){
		cnt++;
		return;
	}
	
	solve(h+1, w);

	// y = (H/W)(x - 1) : x의 '0'도 넣어어서 계산하기 위해서 그래프를 x축으로 1 만큼 평행이동
	// 여기에 (w - 1) => (w+1 - 1) => w, 다음 w+1로 이동 가능여부 우선 check해야 하니까
	//if((double)H/W <= (double)h/(w-1)){
	if((double)H/W <= (double)h/(w)){
		solve(h, w+1);
	}
}

int main()
{
	solve(0, 1);
	std::cout << cnt << std::endl;
    return 0;
}