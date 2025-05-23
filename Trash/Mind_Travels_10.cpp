#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
auto graph = std::vector<std::unordered_map<char,int>>(1);
auto reversedd = std::vector<int>(1,0);
auto max_value = std::vector<int>(1,0);
auto ans_index = std::vector<int>(1,0);
typedef long long ll;
typedef long double ld;

void Ins    (int index,std::string& str,int value,int id,int depth){
    if(max_value[index]<value){
        max_value[index]=value;
        ans_index[index] = id;
    }
    if (depth==str.size()){
        return;
    }
    if (graph[index].find(str[depth])==graph[index].end()) {
        graph[index][str[depth]] = graph.size();
        graph.push_back(std::unordered_map<char, int>());
        reversedd.push_back(index);
        max_value.push_back(0);
        ans_index.push_back(0);
    }
    Ins(graph[index][str[depth]],str,value,id,depth+1);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    ll n,q;
    std::cin>>n>>q;
    std::string s,c;
    ll value;
    for (int i = 0; i < n; ++i) {
        std::cin>>s>>value;
        Ins(0,s,value,i+1,0);
    }
    ll curr_node = 0;
    ll false_append = 0;
    for (int i = 0; i < q; ++i) {
        std::cin>>s;
        if (s[0]=='-'){
            if(false_append!=0){
                false_append--;
            }else{
                curr_node=reversedd[curr_node];
            }
        }else{
            std::cin>>c;
            if (false_append!=0){
                false_append++;
            }else{
                if(graph[curr_node].find(c[0])==graph[curr_node].end()){
                    false_append++;
                }else{
                    curr_node = graph[curr_node][c[0]];
                }
            }
        }
        if(false_append==0){
            std::cout<<ans_index[curr_node]<<std::endl;
        }else{
            std::cout<<-1<<std::endl;
        }
    }
}
