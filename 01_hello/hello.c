#include <linux/module.h>
#include <linux/init.h>

int my_init(void)
{
    printk("Hello kernel world in my_init function\n");
    return 0;

} 

void my_exit(void)
{
    printk("Hello kernel world in my_exit function\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
