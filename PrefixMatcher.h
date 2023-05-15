#ifndef PREFIX_MATCHER_H
#define PREFIX_MATCHER_H

#include <string>
#include <vector>
#include <map>

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
        std::map<std::string, int> routers;

        char getNumberFromPos(int n);
        void dfs(Node* startNode, std::string addr, std::vector<std::string> &matches, std::string networkAddress);
};

#endif