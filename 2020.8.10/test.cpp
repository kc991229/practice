class Solution {
    public:
        int maxProfit(vector<int>& prices)
        {
            if(prices.size()==0)
                return 0;
            int res0=0,res1=0,min=prices[0];
            for(int i=1;i<prices.size();i++)
            {
                if(prices[i]>min)
                {
                    res0=prices[i]-min;
                    res1+=res0;
                    min=prices[i];
                }
                else
                    min=prices[i];                                                    
            }
            return res1;                        
        }
};
