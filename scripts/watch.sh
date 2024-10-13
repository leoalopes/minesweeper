#!/usr/bin/env bash

find app core -type f | entr -dcp "./scripts/run-tests.sh" "--build"
