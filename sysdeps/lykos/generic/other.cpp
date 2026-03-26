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
    int Sysdeps<ClockGet>::operator()(int clock, time_t *secs, long *nanos)
    {
        STUB();
    }

    int Sysdeps<FutexWait>::operator()(int *pointer, int expected, const struct timespec *time)
    {
        STUB();
    }

    int Sysdeps<FutexWake>::operator()(int *pointer, bool all)
    {
        STUB();
    }

    void Sysdeps<LibcLog>::operator()(const char *message)
    {
        syscall1(SYSCALL_DEBUG_LOG, (uint64_t)message);
    }

    [[noreturn]] void Sysdeps<LibcPanic>::operator()()
    {
        char *c = "LIBC PANIC";
        syscall1(SYSCALL_DEBUG_LOG, (uint64_t)c);
        syscall1(SYSCALL_EXIT, 0);

        std::unreachable();
    }

    int Sysdeps<Isatty>::operator()(int fd)
    {
        return ENOTTY;
    }
}
