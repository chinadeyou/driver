/**	
  *	Hello World Module
  *	
  *	2021 DeYou
  *	
  */

#include <linux/init.h>
#include <linux/module.h>

static int __init hello_world_init(void)
{
	printk("hello world\n");

	return 0;
}


static void __exit hello_world_exit(void)
{
	printk("GoodBye\n");
}


module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DeYou");
MODULE_VERSION("1.0.0");
MODULE_DESCRIPTION("hello world");
