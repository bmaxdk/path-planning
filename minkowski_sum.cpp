#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Print 2D vectors coordinate values
void print2DVector(vector<vector<int> > vec)
{
     // Sorting the vector for grading purpose
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[0].size(); ++j) {
                cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
}
//*****************************************************
// Check for duplicate coordinates inside a 2D vector and delete them*** //
vector<vector<int> > delete_duplicate(vector<vector<int> > C)
{
    sort(C.begin(), C.end());
    vector<vector<int>> R;
    for(int i=0; i<C.size()-1; i++)
    {
        if (C[i] != C[i+1])
            R.push_back(C[i]);
    }
    R.push_back(C[C.size()-1]);
    return R;
    
    
}

// Compute the Minkowski Sum of two vectors***//
vector<vector<int> > minkowski_sum(vector<vector<int> > A, vector<vector<int> > B)
{
    vector<vector<int>> C;
    for(int i=0; i<A.size(); i++)
    {
        for (int j=0; j<B.size(); j++)
        {
            C.push_back({A[i][0] + B[j][0], A[i][1]+ B[j][1]});
        }
    }
    
    C = delete_duplicate(C);
    return C;
}

int main()
{
    // Define the coordinates of triangle A and B using 2D vectors*** //
    vector<vector<int>> A(3, vector<int>(2));
    A ={{0,-1},{0,1},{1,0}};
    vector<vector<int>> B(3, vector<int>(2));
    B = {{0,0},{1,1},{1,-1}};
    
    // Compute the minkowski sum of triangle A and B
    vector<vector<int> > C;
    C = minkowski_sum(A, B);

    // Print the resulting vector
    print2DVector(C);

    return 0;
}