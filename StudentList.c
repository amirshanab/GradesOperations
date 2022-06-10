//
// Created by Amir on 27/11/2021.
//
#include"StudentList.h"
#include <stdlib.h>
#include <stdio.h>



StudentList* createList(){//a function to start the list and make the head null.
    StudentList *Lis = (StudentList*) malloc(sizeof (StudentList));
    Lis->head = NULL;
    return Lis;
}

void deleteList(StudentList* Lis) {// a function that deletes the list after we're done using it.
    if (Lis != NULL) {
        if (Lis->head != NULL) {
            StudentNode *NextTemp = Lis->head;
            StudentNode *Temp = NULL;
            while (NextTemp != NULL){
                Temp = NextTemp;
                NextTemp = NextTemp->next;
                free(Temp);// we go over each node in the list and free it and make it null.
                Temp =NULL;
            }
            Lis->head = NULL;
        }
    }
}
void printStudentNode(StudentNode* const Stud){// a function the prints an individual node from the list
    if(Stud == NULL) {// if the node is null it does nothing.
        return;
    }
    StudentNode * Temp = Stud;
    printf("--------------------------------------\n");
    printf("Students ID : %d\n", Temp->st->id);// printing the ID number of the student.
    if(Temp->st->grade1!= -1){// if he did the first exam:-
        printf("First Grade : %d\n" , Temp->st->grade1);// we print the grade
    }
    if(Temp->st->grade2!= -1){// if he did the second exam :-
        printf("Second Grade : %d\n", Temp->st->grade2);// we print the grade.
    }
    printf("--------------------------------------\n");

}


void printStudentList(StudentList* const Lis){// a function that works with the function before:-
    if(Lis == NULL) {// if the list is empty is does noting
        printf("clear\n");
        return;
    }
    StudentNode *temp =Lis->head;
    while(temp!= NULL){// else it goes over all the Student nodes in the list and sends them to the function (PrintStudentNode)
        printStudentNode(temp);
        temp = temp->next;
    }

}

void addToList(StudentList* Lis, Student* Stud){// a function to add student nodes sto the first of the list.
    StudentNode *temp = (StudentNode*) malloc(sizeof (StudentNode));
    temp->st = Stud;
    temp->next = NULL;
    if(Lis->head == NULL){// if the head of the list is empty it adds the student node to the head.
        Lis->head = temp;
    }
    else{// else it goes down the list looking for an empty node (NULL node).
        StudentNode *LastLis = Lis->head;
        while(LastLis->next != NULL){
            LastLis = LastLis->next;
        }
        LastLis->next = temp;
    }
}

