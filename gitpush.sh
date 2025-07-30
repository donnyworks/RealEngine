#!/bin/bash
rm engine
git add *
git commit -m "$1"
git push
