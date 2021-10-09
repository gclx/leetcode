/**

    请你设计一个迭代器，除了支持 hasNext 和 next 操作外，还支持 peek 操作。

    实现 PeekingIterator 类：

    PeekingIterator(int[] nums) 使用指定整数数组 nums 初始化迭代器。
    int next() 返回数组中的下一个元素，并将指针移动到下个元素处。
    bool hasNext() 如果数组中存在下一个元素，返回 true ；否则，返回 false 。
    int peek() 返回数组中的下一个元素，但 不 移动指针。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/peeking-iterator
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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