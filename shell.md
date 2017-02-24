# codesnippet

```shell
# call create_ap to create an access point

start on (net-device-added and usb-device-added and leds-device-added)
stop on runlevel [016]

console log
respawn
# retry up to 10 times within a period of 5 seconds
respawn limit 10 5

script
	sleep 5
	exec /usr/bin/create_ap -n wlan0 vot llllllll
end script
```

```shell
#!/bin/bash
dev_list=`fdisk -l|grep /dev|grep Disk|awk '{print $2}'|tr -d :`
for disk in $dev_list
do
	echo $disk
	if [[ $disk == *"loop"* ]]
	then
		continue
	else
		disk_id=`fdisk -l $disk|grep identifier|awk '{print $3}'`
		if [[ $disk_id -eq 0x709960b4 ]] || [[ $disk_id -eq 0x43a7a05b ]]
		then
			continue
		fi
		echo "target disk found, start writing"
		/usr/sbin/ocs-sr -g auto -e1 auto -e2 -c -r -j2 -scr -p true restoredisk xxx-img ${disk//\/dev\/}
		echo "writing complete"
	fi
done
```

```shell
for i in `seq 0 10`
do
	echi $i
done
```
终端里换行用分号。
