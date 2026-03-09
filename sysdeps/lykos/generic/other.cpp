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
    void sys_libc_log(const char *message)
    {
        syscall1(SYSCALL_DEBUG_LOG, (uint64_t)message);
    }

    [[noreturn]] void sys_libc_panic()
    {
        char *c = "PANIC";
        syscall1(SYSCALL_DEBUG_LOG, (uint64_t)c);
        syscall1(SYSCALL_EXIT, 0);

        std::unreachable();
    }

    int sys_futex_wait(int *pointer [[maybe_unused]], int expected [[maybe_unused]], const struct timespec *time [[maybe_unused]])
    {
        mlibc::infoLogger() << "unimplemented sys_futex_wait called" << frg::endlog;
        return -1;
    }

    int sys_futex_wake(int *pointer [[maybe_unused]])
    {
        mlibc::infoLogger() << "unimplemented sys_futex_wake called" << frg::endlog;
        return -1;
    }

    int sys_stat(fsfd_target fsfdt, int fd, const char *path, int flags, struct stat *statbuf)
    {
        mlibc::infoLogger() << "unimplemented sys_stat called" << frg::endlog;
        return -1;
    }

    int sys_clock_getres(int clock [[maybe_unused]], time_t *secs [[maybe_unused]], long *nanos [[maybe_unused]])
    {
        mlibc::infoLogger() << "unimplemented sys_clock_getres called" << frg::endlog;
        return -1;
    }

    int sys_clock_get(int clock [[maybe_unused]], time_t *secs [[maybe_unused]], long *nanos [[maybe_unused]])
    {
        mlibc::infoLogger() << "unimplemented sys_clock_get called" << frg::endlog;
        return -1;
    }

    int sys_isatty(int fd [[maybe_unused]])
    {
        return ENOTTY;
    }

    int sys_brk(void **out [[maybe_unused]])
    {
        mlibc::infoLogger() << "unimplemented sys_brk called" << frg::endlog;
    	return -1;
    }
}
