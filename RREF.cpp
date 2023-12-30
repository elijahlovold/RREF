#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    int m = 0;
    vector<vector<double>>matrix;
    
    cout << "input matrix size: n x m\n";
 
    cin >> n;
    cin >> m;
    while (n < 1 || m < 1){
        cerr << "\nerror: invalid matrix size\n\n";

        cin >> n;
        cin >> m;
    }

    cout << endl << "input matrix: \n";

    double tmp;
    for (int i = 0; i < n; i++) {
        vector<double>tem;
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            tem.push_back(tmp);
        }
        matrix.push_back(tem);
    }

    double high = 0;
    for (int i = 0; i < n; i++) {
    
        int highindx;
        for (int h = 0; h < m; h++) {
            if (matrix[i][h] != 0) {
                high = matrix[i][h];
                highindx = h;
                break;
            }
        }
        
        for (int n = 0; n < m; n++) {
            matrix[i][n] = matrix[i][n] / high;
        }


        for (int l = i+1; l < n; l++) {
            double mult = matrix[l][highindx];

            for (int j = 0; j < m; j++) {
                matrix[l][j] -= matrix[i][j] * mult;
            }
        }
        for (int l = i-1; l >= 0; l--) {

            double mult = matrix[l][highindx];
           
            for (int j = 0; j < m; j++) {
                matrix[l][j] -= matrix[i][j] * mult;
            }
        }
        
    }

    cout << "\nRREF:\n";
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
