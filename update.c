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
    
    tmp -> id = set_id; 
    tmp -> name = set_name;
    tmp -> next = NULL;
    
    return tmp;
}
 
void push_front(List **list, int set_id, char *set_name){ //новый узел
    
    List *new_element = create(set_id, set_name); 
    
    new_element -> next = *list;
    *list = new_element;
}

void push_back(List **list, int set_id, char *set_name){ //новый узел
    
    List *new_element = create(set_id, set_name); 
    
    List *tmp = *list;
   
    while(tmp -> next != NULL) { 
        tmp = tmp -> next;
    }
    tmp -> next = new_element;
}

// метод обновления элемента списка
void update_element(List **list, int update_id, int set_id, char *set_name) {
   
    List *tmp = *list;
   
    while(tmp -> next != NULL) {
   
        if(tmp -> id == update_id) {
            tmp -> id = set_id;
   
            tmp -> name = set_name;
        }
        tmp = tmp -> next;
    }
}

int main()
{
	List *list = create(0,"Bogdan");
    
    push_front(&list, -1, "VLAD");
    push_front(&list, -2, "NIKITA");
    push_back(&list, 1, "GLEB");
    push_back(&list, 2, "DIMA");
	update_element(&list, 1, 2, "Updated");
	List *tmp=list;
	

	
	
	
	
	while (list !=NULL){
	
	printf("id=%d name=%s\n", list->id, list->name);
	
		list=list -> next;
	}	
return 0;
}

