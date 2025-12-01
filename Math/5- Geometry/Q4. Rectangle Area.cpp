class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);

        int overlapHeight = max(0, min(bx2, ax2) - max(bx1, ax1));
        int overlapWidth = max(0, min(by2, ay2) - max(by1, ay1));

        return area1 + area2 - (overlapWidth * overlapHeight);
    }
};