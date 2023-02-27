# include <iostream>
# include <vector>
# include <string>
using namespace std;

vector<string> get_split(string str){
    vector<string> result;
    if (str.size() == 1)
        result.push_back(str);
    else{
        string tempstr = "";
        string current, next;
        if (str[0] == '-')
            result.push_back("0");//对于开始的进行特殊处理
        for (int i = 0; i < str.size();++i) {
            current = string(1,str[i]);
            next = i == str.size() - 1 ? string("") : string(1, str[i + 1]);
            if (current[0] == ' ')
                continue;
            else if (isdigit(current[0])){
                tempstr += current;
                if(next == "+" || next == "-" || next == ")"){
                    result.push_back(tempstr);
                    tempstr.clear();
                }
            }
            else if (current == "+" || current == "-" || current == "(" || current == ")"){
                if(current == "(" && next == "-"){
                    result.push_back(current);
                    tempstr += next; //单独处理在( 后的负号
                    i += 1;
                }
                else
                    result.push_back(current);
            }
            
        }
        
    }
    return result;
}
int todigit(string sNumber){
    int flag = 1;
    if (sNumber[0] == '-'){
        flag = -1;
        sNumber = sNumber.substr(1);
    }
    int result = 0;
    for(int i = 0;i < sNumber.length();++i){
        result *= 10;
        result += sNumber[i] - '0';
    }
    return result*flag;
}

class Solution {
public:
    
    int calculate(string s) {

    }
};
int main(){
    string s = "-12+123-(15+(-6-8))";
    // for(auto i :get_split(s)){
    //     cout << i << " &&& ";
    // }
    // cout <<  todigit("125") << "\n"; 
}