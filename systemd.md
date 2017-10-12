```
[Unit]
Description=reverse ssh to ys's VPS on DigitalOcean [ip address]
After=ssh.service

[Service]
Type=simple
User=ys
ExecStart=/usr/bin/autossh -M [monitor port] -f -N -R [localport]:localhost:[remoteport] root@[ip address]
Restart=always
RestartSec=60

[Install]
WantedBy=multi-user.target
```
