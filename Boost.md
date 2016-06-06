```c++
#include <boost/progress.hpp>

using namespace std;

int main(void)
{
	boost::timer t;
	for (long i=100000000; i>0; i--);
	cout << t.elapsed() << endl;
	return 0;
}
```
