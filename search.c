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
    

void push_front(List **list, int set_id, char *set_name){ //новый узел
    
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
// поиск по айди
List *search_by_id(List **list, int search_id) {
    List *tmp = *list;
    
    while(tmp -> next != NULL) {// проходимся по списку
        
        if(tmp -> id == search_id) {// если ID совпадает, возвращаем нужное значение
            return tmp;
        }
        tmp = tmp -> next;
    }
    return *list;// если элемент не найден, возвращает первый элемент списка
}

// поиск по имени
List *search_by_name(List **list, char *search_name)
{
    List *tmp = *list;
    while (tmp->next != NULL)// проходимся по списку
    {
        if (tmp->name == search_name)// если Name совпадает, возвращаем нужное значение
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return *list;// если элемент не найден, возвращает первый элемент списка
}
    
int main()
{
	List *list = create(0,"Bogdan");
    
    push_front(&list, -1, "VLAD");
    push_front(&list, -2, "NIKITA");
    push_back(&list, 1, "GLEB");
    push_back(&list, 2, "DIMA");
	
	List *by_id = search_by_id(&list, "-2");
	List *by_name = search_by_name(&list, "GLEB");
	List *tmp=list;
	
	
	while (list !=NULL){
	
	printf("id=%d name=%s\n", list->id, list->name);
	
		list=list -> next;
	}	
	printf("By Name:\n%d  %s\n\n", by_name->id, by_name->name);
	printf("By ID:\n%d  %s\n\n", by_id -> id, by_id -> name);
return 0;
}

