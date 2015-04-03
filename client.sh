#!/bin/bash

magic="12121322124211123422"

if [ "$#" < 2 ]; then
	echo "Help: client <port> <command> [argument]"
	echo "Available commands:"
	echo "get-led-rate"
	echo "set-led-rate <0..5>"
	echo "get-led-state"
	echo "set-led-state <on/off>"
	echo "get-led-color"
	echo "set-led-color <red/green/blue>"
	exit -1;
fi

message=""
case "$2" in
"get-led-rate")
message=${magic:0:4}
;;
"set-led-rate")
message=${magic:2:4}
message="$message $3"
;;
"get-led-state")
message=${magic:6:4}
;;
"set-led-state")
message=${magic:8:4}
message="$message $3"
;;
"get-led-color")
message=${magic:12:4}
;;
"set-led-color")
message=${magic:16:4}
message="$message $3"
;;
esac

exec 3<>/dev/tcp/localhost/$1
echo -e $message >&3
cat <&3;

