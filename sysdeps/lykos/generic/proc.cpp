#include <lykos/syscall.h>

#include <bits/ensure.h>
#include <mlibc/all-sysdeps.hpp>
#include <mlibc/debug.hpp>

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

namespace mlibc
{
    [[noreturn]] void sys_exit(int status)
    {
        syscall1(SYSCALL_EXIT, (uint64_t)status);

        std::unreachable();
    }

    int sys_fork(pid_t *pid)
    {
        mlibc::infoLogger() << "pre fork" << frg::endlog;
		syscall_ret_t ret = syscall0(SYSCALL_FORK);
		mlibc::infoLogger() << "post fork" << frg::endlog;

		*pid = (pid_t)ret.value;

        return ret.error;
	}

    int sys_tcb_set(void *pointer)
    {
        return syscall1(SYSCALL_TCB_SET, (uint64_t)pointer).error;
    }

    int sys_get_cwd(char *buffer, size_t size)
    {
        return syscall2(SYSCALL_GET_CWD, (uint64_t)buffer, size).error;
    }

	pid_t sys_getpid()
	{
    	return syscall0(SYSCALL_GET_PID).value;
	}

	pid_t sys_getppid()
	{
	    return syscall0(SYSCALL_GET_PPID).value;
	}

	// pid_t is correct here
    pid_t sys_gettid()
    {
        return syscall0(SYSCALL_GET_TID).value;
    }
}
