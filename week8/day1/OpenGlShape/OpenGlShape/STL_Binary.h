#pragma
#include<vector>
class STL_Binary
{
public:
	STL_Binary();
	~STL_Binary();
	std::vector<float> loadSTL();
	void addData(float v[],std::vector<float> &points);
};
