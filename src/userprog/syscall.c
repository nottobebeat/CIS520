#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "threads/malloc.h"

static void syscall_handler (struct intr_frame *);
static int system_write(int fd, const void *buffer, unsigned size);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  printf ("system call!\n");
  int* i_esp = (int*)f->esp;
	int sys_call_num = (*( i_esp ));
	printf ("System call number: %i\n", sys_call_num);
	switch(sys_call_num)
	{
		case SYS_HALT:                   /* Halt the operating system. */
		break;
    case SYS_EXIT:                   /* Terminate this process. */
    case SYS_EXEC:                   /* Start another process. */
    case SYS_WAIT:                   /* Wait for a child process to die. */
    case SYS_CREATE:                 /* Create a file. */
    case SYS_REMOVE:                 /* Delete a file. */
    case SYS_OPEN:                   /* Open a file. */
    case SYS_FILESIZE:               /* Obtain a file's size. */
    case SYS_READ:                   /* Read from a file. */
    case SYS_WRITE:                  /* Write to a file. */
		{
			int fd = *(i_esp+1);
			void* buffer = (void*) *(i_esp+2);
			unsigned size = *(i_esp+3);
			printf("fd: %i\n", fd);
			printf("buffer: %p\n", buffer);
			printf("size: %u\n", size);
			system_write(fd, buffer, size);
		}
    case SYS_SEEK:                   /* Change position in a file. */
    case SYS_TELL:                   /* Report current position in a file. */
    case SYS_CLOSE:                  /* Close a file. */
		break;
	  default:
		break;
	}
  thread_exit ();
}

static int system_write(int fd, const void *buffer, unsigned size)
{
	if(fd == 1) /* Writing to console */
	{
		putbuf(buffer, size);
	}
	return 0;
} 
