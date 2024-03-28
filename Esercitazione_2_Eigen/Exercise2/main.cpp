#include "Eigen/Eigen"
#include <iostream>
#define dim 2

using namespace Eigen;

bool SolvePA(const Matrix2d& A, const Vector2d& b, Vector2d& x, double& cond, double& det, double& errRel);
bool SolveQR(const Matrix2d& A, const Vector2d& b, Vector2d& x, double& cond, double& det, double& errRel);




int main()
{
    Matrix2d A1 { {5.547001962252291e-01, -3.770900990025203e-02},
                  {8.320502943378437e-01, -9.992887623566787e-01}  };
    Vector2d b1 {-5.169911863249772e-01, 1.672384680188350e-01};

    double cond = 0, det = 0, errRel = 0;
    Vector2d x;
    std::cout << std::scientific;

    if(SolvePA(A1, b1, x, cond, det, errRel)){
        std::cout << "System1 PA:\tCond = " << cond << "\tDet = " << det
                  << "\tRelErr = " << errRel << std::endl;
    }

    if(SolveQR(A1, b1, x, cond, det, errRel)){
        std::cout << "System1 QR:\tCond = " << cond << "\tDet = " << det
                  << "\tRelErr = " << errRel << std::endl;
    }

    Matrix2d A2 { {5.547001962252291e-01, -5.540607316466765e-01},
                  {8.320502943378437e-01,-8.324762492991313e-01} };
    Vector2d b2 {-6.394645785530173e-04, 4.259549612877223e-04};

    if(SolvePA(A2, b2, x, cond, det, errRel)){
        std::cout << "System2 PA:\tCond = " << cond << "\tDet = " << det
                  << "\tRelErr = " << errRel << std::endl;
    }

    if(SolveQR(A2, b2, x, cond, det, errRel)){
        std::cout << "System2 QR:\tCond = " << cond << "\tDet = " << det
                  << "\tRelErr = " << errRel << std::endl;
    }


    Matrix2d A3 { {5.547001962252291e-01, -5.547001955851905e-01},
                  {8.320502943378437e-01, -8.320502947645361e-01} };
    Vector2d b3 {-6.400391328043042e-10, 4.266924591433963e-10};

    if(SolvePA(A3, b3, x, cond, det, errRel)){
        std::cout << "System3 PA:\tCond = " << cond << "\tDet = " << det
                  << "\tRelErr = " << errRel << std::endl;
    }

    if(SolveQR(A3, b3, x, cond, det, errRel)){
        std::cout << "System3 QR:\tCond = " << cond << "\tDet = " << det
                  << "\tRelErr = " << errRel << std::endl;
    }



    return 0;
}




bool SolvePA(const Matrix2d& A, const Vector2d& b, Vector2d& x, double& cond, double& det, double& errRel){
    JacobiSVD<Matrix2d> svd(A);
    VectorXd singularValuesA = svd.singularValues();

    cond = singularValuesA.maxCoeff() / singularValuesA.minCoeff();
    det = A.determinant();

    if( singularValuesA.minCoeff() < 1e-16){
        std::cout << "Bad Conditioning!  cond = " << cond << std::endl;
        return false;
    }

    Vector2d exact = {-1.,-1.};

    PartialPivLU<Matrix2d> lu(A);
    x = lu.solve(b);

    errRel = (exact - x).norm() / exact.norm();

    return true;
}


bool SolveQR(const Matrix2d& A, const Vector2d& b, Vector2d& x, double& cond, double& det, double& errRel){
    JacobiSVD<Matrix2d> svd(A);
    VectorXd singularValuesA = svd.singularValues();

    cond = singularValuesA.maxCoeff() / singularValuesA.minCoeff();
    det = A.determinant();

    if( singularValuesA.minCoeff() < 1e-16){
        std::cout << "Bad Conditioning!  cond = " << cond << std::endl;
        return false;
    }

    Vector2d exact = {-1.,-1.};

    HouseholderQR<Matrix2d> qr(A);

    x = qr.solve(b);

    errRel = (exact - x).norm() / exact.norm();

    return true;
}
