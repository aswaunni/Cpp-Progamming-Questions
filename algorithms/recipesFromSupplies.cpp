/*
// KAHNS ALGORITHM / TOPOLOGICAL SORT

You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

Example 1:
Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]

Example 2:
Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]

Example 3:
Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
*/

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> remIngr;
    
    unordered_set<string> s;
    for(auto x : supplies) s.insert(x); 
    
    int n = recipes.size();
    
    for (int i = 0; i < n; ++i) {
        remIngr[recipes[i]] = 0;
        for (auto& a : ingredients[i]) {
            if (s.find(a) == s.end()) {
                graph[a].push_back(recipes[i]);
                remIngr[recipes[i]]++;
            }
        }
    }
    //KAHN'S ALGORITHM
    queue<string> q;
    for (auto& a : remIngr) {
        if (a.second == 0)
            q.push(a.first);
    }
    
    vector<string> ans;
    while (!q.empty()) {
        string rec = q.front();
        q.pop();
        ans.push_back(rec);
        
        for (auto& a : graph[rec]) {
            remIngr[a]--;
            
            if (remIngr[a] == 0)
                q.push(a);
        }
    }
    return ans;
}
