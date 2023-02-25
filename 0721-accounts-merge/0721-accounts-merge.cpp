class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        
        unordered_map<string, int> mapMailNode;

        //map mails with its node
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }
        
        //make a list of mails in one node
        vector<string> mailList[n];
        
        for(auto it: mapMailNode)
        {
            //mail from map
            string mail = it.first;
            int node = ds.findUPar(it.second); //nodes ultimate parent, to merge it
            mailList[node].push_back(mail); //add mails to the single node
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++)
        {
            if(mailList[i].size() == 0) continue;
            
            // sort all mails
            sort(mailList[i].begin(), mailList[i].end());
            
            //push the Names
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            
            //send all emails in a array to be returned in final array
            for(auto it: mailList[i])
            {
                temp.push_back(it);
            }
            
            //push to final array
            ans.push_back(temp);
        }
        
        return ans;
    }
};