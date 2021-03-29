/**	
  *	Hello World Module
  *	
  *	2021 DeYou
  *	
  */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>

#define HELLO_DEV_MINOR	0
#define HELLO_NR_DEVS	4

int hello_major;
int hello_minor = 0;

dev_t dev_no;

int hello_open(struct inode *inode, struct file *filp)
{
	return 0;
}

int hello_release(struct inode *inode, struct file *filp)
{
	return 0;
}

ssize_t hello_read(struct file *filp, char __user *addr, size_t size, loff_t *offset)
{
	return 0;
}

ssize_t hello_write(struct file *filp, const char __user *addr, size_t size, loff_t *offset)
{
	return 0;
}

struct file_operations hello_fops = {
	.open = hello_open,
	.read = hello_read,
	.write = hello_write,
	.release = hello_release,
};

static int __init hello_world_init(void)
{

	printk("hello world\n");
	/* alloc device num */
	alloc_chrdev_region(&dev_no, hello_minor, HELLO_NR_DEVS, "hello world");

	printk("alloc dev no is %d\n", dev_no);

//	struct cdev hello;




	return 0;
}


static void __exit hello_world_exit(void)
{
	unregister_chrdev_region(dev_no, HELLO_NR_DEVS);
	printk("unregister dev no is %d\n", dev_no);
	printk("GoodBye\n");
}


module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DeYou");
MODULE_VERSION("1.0.0");
MODULE_DESCRIPTION("hello world");
