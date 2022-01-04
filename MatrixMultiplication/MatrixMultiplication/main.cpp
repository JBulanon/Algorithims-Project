//
//  main.cpp
//  MatrixMultiplication
//
//  Created by Joe Bulanon on 2/18/21.
//  Collobaration with Aleesha Chavez & Kyle Duncan

// C++ program to print optimal parenthesization
// in matrix chain multiplication.
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <exception>


void ErrorMessage()
{
    std::cout << "You don't have enough arguments" << std::endl;
    std::cout << "Expected: {Program}.exe <matrixSize1> <matrixSize2> [matrixSize3] ... [matrixSizen]"<< std::endl;
}

// Function for printing the optimal
// parenthesization of a matrix chain product
void printParenthesis(int i, int j, int n, int** bracket,
                      char& name)
{
    // If only one matrix left in current segment
    if (i == j) {
        std::cout << name++;
        return;
    }
 
    std::cout << "(";
 
    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    // Note that "*((bracket+i*n)+j)" is similar to
    // bracket[i][j]
    printParenthesis(i, bracket[i][j], n,
                     bracket, name);
 
    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(bracket[i][j] + 1, j, n,
                     bracket, name);
    std::cout << ")";
}

void printTable(int **print, int size)
{
//bypass uninitialized values
    for (int i = 0; i < size; i++)
    {
        bool didPrint = false;
        for (int j = 0; j < size; j++)
        {
            if (print[j][i] > 0)
            {
                didPrint = true;
                std::cout << print[j][i] << "\t";
            }

        }
        if(didPrint)
            std::cout << std::endl;
    }
}

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
// Please refer below article for details of this
// function
// https://goo.gl/k6EYKj
void matrixChainOrder(int p[], int n)
{
    /* For simplicity of the program, one extra
       row and one extra column are allocated in
        m[][]. 0th row and 0th column of m[][]
        are not used */
    
    int**m = new int* [n];
    int**dt = new int* [n];
    
    for(int i = 0; i < n; i++)
    {
        m[i] = new int [n];
        dt[i] = new int [n];
    }
    
    for(int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
 
    
 
    // L is chain length.
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            // Optimal Values
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j]
                        + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
 
                    // Each entry bracket[i,j]=k shows
                    // where to split the product arr
                    // i,i+1....j for the minimum cost.
                    dt[i][j] = k;
                }
            }
        }
    }
   
 
    // The first matrix is printed as 'A', next as 'B',
    // and so on
    char name = 'A';
    
    
    std::cout << "Optimal Values:" << std::endl;
    printTable(m, n);
    std::cout << std::endl;
    
    std::cout << "Decision Table:" << std::endl;
    printTable(dt, n);
    
    std::cout << std::endl;
    std::cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n - 1, n, dt, name);
    std::cout << std::endl;
    std::cout << "Optimal Cost is: " << m[1][n - 1];
    std::cout << std::endl;
    
    for (int i = 0; i < n; i++)
    {
        delete[] m[i];
        m[i] = nullptr;
        delete dt[i];
        dt[i] = nullptr;
    }
    
    delete[] m;
    m = nullptr;
    delete[] dt;
    dt = nullptr;
}




 
// Driver code
int main(int argc, char* argv[])
{
    if ( argc > 2)
    {
        try {
            int* set = new int[argc - 1];
            for (int i = 1; i < argc; i++)
                {
                    if (std::stoi(argv[i]) >= 0)
                    {
                         set[i - 1] = std::stoi(argv[i]);
                    }
                    else
                    {
                     throw std::exception();
                    }
            }
            
            
            matrixChainOrder(set, argc - 1);
            delete[] set;
            set = nullptr;
                     
            }
         catch (std::exception ex)
        {
            std::cout<<"Error occured " << ex.what() << std::endl;
            return - 1;
        }
        
    }
    
    else
    {
        ErrorMessage();
        return EIO;
    }
    
    return 0;
}
