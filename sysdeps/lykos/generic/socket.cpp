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
		long ret;
		long error = syscall(SYSCALL_ACCEPT, &ret, fd, (uint64_t)addr_ptr, (uint64_t)addr_length, flags);
		*newfd = ret;
		return error;
	}

	int sys_bind(int fd, const struct sockaddr *addr_ptr, socklen_t addr_length)
	{
		long ret;
		return syscall(SYSCALL_BIND, &ret, fd, (uint64_t)addr_ptr, addr_length);
	}

	int sys_connect(int fd, const struct sockaddr *addr_ptr, socklen_t addr_length)
	{
		long ret;
		return syscall(SYSCALL_CONNECT, &ret, fd, (uint64_t)addr_ptr, addr_length);
	}

	int sys_listen(int fd, int backlog)
	{
		long ret;
		return syscall(SYSCALL_LISTEN, &ret, fd, backlog);
	}

	int sys_msg_recv(int fd, struct msghdr *hdr, int flags, ssize_t *length)
	{
		long ret;
		long err = syscall(SYSCALL_RECVMSG, &ret, fd, (uint64_t)hdr, flags);
		*length = ret;
		return err;
	}

	int sys_msg_send(int fd, const struct msghdr *hdr, int flags, ssize_t *length)
	{
		long ret;
		long err = syscall(SYSCALL_SENDMSG, &ret, fd, (uint64_t)hdr, flags);
		*length = ret;
		return err;
	}

	int sys_peername(int fd, struct sockaddr *addr_ptr, socklen_t max_addr_length, socklen_t *actual_length)
	{
		long ret;
		int len = max_addr_length;
		long error = syscall(SYSCALL_GETPEERNAME, &ret, fd, (uint64_t)addr_ptr, (uint64_t)&len);
		*actual_length = len;
		return error;
	}

	int sys_shutdown(int sockfd, int how)
	{
		long ret;
		return syscall(SYSCALL_SHUTDOWN, &ret, sockfd, how);
	}

	int sys_socket(int family, int type, int protocol, int *fd)
	{
		long ret;
		long err = syscall(SYSCALL_SOCKET, &ret, family, type, protocol);
		*fd = ret;
		return err;
	}

	int sys_sockname(int fd, struct sockaddr *addr_ptr, socklen_t max_addr_length, socklen_t *actual_length)
	{
		long ret;
		int len = max_addr_length;
		long error = syscall(SYSCALL_GETSOCKNAME, &ret, fd, (uint64_t)addr_ptr, (uint64_t)&len);
		*actual_length = len;
		return error;
	}
}
