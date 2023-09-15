// Визначити, що більше: сума додатних і сума модулів від’ємних елементів черги. Черга заповнена цілими числами.

#include <stdio.h>
#include <stdlib.h>

// Структура черги
typedef struct Queue{
    int* elements;
    int front;
    int rear;
    int capacity;
} Queue;

// Функція для ініціалізації черги
Queue* createQueue(int capacity){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->elements = (int*)malloc(sizeof(int) * capacity);
    queue->front = queue->rear = -1;
    return queue;
}

// Функція для додавання елемента в чергу
void enqueue(Queue* queue, int num){
    if (queue->rear == queue->capacity - 1){
        printf("Черга переповнена.\n");
        return;
    }

    if (queue->front == -1){
        queue->front = 0;
    }

    queue->rear++;
    queue->elements[queue->rear] = num;
}

// Функція для обчислення суми додатних чисел в черзі
int sumPositive(Queue* queue){
    int sum = 0;
    for (int i = queue->front; i <= queue->rear; i++){
        if (queue->elements[i] > 0){
            sum += queue->elements[i];
        }
    }
    return sum;
}

// Функція для обчислення суми модулів від'ємних чисел в черзі
int sumNegativeMod(Queue* queue){
    int sum = 0;
    for (int i = queue->front; i <= queue->rear; i++){
        if (queue->elements[i] < 0){
            sum += abs(queue->elements[i]);
        }
    }
    return sum;
}

int main(){
    int n, num;

    printf("Введіть кількість елементів у черзі: ");
    scanf("%d", &n);

    Queue* queue = createQueue(n);

    for (int i = 0; i < n; i++){
        printf("Введіть %d-й елемент черги: ", i + 1);
        scanf("%d", &num);
        enqueue(queue, num);
    }

    int sumPos = sumPositive(queue);
    int sumNegMod = sumNegativeMod(queue);

    if (sumPos > sumNegMod){
        printf("Сума додатних чисел більша.\n");
    }
    else if (sumPos < sumNegMod){
        printf("Сума модулів від'ємних чисел більша.\n");
    }
    else{
        printf("Сума додатних чисел і сума модулів від'ємних чисел рівні.\n");
    }

    free(queue->elements);
    free(queue);

    return 0;
}

