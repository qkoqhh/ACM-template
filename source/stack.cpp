#include <cstdlib>
char _s_t_a_c_k_[128 << 20];
int main()
{
	__asm volatile (
#ifdef __x86_64__
		"movq %0, %%rsp"
#else
		"movl %0, %%esp"
#endif
		::"r"(_s_t_a_c_k_+(128<<20)):
	);

	exit(0);
}
