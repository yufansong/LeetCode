# LeetCode
This project will record my code during learning LeetCode.

# 数组

* 排序
    - 选择排序，插入排序，归并排序，快速排序 
* 查找
    - 二分查找
    - 循环不变量，变量的含义
    - 283,27,26,80
    - 如何定义删除，从数组中删除，还是放在数组末尾
    - 剩余元素的排列是否需要保证原有的相对顺序
    - 是否有空间复杂度的要求O(1)
* 数据结构
    - 栈，队列，堆
* 双索引(三路快排)
    - 75,215
* 指针对撞
    - 167,125,344,345,11
    - 如果有解?如果多个解?
* 滑动窗口
    - 209,3,438,76
    - 什么叫子数组
    - 字符集?字母+数字?ASCII?大小写敏感？
    - 字符集范围
    - 如果没有解怎么办
    - 如果有多个解，题目是否保证只有一个解,返回解的顺序

# 查找

* 查找有无
    - 元素是否存在，set
* 查找对应关系
    - 出现了几次，map
* 操作
    - insert/find/erase/change(map)/make_pair
    - 349,350,242,202,290,205,451
* 数据的顺序性
    - max,min/netx,before/floor,ceil/rank/select
    - 哈希表缺失了这些优势
* 不同实现方式
    - map和set底层实现是平衡二叉树
    - unordered_map和unordered_set的底层实现为哈希表
* 索引
    - 从0开始，还是从1开始
    - 1,15,18,16
    - 454,447,149
    - 点坐标范围，点坐标表实(整数/浮点数/浮点误差)
    - 219,220
    - 如果出现了int溢出的，就用long long，一般面试题很少会考整型溢出

# 链表

* 206, 92
* 83, 86, 328, 2, 445
* 虚拟头节点
    - 203, 82, 21
    - 在链表题里面如果没有申明，只能对节点进行操作，不能修改节点的值
    - 24,25,147,148
* 删除节点
    - 237
* 双指针
    - n从0还是1计算，n不合法，大于链表长度怎么处理
    - 19, 61, 143, 243

# 栈

* 20, 150, 71
* 144, 94 145, 341
* 种类
    - 运算的种类（+ - * /）
    - 字符串表达的数字种类（整数） 
* Unix 路径
    - 路径是否合法
    - 不能回退的情况
    - 多余的/
* 栈和递归
* 注意经常判断栈是否为空

# 队列

* 队列的基本与应用-广度优先遍历
    - 树，层序遍历
    - 图，无权图的最短路径
* 树
    - 102, 107,111,404
* 图
    - 279,127,126
* 优先队列
    - 底层实现用堆
    - 对于堆的底层实现，最好可以白板编程
    - priority_queue
    - 347,23

# 二叉树和递归

    - 226,100,101,222,110
    - 注意终止条件 112, 257,113,129,437
    - 二分搜索树 
        * insert find delete 
        * 最大值最小值 minimum maximum
        * 前驱 后继 successor predecessor
        * 上届 下届 floor ceil
        * 某个元素的排名 rank
        * 寻找第k大小元素 select
        * 235,98,450,108,230,236

    

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
* map 
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
    - unordered_set<string> set(vector.begin(),vector.end())
    - set.erase(element)
* string
    - string.length()
