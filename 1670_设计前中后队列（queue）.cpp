/**

	�������һ�����У�֧����ǰ���У�������λ�õ� push�� pop������

	�������FrontMiddleBack�ࣺ

	FrontMiddleBack()��ʼ�����С�
	void pushFront(int val) ��val��ӵ����е� ��ǰ�档
	void pushMiddle(int val) ��val��ӵ����е� ���м䡣
	void pushBack(int val)��val��ӵ������ ����档
	int popFront()�� ��ǰ�� ��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1��
	int popMiddle() �� ���м��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1��
	int popBack() �� ����� ��Ԫ�شӶ�����ɾ��������ֵ�����ɾ��֮ǰ����Ϊ�գ���ô���� -1��
	��ע�⵱�������м�λ�õ�ʱ��ѡ��ǰ���λ�ý��в������ȷ�˵��

	�� 6��ӵ�[1, 2, 3, 4, 5]���м�λ�ã��������Ϊ[1, 2, 6, 3, 4, 5]��
	��[1, 2, 3, 4, 5, 6]���м�λ�õ���Ԫ�أ�����3�������Ϊ[1, 2, 4, 5, 6]��

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