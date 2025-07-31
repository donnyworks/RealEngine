#!/bin/bash
rm engine
rm -rf classes
git add *
git commit -m "$1"
git push
