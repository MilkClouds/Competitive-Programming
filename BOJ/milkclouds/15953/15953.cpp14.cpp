#include<iostream>

using namespace std;

const int UNIT = 10000;
const int FIRSTREWARD[6] = { 500,300,200,50,30,10 };
const int SECONDREWARD[5] = { 512, 256, 128,64,32 };

int firstCompetitionReward(int rank) {
	if (rank == 0) return 0;
	int sum = 0;
	int cnt = 1;
	for (int i = 0; i < 6; i++) {
		sum += cnt;
		if (rank <= sum)
			return FIRSTREWARD[i]* UNIT;
		cnt++;
	}
	return 0;
}

int secondCompetitionReward(int rank) {
	if (rank == 0) return 0;
	int sum = 0;
	int cnt = 1;
	for (int i = 0; i < 6; i++) {
		sum += cnt;
		if (rank <= sum)
			return SECONDREWARD[i]* UNIT;
		cnt*=2;
	}
	return 0;
}

int getRewardSum(int a, int b) {
	return firstCompetitionReward(a) + secondCompetitionReward(b);
}
int main() {
	int T, a, b;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> a >> b;
		cout << getRewardSum(a, b) << endl;
	}
	return 0;
}