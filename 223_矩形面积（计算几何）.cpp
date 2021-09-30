/**

    给你 二维 平面上两个 由直线构成的 矩形，请你计算并返回两个矩形覆盖的总面积。

    每个矩形由其 左下 顶点和 右上 顶点坐标表示：

    第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
    第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/rectangle-area
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

**/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        if (bx1 < ax1){
            swap(ax1, bx1);
            swap(ax2, bx2);
            swap(ay1, by1);
            swap(ay2, by2);
        }
        int area = abs(ax1-ax2)*abs(ay1-ay2) + abs(bx1-bx2)*abs(by1-by2);
        if (bx1<ax2){
            if (by1<ay2 && by2>ay1)
                area -= (min(by2, ay2)-max(ay1, by1)) * (min(ax2,bx2)-bx1);
        }
        return area;
    }
};