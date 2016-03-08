# codesnippet

```shell
# call create_ap to create an access point

start on (net-device-added and usb-device-added and leds-device-added)
stop on runlevel [016]

console log

script
	sleep 5
	exec /usr/bin/create_ap -n wlan0 vot llllllll
end script
```

```c++
float constrainf(float val, float threshold)
{
	return (val >= 0.0 ? (val > threshold ? threshold : val) : (val < -threshold ? -threshold : val));
}
```
