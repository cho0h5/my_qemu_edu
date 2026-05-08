#include <linux/module.h>

static int __init my_qemu_edu_init(void)
{
	pr_info("my_qemu_edu: loaded\n");
	return 0;
}

static void __exit my_qemu_edu_exit(void)
{
	pr_info("my_qemu_edu: unloaded\n");
}

module_init(my_qemu_edu_init);
module_exit(my_qemu_edu_exit);

MODULE_LICENSE("GPL");
