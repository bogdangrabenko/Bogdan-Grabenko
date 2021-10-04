#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{   
    int id; 
    char *name;

    struct Node *next;  // ������� ��������� �� ����. ���� ������
} List; 

List *create(int set_id, char *set_name) {
    
    List *tmp = (List*)malloc(sizeof(List));// ��������� ������ ��� ������ ������
    
    tmp -> id = set_id; // ������������ �������� ����
    tmp -> name = set_name;
    tmp -> next = NULL;
    
    return tmp; // ��������� ��������
}
    

void push_front(List **list, int set_id, char *set_name){ //����� ����
    
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
// ����� �� ����
List *search_by_id(List **list, int search_id) {
    List *tmp = *list;
    
    while(tmp -> next != NULL) {// ���������� �� ������
        
        if(tmp -> id == search_id) {// ���� ID ���������, ���������� ������ ��������
            return tmp;
        }
        tmp = tmp -> next;
    }
    return *list;// ���� ������� �� ������, ���������� ������ ������� ������
}

// ����� �� �����
List *search_by_name(List **list, char *search_name)
{
    List *tmp = *list;
    while (tmp->next != NULL)// ���������� �� ������
    {
        if (tmp->name == search_name)// ���� Name ���������, ���������� ������ ��������
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return *list;// ���� ������� �� ������, ���������� ������ ������� ������
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

