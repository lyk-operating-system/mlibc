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
    int sys_accept(int fd, int *newfd, struct sockaddr *addr_ptr, socklen_t *addr_length, int flags)
    {
		syscall_ret_t ret = syscall4(SYSCALL_ACCEPT, fd, (uint64_t)addr_ptr, (uint64_t)addr_length, flags);
		*newfd = ret.value;
		return ret.error;
	}

	int sys_bind(int fd, const struct sockaddr *addr_ptr, socklen_t addr_length)
	{
		syscall_ret_t ret = syscall2(SYSCALL_BIND, fd, (uint64_t)addr_ptr);
		return ret.error;
	}

	int sys_connect(int fd, const struct sockaddr *addr_ptr, socklen_t addr_length)
	{
		syscall_ret_t ret =  syscall2(SYSCALL_CONNECT, fd, (uint64_t)addr_ptr);
		return ret.error;
	}

	int sys_listen(int fd, int backlog)
	{
		syscall_ret_t ret = syscall2(SYSCALL_LISTEN, fd, backlog);
		return ret.error;
	}

	int sys_peername(int fd, struct sockaddr *addr_ptr, socklen_t max_addr_length, socklen_t *actual_length)
	{
		syscall_ret_t ret = syscall3(SYSCALL_GETPEERNAME, fd, (uint64_t)addr_ptr, (uint64_t)max_addr_length);
		*actual_length = ret.value;
		return ret.error;
	}

	int sys_shutdown(int sockfd, int how)
	{
	    syscall_ret_t ret = syscall2(SYSCALL_SHUTDOWN, sockfd, how);
		return ret.error;
	}

	int sys_socket(int family, int type, int protocol, int *fd)
	{
		syscall_ret_t ret = syscall3(SYSCALL_SOCKET, family, type, protocol);
		*fd = ret.value;
		return ret.error;
	}

	int sys_sockname(int fd, struct sockaddr *addr_ptr, socklen_t max_addr_length, socklen_t *actual_length)
	{
		syscall_ret_t ret = syscall3(SYSCALL_GETSOCKNAME, fd, (uint64_t)addr_ptr, (uint64_t)max_addr_length);
		*actual_length = ret.value;
		return ret.error;
	}
}
