#include <bits/stdc++.h>
using namespace std;

// Function to compute A × Aᴴ (A * conjugate transpose)
vector<vector<complex<double>>> multiplyWithConjugateTranspose(vector<vector<complex<double>>> &A, int n) {
    vector<vector<complex<double>>> result(n, vector<complex<double>>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * conj(A[j][k]); // conj() gives complex conjugate
            }
        }
    }
    return result;
}

// Function to check if result ≈ Identity matrix
bool isIdentity(vector<vector<complex<double>>> &mat, int n) {
    double EPS = 1e-6;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (abs(mat[i][j] - complex<double>(1.0, 0.0)) > EPS)
                    return false;
            } 
            else {
                if (abs(mat[i][j]) > EPS)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<complex<double>>> A(n, vector<complex<double>>(n));
    cout << "Enter complex matrix elements (real and imaginary parts):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double realPart, imagPart;
            cin >> realPart >> imagPart;
            A[i][j] = complex<double>(realPart, imagPart);
        }
    }

    auto product = multiplyWithConjugateTranspose(A, n);

    if (isIdentity(product, n))
        cout << "✅ The matrix is Unitary.\n";
    else
        cout << "❌ The matrix is NOT Unitary.\n";

    return 0;
}
