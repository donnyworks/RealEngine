#!/bin/bash
rm realengine
rm realengine.so
rm -rf classes
git add *
git commit -m "$1"
git push
