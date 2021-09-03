# Assignment 2 (deadline: 03-Sep 2021 23:59 hrs)

## Instructions

  1. The instructions on how to submit each answer is indicated below
     the question (in the line starting with "Ans."). Please follow
     those instructions carefully.
     
  2. Use code-blocks when you are pasting outputs seen on the terminal.

## Questions

1. **[1 mark]** With an example, explain the output of the `diff` command.

    **Ans.** (Type your answer here. HINT: use 3 files, two of which are the same.
   	 Run the `diff` command with all pairs of (these 3) files.
	 In your own words, explain what you see. )

   #### I created 3 files with names, countries_1.txt,countries_2.txt and countries_3.txt , out of which countries_1.txt and countries_2.txt are same containing the list of coutries names starting with alphabet "a" and countries_3.txt containing countries names starting with alphabet "e"

   ```:
   diff countries_1.txt countries_2.txt
   ```
   #### This Outputs nothing because the both the files are same and no difference between them
   ```:
   diff countries_1.txt countries_3.txt

   1,12c1,9
   < Afghanistan
   < Albania
   < Algeria
   < Andorra
   < Angola
   < Antigua and Barbuda
   < Argentina
   < Armenia
   < Australia
   < Austria
   < Austrian Empire
   < Azerbaijan
   ---
   > East Germany (German Democratic Republic)*
   > Ecuador
   > Egypt
   > El Salvador
   > Equatorial Guinea
   > Eritrea
   > Estonia
   > Eswatini
   > Ethiopia

   ```
   #### The output provides the difference between the both files

2. **[1 mark]** Using an example, show how one can measure the time taken to execute a command.

    **Ans.**. (Type your answer here. HINT: DO NOT write a C program that uses gettimeofday().
      	 Instead use the `time` command. Explain the output of the `time` command in detail.)
   #### By using the time command we can get to know how much time does a program gets to run
   #### For Example :
   ```python:
   time diff countries_1.txt countries_3.txt
   
   1,12c1,9
   < Afghanistan
   < Albania
   < Algeria
   < Andorra
   < Angola
   < Antigua and Barbuda
   < Argentina
   < Armenia
   < Australia
   < Austria
   < Austrian Empire
   < Azerbaijan
   ---
   > East Germany (German Democratic Republic)*
   > Ecuador
   > Egypt
   > El Salvador
   > Equatorial Guinea
   > Eritrea
   > Estonia
   > Eswatini
   > Ethiopia
   jayanth@jayanth:~/Desktop$ time diff countries_1.txt countries_3.txt 
   1,12c1,9
   < Afghanistan
   < Albania
   < Algeria
   < Andorra
   < Angola
   < Antigua and Barbuda
   < Argentina
   < Armenia
   < Australia
   < Austria
   < Austrian Empire
   < Azerbaijan
   ---
   > East Germany (German Democratic Republic)*
   > Ecuador
   > Egypt
   > El Salvador
   > Equatorial Guinea
   > Eritrea
   > Estonia
   > Eswatini
   > Ethiopia

   real	0m0.001s
   user	0m0.001s
   sys	0m0.000s

   ```

   #### real time – the total execution time. This is the time elapsed between invocation and termination of the command.
   #### user CPU time – the CPU time used by your process.
   #### system CPU time – the CPU time used by the system on behalf of your process.

3. **[1 mark]** What is the difference between a hard-link and a soft-link in Linux Filesystem.
   With an example, show the commands you will use to create such links.

    **Ans.**. (Type your answer here. Use code blocks appropriately)
   ### Hard Link :
   #### A hard link acts as a copy (mirrored) of the selected file. It accesses the data available in the original file. If the earlier selected file is deleted, the hard link to the file will still contain the data of that file.
   #### To create a hard link, the command is $ ln file1 link1 and an example is provided below
   ```console
      jayanth@jayanth:~/Desktop$ ln countries_2.txt countries_2_link.txt
   ```
   ### Soft Link :
   #### A soft link (also known as Symbolic link) acts as a pointer or a reference to the file name. It does not access the data available in   the original file. If the earlier file is deleted, the soft link will be pointing to a file that does not exist anymore.
   #### To create a soft link, the command is $ ln -s file1 link1 and an example is provided below
   ```console
      jayanth@jayanth:~/Desktop$ ln -s countries_1.txt countries_1_link.txt
   ```

4. **[1 mark]** How will you create named pipes in UNIX. Show an example usage of such named pipes.

   **Ans.**. (Type your answer here. Use code blocks appropriately)
	#### By using mkfifo() or mnod() commands, we can create named pipes in unix 
   ```
      jayanth@jayanth:~/Desktop/dedup/inputs$ mkfifo named_pipe_1
      jayanth@jayanth:~/Desktop/dedup/inputs$ echo 'created a named pipe' > named_pipe_1 &
      [1] 11451
      jayanth@jayanth:~/Desktop/dedup/inputs$ cat named_pipe_1
      created a named pipe
      [1]+  Done                    echo 'created a named pipe' > named_pipe_1
   ```
