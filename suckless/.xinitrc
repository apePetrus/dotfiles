#!/usr/bin/env bash

pipewire &

feh --no-fehbg --bg-fill "$HOME/.mc-canvas.png"

while true; do
	xsetroot -name " $(date) "
	sleep 1
done &

exec dwm
