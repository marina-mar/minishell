# &#9674; M I N I S H E L L &#9674;
------------

![](https://github.com/marina-mar/minishell/blob/master/preview.gif?raw=true)

------------


## . A little bit of shell .
This project was my first experience doing a shell (a mini UNIX command interpreter) and managing process creation and synchronisation. I followed [-> this subject <-]( process creation and synchronisation "-> this subject <-") rules to develop the shell.


------------


### &#9674; Features
------------


- A promt that reprints itself when a command finishes execution;
- It executes any command found on the PATH provided by the environment and a few builtins:
 . cd
 . env
 . setenv
 . unsetenv
 . exit
 . 8 (that's an eight ball command)
 . lozenge (that is just a sweet personal touch to the shell)
- It manages the expansions $ and ˜

### &#9674; How to run It:
------------
Clone this repositorie, after that execute those commands:
1 | make all
2 | ./minishell
3 | test out the commands and enjoy this cozy shell!

### &#9674; Resources
------------
##### Websites:
[GETCWD( )](http://man7.org/linux/man-pages/man3/getcwd.3.html "GETCWD( )")
[FORK( )](http://man7.org/linux/man-pages/man2/fork.2.html "FORK( )")
[WAITPID( )](http://man7.org/linux/man-pages/man2/waitpid.2.html "WAITPID( )")
[CHDIR( )](https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/ "CHDIR( )")
[EXECVE( )](http://man7.org/linux/man-pages/man2/execve.2.html "EXECV( )")
[RAND ( )](https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm "RAND ( )")
[EXIT_SUCCESS and EXIT_FAILURE](https://en.cppreference.com/w/c/program/EXIT_status:// "EXIT_SUCCESS and EXIT_FAILURE")
[cd Main Page](http://linuxcommand.sourceforge.net/lc3_man_pages/cdh.html "cd Main Page")
[Var environ](http://man7.org/linux/man-pages/man7/environ.7.html "Var environ")
[The Environment Access](https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html "The Environment Access")
[Standard Environment Variables](https://www.gnu.org/software/libc/manual/html_node/Standard-Environment.html#Standard-Environment "Standard Environment Variables")
[Bitwise operators in C](https://www.programiz.com/c-programming/bitwise-operators "Bitwise operators in C")
[Where's the temp folder](http://osxdaily.com/2018/08/17/where-temp-folder-mac-access/ "Where's the temp folder")
[How to use waitpid( )](https://stackoverflow.com/questions/21248840/example-of-waitpid-in-use "How to use waitpid( )")
[How to kill a process from the command line](https://www.linux.com/tutorials/how-kill-process-command-line/ "How to kill a process from the command line")
[Adding color in C](http://web.theurbanpenguin.com/adding-color-to-your-output-from-c/ "Adding color in C")

##### Books:

[The Linux Programming Interface (2010)](http://www.man7.org/tlpi/ "The Linux Programming Interface (2010)") - Michael Kerrisk
