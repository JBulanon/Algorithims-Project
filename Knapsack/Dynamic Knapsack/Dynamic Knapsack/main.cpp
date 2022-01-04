//
//  main.cpp
//  Dynamic Knapsack
//
//  Created by Joe Bulanon on 3/9/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
  
// Prints the items which are put in a knapsack of capacity W

void printknapSack(int W, std::vector<int> wt, std::vector<int> val, int n)
{
    int i, w;
    int tableRefrences = 0;
    std::vector<std::vector<int>> K(n+1, std::vector<int>(W+1));
    std::vector<int> Solution;
    //int K[n + 1][W + 1];
  
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
                tableRefrences = tableRefrences + 1;
            }
            else if (wt[i - 1] <= w)
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                tableRefrences = tableRefrences + 3;
            }
            else
            {
                K[i][w] = K[i - 1][w];
                tableRefrences = tableRefrences + 2;
            }
        }
    }
  
    // stores the result of Knapsack
    int res = K[n][W];
    int totalWeight = 0;
    int totalValue = res;
    tableRefrences = tableRefrences + 1;
    //printf("%d\n", res);
      
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
          
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
        {
            tableRefrences = tableRefrences + 1;
            continue;
        }
        else {
  
            // This item is included.
            totalWeight = totalWeight + wt[i-1];
            
            Solution.push_back(i);
            // Since this weight is included its
            // value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    
    std::sort(Solution.begin(), Solution.end(), [](const int a, const int b) {return a < b;});
    
    std::cout << "Optimal Solution: ";
    for (i = 0; i < Solution.size(); i++)
    {
        std::cout << "I" << Solution[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Optimal Solution's Weight:" << " " << totalWeight << std::endl;
    std::cout << "Optimal Solution's Value:" << " " << totalValue << std::endl;
    
    
    std::cout<< std::endl;
    
    std::cout << std::endl;
    std::cout <<  "Number of Table References:\t" << tableRefrences << std::endl;
    std::cout << "Dynamic Programming Table:" << std::endl;
    for (i = 0; i <= n; i++){
        for (w = 0; w < K[i].size(); w++)
            {
                
                std::cout<< K[i][w] << "\t";
            }
        std::cout << std::endl;
    
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
                        
                        printknapSack(W, wt, val, n);
    
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
    }

