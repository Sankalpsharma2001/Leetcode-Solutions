class MedianFinder {
public:
    priority_queue<double,vector<double>,greater<double>> pqmin;
    
    priority_queue<double,vector<double>> pqmax;
    
       // max heap || min heap
    MedianFinder() {
        
    }
     void balanceHeaps()
    {
        if(pqmin.size()==pqmax.size()+1 || pqmax.size()==pqmin.size()+1 || pqmin.size()==pqmax.size())
        {
            return;
        }
        else
        {
            if(pqmin.size()>pqmax.size())
            {
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
            else
            {
              pqmin.push(pqmax.top());
                pqmax.pop();   
            }
        } 
    }
    void addNum(int x) {
        if(pqmax.empty() || pqmax.top()>=x)
        pqmax.push(x);
        if(pqmax.top()<x)
        {
            pqmin.push(x);
        }
       balanceHeaps();

    }
    
    double findMedian() {

        if(pqmax.size()==pqmin.size())
     {
         return (pqmax.top()+pqmin.top())/2.0;
     }
     else if(pqmax.size()>pqmin.size())
     return pqmax.top();
     else
     return pqmin.top();
    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */