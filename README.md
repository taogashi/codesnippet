# codesnippet
``` cplusplus
cv::Mat hist;
cv::Mat histimg = cv::Mat::zeros(500, 320, CV_8UC3);
int bin = 80;
float range[] = {10,255};
const float *prange = range;
int binW = histimg.cols/bin;
cv::calcHist(&diff_frame, 1, 0, cv::Mat(), hist, 1, &bin, &prange);
for( int i = 0; i < bin; i++ ) {
    int val = cv::saturate_cast<int>(hist.at<float>(i)*histimg.rows/255);
		if (i < 10) {
				rectangle( histimg, cv::Point(i*binW,histimg.rows),
							cv::Point((i+1)*binW,histimg.rows - val),
							cv::Scalar(100, 100, 0));
		} else {
				rectangle( histimg, cv::Point(i*binW,histimg.rows),
							cv::Point((i+1)*binW,histimg.rows - val),
							cv::Scalar(100, 100, 100));
		}
}
```

```
# call create_ap to create an access point

start on (net-device-added and usb-device-added and leds-device-added)
stop on runlevel [016]

console log

script
	sleep 5
	exec /usr/bin/create_ap -n wlan0 vot llllllll
end script
```
