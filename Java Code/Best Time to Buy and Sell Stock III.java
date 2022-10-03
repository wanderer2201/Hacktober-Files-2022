class Solution {
	int maxProfit(int[] prices) {
	    int n = prices.length;
		int[] leftMaxProfit = new int[n], rightMaxProfit = new int[n];
		int minPrice = prices[0];
		for (int i = 1; i < n; i++) {
			minPrice = Math.min(minPrice, prices[i]);
			leftMaxProfit[i] = Math.max(leftMaxProfit[i - 1], prices[i] - minPrice);
		}
		int maxPrice = prices[n - 1];
		for (int i = n - 2; i >= 0 ; i--) {
			maxPrice = Math.max(maxPrice, prices[i]);
			rightMaxProfit[i] = Math.max(rightMaxProfit[i + 1], maxPrice - prices[i]);
		}
		int profit = 0;
		for (int i = 0; i < n; i++) {
			profit = Math.max(profit, rightMaxProfit[i] + leftMaxProfit[i]);
		}
		return profit;
	}
}
