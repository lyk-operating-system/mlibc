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
    int Sysdeps<Close>::operator()(int fd)
    {
        syscall_ret_t ret = syscall1(SYSCALL_CLOSE, (uint64_t)fd);

        return ret.error;
    }

    int Sysdeps<Open>::operator()(const char *path, int flags, mode_t mode, int *fd)
    {
        syscall_ret_t ret = syscall3(SYSCALL_OPEN, (uint64_t)path, (uint64_t)flags, (uint64_t)mode);

        *fd = ret.value;
        return ret.error;
    }

    int Sysdeps<Dup2>::operator()(int fd, [[maybe_unused]] int flags, int newfd)
    {
        STUB();
    }

    int Sysdeps<Read>::operator()(int fd, void *buf, size_t count, ssize_t *bytes_read)
    {
        syscall_ret_t ret = syscall3(SYSCALL_READ, (uint64_t)fd, (uint64_t)buf, (uint64_t)count);

        *bytes_read = ret.value;
        return ret.error;
    }

    int Sysdeps<Write>::operator()(int fd, const void *buf, size_t count, ssize_t *bytes_written)
    {
        syscall_ret_t ret = syscall3(SYSCALL_WRITE, (uint64_t)fd, (uint64_t)buf, (uint64_t)count);

        *bytes_written = ret.value;
        return ret.error;
    }

    int Sysdeps<Seek>::operator()(int fd, off_t offset, int whence, off_t *new_offset)
    {
        syscall_ret_t ret = syscall3(SYSCALL_SEEK, fd, offset, whence);

        *new_offset = ret.value;
        return ret.error;
    }

    int Sysdeps<Stat>::operator()(fsfd_target fsfdt, int fd, const char *path, int flags, struct stat *statbuf)
    {
        STUB();
    }
}
