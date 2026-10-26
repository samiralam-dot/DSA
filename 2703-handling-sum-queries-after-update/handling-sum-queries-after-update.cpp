class Solution {
public:
    vector<int> seg,lazy;

    void build(int idx,int l,int r,vector<int>&nums){
        if(l==r){
            seg[idx]=nums[l];
            return;
        }

        int mid=(l+r)/2;
        build(2*idx,l,mid,nums);
        build(2*idx+1,mid+1,r,nums);

        seg[idx]=seg[2*idx]+seg[2*idx+1];
    }

    void push(int idx,int l,int r){
        if(!lazy[idx]) return;

        seg[idx]=(r-l+1)-seg[idx];

        if(l!=r){
            lazy[2*idx]^=1;
            lazy[2*idx+1]^=1;
        }

        lazy[idx]=0;
    }

    void update(int idx,int l,int r,int ql,int qr){
        push(idx,l,r);

        if(l>qr || r<ql) return;

        if(l>=ql && r<=qr){
            lazy[idx]^=1;
            push(idx,l,r);
            return;
        }

        int mid=(l+r)/2;
        update(2*idx,l,mid,ql,qr);
        update(2*idx+1,mid+1,r,ql,qr);

        seg[idx]=seg[2*idx]+seg[2*idx+1];
    }

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size();

        seg.resize(4*n);
        lazy.resize(4*n,0);

        build(1,0,n-1,nums1);

        long long sum=0;
        for(auto x:nums2) sum+=x;

        vector<long long>ans;

        for(auto &q:queries){
            if(q[0]==1){
                update(1,0,n-1,q[1],q[2]);
            }
            else if(q[0]==2){
                sum+=1LL*q[1]*seg[1];
            }
            else{
                ans.push_back(sum);
            }
        }

        return ans;
    }
};