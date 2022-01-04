//
//  main.cpp
//  Recursion Knapsack
//
//  Created by Joe Bulanon on 3/9/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, std::vector<int>wt, std::vector<int>val, int n, std::vector<int>& taken, int &count)
{
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1, taken, ++count);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
    {
        int preTookSize = taken.size();
        int took = val[n - 1] + knapSack(W - wt[n-1], wt, val, n-1, taken, ++count);
        
        int preLeftSize = taken.size();
        int left = knapSack(W, wt, val, n - 1, taken, ++count);
        
        if (took > left)
        {
            
            if(taken.size() > preLeftSize)
            {
                taken.erase(taken.begin() + preLeftSize, taken.begin() + taken.size());
            }
            taken.push_back(n);
            
            return took;
        }
        
        else
        {
            if (preLeftSize > preTookSize)
            {
                taken.erase(taken.begin() + preTookSize, taken.begin() + preLeftSize);
            }
            
            return left;
        }
 }

}

std::vector<int> processingFile(std::string File)
{
    std::vector<int> nums;
    std::ifstream strm;
    strm.open(File);

        if (strm.is_open() && strm.good())
        {
            int num = 0;

            while (strm >> num)
                nums.push_back(num);
        }

        strm.close();
        return nums;
}


 
// Driver code
int main(int argc, char* argv[])
{
   
    int count = 0;
    
    int totalWeight = 0;
    
    std::vector<int> taken;
    
    std::vector<int> val;
    
    std::vector<int> wt;
  
    
    
    if (argc > 1)
    {
        try
                {
                    int n = 0, W = 0;

                    if (std::stoi(argv[1]) > 0)
                        n = std::stoi(argv[1]);

                    if (std::stoi(argv[2]) > 0)
                        W = std::stoi(argv[2]);
                    
                    if (n != 0 && W != 0)
                    {
                        std::string fileWeights = argv[3];
                        std::string fileValue = argv[4];

                        std::vector<int> wt = processingFile(fileWeights);
                        std::vector<int> val = processingFile(fileValue);
                        
                        if (wt.size() != val.size())
                        {
                            throw(std::exception());
                        }
                        
                        int takenValues = knapSack(W, wt, val, n, taken, ++count);
                      
                        
                        std::cout << "Optimal Solution:";
                        
                        for(int i = 0; i < taken.size(); i++)
                        {
                            std::cout << " I" << taken[i] << " ";
                        }
                        
                        for(int i = 0; i < taken.size(); i++)
                        {
                            totalWeight = totalWeight + wt[taken[i] - 1];
                        }
                        
                        std::cout << std::endl;
                        
                       

                        std::cout << "Optimal Solution Weight: " << totalWeight << std::endl;
                        
                        std::cout << "Optimal Solution Value: " << takenValues << std::endl;
                        
                        std::cout << "Number of Recursive Calls: " << count << std::endl;
    
                    }
    }
        
        
        catch (std::exception e)
                {
                    std::cout << "FATAL Error: " << e.what() << std::endl;
                    return -1;
                }
    }
        
       else
       {
           std::cout << "Number of Arguments are invalid" << std::endl;
           return EIO;
       }

        return 0;
    
    
    return 0;
}
