#include"./pat.h"

using namespace std;

void pat_1001(){

    int a,b;
    cin >> a >> b;
    string res = to_string(a+b);
    int k = 0,len = res.size();
    for(int i=0;i<len;i++){
       cout << res[i];
       if(res[i]=='-') continue;
       if((i+1)%3 == len%3 && i != len-1) cout << ",";
    }
}

void pat_1002(){
    float nums[1001] = {0.0};
    // int exists[1001] = {0};
    int sum = 0,i,j,k,nk;
    float ank;
    for(j=0;j<2;j++){
        cin >> k;
        for(i=0;i<k;i++){
            cin >> nk >> ank;
            // if(exists[nk] == 0){
            //     sum++;
            //     exists[nk] = 1;
            // }
            nums[nk] += ank; 
        }
    }
    for(i=0;i<=1000;i++) {
        if(nums[i]!=0.0) sum++;
    }
    cout << sum;
    for(i=1000;i>=0;i--){
        if(nums[i]) printf(" %d %.1f",i,nums[i]);
    }
    
}



void loop_print(){

    int n,m,c1,c2,x,y,weight,i,j;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    // 邻接矩阵作为存储容器
    int roads[n][n],visited[n],cur;
    for(i=0;i<n;i++){
        visited[i] = 0;
        for(j=0;j<n;j++) roads[i][j] = -1;
    }
    // 有向有权图
    for(i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        cin >> weight;
        roads[x][y] = weight;
        // roads[y][x] = weight;
    }
    // 广度优先遍历
    queue<int> q;
    q.push(c1);
    visited[c1] = 1;
    while(!q.empty()){
       cur = q.front();
       printf(" %d",cur);
       q.pop();
       for(i=0;i<n;i++){
           if(i!=cur && roads[cur][i]!=-1 && !visited[i]){
               q.push(i);
               visited[i] = 1;
           }
       } 
    }

    for(i=0;i<n;i++) visited[i] = 0;
    
    cout << endl;
    // 深度优先遍历
    stack<int> s;
    s.push(c1);
    visited[c1] = 1;
    printf(" %d",c1);
    bool has = false ;
    while(!s.empty()){
        cur = s.top();
        has = false;
        for(i=0;i<n;i++){
            if(i!=cur && roads[cur][i]!=-1 && !visited[i]){
               s.push(i);
               printf(" %d",i);
               has = true;
               visited[i] = 1;
               break;
            }
        }
        if(!has) s.pop();
    }

}

// 最短路径问题
void min_path(){

    int n,m,c1,c2,x,y,weight,recure,i,j,min,min_id;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    // 邻接矩阵作为存储容器
    int roads[n][n],visited[n],recures[n],weights[n],cur,recure_values[n],nums[n];
    for(i=0;i<n;i++){
        cin >> recures[i];
        visited[i] = 0;
        weights[i] = 0;
        nums[i] = 0;
        recure_values[i] = 0;
        for(j=0;j<n;j++) roads[i][j] = -1;
    }
    // 有向有权图
    for(i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        cin >> weight;
        roads[x][y] = weight;
        roads[y][x] = weight;
    }

    
    // dijkstra 附体，单源最短路径问题
    // 本题是它的一个变形而已

    cur = c1;
    visited[cur] = 1;
    nums[cur] = 1;
    recure_values[cur] = recures[cur];
    int left = n;
    while(left > 0){
        min = 0;
        for(i=0;i<n;i++){
            // update new value 
            if(roads[cur][i]!=-1 && !visited[i]){
                weight = weights[cur] + roads[cur][i];
                // handle the recure values
                recure = recure_values[cur] + recures[i];
                if(weight < weights[i]|| weights[i] == 0){
                    weights[i] = weight;
                    recure_values[i] = recure; 
                    nums[i] = nums[cur];
                }
                else if(weights[i] == weight){
                    // 相等怎么处理，一会再看，本题关键在这里，比较一下 对应的recures 值即可
                    // 更新 数量
                    nums[i] =  nums[i] + nums[cur];
                    if(recure > recure_values[i]) recure_values[i] = recure;
                }               
            }
            
            // find the min element of this loop
            if((min == 0 || (min > weights[i] && weights[i] > 0))&&!visited[i]){
                min = weights[i];
                min_id = i;
            }
        }
        
        cur = min_id;
        visited[cur] = 1;
        left --;
        // // debug
        // for(j=0;j<n;j++) cout << weights[j] << " ";
        // cout << endl;
    }

    // cout << endl;
    // for(i=0;i<n;i++){
    //     if(i!=c1) printf("%d %d %d\n",c1,i,weights[i]);
    // }

    cout << nums[c2] << " " <<  recure_values[c2] ;

}

void pat_1003(){
    min_path();
}


// the level loop of a tree
void pat_1004(){
    // 树的层序遍历
    int n,m,i,j;
    cin >> n >> m;
    vector<int> nodes[100];
    int id,k,t;
    for(i=0;i<m;i++){
        cin >> id >> k;
        for(j=0;j<k;j++){
            cin >> t;
            nodes[id].push_back(t);
        }
    }

    int root = 1,level = 1,spare = 0,next_level;
    queue<int> q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        spare = next_level = 0;
        for(i=0;i<level;i++){
            t = q.front();
            q.pop();
            if(nodes[t].size()==0) spare ++;
            else {
                for(j=0;j<nodes[t].size();j++){
                    q.push(nodes[t][j]);
                    next_level++;
                }
            }
        }
        level = next_level;
        if(flag) cout << " ";
        else flag = true;
        cout << spare;
    }

}

int main(){
    pat_1004();
    return 0;
}