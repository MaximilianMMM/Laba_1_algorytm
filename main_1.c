
//Дано стек заповнений цілими числами випадковим чином. Видалити зі стека всі числа не кратні заданому з клавіатури.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int element, top_stc = 0, top_stc_copy = 0;
int stack[50], stack_copy[50];


void push(int element, int stc){
    if(top_stc < 50 && stc == 1) stack[top_stc++] = element;
    else if (top_stc_copy < 50 && stc != 1) stack_copy[top_stc_copy++] = element;
    else printf("Стек переповнений");
}

int pop(){
    if(top_stc >= 1) element = stack[--top_stc];
    else printf("Стек пустий");
    return element;
}

int main() {
    int n, a;

    srand(time(NULL));

    for(int i = 0; i < 50; i++){
        a = rand() % 201 - 100;
        printf("%d ", a);
        push(a, 1);
    }

    printf("\nВведіть число:");
    scanf("%d", &n);

    for(int i = 0; i < 50; i++){
        element = pop();
        if(element % n == 0) continue;
        else push(element, 2);
    }

    for(int i = top_stc_copy - 1; i >= 0; i--){
        printf("%d ", stack_copy[i]);
    }

    return 0;
}
