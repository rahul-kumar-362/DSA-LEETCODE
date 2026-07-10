/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: //since we have told to to of same HD together
    vector<vector<int>> verticalTraversal(TreeNode* root) {


        //IM GOING WITH THE BFS

        int DEPTH =0;
        map<pair<int,int>,vector<int>>mpp;//for HD,DEPTH->VALUES
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>>q;//for NODE and HD ...
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto front = q.front().first;
                int HD = q.front().second;//mere hisaab se
                q.pop();
                mpp[make_pair(HD,DEPTH)].push_back(front->val);
                if(front->left)q.push(make_pair(front->left,HD-1));
                if(front->right)q.push(make_pair(front->right,HD+1));
            }
            DEPTH++;
        }

        auto it = mpp.begin();
        int  currHD = it->first.first;//SINCE,HD KE BASIS PE MERGE
        ans.push_back(it->second);//1st ELEMENT DALDIYA
        it++;

        for( ;it!=mpp.end();it++){
            if(it->first.first == currHD){//pichla HD  same toh merge
                vector<int> last = ans.back();
                ans.pop_back();
                //AB MERGE

                vector<int> &temp = it->second;//USE REFERENCE TO AVOID COPY...

                sort(temp.begin(),temp.end());//PEHLE SORT FIR MERGE...
                last.insert(last.end(),temp.begin(),temp.end());
                
                ans.push_back(last);
            }
            else {
                vector<int>& temp = it->second;
                sort(temp.begin(),temp.end());//PEHLE SORT FOR SAME HD...
                ans.push_back(it->second);
                currHD=it->first.first;//UPDATE it
                }
        }

        return ans;
    }
};