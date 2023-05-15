#ifndef PREFIX_MATCHER_H
#define PREFIX_MATCHER_H

#include <string>
#include <vector>

class PrefixMatcher {
    public:
        PrefixMatcher();
        int selectRouter(std::string networkAddress);
        void insert(std::string address, int routerNumber);
    
    private:
        struct Node {
            std::vector<Node*> children;
            int routerNum = -1;
        };

        Node* root;

        char getNumberFromPos(int n);
        int dfs(Node* startNode, int routerNum);
};

#endif