/* auto-generated by gen_syscalls.py, don't edit */

#include <syscalls/gpio.h>

extern int z_vrfy_gpio_port_toggle_bits(const struct device * port, gpio_port_pins_t pins);
uintptr_t z_mrsh_gpio_port_toggle_bits(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg2;	/* unused */
	(void) arg3;	/* unused */
	(void) arg4;	/* unused */
	(void) arg5;	/* unused */
	union { uintptr_t x; const struct device * val; } parm0;
	parm0.x = arg0;
	union { uintptr_t x; gpio_port_pins_t val; } parm1;
	parm1.x = arg1;
	int ret = z_vrfy_gpio_port_toggle_bits(parm0.val, parm1.val);
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}

