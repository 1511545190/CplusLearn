//
// Created by 刘日亮 on 2023/1/24.
//

// Standard template Library
// 标准模板库

// 容器；通用数据结构   迭代器 ：类指针    算法：函数
// int array[100]        int * p    sort(array,array+70)

//顺序容器,未排序
/*  vector 动态数组，连续存放，尾端增删高性能
 *  deque 双向队列，连续存放，两端增删高性能
 *  list  双向链表，非连续存放
 * */
#include <vector>
#include <deque>
#include <list>


//关联容器，元素排序，以二叉树形式实现，O(long(N))
//查找时性能很好 front back push_back pop_back erase
/*  set
 *  multiset
 *
 *  map,只能放对象，成员变量为first,second
 *  multimap
 * */
#include <set>
#include <map>

//容器适配器
/*  stack 栈
 *  queue 队列
 *  priority_queue 优先级队列
 * */
#include <queue>
#include <stack>


//begin end rbegin rend erase clear