# STL 

* vector
    - vector.size()
    - x = vector[i]
    - vector.push_back(x)
    - dest.insert(dest.end(), src.begin(), src.end());
    - dest.insert(position, val);
    - end = vector.end()-1 = vector.back()
    - vector<int> (n,x) 初始化vector为n个x
    - vector<int> {x1,x2,x3}
    - vector.erase(vector.begin()+i)
    - reverse(vector.begin(),vector.end())
    - sort(vector.begin(),vector.end())
    - vector<int> vector_name(arr, arr+length)
* map 
    - map.find(x) == m.end()
    - for (map< >::iterator it=m.begin();it!=m.end();it++) { (*it)}
* stack
    - size = stack.size()
    - top = stack.top()
    - stack.push(x)
    - stack.pop()

* pair 
    - make_pair(a,b)
    - a = pair.first()
    - b = pair.second()
* queue
    - queue<int> q
    - q.push(x)
    - q.empty()
    - x = q.front()
    - q.pop()
* priority_queue
    - priority_queue<int> q   默认最大堆
    - priority_queue<int,vector<int>,greater<int>>  最小堆，vector参数为底层实现
    - priority_queue<int,vector<int>,function<bool(int,int)>> q(myCmp)
* set
    - unordered_set
    - set.count(element) 
    - set.insert(element)
    - unordered_set<string> set(vector.begin(),vector.end())
    - set.erase(element)
* string
    - string.length()
