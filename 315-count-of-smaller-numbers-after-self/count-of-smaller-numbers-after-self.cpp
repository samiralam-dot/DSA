class Solution {
public:

vector<pair<int,int>>a;
vector<int>ans;

void mergesort(int l,int r){
    if(l>=r)return;
    int m=l+(r-l)/2;
    mergesort(l,m);
    mergesort(m+1,r);
    int i=l,j=m+1;
    int s=0;

    vector<pair<int,int>>temp;

    while(i<=m&&j<=r){
        if(a[i].first>a[j].first){
            s++;
            temp.push_back(a[j]);
            j++;
        }
        else{
            ans[a[i].second]+=s;
            temp.push_back(a[i]);
            i++;
        }

    }

    while(i<=m){
        ans[a[i].second]+=s;
        temp.push_back(a[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(a[j]);
        j++;
    }

    for(int k=0;k<temp.size();k++){
        a[l+k]=temp[k];
    }




}



    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();
        ans.resize(n,0);
        for(int i=0;i<n;i++){
            a.push_back({nums[i],i});
        }
        mergesort(0,n-1);
        return ans;

        
    }
};