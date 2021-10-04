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


    List *remove_element(List **list, int remove_id) { //����� ����
    
    List *tmp = *list, *p = NULL;// ������������ ������ ��������� tmp ��������� list, p - NULL
    
    if(*list == NULL) {// �������� ������ �� �������
        return NULL;
    }
    
    while(tmp && tmp -> id != remove_id) {// ���� ������ �� ����, ����� ��������� �� ������� �������
        p = tmp;
        tmp = tmp -> next;
    }
 
    if(tmp == *list) {   // ���� ��������� ������� ������
        free(list);
        return tmp -> next;
    }
    
    if (!tmp) { // ���� � ������ ��� �������� ��������, �� ���������� �������������� ������
        return *list;
    }
    
    p -> next = tmp -> next;// ������������ ��������� ����������� �������� ��������� tmp
    
    free(tmp);// ������������ ������
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

