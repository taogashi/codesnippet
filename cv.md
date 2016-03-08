```c++
void rotate_image(const cv::Mat &src, cv::Mat &dst, float degree)
{
	float rad = degree/57.296;
	float w1 = fabs(cos(rad));
	float w2 = fabs(sin(rad));
	int new_width = w1 * src.cols + w2 * src.rows;
	int new_height = w2 * src.cols + w1 * src.rows;

	cv::Mat temp_img(src.cols + src.rows, src.cols + src.rows, src.type(), cv::Scalar(255, 255, 255));
	cv::Point tl((temp_img.cols - src.cols)/2, (temp_img.rows - src.rows)/2);
	src.copyTo(temp_img(cv::Rect(tl, src.size())));

	cv::Mat rotate_mat = cv::getRotationMatrix2D(cv::Point(temp_img.cols/2, temp_img.cols/2), degree, 1);
	cv::warpAffine(temp_img, temp_img, rotate_mat, temp_img.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(255,255,255));
	cv::Mat roi = temp_img(cv::Rect(cv::Point((temp_img.cols - new_width)/2, (temp_img.rows - new_height)/2), cv::Size(new_width, new_height))); 

	dst = roi.clone();
}
```
