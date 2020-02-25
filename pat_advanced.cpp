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

void pat_1005(){
    string codes[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string n;
    cin >> n;
    unsigned int i = 0, sum = 0;
    for(i=0;i<n.size();i++){
        sum += n[i] - '0';
    }

    string p = to_string(sum);
    for(i = 0;i< p.size();i++){
        if(i!=0) cout << " ";
        cout << codes[p[i]-'0'];
    }
}

void pat_1006(){
    int n;
    cin >> n;
    int h,m,s,i;
    string id, first,last;
    int min = -1,max = -1,time;
    for(i=0;i<n;i++){
        cin >> id;
        scanf("%d:%d:%d",&h,&m,&s);
        time = (h*60+m)*60 + s;
        if(min==-1||min>time) {
            min = time;
            first = id;
        }
        scanf("%d:%d:%d",&h,&m,&s);
        time = (h*60+m)*60 + s;
        if(max==-1||max < time) {
            max = time;
            last = id;
        }
    }

    cout << first << " " << last;
}
void pat_1007(){
    int n,i;
    cin >> n;
    int max = -1,sum = 0,first = 0,last = n-1,sum_first=0,nums[n];
    for(i= 0 ;i<n;i++){
        cin >> nums[i];
        sum = sum + nums[i];
        if(sum < 0){
            sum = 0;
            sum_first = i+1;
        }
        else if(sum > max) {
            last = i;
            max = sum;
            first = sum_first;
        }
    }
    
    printf("%d %d %d",max<0?0:max,nums[first],nums[last]);
    
    
}


void pat_1008(){
    int up = 6,down = 4,still = 5;
    // int maps[100] = {0};
    vector<int> floors;
    floors.push_back(0);
    int n,tmp,i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> tmp;
        floors.push_back(tmp);
    }
    int next = 1,offset,sum = 0;
    while(next<floors.size()){
        offset = floors[next]-floors[next-1];
        if(offset>0)
            sum +=  offset*up + still;
        else 
            sum  += offset*-1*down + still;
        next++;
    }
    cout << sum;
}

void pat_1009(){
    int n = 2,i,j,k,nk;
    float ank,sum[2001] = {0};
    float nums[2][1001] = {0};
    for(i=0;i<n;i++){
        cin >> k;
        for(j=0;j<k;j++){
            cin >> nk >> ank;
            nums[i][nk] = ank;
        }
    }
    int plot;float res;
    for(i=0;i<1001;i++){
        for(j=0;j<1001 && nums[0][i]!=0;j++){
          if(nums[1][j]!=0){
              plot = i+j;
              res = nums[0][i]*nums[1][j];
              sum[plot]+=res;
          }
        }
    }
    int count = 0;
    for(i=0;i<2001;i++){
        if(sum[i]!=0) count ++;
    }
    cout << count;
    for(i=2000;i>=0;i--){
        if(sum[i]!=0) printf(" %d %.1f",i,sum[i]);
    }
}
int real_p(string a,int i){
     if(a[i]>='a' && a[i]<='z') return a[i]-'a'+10;
     else  return a[i] -'0';
}

long long convert(string a,long long radix){
    long long sum = 0;
    int p;
    for(int i=a.size()-1;i>= 0 ;i-- ){
        p = real_p(a,i);
        sum += p* pow(radix,(a.size()-1-i));
    }
    return sum;
}

int find_max(string b){
     int p,max = -1;
     for(int i=b.size()-1;i>=0;i--){
        p = real_p(b,i);
        if(max < p) max = p;
    }
    return max++;
}


void pat_1010(){
    char n1[10],n2[10];
    long long tag,radix;
    scanf("%s %s %lld %lld",n1,n2,&tag,&radix);
    long long sum1 = 0,sum2 = 0;
    string a,b;
    if(tag==1) {a = n1;b = n2;}
    else {a = n2;b = n1;} 
    sum1 = convert(a,radix);
    long long low = find_max(b);
    long long high = max(low,sum1),mid = 0 ;
    while(low <= high){
        mid = ( low + high )/2;
        sum2 = convert(b,mid);
        if(sum2 > sum1 || sum2 <0) high = mid -1;
        else if(sum1 == sum2){
            cout << mid;
            return;
        }else low = mid+1;
    }
    cout << "Impossible"; 
    
}


void pat_1011(){
    int num = 3, i, j,max_id = 0;
    char codes[3] = {'W','T','L'};
    float max ,cur = 0,sum = 1;
    for(i=0;i<num;i++){
        max = 0;
        for(j=0;j<num;j++){
            cin >> cur;
            if(max < cur) {
                max = cur;
                max_id = j;
            }
        }
        sum *= max;
        cout << codes[max_id] << " ";
    }
    printf("%.2f",(sum*0.65-1)*2);

}


void pat_1101(){
    int n,tmp;
    cin >> n;
    int i,nums[n],checks[n];
    for(i=0;i<n;i++){
        cin >> nums[i];
        checks[i] = 0;
    }
    int max = nums[0];
    for(i=0;i<n;i++){
        if(max <= nums[i]){
            checks[i] = 1;
            max = nums[i];
        }
    }
    int min = nums[n-1];
    for(i=n-1;i>=0;i--){
        if(min < nums[i]) checks[i] = 0;
        else min = nums[i];
    }
    int sum = 0;
    for(i =0;i<n;i++){
        if(checks[i]) sum++;
    }
    cout << sum << endl;
    if(sum==0) cout << endl;
    else{
        bool flag = true;
    for(i=0;i<n;i++){
        if(checks[i]){
            if(!flag) cout << " ";
            else flag = false;
            cout << nums[i];
        }
    }
    }
}



int main(){
    pat_1101();
    return 0;
}