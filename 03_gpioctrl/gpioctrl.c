#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>

static struct gpio_desc *led, *button;

#define IO_LED 2
#define IO_BUTTON 3

#define IO_OFFSET 512

static int __init my_init(void)
{
    int status;
    led = gpio_to_desc(IO_LED + IO_OFFSET);
    if(!led)
    {
        printk("gpioctrl - error getting pin %d\n",IO_LED);
        return -ENODEV;
    }

    button = gpio_to_desc(IO_BUTTON + IO_OFFSET);
    if(!button)
    {
        printk("gpioctrl - error getting pin %d\n",IO_BUTTON);
        return -ENODEV;
    }

    status = gpiod_direction_input(button);
    if(status)
    {
        printk("gpioctrl - error setting pin %d to input\n",IO_BUTTON);
        return -ENODEV;
    }

    status = gpiod_direction_output(led,0);
    if(status)
    {
        printk("gpioctrl - error setting pin %d to output\n",IO_LED);
        return -ENODEV;
    }

    gpiod_set_value(led,1);
    printk("gpioctrl - button is %spressed\n",gpiod_get_value(button) ? "" : "not ");
    
    return 0;
} 

static void __exit my_exit(void)
{
    gpiod_set_value(led,0);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
