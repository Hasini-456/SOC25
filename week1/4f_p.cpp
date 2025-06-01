class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n = height.size();
            int i = 0;
            int j = n-1;
            int max = 0;
            while(i<j){
                int area = (j-i)*(std::min(height[i], height[j]));
                if(area>max) max = area;
                //cause area depends on smaller height, so we are checking by changing smaller height
                if(height[i]<height[j]){
                    i++;
                }else{
                    j--;
                }
            
    
            }
            return max;
        }
    };