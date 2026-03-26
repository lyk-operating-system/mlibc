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
    [[noreturn]] void Sysdeps<Exit>::operator()(int status)
    {
        syscall1(SYSCALL_EXIT, (uint64_t)status);

        std::unreachable();
    }

    int Sysdeps<Fork>::operator()(pid_t *pid)
    {
        syscall_ret_t ret = syscall0(SYSCALL_FORK);

        *pid = (pid_t)ret.value;
        return ret.error;
    }

    int Sysdeps<TcbSet>::operator()(void *pointer)
    {
        return syscall1(SYSCALL_TCB_SET, (uint64_t)pointer).error;
    }

    int Sysdeps<GetCwd>::operator()(char *buf, size_t size)
    {
        return syscall2(SYSCALL_GET_CWD, (uint64_t)buf, size).error;
    }

    pid_t Sysdeps<GetPid>::operator()()
    {
        return syscall0(SYSCALL_GET_PID).value;
    }

    pid_t Sysdeps<GetPpid>::operator()()
    {
        return syscall0(SYSCALL_GET_PPID).value;
    }

    // pid_t is correct here
    pid_t Sysdeps<GetTid>::operator()()
    {
        return syscall0(SYSCALL_GET_TID).value;
    }
}
