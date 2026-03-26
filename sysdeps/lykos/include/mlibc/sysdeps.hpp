#pragma once

#include <mlibc/sysdep-signatures.hpp>

namespace mlibc {

struct LykOSSysdepTags :
	// IO
	Close,
	Open,
	Dup2,
	Read,
	Write,
	Seek,
	Stat,
	// Memory
	AnonAllocate,
	AnonFree,
	VmMap,
	VmUnmap,
	VmProtect,
	// Other
	ClockGet,
	FutexWait,
	FutexWake,
	LibcLog,
	LibcPanic,
	Isatty,
	// Proc
	Exit,
	Fork,
	TcbSet,
	GetCwd,
	GetPid,
	GetPpid,
	GetTid,
	// Socket
	Accept,
	Bind,
	Connect,
	Listen,
	Peername,
	Shutdown,
	Socket,
	Sockname
{};

template<typename Tag>
using Sysdeps = SysdepOf<LykOSSysdepTags, Tag>;

} // namespace mlibc
