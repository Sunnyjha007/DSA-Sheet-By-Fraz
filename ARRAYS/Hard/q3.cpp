class RandomizedCollection {
public:
    unordered_map<int,vector<int>> map;
    vector<pair<int,int>> nums;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if(map.find(val)==map.end()){
            nums.push_back(make_pair(val,map[val].size()));
            map[val].push_back(nums.size()-1);
            return true;
        }else{
            nums.push_back(make_pair(val,map[val].size()));
            map[val].push_back(nums.size()-1);
            return false;
        }
    }
    bool remove(int val) {
        if(map.find(val) == map.end())return false;
            pair<int,int> last = nums.back();
            map[last.first][last.second] = map[val].back();
            nums[map[val].back()] = last;
            map[val].pop_back();
            if(map[val].empty())
                map.erase(val);
            nums.pop_back();
            return true;
         
    }
    int getRandom() {
        return nums[rand()%nums.size()].first;      
    }
};