5. Analysis of the `syslog` file.

    a. **[2 marks]** Count the number of error messages in the `syslog` file.

    **Ans.**. (Type your answer here. HINT: Assume there is the word "error" in all of the
      	    error messages. Paste the command(s)/script you used, and its output, as seen
	    in your terminal here. Remember to code blocks here)
      ```
         jayanth@jayanth:~/Desktop$ grep -o -i error /var/log/syslog | wc -l
         32
      ```
    b. **[2 marks]** Count the number of lines in the log file.	    

    **Ans.**. (Type your answer here. Paste the command(s)/script you used, and its output,
      	    as seen in your terminal here. Remember to code blocks here.)

      ```
         jayanth@jayanth:~/Desktop$ wc -l /var/log/syslog
         1183 /var/log/syslog
      ```
    c. **[2 marks]** Count the number of unique words in the log file.	    

    **Ans.**. (Type your answer here. Paste the command(s)/script you used, and its output,
      	    as seen in your terminal here. Remember to code blocks here.)

      ```
         jayanth@jayanth:~/Desktop$ tr ' ' '\n' < /var/log/syslog | sort | uniq -c | wc -l 
         2543
      ```

    d. **[2 marks]** Find the latest error message

    **Ans.**. (Type your answer here. Paste the command(s)/script you used, and its output,
      	    as seen in your terminal here. Remember to code blocks here.)
   ```
         jayanth@jayanth:~/Desktop/dedup/inputs$ grep 'error' /var/log/syslog | tail -1
         Sep  3 19:51:58 jayanth apt.systemd.daily[2738]: An error occurred: 404  Not Found [IP: 91.189.91.38 80]
   ```

    e. **[2 marks]** Find the oldest error message

    **Ans.**. (Type your answer here. Paste the command(s)/script you used, and its output,
      	    as seen in your terminal here. Remember to code blocks here.)

      ```
            jayanth@jayanth:~/Desktop/dedup/inputs$ grep 'error' /var/log/syslog | head -1
            Sep  3 19:18:43 jayanth snapd[626]: stateengine.go:150: state ensure error: decode new commands catalog: net/http: request canceled (Client.Timeout exceeded while reading body)

      ```

    f. **[2 marks]** Find the average time between the errors

    **Ans.**. (Type your answer here. Paste the command(s)/script you used, and its output,
      	    as seen in your terminal here. Remember to code blocks here.)
   

6. `echoes` using pipes. You should do all the following
   questions inside the folder `lab2/echoes`

    a. **[2 marks]**  Write a C program (`iecho.c`) that reads an input (using `scanf()`)
      and stores it to a variable named `num`, increments `num` by one, and prints
      the incremented value (using `printf()`). Compile this program to create
      an executable named `iecho`.

    **Ans.**. (Do this in the folder echoes. YOU SHOULD NOT COMMIT THE EXECUTABLE
      	   `iecho` INTO YOUR REPO. DOING SO WILL ATTRACT PENALTY).

      ```
         #include <stdio.h>
         int main() {   
             int num;

             // reads and stores input
             scanf("%d", &num);
         	num++;
             // displays output
             printf("%d\n", num);

             return 0;
         }
      ```

      ```
         jayanth@jayanth:~/Desktop$ ./iecho 
         12
         13
      ```

    b. **[2 marks]**  Compile `driver.c` into an executable named `driver`. Pipe the output
      of `driver` as the input of `iecho`.

    **Ans.**. (PASTE the command used to achieve this, and the output seen on your
      	   terminal. Enclose the text/command/output that you are copying from
	   the terminal into this file in code blocks).

      ```
         jayanth@jayanth:~/Desktop$ gcc driver.c -o driver
         jayanth@jayanth:~/Desktop$ ./iecho < ./driver
         32768
      ```
    c. **[8 marks]**  Uncomment the lines 9 and 10 of `driver.c`, and recompile the code
      (executable name can continue to be `driver`). Write a command or shell script
      such that `driver` gets (or reads) the incremented value (which is nothing but
      the output of `iecho`). NOTE: This requires a two-way communication where `driver`
      sends a number to `iecho`, `iecho` increments it and sends the incremented value
      back to `driver`. The `driver` then prints both the original value sent and the
      incremented value it received on `stderr`.

    **Ans.**. (PASTE the command used to achieve this, and the output seen on your
      	   terminal. Enclose the text/command/output that you are copying from
	   the terminal into this file in code blocks).

      ```
         jayanth@jayanth:~/Desktop$ gcc driver.c -o driver
         jayanth@jayanth:~/Desktop$ ./iecho < ./driver | ./driver
         0
         Even: sent: 0, got 32767
         1
         Even: sent: 1, got 32767
         2
         Even: sent: 2, got 32767
         3
         Even: sent: 3, got 32767
         4
         Even: sent: 4, got 32767
      ```

7. **[12 marks]** The folder `lab2/dedup/inputs` has some files that contain information about the
   marks secured by some students in a few subjects. Since a lot of such files may be
   generated in future, you wish to save disk space. Write a shell script `dedup.sh`
   that takes a directory name as an input argument, finds all regular files immediately
   under this directory that are duplicates, and replaces the duplicates with soft-links.
   NOTE:
	a. The filename of the duplicates should remain same (before and after replacing them
	   with soft links).
	b. Your script should not search for duplicates recursively.
	b. The original files that is the one that is lexicographically first.
	c. If there are more than one duplicate, the duplicates should continue to link
	   to the original (lexicographically first) file only.
	d. If the script is not given any input argument, it is assume the current working
	   directory as its input.
	e. The filenames can contain special characters such as "*", spaces, "~", and
	   leading "-".
	f. Your script should ignore all non-regular files such as links, pipes, directories

    **Ans.**. (Complete this exercise in `dedup.sh` present under `lab2/dedup`)

