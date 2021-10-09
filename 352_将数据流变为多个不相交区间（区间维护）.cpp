/**

    给你一个由非负整数 a1, a2, ..., an 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。

    实现 SummaryRanges 类：

    SummaryRanges() 使用一个空数据流初始化对象。
    void addNum(int val) 向数据流中加入整数 val 。
    int[][] getIntervals() 以不相交区间 [starti, endi] 的列表形式返回对数据流中整数的总结。
     

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class SummaryRanges {

private:
    vector<vector<int>> v;

public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (v.size() == 0){
            vector<int> tmp = {val, val};
            v.push_back(tmp);
            return;
        }
        for (int i = 0; i < v.size(); i++){
            if (val >= v[i][0] && val <= v[i][1])
                break;
            if (val == v[i][0]-1){
                v[i][0] = v[i][0]-1;
                break;
            }
            else if (val == v[i][1]+1){
                if (i+1 < v.size() && val == v[i+1][0]-1){
                    v[i][1] = v[i+1][1];
                    v.erase(v.begin()+i1);
                } else {
                    v[i][1] = v[i][1]+1;
                }
                break;
            }
            else if (val < v[i][0]){
                vector<int> tmp = {val, val};
                v.insert(v.begin()+i, tmp);
                break;
            }
            else if (val > v[i][1] && i == v.size()-1){
                vector<int> tmp = {val, val};
                v.insert(v.end(), tmp);
                break;
            }
        }
        return;
    }
    
    vector<vector<int>> getIntervals() {
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */