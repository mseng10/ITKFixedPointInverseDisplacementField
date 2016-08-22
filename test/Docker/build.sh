#!/bin/sh

script_dir="`cd $(dirname $0); pwd`"

docker build -t insighttoolkit/fixedpointinversedisplacementfield-test $script_dir
