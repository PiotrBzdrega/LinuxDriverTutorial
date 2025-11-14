#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int major;

static int my_open(struct inode *inode, struct file *filep)
{
    pr_info("hello_cdev - Open is called Major %d, Minor %d\n", imajor(inode), iminor(inode));
    pr_info("filep->f_pos: %lld\n", filep->f_pos);
    pr_info("filep->f_mode: 0x%x\n", filep->f_mode);
    pr_info("filep->f_flags: 0x%x\n", filep->f_flags);
    return 0;
}

static ssize_t my_read (struct file *file, char __user *u, size_t l, loff_t *o)
{
    pr_info("hello_cdev - Read is called \n");
    return 0;
} 


static int my_release (struct inode *inode, struct file *filep)
{
    pr_info("hello_cdev - Release is called \n");
    return 0;
} 

static struct file_operations fops = 
{
    .open = my_open,
    .release = my_release
};

static int __init my_init(void)
{
    major = register_chrdev(0,"hello_cdev",&fops);
    if(major<0)
    {
        pr_err("hello_cdev - Error registering chrdev\n");
        return major;
    }
    printk("hello_cdev - Major Device Number: %d\n", major);
    return 0;

} 

static void __exit my_exit(void)
{
    unregister_chrdev(major,"hello_cdev");
    pr_info("Hello kernel world in my_exit function\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A sample driver for registering a character device");
