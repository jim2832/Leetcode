#include <vector>
#include <queue>

class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        // 優先佇列，用於紀錄每一步使用的磚塊數目，由小到大排序
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        int i;
        // 迭代每一個建築物的高度
        for (i = 0; i < heights.size() - 1; i++) {
            // 計算相鄰兩個建築物的高度差
            int diff = heights[i + 1] - heights[i];

            // 如果相鄰建築物高度差為正，表示需要使用磚塊
            if (diff > 0) {
                pq.push(diff); // 將使用的磚塊數目加入優先佇列
            }

            // 如果優先佇列中的元素數目超過梯子的數目，表示需要用磚塊替代梯子
            // 當優先佇列中的元素數目超過梯子的數目時，代表已經使用了太多的磚塊來建造建築物，而梯子的數量不足以彌補。
            // 當梯子的數目不足以應對建築物的高度差時，就需要使用磚塊來彌補，以確保建造的連貫性。
            if (pq.size() > ladders) {
                bricks -= pq.top(); // 使用磚塊替代梯子，減去最小的磚塊數目
                pq.pop(); // 移除優先佇列中最小的磚塊數目
                // 如果剩餘的磚塊數目小於0，表示無法再繼續建造，跳出迴圈
                if (bricks < 0) {
                    break;
                }
            }
        }

        return i; // 返回最遠的建築物索引
    }
};
