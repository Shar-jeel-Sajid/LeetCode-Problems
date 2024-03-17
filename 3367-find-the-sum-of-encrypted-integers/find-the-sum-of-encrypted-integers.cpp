class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int &i:nums) {
            if(!i)
                continue;
            int isum = i%10,places = 1;
            while(i/=10){
                places++;
                if(i%10 > isum)
                    isum = i%10;
            }
            sum += (isum*(pow(10,places)-1)/(9));
        }
        return sum;
    }
};