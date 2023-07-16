#include <iostream>
#include <vector>
#include <qpOASES.hpp>
#include <Eigen/Dense>

using namespace std;
using namespace qpOASES;

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> RowMajMat;




/** Example for qpOASES main function using the QProblem class. */
int main()
{
	Eigen::Matrix<double, 2, 2> H_;
	Eigen::Matrix<double, 1, 2> A_;
	Eigen::Matrix<double, 1, 2> g_;
	Eigen::Matrix<double, 1, 2> lb_;
	Eigen::Matrix<double, 1, 2> ub_;
	Eigen::Matrix<double, 1, 2> solution;


	H_ << 1.0, 0.0,
		  0.0, 0.5;
	A_ << 1.0, 1.0;
	g_ << 1.5, 1.0;
	lb_ << 0.5, -2.0;
	ub_ << 5.0, 2.0;

	// Solution
	vector<double> sol = {0, 0}; 

	
	/* Setup data of first QP. */
	real_t H[2*2];
	real_t A[1*2];
	real_t g[2];
	real_t lb[2];
	real_t ub[2];
	real_t lbA[1] = { -1.0 };
	real_t ubA[1] = { 2.0 };


	RowMajMat::Map(H, H_.rows(), H_.cols()) = H_;
	RowMajMat::Map(A, A_.rows(), A_.cols()) = A_;
	RowMajMat::Map(g, g_.rows(), g_.cols()) = g_;
	RowMajMat::Map(lb, lb_.rows(), lb_.cols()) = lb_;
	RowMajMat::Map(ub, ub_.rows(), ub_.cols()) = ub_;

	/* Setting up QProblem object. (Number of decision variables, Number of constraints) */
	QProblem example( 2,1 );

	// Setting up options
	Options options;
    options.printLevel = PL_MEDIUM;
	example.setOptions( options );

	/* Solve first QP. */
	int_t nWSR = 10;
	example.init( H, g, A, lb, ub, lbA, ubA, nWSR );

	/* Get and print solution of first QP. */
	real_t xOpt[2];
	example.getPrimalSolution( xOpt ); // solution pointer


	// Copy data from xOpt to solution
	memcpy(solution.data(),xOpt,sizeof(real_t)*2);

	// Print Solution
	cout << solution << endl;

	return 0;
}