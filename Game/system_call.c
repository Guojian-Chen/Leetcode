#include <unistd.h>
#include <sys/wait.h>
#define NUMARGS 2

int main (int argc, char *argv[])
{
  pid_t child_pid, wait_pid;
  int * child_status;
  char * exec_path = "/path/to/executable";
  char * child_args[NUMARGS] = {0,0};

  child_pid = fork();
  if (0 == child_pid)
  { // In child process
     ...
     int child_ret_code = execv(exec_path, child_args);  //or whichever flavor of exec() that floats your boat
     ... // if child_ret_code = -1, process execv() error return
  }
  else if (-1 == child_pid)
  {
     ... //process error return from fork
  }
  else if (0 < child_pid)
  {  // Parent process
     wait_pid = wait(child_status);
     if (-1 == wait_pid)
     {
       ... //Process error return from wait()
     }
     else
     {  //  Good fork/exec/wait
        if (WIFEXITED(child_status))  // Child exited normally and hopefully returned exit code
        {
           int child_ret_code = WEXITSTATUS(child_status);
           ...  // Continue on as you would after call to system(3)
                //   except now you have the return code you needed
        }
     }
  }
}
