#include <iostream>
#include <bitset>

class Solution {
public:
    int binaryGap(int n) {
        std::string binarystring = std::bitset<sizeof(int) * 8>(n).to_string();

        int ans = 0;
        for (int i=0; i < 32; i++){
            // std::cout << binarystring[i] << std::endl;
            if (binarystring[i] == '1')
                for (int j =i+1;j< 32; j++)
                    if (binarystring[j] == '1'){

                        if ((j-i) > ans){
                            ans = j-i;
                        }
                        // std::cout << ans << std::endl;
                        break;
                    }
                
        }
        return ans;
        
    }
};

int main() {
    int myNumber = 5;

    Solution obj;
    // Convert the integer to binary string
    int ans = obj.binaryGap(myNumber);

    // Print the result
    std::cout << "Binary gap of " << myNumber << ": " << ans << std::endl;

    return 0;
}