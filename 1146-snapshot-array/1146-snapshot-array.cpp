class SnapshotArray {
public:
    vector<vector<pair<int,int>>> v;
    int cnt;
    SnapshotArray(int length) {
     v.resize(length);
        cnt=0;
        
    }
    
    void set(int index, int val) {
        if(!v[index].empty() && v[index].back().first==cnt)
        {
             v[index].back().second=val;
        }
        else
        {
            v[index].push_back({cnt,val});
        }
    }
    
    int snap() {
     cnt++;
        return cnt-1;
    }
    
    int get(int index, int snap_id) {
       int idx=upper_bound(v[index].begin(),v[index].end(),make_pair(snap_id,INT_MAX))-v[index].begin();
        if(idx==0) return 0;
        return v[index][idx-1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */