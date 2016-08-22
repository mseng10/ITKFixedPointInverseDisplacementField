#!/bin/sh

script_dir="`cd $(dirname $0); pwd`"

docker run \
  --rm \
  -v $script_dir/../..:/usr/src/FixedPointInverseDisplacementField \
    insighttoolkit/fixedpointinversedisplacementfield-test \
      /usr/src/FixedPointInverseDisplacementField/test/Docker/test.sh
