#!/bin/bash

find . -type f -exec sh -c "file -i '{}' | grep -q 'charset=binary'" \; -print | xargs rm -vf