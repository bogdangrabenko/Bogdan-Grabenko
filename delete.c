#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{   
    int id; 
    char *name;

    struct Node *next;  // создаем указатель на след. узел списка
} List; 

List *create(int set_id, char *set_name) {
    
    List *tmp = (List*)malloc(sizeof(List));// выделение памяти под корень списка
    
    tmp -> id = set_id; // присваивание значения узлу
    tmp -> name = set_name;
    tmp -> next = NULL;
    
    return tmp; // возвращаю значение
}
    

void push_front(List **list, int set_id, char *set_name){ 
    
    List *new_element = create(set_id, set_name); 
    
    new_element -> next = *list;
    *list = new_element;
}


void push_back(List **list, int set_id, char *set_name){
    
    List *new_element = create(set_id, set_name); 
    
    List *tmp = *list;
   
    while(tmp -> next != NULL) { 
        tmp = tmp -> next;
    }
    tmp -> next = new_element;

}


    List *remove_element(List **list, int remove_id) { //новый узел
    
    List *tmp = *list, *p = NULL;// Присваивание новому указателю tmp указателя list, p - NULL
    
    if(*list == NULL) {// Проверка списка на пустоту
        return NULL;
    }
    
    while(tmp && tmp -> id != remove_id) {// Если список не пуст, поиск указателя на искомый элемент
        p = tmp;
        tmp = tmp -> next;
    }
 
    if(tmp == *list) {   // Если удаляемый элемент первый
        free(list);
        return tmp -> next;
    }
    
    if (!tmp) { // Если в списке нет искомого элемента, то возвращаем первоначальный список
        return *list;
    }
    
    p -> next = tmp -> next;// Присваивание указателю предыдущего элемента указателя tmp
    
    free(tmp);// Освобождение памяти
    return *list;
}

int main()
{
	List *list = create(0,"Bogdan");
    
    push_front(&list, -1, "VLAD");
    push_front(&list, -2, "NIKITA");
    push_back(&list, 1, "GLEB");
    push_back(&list, 2, "DIMA");
	
	list = remove_element(&list, 2);
	
	
	while (list !=NULL){
	
	printf("id=%d name=%s\n", list->id, list->name);
	
		list=list -> next;
	}	
return 0;
}

