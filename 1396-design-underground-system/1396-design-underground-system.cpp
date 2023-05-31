#define ll long long
class UndergroundSystem {
public:
    map<pair<string,string>,pair<ll,ll>> avg;
    map<int,pair<string,int>> travel;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        travel[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p=travel[id];
        ll time=t-p.second;
        if(avg.find({p.first,stationName})==avg.end())
        {
            avg[{p.first,stationName}]=make_pair(time,1);
            return;
        }
        auto temp=avg[{p.first,stationName}];
        avg[{p.first,stationName}]=make_pair(temp.first+time,temp.second+1);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans=0;
        auto v=avg[{startStation,endStation}];
        
        return (double)v.first/v.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */