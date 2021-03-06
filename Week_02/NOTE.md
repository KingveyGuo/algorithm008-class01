# 学习笔记 #

## 哈希表 ##
又叫散列表，核心是哈希函数，加快查询速度。
哈希函数是映射到有限空间，所以无法避免哈希碰撞，解决方法：后移/拉链存储。
完美哈希？
## 映射 ##
Map  key-value  键值对，键唯一
## 集合 ##
Set  不重复元素的几何

前面两种数据结构底层都可以用哈希表实现

## 树 ##
树是带分叉的单向链表
链表->分叉->树->有环->图
## 二叉树 ##
父节点最多有两个子节点的树
遍历：前序、中序、后序
## 二叉搜索树 ##
有序的二叉树。

左子树的所有结点小于父节点，右子树的所有结点大于父节点。

插入在查询未找到的位置。

查询、插入、删除时间复杂度都是logn。

极端情况会退化成链表。

## 堆 ##
一般用树结构表达。

应用场景：找最大或最小，大/小顶/根堆。

二叉堆(完全二叉树，底层用数组实现，简单常见非最优)

插入操作：直接插到数组尾部，再依次向上调整，大于父节点就交换。

删除操作：用堆尾替换顶部，从堆顶依次向下调整，与较大的子节点交换，大于两个子节点或到叶子层就停止。

(严格)斐波那契堆  性能最优，实现最复杂

图(方向、权重)

邻接矩阵/二维数组、邻接表

常见算法：DFS深度优先（队列）、BFS广度优先（栈）

与树的遍历算法区别：注意判断当前结点是否访问过。

递归实现算法比较简洁，防止递归黑洞可以进行尾递归优化(分析递归树，缓存中间结果)。