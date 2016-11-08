#!/bin/sh

kill -9 $(ps aux | grep [c]ear | awk '{print $2}')
