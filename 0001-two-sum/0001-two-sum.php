class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $hashMap = [];

        for($i = 0; $i < count($nums); $i++){
            if (isset($hashMap[$target - $nums[$i]])) {
                return [$i, $hashMap[$target - $nums[$i]]];
            }
            $hashMap[$nums[$i]] = $i;
        }

        return [];
    }
}