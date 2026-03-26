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
    int Sysdeps<AnonAllocate>::operator()(size_t size, void **pointer)
    {
        syscall_ret_t ret = syscall6(
            SYSCALL_MMAP,
            (uint64_t)NULL,
            (uint64_t)size,
            (uint64_t)PROT_WRITE | PROT_READ | PROT_EXEC,
            (uint64_t)MAP_ANON,
            (uint64_t)-1,
            (uint64_t)0
        );

        *pointer = (void *)ret.value;
        return ret.error;
    }

    int Sysdeps<AnonFree>::operator()(void *pointer, size_t size)
    {
        STUB();
    }

    int Sysdeps<VmMap>::operator()(void *hint, size_t size, int prot, int flags, int fd, off_t offset, void **window)
    {
        syscall_ret_t ret = syscall6(
            SYSCALL_MMAP,
            (uint64_t)hint,
            (uint64_t)size,
            (uint64_t)prot,
            (uint64_t)flags,
            (uint64_t)fd,
            (uint64_t)offset
        );

        *window = (void *)ret.value;
        return ret.error;
    }

    int Sysdeps<VmUnmap>::operator()(void *pointer, size_t size)
    {
        STUB();
    }

    int Sysdeps<VmProtect>::operator()(void *pointer, size_t size, int prot)
    {
        STUB();
    }
}
