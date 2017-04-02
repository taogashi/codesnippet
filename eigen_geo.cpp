#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

int main()
{
	Rotation2D<double> rot2(M_PI/6);
	cout << rot2.angle() << endl;;

	Affine2d T2;
	T2.fromPositionOrientationScale(Vector2d(1.0, -1.0),
			rot2, Vector2d(1.0, 1.0));
	cout << Rotation2D<double>(T2.rotation()).angle() << endl;
	cout << T2.translation() << endl;

	Matrix3d rot3;
	rot3 = AngleAxisd(0.1, Vector3d::UnitZ()) * AngleAxisd(0.15, Vector3d::UnitY())* AngleAxisd(0.2, Vector3d::UnitX());
	//wrong: Matrix3d rot3 = AngleAxisd(0.1, Vector3d::UnitZ()) * AngleAxisd(0.2, Vector3d::UnitX());

	Affine3d T3;
	T3 = rot3;
	//wrong: Affine3d T3 = rot3;
	cout << T3.matrix() << endl;

	T3.fromPositionOrientationScale(Vector3d(0.2, 1.0, -1.0),
			rot3, Vector3d(1.0, 1.0, 1.0));
	cout << T3.translation().norm() << endl;

	Matrix4d T3m = T3.matrix();
	Transform<double, 3, Affine> T3_(T3m);
	cout << T3_.rotation() << endl;
	cout << T3_.rotation().eulerAngles(2,1,0) << endl;
	cout << Affine3d(T3m).translation() << endl;
	cout << T3m.block<3,1>(0, 3) << endl;

	return 0;
}
