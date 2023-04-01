class RandomizedSet {
public:
//   O(1)
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.count(val))return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val))return false;
        int last_ele = v.back();
        mp[last_ele] = mp[val];
        v[mp[val]] = last_ele;
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};
//naive will be only vector but remove will be in O(n) then
