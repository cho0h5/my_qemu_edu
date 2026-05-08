obj-m := my_qemu_edu.o

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

test: all
	sudo rmmod my_qemu_edu.ko
	sudo insmod my_qemu_edu.ko
