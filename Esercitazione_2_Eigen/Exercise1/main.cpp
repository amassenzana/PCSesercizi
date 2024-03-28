#include <iostream>
#include "Eigen/Eigen"

#define dim 4
#define interrupt "\n\n*-*-*-*-*-*-*-*-*-*-*-*\n"

typedef Eigen::Matrix<double, dim, dim> MatrixNxN;
typedef Eigen::Vector<double,dim> VectorN;


MatrixNxN Shape(bool print = false);
MatrixNxN Rand (bool print = false);
MatrixNxN Hilb (bool print = false);

bool SolveSystem(const MatrixNxN& A, const VectorN& b, VectorN& x, double& det, double& cond, bool print = false);

int main()
{
    MatrixNxN S = Shape();
    VectorN solution = VectorN::Ones();
    VectorN b = S*solution;
    VectorN x = VectorN::Zero();
    double det = 0, cond = 0;

    if (SolveSystem(S, b, x, det, cond)){
        std::cout << "For the Shape matrix\n" << S
                  << "\n\nThe solution is: " << x.transpose()
                  << "\nThe conditioning is: " << cond << std::endl;
    }


    MatrixNxN H = Hilb();
    b = H*solution;
    if (SolveSystem(H, b, x, det, cond)){
        std::cout << interrupt << "For the Hilbert matrix\n" << H
                  << "\n\nThe solution is: " << x.transpose()
                  << "\nThe conditioning is: " << cond << std::endl;
    }


    MatrixNxN R = Rand();
    b = R*solution;
    if (SolveSystem(R, b, x, det, cond)){
        std::cout << interrupt << "For the Random matrix\n" << R
                  << "\n\nThe solution is: " << x.transpose()
                  << "\nThe conditioning is: " << cond << std::endl;
    }


    return 0;
}


MatrixNxN Shape(bool print){

    Eigen::VectorXd linspaceVector = Eigen::VectorXd::LinSpaced(dim*dim, 1, dim*dim);
    MatrixNxN A = linspaceVector.reshaped<Eigen::RowMajor>(dim, dim);

    if(print)
        std::cout << interrupt << "Shape Matrix: \n" << A << std::endl;

    return A;
}

MatrixNxN Rand(bool print){
    srand(10);
    MatrixNxN Rand = MatrixNxN::Random (dim,dim) + MatrixNxN::Ones (dim,dim);

    if(print)
        std::cout << interrupt << "Random matrix: \n" << Rand << std::endl;

    return Rand;
}

MatrixNxN Hilb(bool print)
{
    MatrixNxN Hilb = MatrixNxN::Zero(dim,dim);
    for (unsigned int i = 0; i < dim; i++){
        for (unsigned int j = 0; j < dim; j++){
            Hilb.row(i)[j] = 1./(1. + double(j) + double(i));
        }
    }

    if(print)
        std::cout << interrupt << "Hilbert matrix: \n" << Hilb << std::endl;
    return Hilb;
}


bool SolveSystem(const MatrixNxN& A, const VectorN& b, VectorN& x, double& det, double& cond, bool print){

    Eigen::JacobiSVD<MatrixNxN> svd(A);
    Eigen::VectorXd singularValuesA = svd.singularValues();
    cond = singularValuesA.maxCoeff() / singularValuesA.minCoeff();

    det = A.determinant();

    if( singularValuesA.minCoeff() < 1e-16){
        std::cout << "Conditioning is too small!  cond = " << cond << std::endl;
        return false;
    }

    Eigen::FullPivLU<MatrixNxN> lu(A);
    MatrixNxN l = MatrixNxN::Identity();
    l.block<dim,dim>(0,0).triangularView<Eigen::StrictlyLower>() = lu.matrixLU();
    MatrixNxN u = lu.matrixLU().triangularView<Eigen::Upper>();
    MatrixNxN P = lu.permutationP()*MatrixNxN::Identity();
    MatrixNxN Q = lu.permutationQ()*MatrixNxN::Identity();

    VectorN y = l.fullPivLu().solve(P*b);

    x = (u*Q.inverse()).fullPivLu().solve(y);

    if(print){
        std::cout << "Here is the matrix A:\n"  << A << std::endl;
        std::cout << "Here is the L part:\n"    << l << std::endl;
        std::cout << "Here is the U part:\n"    << u << std::endl;
        std::cout << "The matrix P:\n"          << P << std::endl;
        std::cout << "The matrix Q:\n"          << Q << std::endl;
        std::cout << "Solution: "               << x.transpose() << std::endl;
    }



    return true;
}
