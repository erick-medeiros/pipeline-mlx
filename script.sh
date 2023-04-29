#!/bin/bash

export DISPLAY=":99"
export WINDOW_NAME="program"
Xvfb $DISPLAY -screen 0 1080x720x24 &
XPID=$!
valgrind -q --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./program.out &
#./program.out &
PID=$!
#sleep 5
#xdotool search --name $WINDOW_NAME windowfocus key Escape
until xdotool search --name $WINDOW_NAME windowfocus &> /dev/null; do echo sleep; sleep 1; done
xdotool key Escape
wait $PID
EXITCODE=$?
kill $XPID
exit $EXITCODE
