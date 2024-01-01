#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node
{
	int			data;
	struct Node	*next;
}				t_node;

// Function to swap data values of a node and its next node
void	swap(t_node *tab_a)
{
	int	tmp;

	tmp = tab_a->data;
	tab_a->data = tab_a->next->data;
	tab_a->next->data = tmp;
}

// Function to print the linked list
void	printList(t_node *head)
{
	while (head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	// Create a sample linked list
	t_node *head = malloc(sizeof(t_node));
	head->data = 1;

	t_node *second = malloc(sizeof(t_node));
	second->data = 2;

	t_node *third = malloc(sizeof(t_node));
	third->data = 3;

	head->next = second;
	second->next = third;
	third->next = NULL;

	// Print the original linked list
	printf("Original Linked List: ");
	printList(head);

	// Call the swap function on the first node
	swap(head);

	// Print the linked list after swapping
	printf("Linked List after swap: ");
	printList(head);

	// Free the allocated memory
	free(head);
	free(second);
	free(third);

	return (0);
}