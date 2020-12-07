#!/bin/bash

PORT=2500
TESTVAL="This is my value"
TESTOK=1

# make all

echo "TESTING: two gets waiting for a put"

# Reset outputs
echo "" > out1.txt
echo "" > out2.txt

# Start server -- use "&" to make it run in background
./iVar-server $PORT &
# Get server PID for later kill
serverpid=$(echo "$!")
echo "Server running on pid: $serverpid"

# Sleeps are not needed but make my presentation dramatic :)
sleep 1

# Start a couple of gets that should wait
echo "Starting gets"
./get localhost $PORT > out1.txt &
./get localhost $PORT > out2.txt &

sleep 1

# Test that output has not been written
out1cont=$(cat out1.txt)
echo "Out1 is still empty: \"$out1cont\""
if [ "$out1cont" != "" ]; then
    TESTOK=0
    echo ">> FAILED WAIT"
fi

sleep 1

# Put value to storage
echo "Putting value"
putval=$(echo $TESTVAL | ./put localhost $PORT)

echo "The put reply: \"$putval\""
if [ "$putval" != "OK" ]; then
    TESTOK=0
    echo ">> FAILED PUT"
fi

sleep 1

# Check put value
out1cont=$(cat out1.txt)
echo "Out1 is : \"$out1cont\""
if [ "$out1cont" != "$TESTVAL" ]; then
    TESTOK=0
    echo ">> FAILED WAIT"
fi

# Clean up
kill $serverpid
rm out1.txt out2.txt

if [ $TESTOK == 1 ]; then
    echo ">> TEST SUCCESS"
else
    echo ">> TEST FAILED"
fi
