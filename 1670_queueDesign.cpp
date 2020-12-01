/**

	请你设计一个队列，支持在前，中，后三个位置的 push和 pop操作。

	请你完成FrontMiddleBack类：

	FrontMiddleBack()初始化队列。
	void pushFront(int val) 将val添加到队列的 最前面。
	void pushMiddle(int val) 将val添加到队列的 正中间。
	void pushBack(int val)将val添加到队里的 最后面。
	int popFront()将 最前面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1。
	int popMiddle() 将 正中间的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1。
	int popBack() 将 最后面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1。
	请注意当有两个中间位置的时候，选择靠前面的位置进行操作。比方说：

	将 6添加到[1, 2, 3, 4, 5]的中间位置，结果数组为[1, 2, 6, 3, 4, 5]。
	从[1, 2, 3, 4, 5, 6]的中间位置弹出元素，返回3，数组变为[1, 2, 4, 5, 6]。

**/




class FrontMiddleBackQueue {
public:
    int arr[1005];
    int pos = 0;
    FrontMiddleBackQueue() {
        memset(arr, 0, sizeof arr);
    }
    
    void pushFront(int val) {
        int cnt = pos;
        while (cnt != 0)
        {
            arr[cnt] = arr[cnt-1];
            cnt--;
        }
        arr[0] = val;
        pos++;
    }
    
    void pushMiddle(int val) {
        int cnt = pos / 2;
        for (int i = pos; i > cnt; i--)
            arr[i] = arr[i-1];
        arr[cnt] = val;
        pos++;
    }
    
    void pushBack(int val) {
        arr[pos++] = val;
    }
    
    int popFront() {
        if (pos == 0)
            return -1;
        int ans = arr[0];
        for (int i = 0; i < pos-1; i++)
            arr[i] = arr[i+1];
        pos--;
        return ans;
    }
    
    int popMiddle() {
        if (pos == 0)
            return -1;
        int cnt = (pos-1) / 2;
        int ans = arr[cnt];
        for (int i = cnt; i < pos-1; i++)
            arr[i] = arr[i+1];
        pos--;
        return ans;
    }
    
    int popBack() {
        if (pos == 0)
            return -1;
        pos--;
        return arr[pos];
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */