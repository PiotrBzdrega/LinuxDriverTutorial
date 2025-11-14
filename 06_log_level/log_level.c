#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void)
{
    
    printk("Hello kernel world in my_init function\n");
    printk(KERN_WARNING "warning\n");
    printk(KERN_DEBUG "debug\n");
    printk(KERN_EMERG "emergency\n");
    return 0;

} 

static void __exit my_exit(void)
{
    printk("Hello kernel world in my_exit function\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
