#include <linux/module.h>
#include <linux/pci.h>

#define DRIVER_NAME "my_qemu_edu"
#define VENDOR_ID 0x1234
#define PRODUCT_ID 0x11e8

static const struct pci_device_id my_qemu_edu_ids[] = {
	{ PCI_DEVICE(VENDOR_ID, PRODUCT_ID) },
	{ 0, }
};

static int my_qemu_edu_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
	int err;

	err = pcim_enable_device(pdev);
	if (err) {
		return err;
	}

	err = pcim_iomap_regions(pdev, BIT(0), DRIVER_NAME);
	if (err) {
		return err;
	}

	void __iomem *bar0 = pcim_iomap_table(pdev)[0];

	const u32 value = readl(bar0 + 0x00);
	dev_info(&pdev->dev, "BAR0+0x00 = 0x%08x\n", value);

	pr_info("my_qemu_edu: probe\n");
	return 0;
}

static void my_qemu_edu_remove(struct pci_dev *pdev)
{
	pr_info("my_qemu_edu: remove\n");
}

static struct pci_driver my_qemu_edu_driver = {
	.name = DRIVER_NAME,
	.id_table = my_qemu_edu_ids,
	.probe = my_qemu_edu_probe,
	.remove = my_qemu_edu_remove,
};

module_pci_driver(my_qemu_edu_driver);

MODULE_LICENSE("GPL");
