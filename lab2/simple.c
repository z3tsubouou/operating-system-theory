#include <linux/init.h>
 #include <linux/kernel.h>
 #include <linux/module.h>
#include <linux/slab.h>

typedef struct birthday { 
    int day; 
int month; 
int year; 
struct list_head list;
}birthday;

LIST_HEAD(birthday_list);
/* This function is called when the module is loaded. */ 
int simple_init(void) {
birthday * person;
birthday * ptr;
int i =0;
for(;i<5; i++) {
    person = kmalloc(sizeof(*person), GFP_KERNEL);
    person->day = 10+i;
    person->month = 7+i;
    person->year=2000+i;
    INIT_LIST_HEAD(&person->list);
    list_add_tail(&person->list, &birthday_list);
}

list_for_each_entry(ptr, &birthday_list, list) {
    printk(KERN_INFO "year: %d, month: %d, day: %d", ptr->year, ptr->month, ptr->day);
}

printk(KERN_INFO "Loading Module\n"); 
return 0;
}
/* This function is called when the module is removed. */ 
void simple_exit(void) { 
    birthday *ptr, *next;
    list_for_each_entry_safe(ptr, next, &birthday_list, list) {
        list_del(&ptr->list);
        kfree(ptr); 
    }
    printk(KERN_INFO "Removing Module\n"); 
}
/* Macros for registering module entry and exit points. */ 
module_init(simple_init); 
module_exit(simple_exit);
MODULE_LICENSE("GPL"); 
MODULE_DESCRIPTION("Simple Module"); 
MODULE_AUTHOR("SGG"); 
