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
    int sys_anon_allocate(size_t size, void **pointer)
    {
        return sys_vm_map(NULL, size, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_ANON, -1, 0, pointer);
    }

    int sys_anon_free(void *pointer, size_t size)
    {
        // TODO: Implement
        mlibc::infoLogger() << "UNIMPLEMENTED sys_anon_free" << frg::endlog;
        return -1;
    }

    // mlibc assumes that anonymous memory returned by sys_vm_map() is zeroed by the kernel / whatever is behind the sysdeps
    int sys_vm_map(void *hint [[maybe_unused]], size_t size [[maybe_unused]], int prot [[maybe_unused]], int flags [[maybe_unused]], int fd [[maybe_unused]], off_t offset [[maybe_unused]], void **window [[maybe_unused]])
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

    int sys_vm_unmap(void *pointer [[maybe_unused]], size_t size [[maybe_unused]])
    {
        // TODO: Implement
        mlibc::infoLogger() << "unimplemented sys_vm_unmap called" << frg::endlog;
        return -1;
    }

    int sys_vm_protect(void *pointer [[maybe_unused]], size_t size [[maybe_unused]], int prot [[maybe_unused]])
    {
        // TODO: Implement
        mlibc::infoLogger() << "unimplemented sys_vm_protect called" << frg::endlog;
        return -1;
    }
}
