#include <stdio.h>

#define STACKSIZE 100

struct stack
{
    int items[STACKSIZE];
    int top;
};

void push(struct stack *s, int x);
int pop(struct stack *s);
int viewTop(struct stack *s);
void display(struct stack *s);
int isStackEmpty(struct stack *s);
int isStackFull(struct stack *s);

int main()
{
    struct stack s; // Declaring Stack
    s.top = -1;     // Initialising

    int choice, x;
    int empty, full;
    while (choice != 7)
    {
        printf("\nStack Operations:\n");
        printf("1) push\n");
        printf("2) pop\n");
        printf("3) viewTop\n");
        printf("4) display\n");
        printf("5) isStackEmpty\n");
        printf("6) isStackFull\n");
        printf("7) exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // PUSH
            printf("Enter a number to push: ");
            scanf("%d", &x);
            push(&s, x);
            break;

        case 2: // POP
            x = pop(&s);
            printf("Popped: %d\n", x);
            break;

        case 3: // VIEW TOP
            x = viewTop(&s);
            printf("Top Element: %d\n", x);
            break;

        case 4: // DISPLAY
            display(&s);
            break;

        case 5: // isStackEmpty
            empty = isStackEmpty(&s);
            printf("Stack Empty: %d\n", empty);
            break;

        case 6: // isStackFull
            full = isStackFull(&s);
            printf("Stack Full: %d\n", full);
            break;

        case 7: // EXIT
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Choose again.\n");
            break;
        }
    }

    return 0;
}

void push(struct stack *s, int x)
{
    if (s->top == STACKSIZE - 1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }

    s->top++;             // Update index
    s->items[s->top] = x; // Store value

    return;
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("STACK UNDERFLOW\n");
        return -10000000;
    }

    int x = s->items[s->top]; // Store popped element
    s->top--;                 // Logical Deletion

    return x;

    // OR
    // return s->items[s->top--];
}

int viewTop(struct stack *s) // similar to pop()
{
    if (s->top == -1)
    {
        printf("STACK EMPTY\n");
        return -10000000;
    }

    return s->items[s->top]; // Top element
}

void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("STACK EMPTY\n");
        return;
    }

    //? Using push(), pop()
    // Temporary Stack
    struct stack temp;
    temp.top = -1;

    // Pushing elements from original stack to temp stack
    while (s->top != -1)
    {
        int x = pop(s);
        push(&temp, x);
    }

    // Displaying elements and copying to original stack simultaneously
    printf("[ ");
    while (temp.top != -1)
    {
        int x = pop(&temp);
        printf("%d ", x);
        push(s, x);
    }
    printf("]\n");

    //? Using for loop
    // printf("[ ");
    // for (int i = 0; i <= s->top; i++)
    // {
    //     printf("%d ", s->items[i]);
    // }
    // printf("]\n");

    return;
}

int isStackEmpty(struct stack *s)
{
    return s->top == -1;
}

int isStackFull(struct stack *s)
{
    return s->top == STACKSIZE - 1;
}
