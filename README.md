*This project has been created as part of the 42 curriculum by cpinho-c.*

# Pipex

## Main objective

The objective of this project is to make a program that can execute a simple command line. It is the first step in understand how command execution works and a good start learning point that will be needed for a future project called minishell.

The pipex should be executed as follows
```cmd
	./pipex file1 cmd1 cmd2 file2
```

It must always take 4 arguments:
- **file1** and **file2** are file names
- **cmd1** and **cmd2** are shell commands with their parameters

for example, the following command line '< infile ls -l | wc -l > outfile' will look like this on pipex:

```
	./pipex infile "ls -l" "wc -l" outfile
```
