
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> s;
        for(int i=0;i<k;i++){
            s.insert(i);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> cnt(k,0);

        int n=arrival.size();

        for(int i=0;i<n;i++){

            while(!pq.empty() && pq.top().first<=arrival[i]){
                s.insert(pq.top().second);
                pq.pop();
            }

            if(s.empty()) continue;

            int id=i%k;

            auto it=s.lower_bound(id);

            if(it==s.end()){
                it=s.begin();
            }

            int server=*it;

            s.erase(it);

            cnt[server]++;

            pq.push({arrival[i]+load[i],server});
        }

        int maxi=*max_element(cnt.begin(),cnt.end());

        vector<int> ans;

        for(int i=0;i<k;i++){
            if(cnt[i]==maxi){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
