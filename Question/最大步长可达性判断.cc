//2 1 0 1 2 3 不能到达
//2 1 1 1 2 3 可以到达

bool CanGet(vector<int>& array){
	int n = array.size();
	vector<int> dp(n, 0);
	dp[0] = 1;


	for (int i = 0; i < n; i++){
		if (dp[i] == 0){
			continue;
		}

		for (int j = 1; j <= array[i]; j++){
			int temp = i + j;
			if (temp < n){
				dp[temp] = 1;
			}
		}
	}

	if (dp[n - 1]){
		return true;
	}
	else{
		return false;
	}
}
