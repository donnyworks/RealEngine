#!/bin/bash
rm bin/realengine
rm bin/realengine.so
rm -rf classes
git add *
git commit -m "$1"
git push
