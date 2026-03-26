#ifndef _LYKOS__SYSCALL_H
#define _LYKOS__SYSCALL_H

#include <stdint.h>

enum
{
    // DEBUG
    SYSCALL_DEBUG_LOG = 0,
    // IO
    SYSCALL_OPEN,
    SYSCALL_CLOSE,
    SYSCALL_READ,
    SYSCALL_WRITE,
    SYSCALL_SEEK,
    // MEMORY
    SYSCALL_MMAP,
    // PROC
    SYSCALL_EXIT,
    SYSCALL_FORK,
    SYSCALL_GET_CWD,
    SYSCALL_GET_PID,
    SYSCALL_GET_PPID,
    SYSCALL_GET_TID,
    SYSCALL_TCB_SET,
    // SOCKET
    SYSCALL_ACCEPT,
    SYSCALL_BIND,
    SYSCALL_CONNECT,
    SYSCALL_GETPEERNAME,
    SYSCALL_GETSOCKNAME,
    SYSCALL_LISTEN,
    SYSCALL_RECV,
    SYSCALL_SEND,
    SYSCALL_SHUTDOWN,
    SYSCALL_SOCKET
};

#define STUB()                              \
({                                          \
    __ensure(!"STUB function was called");  \
    __builtin_unreachable();                \
})

#ifndef __MLIBC_ABI_ONLY

typedef struct
{
    uint64_t value;
    uint64_t error;
}
syscall_ret_t;

#define DEFINE_SYSCALL(...)                         \
    syscall_ret_t result;                           \
    asm volatile(                                   \
        "syscall"                                   \
        : "=a" (result.value), "=d" (result.error)  \
        : __VA_ARGS__                               \
        : "rcx", "r11", "memory"                    \
    );                                              \
    return result;

#ifdef __cplusplus
extern "C"
{
#endif

    static syscall_ret_t syscall0(uint64_t sc)
    {
        DEFINE_SYSCALL("a" (sc));
    }

    static syscall_ret_t syscall1(uint64_t sc, uint64_t arg1)
    {
        DEFINE_SYSCALL("a" (sc), "D" (arg1));
    }

    static syscall_ret_t syscall2(uint64_t sc, uint64_t arg1, uint64_t arg2)
    {
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2));
    }

    static syscall_ret_t syscall3(uint64_t sc, uint64_t arg1, uint64_t arg2, uint64_t arg3)
    {
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2), "d" (arg3));
    }

    static syscall_ret_t syscall4(uint64_t sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4)
    {
        register uint64_t arg4_reg asm("r10") = arg4;
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2), "d" (arg3), "r" (arg4_reg));
    }

    static syscall_ret_t syscall5(uint64_t sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5)
    {
        register uint64_t arg4_reg asm("r10") = arg4;
        register uint64_t arg5_reg asm("r8") = arg5;
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2), "d" (arg3), "r" (arg4_reg), "r" (arg5_reg));
    }

    static syscall_ret_t syscall6(uint64_t sc, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6)
    {
        register uint64_t arg4_reg asm("r10") = arg4;
        register uint64_t arg5_reg asm("r8") = arg5;
        register uint64_t arg6_reg asm("r9") = arg6;
        DEFINE_SYSCALL("a" (sc), "D" (arg1), "S" (arg2), "d" (arg3), "r" (arg4_reg), "r" (arg5_reg), "r" (arg6_reg));
    }

#ifdef __cplusplus
}
#endif

#endif

#endif
