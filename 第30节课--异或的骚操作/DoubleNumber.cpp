// 数组中有2种数出现了奇数次，其他的数都出现了偶数次
// 返回这2种出现了奇数次的数
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 遍历数组，异或所有数，最终eor1 = a ^ b（a、b是出现奇数次的两个数）
        int eor1 = 0;
        for (int num : nums) {
            eor1 ^= num;
        }
        // Brian Kernighan算法：提取二进制中最右侧的1
        // 先将有符号int转为无符号unsigned int，避免溢出
        unsigned int ueor = static_cast<unsigned int>(eor1);
        unsigned int rightOne = ueor & -ueor;
        int eor2;
        // 按最右侧的1分组异或，分离出其中一个数
        for (int num : nums) {
            if ((num & rightOne) == 0) {
                eor2 ^= num;
            }
        }
        return{ eor2,eor2 ^ eor1 };
    }
};
/*eor1 = a ^ b,某一位上值为1，一定是a,b在这个位置上不同，可以把a,b分在两个阵营，只要异或和一个阵营，就可以；
rightOne只记下当前位置的1，例如0000 0100，只记录这个状态*/