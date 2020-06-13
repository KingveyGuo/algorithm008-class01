# 学习笔记 #

## 位运算 ##

计算机里数字表示方式和存储格式都是二进制

位运算符

左移 << ；右移 >> ；位或 |；位与 &；取反 ~；异或 ^

c = a ^ b  =>  a ^ c = b , b ^ c = a

a ^ b ^ c = a ^ (b ^ c) = (a ^ b) ^ c

将x最右边n位设为0： x & (~0 << n)

获取x第n位的值： (x >> n) & 1

获取x第n位的幂值： x & (1 << n)

仅将第n位置为1： x | (1 << n)

仅将第n位置为0： x & (~(1 << n))

将x最高为至第n位置为0： x & ((1 << n) - 1)

判断奇偶性： x & 1 == 1 ? 奇数 : 偶数

除以2： x >> 1

最低位的1置为0： x & (x - 1)

得到最低位的1： x & -x

x & ~x = 0

## 布隆过滤器 Bloom Filter ##

一个很长的二进制向量和一系列随机映射函数。

可以用于检验一个元素是否在一个集合中。

优点：内存小，查询快

缺点：有一定误识别率，删除困难

不存在是确定的，存在还需进一步确认

应用：作为粗筛，快速排除不存在的

## LRU Cache ##

Cache缓存

要点：大小、替换策略

HashTable + Double LinkedList

时间复杂度：O(1) 查询， O(1) 修改、更新

## 排序 ##

比较类：通过比较决定元素次序，时间复杂度>O(nlogn)

冒泡、快速、插入、希尔、选择、堆、归并

非比较类：不进行元素比较，突破比较排序的时间下界，达到线性时间复杂度

桶、计数、基数

简单-O(n^2)：选择、插入、冒泡

高级排序-O(nlogn)：

快速 确定标杆->按大小分组->递归(组内排序)

归并 不排序分组->组内排序->有序组合并

堆排序：先遍历插入堆，再不断取堆顶元素

特殊排序：

计数排序-O(n + k)

桶排序：计数排序升级版，一个数->范围

基数排序：从低位到高位，逐一排序

    void sortBubble(vector<int>& arr, int s, int e)
    {
        while (e > s)
        {
            bool bChange = false;
            for (int j = s; j < e; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    bChange = true;
                }
            }
            if (!bChange) break;
            e--;
        }
    }

    void sortSelect(vector<int>& arr, int s, int e)
    {
        for (int i = s; i < e; i++)
        {
            int iMin = i;
            for (int j = i + 1; j <= e; j++)
                if (arr[iMin] > arr[j]) iMin = j;
            swap(arr[i], arr[iMin]);
        }
    }

    void sortInsert(vector<int>& arr, int s, int e)
    {
        int end = s + 1;
        while (end <= e)
        {
            for (int i = end; i > s; i--)
            {
                if (arr[i - 1] <= arr[i]) break;
                swap(arr[i - 1], arr[i]);
            }
            end++;
        }
    }

    void sortQuick(vector<int>& arr, int s, int e)
    {
        if (s >= e) return;
        if (e - s == 1)
        {
            if (arr[s] > arr[e]) swap(arr[s], arr[e]);
            return;
        }
        int left = s;
        int right = e - 1;
        while (left <= right)
        {
            while (arr[left] < arr[e] && left <= right) left++;
            while (arr[right] >= arr[e] && right >= left) right--;
            if (left < right) swap(arr[left++], arr[right--]);
        }
        swap(arr[left], arr[e]);
        sortQuick(arr, s, left - 1);
        sortQuick(arr, left + 1, e);
    }

    void sortMerge(vector<int>& arr, int s, int e)
    {
        if (s >= e) return;
        int mid = (s + e) >> 1;
        int ss = s;
        int es = mid + 1;
        sortMerge(arr, s, mid);
        sortMerge(arr, es, e);
        vector<int> tmp;
        while (ss <= mid && es <= e) 
            arr[ss] < arr[es] ? tmp.push_back(arr[ss++]) : tmp.push_back(arr[es++]);
        while (ss <= mid) tmp.push_back(arr[ss++]);
        while (es <= e) tmp.push_back(arr[es++]);
        for (int i = 0; i < tmp.size(); i++) arr[s + i] = tmp[i];
    }