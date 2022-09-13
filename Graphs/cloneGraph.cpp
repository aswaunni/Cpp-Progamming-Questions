/*
Clone Graph

Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

Example 1:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        
        vector<Node*> v(101, NULL);
        queue<Node*> q;
        
        Node* n = new Node(node->val);
        v[node->val] = n;
        q.push(node);
        
        while (!q.empty()) {
            Node* f = q.front();
            q.pop();
            
            for (Node* a : f->neighbors) {
                if (v[a->val]) {
                    v[f->val]->neighbors.push_back(v[a->val]);
                } else {
                    Node* x = new Node(a->val);
                    v[f->val]->neighbors.push_back(x);
                    v[a->val] = x;
                    q.push(a);
                }
            }
        }
        
        return n;
    }
};

//OR

unordered_map<Node*, Node*> m;

Node* dfs(Node* node) {
    if (m.count(node))
        return m[node];
    
    Node* t = new Node(node->val);
    m[node] = t;
    
    for (auto& a : node->neighbors)
        t->neighbors.push_back(dfs(a));

    return t;        
}

Node* cloneGraph(Node* node) {
    if (!node)
        return NULL;
    return dfs(node);
}
