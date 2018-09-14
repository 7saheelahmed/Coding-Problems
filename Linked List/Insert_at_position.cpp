// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* target = new SinglyLinkedListNode(data);
    
    if(head == nullptr){
        head = target;
        
    }
    else if(position == 1){
        target->next = head;
        head = target;
        
    }
    else{
        SinglyLinkedListNode* temp = head;
        for(int i=0;i<position-1;i++){
            temp = temp->next;
        }
        target->next = temp->next;
        temp->next = target;
    }
    return head;

}