# c/c++ codesnippet

```c++
float constrainf(float val, float threshold)
{
	return (val >= 0.0 ? (val > threshold ? threshold : val) : (val < -threshold ? -threshold : val));
}
```

```C++
#include <unistd.h>
sleep(sec);
usleep(micro second)
```

```c
#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
```

```c
float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}
```

```cmake
find_package(Eigen3 REQUIRED)
include_directories(
	${EIGEN3_INCLUDE_DIR}
	)
```

```c++
/// generate random unique sequence
std::vector<int> seq_all(range);
std::iota(seq_all.begin(), seq_all.end(), 0);
std::random_shuffle ( seq_all.begin(), seq_all.end() );
std::vector<int> random_seq(seq_all.begin(), seq_all.begin() + sample_num);
```

```c++
static inline uint32_t NumberOfBits(uint32_t i)
{
    // Java: use >>> instead of >>
    //      // C or C++: use uint32_t
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
```
