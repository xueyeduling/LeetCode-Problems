#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[6] = {1, 2, 3, 4, 5, 6};

    auto tmp = (&arr + 1);
    printf("%d\n", tmp);
    printf("%d\n", arr);

    int* tmp2 = (int*)tmp;
    printf("%d\n", *(tmp2));
    printf("%d\n", *(tmp2 + 1));
    printf("%d\n", *(tmp2 - 1));
    printf("%d\n", *(tmp2 - 2));

    int* ptr = (int*)(&arr + 1);

    printf("%d\n", *ptr);
    printf("%d", *(ptr - 1));
}

/*
关于排序算法的以下说法，正确的是：________________

A. 归并排序的平均时间复杂度为O(n log n)，最坏时间复杂度为O(n2)

B. 快速排序的平均时间复杂度为O(n log n)，最坏时间复杂度为O(n2)

C. 堆排序的平均时间复杂度为O(n log n)，最坏时间复杂度为O(n log n)

D. 冒泡排序的平均时间复杂度为O(n2)，最坏时间复杂度为O(n2)
*/

/*
假设我们有一个名为`Orders`的表，它的结构如下：

Orders
------
OrderID (int)
CustomerID (int)
OrderDate (date)
ProductID (int)
Quantity (int)

请编写一个SQL查询，返回每个产品的总销售量（即所有订单中每个产品的数量总和）。
*/

/*
下列关于进程和线程的叙述中，正确的是________________

A．不管系统是否支持线程，进程都是资源分配的基本单位

B．线程是资源分配的基本单位，进程是调度的基本单位

C．系统级线程和用户级线程的切换都需要内核的支持

D．同一进程中的各个线程拥有各自不同的地址空间
*/

/*
请描述C语言程序的内存布局，包括各个部分（如代码段、数据段等）的作用和内容。另外，栈和堆在内存中的位置是怎样的，它们之间有什么区别？
*/

/*
什么情况下tcp连接会进入time_wait状态
*/