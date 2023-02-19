class Solution {
public:
     map<vector<int>,int>state;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(state[needs]) return state[needs];
        int bestPrice = calculateWOOffers(price, needs);
        for(auto &s:special)
        {
            subtractOffer(needs,s);
            if(noNegative(needs))
            {
                int withOffer=s.back()+shoppingOffers(price,special,needs);
                bestPrice=min(bestPrice,withOffer);
            }
            addOffer(needs,s);
        }
        return state[needs]=bestPrice;
        
    }
    int calculateWOOffers(vector<int> &price,vector<int> &needs)
    {
        int p=0;
        for(int i=0;i<needs.size();i++)
        {
            p+=(needs[i]*price[i]);
        }
        return p;
    }
    void subtractOffer(vector<int> &needs,vector<int> &s)
    {
        for(int i=0;i<needs.size();i++)
        {
            needs[i]-=s[i];
        }
    }
    void addOffer(vector<int> &needs,vector<int> &s)
    {
        for(int i=0;i<needs.size();i++)
        {
            needs[i]+=s[i];
        }
    }
    bool noNegative(vector<int> &needs)
    {
        for(int i=0;i<needs.size();i++)
        {
            if(needs[i]<0)
                return false;
        }
        return true;
    }
};