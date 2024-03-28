#include <iostream>
#include "Eigen/Eigen"

using namespace Eigen;
using namespace std;



int main()
{
    // Vector2d Vector2i Vector2f

    // Vector4d v1 = Vector4d::Zero();
    // Vector4d v1 = Vector4d::Ones();
    // Vector4d v1 = Vector4d::Random();
    srand(5); // set seed
    // Vector4d v1 = Vector4d::Constant(2.0);

    RowVectorXd v1 = VectorXd::Ones(5);

    cout << "v1: " << v1 << endl;
    cout << "size: " << v1.size() << endl;

    v1.conservativeResize(4);

    cout << "v1: " << v1 << endl;
    cout << "size: " << v1.size() << endl;






    return 0;
}
