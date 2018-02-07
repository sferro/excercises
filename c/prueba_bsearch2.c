#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* routine to compare two nodes based on an  */
/* alphabetical ordering of the string field */

struct node {            /* these are stored in the table */
	char string[20];
};

static int node_compare( void *node1,  void *node2);

/*
static struct node table[] = {     
    { "asparagus", 10 },
    { "beans", 6 },
    { "tomato", 7 },
    { "watermelon", 11 },
};
*/

main() {
	struct node *node_ptr, node;
    /* routine to compare 2 nodes */
    char str_space[20];   /* space to read string into */
	struct node table[10];
	
	strcpy(table[0].string, "111");
	strcpy(table[1].string, "112");
	strcpy(table[2].string, "113");
	strcpy(table[3].string, "114");
	strcpy(table[4].string, "115");
	
	printf("sizeof table= %d\n", sizeof(table));
    
    while (scanf("%20s", node.string) != EOF) {
    	node_ptr = bsearch( &node, table, sizeof(table)/sizeof(struct node),
                            sizeof(struct node), node_compare);
        if (node_ptr != NULL) {
        	 printf("string = %20s\n",
            node_ptr->string);
        } 
        else {
        	printf("not found: %20s\n", node.string);
		}
	}
	return(0);
}


static int node_compare( void *node1,  void *node2) {
    	return (strcmp((( struct node *)node1)->string, (( struct node *)node2)->string));
}
