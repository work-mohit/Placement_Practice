// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int>& prices) {
    int currentBuy = prices[0];
    
    int maxSell = 0;
    for (int i = 0; i < prices.size(); i++){
        currentBuy = min(currentBuy , prices[i]);             
        maxSell = max(maxSell,prices[i]-currentBuy);
        
    }
    return maxSell;
}
