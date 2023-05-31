class UndergroundSystem {
public:
    map<pair<string,string>,vector<int>> avg;
    map<int,pair<string,int>> travel;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        travel[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p=travel[id];
        int time=t-p.second;
        avg[{p.first,stationName}].push_back(time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans=0;
        vector<int> v=avg[{startStation,endStation}];
        for(auto &it:v) ans+=it;
        return ans/v.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */