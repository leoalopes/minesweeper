#!/usr/bin/env bash

# Parse arguments
while [[ $# -gt 0 ]]; do
	case $1 in
	--clean)
		export CLEAN_BUILD=1
		shift
		;;
	-* | --*)
		err "Unknown option $1"
		exit 1
		;;
	*)
		err "Illegal argument $1"
		exit 1
		;;
	esac
done

if [ -n "$CLEAN_BUILD" ]; then
	rm -rf build
fi

cmake -S . -B build
cmake --build build
