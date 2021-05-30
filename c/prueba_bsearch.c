#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* routine to compare two nodes based on an  */
/* alphabetical ordering of the string field */


struct node {            /* these are stored in the table */
	char string[20];
};

/*
static struct node table[] = {     
    { "asparagus", 10 },
    { "beans", 6 },
    { "tomato", 7 },
    { "watermelon", 11 },
};
*/

int node_compare( void *node1,  void *node2);
int cargar(struct node t[10]);


int main(int argc, char **argv) {
	struct node *node_ptr, node;
    /* routine to compare 2 nodes */
    char str_space[20];   /* space to read string into */
	struct node *table;
	int n;
	
	if((table=(struct node *)malloc(5 * sizeof(struct node)))==NULL)
		exit(1);

	
	cargar(table);
	
    printf("sizeof struct node= %d\n", sizeof(struct node));
    n= 10 * sizeof(struct node);
    
    while (scanf("%20s", node.string) != EOF) {
    	if(!strcmp(node.string,"exit")) exit(1);
    	node_ptr = bsearch( &node, table, 5,
                            sizeof(struct node), node_compare);
        if (node_ptr != NULL) {
        	 printf("string = %20s\n",
            node_ptr->string);
        } 
        else {
        	printf("not found: %20s\n", node.string);
		}
	}
	return 0;
}


int node_compare( void *node1,  void *node2) {
    	return (strcmp((( struct node *)node1)->string, (( struct node *)node2)->string));
}

int cargar(struct node t[10]) {
	strcpy(t[0].string, "seba1");
	strcpy(t[1].string, "seba2");
	strcpy(t[2].string, "seba3");
	strcpy(t[3].string, "seba4");
	strcpy(t[4].string, "seba5");
	return 0;
}
