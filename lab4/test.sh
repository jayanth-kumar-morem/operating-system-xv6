#!usr/bin/bash
if [ "$(diff tests/junk.out $1 |sort|uniq|wc -l)" == "0" ]; then
    echo "Test Case Passed"
else
    echo "Test Case Failed"
fi
rm -f tests/junk.out