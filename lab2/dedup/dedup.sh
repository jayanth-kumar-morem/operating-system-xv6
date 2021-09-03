for file1 in $(find . -name '*.csv'); do
    for file2 in $(find . -name '*.csv'); do
    	if diff -q "${file1}" "${file2}" >/dev/null && "$file1" != "$file2" ; then
    		"$(ln -s "${file1}" "${file2}")"
    		#"$(rm "${file2}")"
    	fi
    done
done