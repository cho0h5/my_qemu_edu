obj-m := my_qemu_edu.o

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

test: all
	sudo insmod my_qemu_edu.ko
	sleep 1
	sudo rmmod my_qemu_edu.ko
