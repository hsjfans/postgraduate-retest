#include"./pat.h"

using namespace std;

void pat_1001(){

    long a,b;
    cin >> a >> b;
    string res = to_string(a+b);
    int k = 0;
    for(unsigned int i=0;i<res.size();i++){
       cout << res[i];
       if(res[i]<='9'&&res[i]>='0'){
           k++;
           if(k%3 == 0 && i < res.size()-1) cout << ",";
       }
    }
}
int main(){

    pat_1001();
    return 0;

}