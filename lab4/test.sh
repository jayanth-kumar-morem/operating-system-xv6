#!usr/bin/bash
if [ "$(diff Tests/junk.out $1 |sort|uniq|wc -l)" == "0" ]; then
    echo "Test Case Passed"
else
    echo "Test Case Failed"
fi
rm -f Tests/junk.out