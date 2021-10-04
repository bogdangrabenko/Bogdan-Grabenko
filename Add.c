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
    
//���������� �������� � ������ ������
void push_front(List **list, int set_id, char *set_name){ //����� ����
    
    List *new_element = create(set_id, set_name); 
    
    new_element -> next = *list;// ������������� ��������� �� ����� �������
    *list = new_element;// ����� ������� ���������� ����� ������ � ������
}

// ���������� �������� � ����� ������
void push_back(List **list, int set_id, char *set_name){ //����� ����
    
    List *new_element = create(set_id, set_name); 
    
    List *tmp = *list;
   
    while(tmp -> next != NULL) { // ����� ����� ��������� ������ � ����� ����� ��������������� ������
        tmp = tmp -> next;
    }
    tmp -> next = new_element;
    // ������������ ��������� tmp -> next �������� ���������� ������ ����
    // ������������� ���������� next � ��������� �������� �������� ������
}

// ����� ���������� ������ �������� ����� ��������� insert_id � ��������� ���������
void insert_element(List **list, int insert_id, int set_id, char *set_name) { 
    
    List *tmp = *list;// �������� ����� ���������-����� ������ list
    while (tmp -> next != NULL)// �������� ������
    {
        
        if (tmp -> id == insert_id)// �������������� �� �������� insert_id
        {
            
            List *new_element = create(set_id, set_name);// ������ ����� �������
            // ����� �������� ��������� next � ��������� insert_id � ����� ��������
            // ������ ����� ������� ��������� �� ������� , ��������� �� insert_id, �� ������� insert_id ������ ��������
            new_element -> next = tmp -> next;
            // �������� ��������� next �������� insert_id �� ����� �������
            tmp -> next = new_element;
        }
        // ��������� �� ���� ��������� ������
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
	
	List *tmp=list;
	
	while(tmp->next !=NULL)
	{
		if(tmp->id==1){
			List *new_element=create(1000,"INSERT");
			new_element->next=tmp->next;
			tmp->next=new_element;
		}
		tmp=tmp->next;
	}
	
	
	
	
	while (list !=NULL){
	
	printf("id=%d name=%s\n", list->id, list->name);
	
		list=list -> next;
	}	
return 0;
}

