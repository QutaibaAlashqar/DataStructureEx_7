

/// QUTAIBA ALASHQAR, 20290036.
/// DATA STRUCRUE, LAB 7;


#include <stdio.h>
#include <malloc.h>


void function1();
void function2();


struct node{

    int guess;
    int data;
    struct node *right;
    struct node *left;
}node;


struct node *binary_tree = NULL;


struct node *add(struct node *tras, int number, int info){

    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    (new_node-> data) = info;
    (new_node-> guess) = number;
    (new_node-> right) = NULL;
    (new_node-> left) = NULL;

    if (tras == NULL){

        tras = new_node;
        (tras-> left) = NULL;
        (tras-> right) = NULL;
    }

    else{

        struct node *new_ptr;
        struct node *pre_ptr;

        new_ptr = tras;
        pre_ptr = NULL;

        while (new_ptr != NULL){

            pre_ptr = new_ptr;

            if (info < (new_ptr-> data)){
                new_ptr = (new_ptr-> left);
            }

            else{
                new_ptr = (new_ptr-> right);
            }
        }

        if (info < (pre_ptr-> data)){
            (pre_ptr-> left) = new_node;
        }

        else{
            (pre_ptr-> right) = new_node;
        }
    }
    return tras;
}


void function1(struct node *number){

    if (number != NULL){

        function1(number-> left);
        printf("%d %d\n", (number-> guess), (number-> data));
        function1(number-> right);
    }
}


void function3(struct node* number, int level, char charr, int value){

    if (number == NULL){
        return;
    }

    if (level == 1){

        if(number != binary_tree){
            printf("%d %d (%d %c) ", (number-> guess), (number-> data), value, charr);
        }

        else{
            printf("%d %d", (number-> guess), (number-> data));
        }
    }
    else if(level > 1){

        function3((number-> left), (level - 1), 'L', (number-> data));
        function3((number-> right), (level - 1), 'R', (number-> data));
    }
}


int Height(struct node *number){

    if(number == NULL){
        return (0);
    }

    else{

        int height1 = Height(number-> left);
        int height2  = Height(number-> right);

        if(height1 > height2){
            return (height1 + 1);
        }

        else{
            return (height2 + 1);
        }
    }
}


void function2(struct node* number){

    char charr = ('\0');
    int zero = 0;
    int number_of_height = Height(number);
    for (int i = 1; i <= number_of_height; i++){

        function3(number, i, charr, zero);
        printf("\n");
    }
}


int main(){

    int index1;
    int index2;
    scanf("%d", &index1);

    while (index1 != -1){

        scanf("%d", &index2);
        binary_tree = add(binary_tree, index1, index2);
        scanf("%d", &index1);
    }

    function1(binary_tree);
    printf("\n");
    function2(binary_tree);

    return 0;
}
