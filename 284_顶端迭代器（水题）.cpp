/**

    �������һ��������������֧�� hasNext �� next �����⣬��֧�� peek ������

    ʵ�� PeekingIterator �ࣺ

    PeekingIterator(int[] nums) ʹ��ָ���������� nums ��ʼ����������
    int next() ���������е���һ��Ԫ�أ�����ָ���ƶ����¸�Ԫ�ش���
    bool hasNext() ��������д�����һ��Ԫ�أ����� true �����򣬷��� false ��
    int peek() ���������е���һ��Ԫ�أ��� �� �ƶ�ָ�롣

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/peeking-iterator
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

**/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int theNext;
    bool flag;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        flag = Iterator::hasNext();
        if (flag)
            theNext = Iterator::next();
	}
	
	int peek() {
        return theNext;
	}
	
	int next() {
        int ans = theNext;
        flag = Iterator::hasNext();
        if (flag)
            theNext = Iterator::next();
	    return ans;
	}
	
	bool hasNext() const {
	    return flag;
	}
};