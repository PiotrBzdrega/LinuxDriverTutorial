#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

static int __init my_init(void)
{
    /* Setup the gpio */
    if(gpio_request(17,"rpi-gpio-17
    printk("Hello kernel world in my_init function\n");
    return 0;

} 

static void __exit my_exit(void)
{
    printk("Hello kernel world in my_exit function\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
