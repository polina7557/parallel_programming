#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

void print_matrix(const vector<vector<double>> &M, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

long long operations = 0;

vector<vector<double>> multiply_matrices(const vector<vector<double>>& A, const vector<vector<double>>& B, int size, long long &operations)
{
	vector<vector<double>> C;
	for (int i = 0; i < size; i++)
	{
		vector<double> str(size, 0);
		C.push_back(str);
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
				operations++;
			}
		}
	}

	return C;
}

int main()
{
	ifstream inputFile;
	inputFile.open("input.txt");

	if (!inputFile.is_open())
	{
		cout << "The file was not found";
		return 1;
	}

	int n;
	inputFile >> n;

	vector<vector<double>> A(n, vector<double>(n, 0));
	vector<vector<double>> B(n, vector<double>(n, 0));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			inputFile >> A[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			inputFile >> B[i][j];
		}
	}
	

	cout << "Matrix A: " << endl;
	print_matrix(A, n);

	cout << "Matrix B: " << endl;
	print_matrix(B, n);

	auto start = chrono::steady_clock::now();
	vector<vector<double>> C = multiply_matrices(A, B, n, operations);
	auto end = chrono::steady_clock::now();
	chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);

	cout << "Matrix C = A * B:"  << endl;
	print_matrix(C, n);

	cout << "Volume of work: " << operations << endl;
	cout << "Execution time: " << duration.count() << " mks" << endl << endl;

	inputFile.close();


	ofstream outputFile;
	outputFile.open("output.txt");

	outputFile << "Size: " << n << endl;
	outputFile << "Volume of work: " << operations << endl;
	outputFile << "Execution time: " << duration.count() << " mks" << endl << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			outputFile << C[i][j] << "\t";
		}

		outputFile << endl;
	}

	outputFile.close();

	return 0;
}



